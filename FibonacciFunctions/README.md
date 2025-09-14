
# A Comparative Analysis of Fibonacci Algorithms

This document demonstrates and compares three different algorithmic approaches to calculating the n-th term of the Fibonacci sequence. The methods analyzed are:

1.  **Iterative Approach**
2.  **Naive Recursive Approach**
3.  **Recursive Approach with Memoization (Dynamic Programming)**

## 1. Iterative Approach

This method is one of the most straightforward and efficient ways to calculate the n-th Fibonacci number. It utilizes a loop to sequentially compute each number based on the two preceding ones, starting from the beginning of the sequence.

### Analysis

*   **Time Complexity: `O(n)`**
    The algorithm performs a single loop that runs approximately `n` times. This linear complexity is very efficient.
*   **Space Complexity: `O(1)`**
    The algorithm only uses a few variables to store the state, regardless of the value of `n`. This makes its space usage constant and highly memory-efficient.

## 2. Naive Recursive Approach

This approach is a direct translation of the mathematical definition of the Fibonacci sequence: `F(n) = F(n-1) + F(n-2)`. While it is elegant and easy to read, its performance is extremely poor due to redundant computations.

### Analysis

*   **Time Complexity: `O(2^n)`**
    This is an exponential complexity. The core problem is that the function recomputes the same values multiple times. For example, to calculate `F(5)`, `F(3)` is calculated twice, `F(2)` is calculated three times, and so on. The number of calls grows explosively as `n` increases, making this approach impractical for anything but small values of `n`.
*   **Space Complexity: `O(n)`**
    The memory usage is determined by the maximum depth of the recursion on the call stack, which is proportional to `n`.

## 3. Recursive Approach with Memoization

This method, a form of Dynamic Programming, combines the elegance of recursion with the efficiency of the iterative approach. The key idea is to store (or "memoize") the results of expensive function calls in a cache and return the cached result when the same inputs occur again, avoiding redundant work.

### Usage

Before calling the function, it is necessary to initialize a helper data structure (e.g., a `std::vector`) to act as a cache. This vector must be sized to `n + 1` and filled with a sentinel value (like `0`) to indicate that no values have been computed yet. For example, this can be achieved with the line:
`vec.assign(number + 1, 0);`

### Analysis

*   **Time Complexity: `O(n)`**
    Although the structure is recursive, each Fibonacci number up to `n` is calculated **exactly once**. Any subsequent calls for a number that has already been computed will return the stored value from the cache in `O(1)` time. As a result, the overall time complexity becomes linear.
*   **Space Complexity: `O(n)`**
    Space is consumed by two sources: the call stack depth (`O(n)`) and the cache vector required to store the computed values (`O(n)`).

