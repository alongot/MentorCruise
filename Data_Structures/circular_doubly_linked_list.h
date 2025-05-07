#ifndef CIRCULAR_DOUBLY_LINKED_LIST_H
#define CIRCULAR_DOUBLY_LINKED_LIST_H
#include <iostream>
#include "optional.h"
using namespace std;

template <typename T>
class CircularDoublyLinkedList
{
private:
    struct Node
    { 
        T data;     // The value of the node
        Node* next; // Pointer to the next node
        Node* previous;
        // Constructor to initialize node
        Node(const T &dataValue) : data(dataValue), next(nullptr), previous(nullptr) {}
    };
    Node *top; // Pointer to the front 


public:
    // Make top pointer accessible
    CircularDoublyLinkedList() : top(nullptr) {}

    // Destructor cleans up memory
    ~CircularDoublyLinkedList() {
        if (top == nullptr) return; 

        Node* temp = top;
        Node* start = top;
        while (temp != nullptr) {
            Node* nextNode = temp->next; // Save next node
            delete temp; // Delete current node
            if (nextNode == start) break; // Stop when we circle back to the start
            temp = nextNode; // Move to next node
        }

        top = nullptr; // Ensure the list is empty
    }

   // Check if list is empty
   bool isEmpty() const
   {
       return top == nullptr;
   } // End of isEmpty

   // Inserts a new node into the list while sorting
   void InsertSorted(const T& value)
   {
    // Create new node
    Node *newnode = new Node(value);
    // If list empty make new node point to itself
    if (isEmpty()) {
        newnode->next = newnode;
        newnode->previous = newnode;
        top = newnode;
    } else {
        Node *last = top->previous; // Previous node to the top node is the last node
        last->next = newnode; // Connect last node
        newnode->previous = last; // Connect new node to last node
        newnode->next = top; // New node points to the top
        top->previous = newnode; // The top previous node is new node
    }

   } // InsertSorted

   Optional<T> Deletion(const T &data) {
    // Stop if user tries to delete from an empty list
    if (isEmpty()) {
        cout << "Trying to delete from an empty list.\n";
        return Optional<T>(); 
    }
    Node* curr = top;
    // Delete top node
    if (curr->data == data) {
        Node* temp = top;
        // If there's only one node in the list
        if (curr->next == top) {
            top = nullptr; // List becomes empty
        } else {
            top = top->next;
            top->previous = curr->previous;
            curr->previous->next = top;
        }

        T deletedData = temp->data;
        delete temp;
        return Optional<T>(deletedData); 
    }

    // Traverse through the list to find node
    Node* start = top;
    while (curr != nullptr) {
        if (curr->data == data) {
            // Deleting a middle or tail node
            if (curr->previous) {
                curr->previous->next = curr->next;
            }
            if (curr->next) {
                curr->next->previous = curr->previous;
            }
            T deletedData = curr->data;
            delete curr;
            return Optional<T>(deletedData);
        }
        curr = curr->next;
        if (curr == start) break; // Stop when we circle back to the start
    }
    // Value not found in the list
    cout << "Value not found in list.\n";
    return Optional<T>(); 
   } // Deletion

    bool Contains(const T &data) {
        // Return false if list is empty
        if (isEmpty()) {
            cout << "List is empty \n";
            return false;
        } else {
            Node *temp = top;
            Node *start = top;
            while (temp != nullptr) {
                // If the target is found, return true
                if (temp->data == data) {
                    return true;
                }
                // Otherwise, proceed to the next node
                temp = temp->next;
                if (temp == start) break; // Stop when we circle back to the start
            }
            // If the loop ends without finding the data, return false
            return false;
        }
    } // End of Contains
    
    // Display linked list
    void Display() const {
        if (isEmpty()) {
            cout << "Linked list is empty\n";
            return;
        }

        Node* tmp = top;
        Node* start = top;
        while (tmp != nullptr) {
            cout << tmp->data << endl;
            tmp = tmp->next;
            if (tmp == start) break; // Stop when we circle back to the start
        }
    } // End of Display function

}; // End of Doubly List Class

#endif
