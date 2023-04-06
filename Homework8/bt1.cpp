#include <iostream>
#include <algorithm>
using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int partition(int a[], int left, int right) {
    int p = a[right], i = left - 1;
    for (int j = left; j < right; j++) {
        if (a[j] < p) {
            i++;
            swap(a[j], a[i]);
        }
    }
    swap(a[i + 1], a[right]);
    return i + 1;
}
void quickSort(int a[], int left, int right) {
    if (left < right) {
        int p = partition(a, left, right);
        quickSort(a, left, p - 1);
        quickSort(a, p + 1, right);
    }
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    quickSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    
}