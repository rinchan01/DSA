#include <iostream>
#include <vector>
using namespace std;

struct Stack {
    vector <int> s1;

    void push(int data) {
        s1.push_back(data);
    }

    void pop() {
        s1.pop_back();
    }
};
int main() {
    int n;
    cin >> n;
    int number;
    string cmd[n];
    int count = 0;
    Stack *stack = new Stack();
    
    for (int i = 0; i < n; i++) {
        cin >> cmd[i];
        if (cmd[i] == "push") {
            cin >> number;
            stack->push(number);
            count++;
        } if (cmd[i] == "pop") {
            stack->pop();
            count--;
        }
    }
    for (int i = 0; i < count; i++) {
        cout << stack->s1[i] << " ";
    }
    return 0;
}