#include <iostream>
#include <algorithm>
using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void heapTree(int arr[], int size, int i) {
    int root = i;
    int left = 2 * i + 1; // le
    int right = 2 * i + 2; // chan 

    // if the number at root index is smaller than the left one
    if (left < size && arr[left] > arr[root]) {
        root = left;
    }
    // if the number at root index is smaller than the right one
    if (right < size && arr[right] > arr[root]) {
        root = right;
    }
    // if root isn't index 0
    if (root != i) {
        swap(arr[i], arr[root]);
        // call the function for the sub-tree
        heapTree(arr, size, root);
    }
}


int main() {
    //make a max heap tree with arrays
    int arr[] = {2, 1, 10, 6, 3, 8, 7, 13, 20, 14, 0, 35}; 
    int size = sizeof(arr) / sizeof(arr[0]);

    //cac phan tu la luon co chi so lon hon n/2, 
    //nen chi can xet tu n/2 tro ve truoc (node la khong co con)
    for (int i = size/2 - 1; i >= 0; i--) {
        heapTree(arr, size, i);
    }

    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}