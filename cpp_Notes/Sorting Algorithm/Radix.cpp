#include <vector>
#include <algorithm>

using namespace std;

void countingSortByDigit(vector<int>& a, long long digitPlace) {
    vector<int> count(10, 0);
    vector<int> output(a.size());

    for (int value : a) {
        int digit = (value / digitPlace) % 10;
        count[digit]++;
    }

    for (int i = 1; i < 10; ++i) {
        count[i] += count[i - 1];
    }

    // Traverse from right to left to preserve stability.
    for (int i = static_cast<int>(a.size()) - 1; i >= 0; --i) {
        int digit = (a[i] / digitPlace) % 10;
        output[--count[digit]] = a[i];
    }

    a = output;
}

void radixSort(vector<int>& a) {
    if (a.size() <= 1) {
        return;
    }

    int maxValue = *max_element(a.begin(), a.end());

    for (long long digitPlace = 1;
         maxValue / digitPlace > 0;
         digitPlace *= 10) {
        countingSortByDigit(a, digitPlace);
    }
}