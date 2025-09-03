#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

// Queue structure using linked list
class Queue {
private:
    Node* front;  // pointer to front
    Node* rear;   // pointer to rear

public:
    // Constructor
    Queue() {
        front = rear = nullptr;
    }

    // Enqueue (insert at rear)
    void enqueue(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;

        if (rear == nullptr) {  // queue empty
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        cout << value << " enqueued to queue\n";
    }

    // Dequeue (remove from front)
    void dequeue() {
        if (front == nullptr) {
            cout << "Queue is empty. Nothing to dequeue.\n";
            return;
        }
        Node* temp = front;
        cout << front->data << " dequeued from queue\n";
        front = front->next;

        if (front == nullptr) {
            rear = nullptr;
        }
        delete temp;
    }

    // Peek front element
    void peek() {
        if (front == nullptr) {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "Front element is: " << front->data << endl;
    }

    // Check if queue is empty
    bool isEmpty() {
        return front == nullptr;
    }

    // Display queue elements
    void display() {
        if (front == nullptr) {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "Queue elements: ";
        Node* temp = front;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Destructor to free memory
    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }
};

// Main function
int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.display();

    q.peek();

    q.dequeue();
    q.display();

    return 0;
}