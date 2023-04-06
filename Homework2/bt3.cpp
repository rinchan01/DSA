#include <iostream>
using namespace std;

class DoublyLinkedList {
    public:
    int data;
    DoublyLinkedList *next;
    DoublyLinkedList *prev;
};

DoublyLinkedList *head = NULL, *tail = NULL;

void insert(int data) {
    DoublyLinkedList *temp = new DoublyLinkedList();
    temp->data = data;
    temp->prev = NULL;
    temp->next = NULL;

    if (head == nullptr) {
        head = temp;
        tail = temp;
    } else {
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
    
}
int countTriplets(DoublyLinkedList* h)
{
    DoublyLinkedList *firstNode, *secondNode, *thirdNode;
    int count = 0;
  
    for (firstNode = h; firstNode != NULL; firstNode = firstNode->next){
        for (secondNode = firstNode->next; secondNode != NULL; secondNode = secondNode->next){
            for (thirdNode = secondNode->next; thirdNode != NULL; thirdNode = thirdNode->next){
                if ((firstNode->data + secondNode->data + thirdNode->data) == 0)   count++; 
            }
        }
    }
    return count;
}
int main() {
    int n;
    cin >> n;
    int data;
    for (int i = 0; i < n; i++) {
        cin >> data;
        insert(data);
    }
    DoublyLinkedList *temp = head;
    
    cout << countTriplets(head);
    return 0;
}