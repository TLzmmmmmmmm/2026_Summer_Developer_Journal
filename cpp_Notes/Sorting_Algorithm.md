# Sorting Algorithms

## 1. Selection Sort

- Description:
  - Divide the array into a sorted part and an unsorted part.
  - Repeatedly select the minimum element from the unsorted part.
  - Swap it with the first element of the unsorted part.
  - After the `i`th iteration, the first `i` elements are in their final positions.
- Time Complexity:
  - Best: `O(n^2)`
  - Average: `O(n^2)`
  - Worst: `O(n^2)`
- Space Complexity: `O(1)`
- In-place.
- Usually unstable.
- Performs only `O(n)` swaps, so it can be useful when writing or swapping elements is expensive.
- [Template Code](https://github.com/TLzmmmmmmmm/2026_Summer_Developer_Journal/blob/main/cpp_Notes/templates/Sorting_Algorithm/Selection.cpp)

## 2. Insertion Sort

- Description:
  - Maintain a sorted prefix of the array.
  - Take the next element and insert it into the correct position in the sorted prefix.
  - Shift larger elements one position to the right.
- Time Complexity:
  - Best: `O(n)` when the array is already sorted.
  - Average: `O(n^2)`
  - Worst: `O(n^2)`
- Space Complexity: `O(1)`
- In-place.
- Stable if equal elements are not moved past each other.
- Efficient for small or nearly sorted arrays.
- Commonly used as a subroutine in hybrid sorting algorithms.
- [Template Code](https://github.com/TLzmmmmmmmm/2026_Summer_Developer_Journal/blob/main/cpp_Notes/templates/Sorting_Algorithm/Insertion.cpp)

## 3. Bubble Sort

- Description:
  - Repeatedly compare adjacent elements.
  - Swap them if they are in the wrong order.
  - After each iteration, the largest remaining element moves to the end.
- Time Complexity:
  - Best: `O(n)` with an early-stop flag.
  - Average: `O(n^2)`
  - Worst: `O(n^2)`
- Space Complexity: `O(1)`
- In-place.
- Stable if elements are swapped only when the left element is strictly greater.
- Mainly useful for learning and very small inputs.
- Stop early if no swap occurs during an iteration.
- [Template Code](https://github.com/TLzmmmmmmmm/2026_Summer_Developer_Journal/blob/main/cpp_Notes/templates/Sorting_Algorithm/Bubble.cpp)

## 4. Merge Sort

- Description:
  - Divide the array into two halves.
  - Recursively sort both halves.
  - Merge the two sorted halves into one sorted array.
- Divide-and-conquer algorithm.
- Time Complexity:
  - Best: `O(n log n)`
  - Average: `O(n log n)`
  - Worst: `O(n log n)`
- Space Complexity:
  - `O(n)` for the standard array implementation.
- Stable if equal elements from the left half are selected first during merging.
- Usually not in-place for arrays.
- Suitable for linked lists and external sorting.
- Guarantees `O(n log n)` time complexity.
- [Template Code](https://github.com/TLzmmmmmmmm/2026_Summer_Developer_Journal/blob/main/cpp_Notes/templates/Sorting_Algorithm/Merge.cpp)

## 5. Quick Sort

- Description:
  - Select a pivot.
  - Partition the array so that smaller elements are placed before the pivot.
  - Place larger elements after the pivot.
  - Recursively sort the two partitions.
- Divide-and-conquer algorithm.
- Time Complexity:
  - Best: `O(n log n)`
  - Average: `O(n log n)`
  - Worst: `O(n^2)` when the partitions are extremely unbalanced.
- Space Complexity:
  - Average: `O(log n)` recursion stack.
  - Worst: `O(n)` recursion stack.
- Usually implemented in-place.
- Usually unstable.
- Generally fast for arrays because of good cache locality and small constant factors.
- Randomized pivot selection reduces the probability of the worst case.
- Three-way partitioning is useful when the array contains many duplicate values.
- [Template Code](https://github.com/TLzmmmmmmmm/2026_Summer_Developer_Journal/blob/main/cpp_Notes/templates/Sorting_Algorithm/Quick.cpp)

## 6. Counting Sort

- Description:
  - Count how many times each value appears in the input array.
  - Store the frequency of each value in a counting array.
  - Reconstruct the sorted array according to the frequencies.
- Non-comparison sorting algorithm.
- Requirements:
  - The values must be integers or convertible into integer keys.
  - The value range should not be too large compared with the number of elements.
- Basic Steps:
  - Find the minimum and maximum values.
  - Create a counting array for the range from `minValue` to `maxValue`.
  - For each element `x`, increase:
    - `count[x - minValue]`
  - Traverse the counting array in ascending order.
  - Write each value back according to its frequency.
- Time Complexity:
  - Best: `O(n + k)`
  - Average: `O(n + k)`
  - Worst: `O(n + k)`
  - `n` is the number of elements.
  - `k` is the size of the value range:
    - `k = maxValue - minValue + 1`
- Space Complexity:
  - `O(k)` for the basic implementation.
  - `O(n + k)` for the stable implementation using an output array.
- Stability:
  - The basic reconstruction version is not generally used to preserve the relative order of associated records.
  - Counting Sort can be stable when prefix sums and an output array are used.
- Usually not in-place.
- Efficient when:
  - `k` is small or comparable to `n`.
  - The input contains many repeated integer values.
- Commonly used as a stable subroutine in Radix Sort.
- [Template Code](https://github.com/TLzmmmmmmmm/2026_Summer_Developer_Journal/blob/main/cpp_Notes/templates/Sorting_Algorithm/Counting.cpp)

## 7. Bucket Sort

- Description:
  - Divide the input elements into several buckets according to their values.
  - Sort the elements inside each bucket.
  - Concatenate all buckets in order to obtain the final sorted array.
- Distribution-based sorting algorithm.
- Time Complexity:
  - Best: `O(n + k)`
  - Average: `O(n + k)`
  - Worst: `O(n^2)`
  - `n` is the number of elements.
  - `k` is the number of buckets.
  - The actual complexity also depends on the sorting algorithm used inside each bucket.
- Space Complexity:
  - Usually `O(n + k)`.
- Stability:
  - Bucket Sort can be stable if:
    - Elements are inserted into buckets in their original order.
    - A stable sorting algorithm is used inside each bucket.
- Usually not in-place.
- Efficient when:
  - The value range is known.
  - The elements are distributed relatively uniformly.
  - The elements can be naturally divided into value intervals.

## 8. Radix Sort

- Description:
  - Sort elements digit by digit.
  - A stable sorting algorithm, usually Counting Sort, is used for each digit.
- Non-comparison sorting algorithm.
- Requirements:
  - The keys must be representable by digits.
- Basic Steps:
  - Find the maximum value to determine the number of digits.
  - Sort the elements by the ones digit.
  - Repeat for the tens, hundreds, and higher digits.
- Time Complexity:
  - `O(d(n + b))`
  - `d` is the number of digits.
  - `b` is the numerical base, usually `10`.
- Space Complexity:
  - `O(n + b)`
- Stability:
  - Stable if the sorting method used for each digit is stable.
- Usually not in-place.
- Efficient when:
  - Sorting many integers with a limited number of digits.
- [Template Code](https://github.com/TLzmmmmmmmm/2026_Summer_Developer_Journal/blob/main/cpp_Notes/templates/Sorting_Algorithm/Radix.cpp)

## 9. Heap Sort

- Description:
  - Build a max-heap from the input array.
  - Repeatedly move the maximum element to the end.
  - Restore the max-heap after each removal.
- Comparison-based sorting algorithm.
- Basic Steps:
  - Build a max-heap.
  - Swap the root with the last unsorted element.
  - Reduce the heap size.
  - Apply heapify to restore the max-heap.
- Time Complexity:
  - Best: `O(n log n)`
  - Average: `O(n log n)`
  - Worst: `O(n log n)`
  - Building the heap takes `O(n)`.
- Space Complexity:
  - `O(1)` excluding the recursion stack.
- Stability:
  - Not stable.
- In-place sorting algorithm.
- Efficient when:
  - Guaranteed `O(n log n)` worst-case performance is required.
  - Extra memory should be minimized.
- Disadvantage:
  - Usually slower in practice than Quick Sort because of poor cache locality.
- [Template Code](https://github.com/TLzmmmmmmmm/2026_Summer_Developer_Journal/blob/main/cpp_Notes/templates/Sorting_Algorithm/Heap.cpp)