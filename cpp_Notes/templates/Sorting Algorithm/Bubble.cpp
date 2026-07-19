#include <vector>
using namespace std;

void bubbleSort(vector<int>& a) {
    int n = a.size();
    for(int i = n-1 ; i > 0; i--) {
        bool swapped = false;
        for(int j = 0; j < i; j++) {
            if(a[j] > a[j+1]) {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
                swapped = true;
            }
        }
        if (!swapped)
        {
            break;
        }
    } 
}