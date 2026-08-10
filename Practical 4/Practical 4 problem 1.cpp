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


    void insertFront(int x) {
        Node* newNode = new Node(x);
        newNode->next = head;
        head = newNode;
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


    void insertAtPosition(int x, int pos) {
        if (pos <= 1) {
            insertFront(x);
            return;
        }

        Node* temp = head;

        for (int i = 1; i < pos - 1 && temp != NULL; i++)
            temp = temp->next;


        if (temp == NULL) {
            cout << "Invalid position!" << endl;
            return;
        }

        Node* newNode = new Node(x);
        newNode->next = temp->next;
        temp->next = newNode;
    }


    void display() {
        Node* temp = head;

        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Queue q;


    q.insertFront(101);
    q.display();


    q.insertEnd(102);
    q.display();

    q.insertEnd(103);
    q.display();


    q.insertAtPosition(999, 2);
    q.display();


    q.insertAtPosition(500, 10);
    q.display();

    return 0;
}
