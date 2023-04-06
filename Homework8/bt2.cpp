#include <iostream>
using namespace std;

int main() {
    int n, X, res = 0;
    cin >> n >> X;
    int arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < n; j++) {
            sum += arr[i];
            if (sum == X) {
                res++;
                cout << "YES";
                break;
            }
        }
        if (res != 0) break;
    }

    if (res == 0) cout << "NO";

    return 0;
}