#include <iostream>
#include "optional.h"

using namespace std;

template <typename T>
class Queue {
private:
    struct Node {
        T data;     // The value of the node
        Node* next; // Pointer to the next node
        // Constructor to initialize node
        Node(const T& dataValue) : data(dataValue), next(nullptr) {}
    };

    Node* front;  // Pointer to the front of the queue
    Node* rear;   // Pointer to the rear of the queue

public:
    // Constructor: Initializes an empty queue
    Queue() : front(nullptr), rear(nullptr) {}

    // Destructor: Cleans up all nodes in the queue
    ~Queue() {
        while (front != nullptr) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }

    // Enqueue: Adds a value to the rear of the queue
    void Enqueue(const T& value) {
        Node* newNode = new Node(value); 
        if (rear == nullptr) { 
            front = rear = newNode; 
        } else {
            rear->next = newNode;
            rear = newNode;       // Update the rear pointer
        }
    }

    // Dequeue: Removes a value from the front of the queue
    Optional<T> Dequeue() {
        if (front == nullptr) {  // If the queue is empty
            return Optional<T>(); 
        }
        T dequeuedValue = front->data;  // Get the value at the front
        Node* temp = front;
        front = front->next;  
        if (front == nullptr) {  // 
            rear = nullptr; // Set the rear to nullptr
        }
        delete temp;  // Delete the old front node
        return Optional<T>(dequeuedValue);  
    }

    bool isEmpty() const {
        return front == nullptr; 
    }
    void Top() const {
        if (front == nullptr) {  // If the queue is empty
            cout << "Queue is empty!" << endl;  
        } else {
            cout << "Top element: " << front->data << endl; 
        }
    }

    // Display: Prints all elements in the queue
    void Display() const {
        Node* temp = front;
        while (temp != nullptr) {  // Traverse the queue
            cout << temp->data << " ";  // Print each value
            temp = temp->next;  // Move to the next node
        }
        cout << endl;
    }
};
