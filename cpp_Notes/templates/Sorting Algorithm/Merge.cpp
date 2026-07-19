#include <vector>
using namespace std;

void merge(
    vector<int>& a,
    vector<int>& buffer,
    int left,
    int mid,
    int right
) {
    int i = left;
    int j = mid;
    int k = left;

    while (i < mid && j < right) {
        if (a[i] <= a[j]) {
            buffer[k++] = a[i++];
        } else {
            buffer[k++] = a[j++];
        }
    }

    while (i < mid) {
        buffer[k++] = a[i++];
    }

    while (j < right) {
        buffer[k++] = a[j++];
    }

    for (int index = left; index < right; ++index) {
        a[index] = buffer[index];
    }
}

void mergeSortImpl(
    vector<int>& a,
    vector<int>& buffer,
    int left,
    int right
) {
    // The range contains zero or one element.
    if (right - left <= 1) {
        return;
    }

    int mid = left + (right - left) / 2;

    mergeSortImpl(a, buffer, left, mid);
    mergeSortImpl(a, buffer, mid, right);

    // The two halves are already in the correct order.
    if (a[mid - 1] <= a[mid]) {
        return;
    }

    merge(a, buffer, left, mid, right);
}

void mergeSort(std::vector<int>& a) {
    if (a.size() <= 1) {
        return;
    }

    vector<int> buffer(a.size());

    mergeSortImpl(
        a,
        buffer,
        0,
        a.size()
    );
}