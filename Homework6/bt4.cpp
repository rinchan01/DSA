#include <iostream>
#include <string>
#include <math.h>
using namespace std;


int main() {
    int n; 
    cin >> n;
    string s = "";

    for (int i = 0; i < n; i++) {
        s += '0';
    }


    for (int i = 0; i < pow(2, n); i++) {
        cout << s << endl;
        for (int i = n - 1; i >= 0; i--) {
            //000->001->010
            if (s[i] == '0') {
                s[i] = '1';
                break;
            } else {
                s[i] = '0';
            }
        } 
    }
    return 0;
}