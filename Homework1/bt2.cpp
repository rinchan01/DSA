#include <iostream>
using namespace std;

int main() {
    char str[1000];
    cin.getline(str, 1000);
    int size=0;
    while (str[size] != NULL) {
        size++;
    }
    for (int i=size-1; i>=0; i--) {
        cout << str[i];
    }
    return 0;
}
