## Problem Description

For an array $\textbf{a}$ with $N$ integers $\textbf{a}[1], \textbf{a}[2], \ldots, \textbf{a}[N]$, we say this array is **beautiful** if it satisfies the following condition: $$(\textbf{a}[i+1] - \textbf{a}[i])(\textbf{a}[i+2] - \textbf{a}[i+1]) < 0,\text{ for all }1 \leq n\leq N-2.$$

Consider the permutations of any given integer array $\textbf{a}$, please output all the **beautiful** permutations of $\textbf{a}$.

### Input

The first line includes an integer $N$, representing the length of the array. The second line includes $N$ integers, representing the elements of the array $\textbf{a}[1], \textbf{a}[2], \ldots, \textbf{a}[N]$. All integers are separated by spaces. *Note that $\textbf{a}$ can contain repeated elements and is not guaranteed to be ordered.*

### Output

In the first line, output a number $M$ that indicates the number of *different* **beautiful** permutations of $\textbf{a}$. Note that $M = 0$ if there is no such permutation.

For each of the following $M$ lines, output the *different* **beautiful** permutations in lexicographical order, from the smallest to the largest. [Lexicographic order](https://en.wikipedia.org/wiki/Lexicographic_order) defines a length-$N$ array $\mathbf{p}$ to be smaller than another same-length array $\mathbf{q}$ if and only if $\mathbf{p}[n] < \mathbf{q}[n]$ for the first~$n$ in $1, 2, \ldots, N$ such that $\mathbf{p}[n] \neq \mathbf{q}[n]$. 
The **beautiful** permutation should be outputted with $N$ integers, separated by spaces.

### Constraints

- $1 \leq N \leq 20$
- $-10^9 \leq \textbf{a}[n] \leq 10^9$ for every $n \in \{1, 2, \ldots, N\}$
- The number of **beautiful** permutations ($M$) is no more than $2 \times 10^5$.

## Subtasks
### Subtask 1 (10 pts)
- $1 \le N \le 10$

### Subtask 2 (20 pts)
- $-10^4 \leq \textbf{a}[n] \leq 10^4$ for every $n \in \{1, 2, \ldots, N\}$

### Subtask 3 (20 pts)
- no other constraints

## Sample Testcases

### Sample Input 1
```
3
3 2 1
```

### Sample Output 1
```
4
1 3 2
2 1 3
2 3 1
3 1 2
```

### Sample Input 2
```
7
7 7 7 7 7 14 49
```

### Sample Output 2
```
0
```

### Sample Input 3
```
3
7 7 49
```

### Sample Output 3
```
1
7 49 7
```

### Sample Input 4
```
2
1 2
```

### Sample Output 4
```
2
1 2
2 1
```

## Hints
- Any array with length $N \le 2$ satisfies all the beauty constraints and hence should be considered **beautiful**.
- You may get TLE (Time Limit Exceeded) if you only enumerate every permutation in a brute-force manner without considering any cut-off. That is, you should try to stop spending time on permutations that are **not** beautiful.
- While $\textbf{a}[n]$ does not exceed the range of 4-byte integers, their difference and multiplication may not stay within 4 bytes. So using some longer integer format such as `long long` can be helpful.
