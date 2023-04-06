#include <iostream>
using namespace std;

int search(int arr[], int n, int x) {
    if (n-1<0) return -1;
    if (arr[n-1] == x) return n-1;
    return search(arr, n-1, x);
    
    
}

int main() {
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << search(arr, 10, 10);
    return 0;
}