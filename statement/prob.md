## Description

Given an array $a$ with $n$ numbers $a_1, a_2, \dots, a_n$ (possibly repeated), we say this array is `beautiful` if it satisfies the following condition:

$$(a_{i+1} - a_i)(a_{i + 2} - a_{i+1}) < 0 \text{, for all } 1 \leq i \leq n-2$$

Now, we can rearrange the elements in the array. Please output all the `beautiful` permutations of $a$.


## Input

The first line includes an integer $n$, representing the size of the array.

The second line includes $n$ numbers, representing the elements of the array.


## Output

In the first line, output the number of `beautiful` permutations. Repeated permutations should be considered the same.

For the following lines, output all the `beautiful` permutations in lexicographical order, from smallest to largest. In other words, if the $k$-th output is $b_1, b_2, \dots, b_n$, and the $(k+1)$-th output is $c_1, c_2, \dots, c_n$, there exists an index $m$ such that:

- $b_i = c_i$ for all $1 \leq i \leq m-1$
- $b_m > c_m$

Each line of the output represents a `beautiful` permutation, and its elements are separated by spaces. If there is no such permutation, output `-1`.


## Constraint

- $1 \leq n \leq 20$
- $-10^9 \leq a_i \leq 10^9$
- The number of `beautiful` permutations is no more than $2 \times 10^5$

### Subtask 1 (20pts)

- $1 \leq n \leq 10$

### Subtask 2 (30pts)

- $-10000 \leq a_i \leq 10000$

### Subtask 3 (40pts)

No other constraints


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
-1
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

## Hint

- Any sequence with a length of no more than two is considered 'beautiful.'
- You may get TLE (Time Limit Exceeded) if you use brute force without a cut-off. In other words, you should stop searching if the current sequence is not beautiful.
