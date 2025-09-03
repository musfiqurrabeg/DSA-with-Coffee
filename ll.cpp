#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

class List {
    Node* head;
    Node* tail;

public:
    List() {
        head = tail =  NULL;
    }

    void pushFront(int value) {
        Node* newNode = new Node(value);

        if(head == NULL) {
            head = tail = newNode;
            return;
        }
        else {
            newNode -> next = head;
            head = newNode;
        }
    }

    void pushBack(int value) {
        Node* newNode = new Node(value);
        if(head == NULL) {
            head = tail = newNode;
        } else {
            tail -> next = newNode;
            tail = newNode;
        }
    }

    void popFront() {
        if(head == NULL) {
            cout << "List is empty, cannot pop from front." << endl;
            return;
        }
        
        Node* temp = head;
        head = head -> next;
        temp -> next = NULL;
        delete temp;
        
    }

    void popBack() {
        if(head == NULL) {
            cout << "List is empty, cannot pop from back." << endl;
            return;
        }

        Node* temp = head;
        while(temp -> next != tail) {
            temp = temp -> next;
        }
        temp -> next = NULL;
        delete tail;
        tail = temp;
    }

    void insert(int value, int position) {
        if(position < 0) {
            cout << "Invalid position." << endl;
            return;
        }
        if(position == 0) {
            pushFront(value);
            return;
        }

        Node* temp = head;
        for(int i = 0; i < position - 1; i++) {
            if(temp == NULL) {
                cout << "Position out of bounds." << endl;
                return;
            }
            temp = temp -> next;
        }

        Node* newNode = new Node(value);
        newNode -> next = temp -> next;
        temp -> next = newNode;
    }

    int search(int value) {
        Node* temp = head;
        int index = 0;

        while(temp != NULL) {
            if(temp -> data == value) {
                return index;
            }

            temp = temp -> next;
            index++;
        }
        return -1; 
    }

    void printLL() {
        Node* temp = head;

        while(temp != NULL) {
            cout << temp -> data << " -> ";
            temp = temp -> next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    cout << "Hello, World!" << endl;

    List myList;

    myList.pushFront(10);
    myList.pushFront(20);
    myList.pushFront(30);
    myList.pushFront(40);
    myList.pushFront(50);

    cout << "after pushFront: ";
    myList.printLL();

    myList.pushBack(60);
    myList.pushBack(70);
    myList.pushBack(80);
    myList.pushBack(90);
    myList.pushBack(100);

    cout << "after pushBack: ";
    myList.printLL();

    myList.popFront();
    myList.popFront();
    cout << "after popFront: ";
    myList.printLL();

    myList.popBack();
    myList.popBack();
    cout << "after popBack: ";
    myList.printLL();


    return 0;
}
