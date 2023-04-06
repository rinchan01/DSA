#include <iostream>
using namespace std;

//get maximum number to get max number of digits
int getMax(int arr[], int size) {
    int res = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > res) {
            res = arr[i];
        }
    }
    return res;
}

//radix sorting, instead of passing digit number,
// pass 10^i (exp), then (a[i]/exp) % 10 is the digit number.
void radixSort(int arr[], int size, int exp) {

    // output array and count-the-occurence array
    int output[size];
    int counts[10] = {0};
    
    //store the occurence
    for (int i = 0; i < size; i++) {
        int digit = (arr[i]/exp) % 10;
        counts[digit]++;
    }

    //doing prefix sum, make counts[i] the 
    //actual position of number in output array.
    // the first element not changing.
    for (int i = 1; i < 10; i++) {
        counts[i] += counts[i-1];
    }
    
    // build output array. 
    for (int i = size - 1; i >= 0; i--) {
        int digit = (arr[i]/exp) % 10;
        output[counts[digit] - 1] = arr[i];
        counts[digit]--;
    }

    // copy the output array to the input array
    for (int i = 0; i < size; i++) {
        arr[i] = output[i];
    }
}

int main() {
    int size;
    cin >> size;
    int arr[size];

    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    int max = getMax(arr, size);
    for (int exp = 1; max / exp > 0; exp *= 10) {
        radixSort(arr, size, exp);
    }

    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    return 0;

}