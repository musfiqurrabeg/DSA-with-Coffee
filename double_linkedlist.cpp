#include <iostream>
using namespace std;

// Node structure for doubly linked list
struct Node {
    int data;
    Node* prev;
    Node* next;
};

// Insert at beginning
void insertBegin(Node*& head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->prev = nullptr;
    newNode->next = head;

    if (head != nullptr)
        head->prev = newNode;

    head = newNode;
}

// Insert at end
void insertEnd(Node*& head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;

    if (head == nullptr) {
        newNode->prev = nullptr;
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

// Insert at a given position (1-based)
void insertMiddle(Node*& head, int value, int position) {
    if (position <= 1) {
        insertBegin(head, value);
        return;
    }

    Node* temp = head;
    for (int i = 1; i < position - 1 && temp != nullptr; i++) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Position out of range, inserting at end.\n";
        insertEnd(head, value);
        return;
    }

    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != nullptr)
        temp->next->prev = newNode;

    temp->next = newNode;
}

// Search for a value
int search(Node* head, int key) {
    Node* temp = head;
    int position = 1;
    while (temp != nullptr) {
        if (temp->data == key)
            return position;
        temp = temp->next;
        position++;
    }
    return -1;
}

// Delete by position
void deleteByPosition(Node*& head, int position) {
    if (head == nullptr || position <= 0) {
        cout << "Invalid position or empty list.\n";
        return;
    }

    Node* temp = head;

    if (position == 1) { // delete first node
        head = head->next;
        if (head != nullptr)
            head->prev = nullptr;
        delete temp;
        return;
    }

    for (int i = 1; i < position && temp != nullptr; i++) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Position out of range.\n";
        return;
    }

    if (temp->next != nullptr)
        temp->next->prev = temp->prev;

    if (temp->prev != nullptr)
        temp->prev->next = temp->next;

    delete temp;
}

// Display list forward
void displayList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    Node* head = nullptr;

    insertEnd(head, 10);
    insertEnd(head, 20);
    insertEnd(head, 30);
    insertEnd(head, 40);

    cout << "Initial List: ";
    displayList(head);

    insertBegin(head, 5);
    cout << "After inserting 5 at beginning: ";
    displayList(head);

    insertMiddle(head, 15, 3);
    cout << "After inserting 15 at position 3: ";
    displayList(head);

    int key = 20;
    int pos = search(head, key);
    if (pos != -1)
        cout << "Element " << key << " found at position " << pos << "\n";
    else
        cout << "Element " << key << " not found\n";

    deleteByPosition(head, 3);
    cout << "After deleting node at position 3: ";
    displayList(head);

    return 0;
}