#include <iostream>
#include <fstream>
#include <ostream>
#include <stdlib.h>
#include <string>
using namespace std;

int row, col;

//rectangle between (start, left) & (finish, right) has the largest sum.

void printRes(int r1, int c1, int r2, int c2, int sum) {
    cout << r1 << " " << c1 << " " << r2 << " " << c2 << " " << sum << endl;
}
// Kadane Algorithm: compare sum of subarrays,
// use Kadane to compare the row's subarrays.
int kadane(int arr[], int *start, int *finish, int size){
    int sum = 0, i = 0, maxSum = INT_MIN;
    // as the maxSum can be a negative number, choose INT_MIN to 
    // initialize maxSum.

    // Kadane's algorithm can only works with arrays which have at least
    // one positive number. Set finish to -1 to check the case that an input
    // array has no positive number later.
    *finish = -1;

    int start_temp = 0;

    for (; i < size; i++) {
        sum += arr[i];
        if (sum < 0) {
            sum = 0;
            start_temp = i + 1;
        } else if (sum > maxSum) {
            maxSum = sum;
            *start = start_temp;
            *finish = i;
        }
    }

    if (*finish != -1) return maxSum;
    // if the array has all of the elements which are negative numbers,
    // the largest sum is the max number of the array.
    
    maxSum = arr[0];
    *start = *finish = 0;

    for (i = 1; i < size; i++) {
        if (arr[i] > maxSum) {
            maxSum = arr[i];
            *start = *finish = i;
        }
    }
    return maxSum;

}



int main() {
    ifstream myfile("Matrix.txt");
    string line = "";
    string number = "";
    
    //read file.
    if (myfile.is_open()) {
        myfile >> row >> col;
        int numbers[row][col];
        for (int i = 0; i < row; i++) { 
            for (int j = 0; j < col; j++) {
                myfile >> numbers[i][j];
            }
        }
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                cout << numbers[i][j] << " ";
            }
            cout << endl;
        }
    
    // find the rectangle with largest sum.
    int maxSum = INT_MIN, resLeft, resRight, resTop, resBottom;
    int sum, start, finish;
    int left, right;

    for (left = 0; left < col; left++) {
        // array has elements are sums of elements of rows 
        // from left -> right.
        int temp[row] = {0};

        for (right = left; right < col; right++) {
            for (int i = 0; i < row; i++) {
                temp[i] += numbers[i][right];

                // find the maximum rectangle in 'temp' array by kadane.
                sum = kadane(temp, &start, &finish, row);

            // check the maxSum of the 2D array and change to new maxSum
            // update the co-ordinate of the rectangle (fisrt and finish point).
                if (sum > maxSum) {
                    maxSum = sum;
                    resLeft = left;
                    resRight = right;
                    resTop = start;
                    resBottom = finish;
                }
            }
        }

    }
    // +1 as the result start from 1.
    printRes(resTop + 1, resLeft + 1, resBottom + 1, resRight + 1, maxSum);
    } else {
        cout << "Cannot open file!" << endl;
    }
    return 0;
}