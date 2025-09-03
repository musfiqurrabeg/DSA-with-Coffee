#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

// Stack structure using linked list
class Stack {
private:
    Node* top;  // pointer to the top of stack

public:
    // Constructor
    Stack() {
        top = nullptr;
    }

    // Push an element onto the stack
    void push(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = top;
        top = newNode;
        cout << value << " pushed to stack\n";
    }

    // Pop an element from the stack
    void pop() {
        if (top == nullptr) {
            cout << "Stack is empty. Nothing to pop.\n";
            return;
        }
        Node* temp = top;
        cout << top->data << " popped from stack\n";
        top = top->next;
        delete temp;
    }

    // Peek the top element
    void peek() {
        if (top == nullptr) {
            cout << "Stack is empty.\n";
            return;
        }
        cout << "Top element is: " << top->data << endl;
    }

    // Check if stack is empty
    bool isEmpty() {
        return top == nullptr;
    }

    // Display stack elements
    void display() {
        if (top == nullptr) {
            cout << "Stack is empty.\n";
            return;
        }
        cout << "Stack elements: ";
        Node* temp = top;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Destructor to free memory
    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }
};

// Main function
int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);

    s.display();

    s.peek();

    s.pop();
    s.display();

    return 0;
}