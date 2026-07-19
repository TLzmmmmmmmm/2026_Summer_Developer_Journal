#include <vector>
#include <algorithm>

using namespace std;

void countingSort(vector<int>& a) {
    if (a.size() <= 1) {
        return;
    }

    // 1. Find the minimum and maximum values.
    int minValue = *min_element(a.begin(), a.end());
    int maxValue = *max_element(a.begin(), a.end());

    // k is the size of the value range.
    int range = maxValue - minValue + 1;

    // 2. Count the frequency of each value.
    vector<int> count(range, 0);

    for (int value : a) {
        count[value - minValue]++;
    }

    // 3. Convert frequencies into prefix sums.
    //
    // count[i] now represents the number of elements
    // whose values are less than or equal to:
    // i + minValue
    for (int i = 1; i < range; i++) {
        count[i] += count[i - 1];
    }

    // 4. Build the sorted output array.
    vector<int> output(a.size());

    // Traverse from right to left to preserve stability.
    for (int i = static_cast<int>(a.size()) - 1; i >= 0; i--) {
        int countIndex = a[i] - minValue;
        int outputIndex = count[countIndex] - 1;

        output[outputIndex] = a[i];
        count[countIndex]--;
    }

    // 5. Copy the sorted result back into the original array.
    a = output;
}