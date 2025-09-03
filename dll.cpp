#include<iostream>
#include<vector>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int value) {
        data = value;
        next = prev = NULL;
    }
};

class DoubleLinkedList {
    Node* head;
    Node* tail;

public:
    DoubleLinkedList() {
        head = tail = NULL;
    }

    void pushFront(int value) {
        Node* newNode = new Node(value);

        if(head == NULL) {
            head = tail = newNode;
        } else {
            newNode -> next = head;
            head -> prev = newNode;
            head = newNode;
        }
    }

    void pushBack(int value) {
        Node* newNode = new Node(value);

        if(head == NULL) {
            head = tail = newNode;
        } else {
            newNode -> prev = tail;
            tail -> next = newNode;
            tail = newNode;
        }
    }

    void popFront() {
        if(head == NULL) {
            cout << "List is empty, can't pop from the front" << endl;
            return;
        }

        Node* temp = head;
        head = head -> next;

        if(head != NULL) {
            head -> prev = NULL;
        }

        temp -> next = NULL;
        delete temp;
    }

    void popBack() {
        if(head == NULL) {
            cout << "List is empty, can't pop from the back" << endl;
            return;
        }
        Node* temp = tail;
        tail = tail -> prev;
        if(tail != NULL) {
            tail -> next = NULL;
        }

        temp -> prev = NULL;
        delete temp;
    }

    void printList() {
        Node* temp = head;

        while(temp != NULL) {
            cout << temp -> data << " <=> ";
            temp = temp -> next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    DoubleLinkedList dll;

    cout << endl;
    dll.pushFront(10);
    dll.pushFront(20);
    dll.pushFront(30);
    dll.pushFront(40);
    dll.pushFront(50);

    cout << "After Push Front Current List: ";
    dll.printList();
    cout << endl;

    cout << endl;
    dll.pushBack(60);
    dll.pushBack(70);
    dll.pushBack(80);
    dll.pushBack(90);
    dll.pushBack(100);

    cout << "After Push Back Current List: ";
    dll.printList();
    cout << endl;





     
    return 0;
}