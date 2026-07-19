#include <vector>
#include <utility>

using namespace std;

void heapify(vector<int>& a, int heapSize, int root) {
    while (true) {
        int largest = root;
        int leftChild = root * 2 + 1;
        int rightChild = root * 2 + 2;

        if (leftChild < heapSize &&
            a[leftChild] > a[largest]) {
            largest = leftChild;
        }

        if (rightChild < heapSize &&
            a[rightChild] > a[largest]) {
            largest = rightChild;
        }

        if (largest == root) {
            return;
        }

        swap(a[root], a[largest]);
        root = largest;
    }
}

void heapSort(vector<int>& a) {
    int n = static_cast<int>(a.size());

    // Build a max-heap.
    for (int i = n / 2 - 1; i >= 0; --i) {
        heapify(a, n, i);
    }

    // Move the maximum element to the end.
    for (int end = n - 1; end > 0; --end) {
        swap(a[0], a[end]);
        heapify(a, end, 0);
    }
}