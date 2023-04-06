#include <iostream>
using namespace std;

int main() {
    int arr[5];
    for (int i=0; i<5; i++) {
        cin >> arr[i];
    }
    int max=arr[0], min=arr[0];
    for (int i=1; i<5; i++) {
        if (max < arr[i]) max = arr[i];
        if (min > arr[i]) min = arr[i];
    }
    cout << min + max;
    return 0;
}
