# Advanced Data Structure

## 1. High-Precision Arithmetic
- Used when an integer exceeds the range of long long.
- Store each decimal digit in a vector<int>.
- Digits are stored in reverse order.
  - 12345 -> {5, 4, 3, 2, 1}