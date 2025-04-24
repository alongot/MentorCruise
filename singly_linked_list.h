#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

#include <iostream>
using namespace std;

class Singly_Linked_List {
private:
    struct Node {
        int data;
        Node* next;

        Node(int d) : data(d), next(nullptr) {}
    }; // End of private 

    Node* top;

public:
    // Make top pointer accesable
    Singly_Linked_List() : top(nullptr) {}

    // Constructor for list
    ~Singly_Linked_List() {
        Node* tmp = top;
        while (tmp != nullptr) {
            Node* nextNode = tmp->next;
            delete tmp;
            tmp = nextNode;
        }
        top = nullptr;
    }// End of singly linked list constructor

    // Check if list is empty
    bool isEmpty() const {
        return top == nullptr;
    } // End of isempty

    // Append node into the list
    void append(int data) {
        if (top == nullptr) {
            top = new Node(data);
            return;
    }
        Node* tmp = top;
        while (tmp->next != nullptr) {
            tmp = tmp->next;
        }
        tmp->next = new Node(data);
    }// End of append function

     // Delete node from the list
    void deletion() {
        if (top != nullptr) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }else{
            cout << "Singly linked list is empty\n";        
        }
    }// End of deletion function


    // Display linkedl ist
    void Display() const {
        if(isEmpty()) {
            cout << "Linked list is empty\n";
            return;
        }

        Node* tmp = top;
        while (tmp != nullptr){
            cout << tmp->data << endl;
            tmp = tmp->next;
        }
    }// End of display function

    Node* getTop() const {
        return top;
    }// End of getTop function
}; // End of Singly List Class

#endif
