#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
using namespace std;


void sort(int a[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) {
                swap(a[i], a[j]);
            }
        }
    }
}


int main() {
    ifstream myfile ("numbers.txt");
    string number = "";
    string line;
    int ind = 0;
    int numbers[100];
    int i = 0;
    
    // read file and add numbers to number array.
    if (myfile.is_open()) {
        while (getline(myfile, line)) {
            
            while (ind <= line.length()) {
                if (line[ind] == ' ' || ind == line.length()) {
                    numbers[i] = stoi(number);
                    number = "";
                    i++;
                    ind++;
                } else {
                    number += line[ind];
                    ind++;
                }
            }
            ind = 0;
            
        } 
        myfile.close();
        
        sort(numbers, i);

        ofstream myOutFile;
        myOutFile.open("numbers_sorted.txt");
        for (int j = 0; j < i; j++) {
            myOutFile << numbers[j] << " ";
        }

        
    } else {
        cout << "Unable to open file!";
    }
    return 0;
}