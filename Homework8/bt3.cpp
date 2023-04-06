#include <iostream>
#include <algorithm>
using namespace std;


int max_value_sum(int weight[], int value[], int items, int maxWeight) {
    int V[items + 1][maxWeight + 1];
    //i : item
    //j : weight
    for (int i = 0; i <= items; i++) {
        for (int j = 0; j <= maxWeight; j++) {
            if (i == 0 || j == 0) {
                V[i][j] = 0;
            } else if (weight[i-1] <= j) {
                V[i][j] = max(V[i-1][j], V[i-1][j - weight[i - 1]] + value[i - 1]);
            } else {
                V[i][j] = V[i-1][j];
            }
        }
    }
    return V[items][maxWeight];
}

int main() {
    int n, X;
    cin >> n >> X;
    int weight[n];
    int value[n];

    for (int i = 0; i < n; i++) {
        cin >> weight[i] >> value[i];
    }
        
    cout << max_value_sum(weight, value, n, X);
    return 0;

}