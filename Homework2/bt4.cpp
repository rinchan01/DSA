#include <iostream>

using namespace std;

int queue[100000];
int ind = 0; 

void enqueue(int x) {
    queue[ind] = x;
    ind++;
}

void dequeue() {
    int i = 0;
    int size = ind;
    while (i < size) {
        queue[i] = queue[i+1];
        i++;
    }
    ind--;
}

int main() {
    int n;
    cin >> n;
    int x;
    string cmd[n];
    for (int i = 0; i < n; i++) {
        cin >> cmd[i];
        if (cmd[i] == "enqueue") {
            cin >> x;
            enqueue(x);
        } else {
            dequeue();
        }
    }
    for (int i = 0; i < ind; i++) {
        cout << queue[i] << " ";
    }
    return 0;
}