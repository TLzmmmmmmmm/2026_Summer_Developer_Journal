#include <vector>
#include <random>
#include <utility>
using namespace std;

void quickSortImpl(vector<int>& a, int left, int right) {
    // Sort the closed interval [left, right].
    if (left >= right) {
        return;
    }

    static std::mt19937 generator(std::random_device{}());

    std::uniform_int_distribution<int> distribution(left, right);
    int pivot = a[distribution(generator)];

    // Three-way partition:
    // [left, less - 1]     < pivot
    // [less, current - 1]  == pivot
    // [current, greater]   unknown
    // [greater + 1, right] > pivot
    int less = left;
    int current = left;
    int greater = right;

    while (current <= greater) {
        if (a[current] < pivot) {
            std::swap(a[less], a[current]);
            ++less;
            ++current;
        } else if (a[current] > pivot) {
            std::swap(a[current], a[greater]);
            --greater;
        } else {
            ++current;
        }
    }

    quickSortImpl(a, left, less - 1);
    quickSortImpl(a, greater + 1, right);
}

void quickSort(std::vector<int>& a) {
    if (a.size() <= 1) {
        return;
    }

    quickSortImpl(
        a,
        0,
        static_cast<int>(a.size()) - 1
    );
}