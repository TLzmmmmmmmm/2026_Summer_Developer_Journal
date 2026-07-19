#include <vector>
using namespace std;

void insertionSort(vector<int>& a) {
    int n = a.size();
    for(int i = 1 ; i < n; i++) {
        int x = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > x) {
            a[j + 1] = a[j];
            j--;
        }
        a[j+1] = x;
    }
}