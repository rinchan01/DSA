#include <iostream>
using namespace std;

int main() {
    int size;
    cin >> size;
    int arr[size];
    for (int i=0; i<size; i++) {
        cin >> arr[i];
    }
    int temp;
    for (int i=0; i<size; i++) {
        for (j=i+1; j<size; j++) {
            if (arr[j] < arr[i]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    for (int i=0; i<size; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
