#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

Node *addEnd(Node *head, int data) {
    Node *temp = new Node();
    temp->data = data;
    temp->next = NULL;
    if (head == nullptr) {
        head = temp;
        return head;
    } else {
        Node *p = head;
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = temp;
        return head;
    }
}
Node *insert(Node *head, int position, int data) {
    Node *temp = new Node();
    temp->data = data;
    temp->next = NULL;
 
    /**
     * if the position is 0, it means add the node to the head.
     * if head is null, the list is null.
     */
    if (position == 0 || head == nullptr) {
        if (head == nullptr) {
            head = temp;
        } else {
            temp->next = head;
            head = temp;
        }
        return head;
    }
    else {
        int count = 0;
        for (Node *p=head; p != nullptr; p = p->next) {
            count++;
            if (count == position) {
                temp->next = p->next;
                p->next = temp;
            }
        }
        return head;
    }
}
Node *deletePos(Node *head, int position) {
    Node *temp = head;
    /**
     * if the position is 0, delete the head.
     * if not, change the node at given position to its next node.
     * use an integer to reach the given position.
     */
    if (position == 0) {
        head = head->next;
        return head;
    }
    int k = 1;
    while (k < position-2) {
        temp = temp->next;
        k++;
    }
    temp->next = temp->next->next;
    return head;
}
int main() {
    int n;
    cin >> n;
    string cmd[n];
    int position[n];
    int number[n];
    Node *head = new Node();
    head = nullptr;
    int count = 0;

    for (int i=0; i<n; i++) {
        cin >> cmd[i];
        if (cmd[i] == "insert") {
            cin >> position[i] >> number[i];
            count++;
            if (count < position[i]) {
                cout << "The position is bigger than the size of the list." << endl;
            } else {
                head = insert(head, position[i], number[i]);
            }
                
        }
        else if (cmd[i] == "delete") {
            cin >> position[i];
            head = deletePos(head, position[i]);
        }
    }
    for (Node *p=head; p != nullptr; p = p->next) {
        cout << p->data << " ";
    }
    return 0;
}