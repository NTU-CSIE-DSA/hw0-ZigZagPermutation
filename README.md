# DSA 2024 HW0 Problem 2 - Zig-Zag Permutation 
## tutorial 
In this problem, we need to implement a recursive function. We declare an array called 'ans' and a variable 'num' to record the beautiful permutations found so far. The 'cur' array represents the array we are currently checking, while the 'used' array records which elements from the given array 'a' have already been placed into 'cur'.

In the 'main' function, to avoid finding duplicate beautiful permutations in subsequent functions, we first sort the 'a' array.

In the 'solve' function, we pass two parameters: 'idx' and 'n'. 'idx' is used to track which position to fill in 'cur', while 'n' indicates when to terminate the recursion. When entering the recursive function, we first check if 'idx' is equal to 'n'. If they are equal, it means we have filled 'cur' with all elements from 'a', so we copy 'cur' to 'ans[num]' and increment 'num'. If 'idx' is not equal to 'n', we need to fill 'cur' with elements from 'a'. During each recursion, we iterate through the elements of 'a' one by one. If an element has been marked as used in previous recursions, we move to the next element. Additionally, to avoid checking duplicate occurrences of 'cur' prematurely, if we find that the current element from 'a' is the same as the previous one used, we also skip it.

After filling 'cur' with elements from 'a', we check whether 'cur' is beautiful. The checking process involves first verifying if 'cur' contains only two or fewer elements. If there are three or more elements, we then confirm whether the last three elements added to 'cur' form a beautiful permutation. Once we confirm that the 'cur' with the newly added element remains beautiful, we can proceed to the next recursion. However, before calling the function, we need to mark the element as 'used' in the 'used' array, and upon the function's return, we need to unmark it.


## sample code
```C
#include <stdio.h>
#include <stdbool.h>

int a[20];  // the given array 'a' in the problem
int ans[200000][20];  // record all the beautiful permutations
int cur[20];  // record the current sequence during recursion
int num = 0;  // record the number of beautiful permutations
bool used[20] = {};  // record whether the element in 'a' has been used during recursion

// Use recursion to find all the beautiful permutations
// 'idx' represents the current position during recursion
void solve(int idx, int n) {
  if (idx == n) {  // The current sequence ('cur') is a beautiful permutation
    for (int i = 0; i < n; i++) {
      ans[num][i] = cur[i];
    }
    num++;
    return;
  }
  int pre = -1;
  for (int i = 0; i < n; i++) {
    // If 'a[i]' hasn't been used, try to put 'a[i]' at 'cur[idx]'
    if (!used[i]) {
      // Avoid repeated recursion (the same 'cur[0...idx]' should not be recursed more than once)
      if (pre != -1 && a[pre] == a[i]) continue;
      pre = i;

      if (idx < 2 || ((long long)(a[i] - cur[idx - 1]) * (cur[idx - 1] - cur[idx - 2]) < 0)) {
        // Continue recursion only when the current sequence ('cur') is not beautiful
        cur[idx] = a[i];
        used[i] = true;
        solve(idx + 1, n);
        used[i] = false;
      }
    }
  }
}

int main() {

  int n;
  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }

  // Sort the array from small to large
  for (int i = 0; i < n; i++) {
    for (int j = 1; j < n; j++) {
      if (a[j - 1] > a[j]) {
        int tmp = a[j - 1];
        a[j - 1] = a[j];
        a[j] = tmp;
      }
    }
  }

  solve(0, n);
  // Output all the beautiful permutations in 'ans'
  printf("%d\n", num);
  for (int i = 0; i < num; i++) {
    for (int j = 0; j < n; j++) {
      printf("%d ", ans[i][j]);
    }
    printf("\n");
  }

  return 0;
}

```

## common mistake
1. When we confirm whether three numbers $a, b, c \ \ (-10^9 \le a, b, c \le 10^9)$ form a beautiful permutation, we need to calculate $(b - a) \times (c - b)$. Using int to store the data might lead to overflow. Therefore, we should use long long to store the data.
2. If we don't prevent duplicate beautiful permutations in advance and instead list out all permutations and then remove duplicates, it will lead to timeouts. This is because listing all permutations requires a time complexity of $O(n!)$, where $n$ can be up to $20$. On average, a computer can execute only $10^8$ instructions per second.