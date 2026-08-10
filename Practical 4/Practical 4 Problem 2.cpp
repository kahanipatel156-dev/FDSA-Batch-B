#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Queue {
    Node* head;

public:
    Queue() {
        head = NULL;
    }

    void insertEnd(int x) {
        Node* newNode = new Node(x);

        if (head == NULL) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
    }


    void deleteByValue(int x) {
        if (head == NULL)
            return;


        if (head->data == x) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* temp = head;

        while (temp->next != NULL && temp->next->data != x)
            temp = temp->next;


        if (temp->next != NULL) {
            Node* del = temp->next;
            temp->next = del->next;
            delete del;
        }
    }


    void displayForward() {
        Node* temp = head;

        cout << "Front to Back: ";
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }


    void displayReverse(Node* temp) {
        if (temp == NULL)
            return;

        displayReverse(temp->next);
        cout << temp->data << " ";
    }

    void reversePrint() {
        cout << "Back to Front: ";
        displayReverse(head);
        cout << endl;
    }
};

int main() {
    Queue q;


    q.insertEnd(101);
    q.insertEnd(102);
    q.insertEnd(103);
    q.insertEnd(104);
    q.insertEnd(105);


    q.displayForward();


    q.deleteByValue(103);

    cout << "After deleting 103:" << endl;
    q.displayForward();


    q.reversePrint();

    return 0;
}
