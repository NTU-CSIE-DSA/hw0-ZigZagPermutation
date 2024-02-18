#include <stdio.h>
#include <stdbool.h>

int a[20];
int ans[200000][20];
int cur[20];
int num = 0;
bool used[20] = {};

void solve(int idx, int n) {
  if(idx == n) {
    for(int i = 0; i < n; i++) {
      ans[num][i] = cur[i];
      if(i >= 2 && ((long long) (cur[i] - cur[i - 1]) * (cur[i - 1] - cur[i - 2]) >= 0)) {
        return;
      }
    }
    num++;
    return;
  }
  int pre = -1;
  for(int i = 0; i < n; i++) {
    if(!used[i]) {
      if(pre != -1 && a[pre] == a[i]) continue;
      pre = i;
      cur[idx] = a[i];
      used[i] = true;
      solve(idx + 1, n);
      used[i] = false;
    }
  }
}

int main() {

  int n;
  scanf("%d", &n);

  for(int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  for(int i = 0; i < n; i++) {
    for(int j = 1; j < n; j++) {
      if(a[j - 1] > a[j]) {
        int tmp = a[j - 1];
        a[j - 1] = a[j];
        a[j] = tmp;
      }
    }
  }

  solve(0, n);
  printf("%d\n", num);
  for(int i = 0; i < num; i++) {
    for(int j = 0; j < n; j++) {
      printf("%d ", ans[i][j]);
    }
    printf("\n");
  }

  return 0;
}

