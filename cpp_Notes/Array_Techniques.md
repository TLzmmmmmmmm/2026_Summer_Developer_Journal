# Array and Sequence Techniques

## 1. Prefix Sum

- Purpose:
  - Preprocess an array so that range-sum queries can be answered efficiently.
- State Definition:
  - `prefix[i]` is the sum of the first `i` elements.
  - Use an array of size `n + 1`.
- Initialization:
  - `prefix[0] = 0`
- Construction:
  - `prefix[i + 1] = prefix[i] + nums[i]`
- Range Sum:
  - For a zero-indexed inclusive range `[left, right]`:
    - `sum(left, right) = prefix[right + 1] - prefix[left]`
- Time Complexity:
  - Preprocessing: `O(n)`
  - Each range query: `O(1)`
- Space Complexity:
  - `O(n)`
- Common Uses:
  - Range-sum queries.
  - Counting subarrays with a required sum.
  - Two-dimensional matrix range sums.
  - Prefix XOR and prefix frequency techniques.
- Limitation:
  - Basic prefix sums are most useful when the array does not change frequently.
  - For frequent updates and queries, use a Fenwick Tree or Segment Tree.

## 2. Two Pointers

- Description:
  - Use two indices or pointers to traverse a sequence while maintaining a relationship between them.
- Common Patterns:
  - Opposite-direction pointers:
    - Start one pointer at each end.
    - Move them toward each other.
  - Same-direction pointers:
    - Both pointers move from left to right.
    - One pointer may represent the start of a valid range.
  - Fast and slow pointers:
    - Move the pointers at different speeds.
    - Commonly used for linked-list cycle detection.
- Time Complexity:
  - Usually `O(n)` because each pointer moves at most `O(n)` times.
- Space Complexity:
  - Usually `O(1)`.
- Efficient when:
  - The array is sorted.
  - The problem asks for a pair, interval, partition, or duplicate removal.
  - A nested loop can be replaced by controlled pointer movement.
- Common Uses:
  - Two-sum in a sorted array.
  - Removing duplicates.
  - Merging sorted sequences.
  - Palindrome checking.
  - Linked-list cycle detection.

## 3. Sliding Window

- Description:
  - Maintain a contiguous subarray or substring while moving its boundaries.
  - Sliding Window is usually a specialized same-direction two-pointer technique.
- Window Boundaries:
  - `left` represents the start of the window.
  - `right` expands the window.
  - Move `left` forward when the window violates a condition.
- Time Complexity:
  - Usually `O(n)` because each element enters and leaves the window at most once.
- Space Complexity:
  - `O(1)` when only numeric statistics are maintained.
  - `O(k)` when a map or frequency array is used.
- Common Uses:
  - Maximum or minimum sum of a fixed-length subarray.
  - Longest substring satisfying a condition.
  - Shortest subarray satisfying a condition.
  - Frequency-based substring problems.