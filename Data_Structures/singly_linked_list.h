#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

#include <iostream>
#include "optional.h"
using namespace std;

template <typename T>
class SinglyLinkedList
{
private:
    struct Node
    {
        T data;     // The value of the node
        Node *next; // Pointer to the next node
        // Constructor to initialize node
        Node(const T &dataValue) : data(dataValue), next(nullptr) {}
    };
    Node *top; // Pointer to the front of the stack

public:
    // Make top pointer accesable
    SinglyLinkedList() : top(nullptr) {}

    // Constructor for list
    ~SinglyLinkedList()
    {
        Node *tmp = top;
        while (tmp != nullptr)
        {
            Node *nextNode = tmp->next;
            delete tmp;
            tmp = nextNode;
        }
        top = nullptr;
    } // End of singly linked list constructor

    // Check if list is empty
    bool IsEmpty() const
    {
        return top == nullptr;
    } // End of isempty

    // Append node into the list
    void Append(const T &value)
    {
        Node *newNode = new Node(value);
        if (top == nullptr) {
            top = new Node(value);
            return;
    }
        Node* tmp = top;
        while (tmp->next != nullptr) {
            tmp = tmp->next;
        }
        tmp->next = new Node(value);
    } // End of append function

    Optional<T> Deletion(const T &data)
    {
        if (IsEmpty())
        {
            cout << "Singly linked list is empty\n";
            return Optional<T>(); // Return invalid Optional if the list is empty
        }

        if (top->data == data)
        {
            Node *temp = top;
            top = top->next;
            T deletedData = temp->data; // Store the data to return
            delete temp;
            return Optional<T>(deletedData); // Return the deleted value in an Optional
        }

        Node *previous = nullptr;
        Node *tmp = top;

        while (tmp != nullptr)
        {
            if (tmp->data == data)
            {
                previous->next = tmp->next;
                T deletedData = tmp->data; // Store the data to return
                delete tmp;
                return Optional<T>(deletedData); // Return the deleted value in an Optional
            }
            previous = tmp;
            tmp = tmp->next;
        }

        cout << "Value not found in the list.\n";
        return Optional<T>(); // Return invalid Optional if the value is not found
    }

    // Contains method, check if list contains target elemetn
    // Contains method, check if list contains target elemetn
    bool Contains(int data)
    {
        if (IsEmpty())
        {
            cout << "Singly linked list is empty\n";
            return false;
        }
        else
        {
            Node *tmp = top;
            while (tmp != nullptr)
            {
                if (tmp->data == data)
                {
                    return true;
                }
                tmp = tmp->next;
            }
            return false;
        }
    }

    // Display linkedl ist
    void Display() const {
        if (IsEmpty())
        {
            cout << "Linked list is empty\n";
            return;
        }

        Node* tmp = top;
        while (tmp != nullptr){
            cout << tmp->data << endl;
            tmp = tmp->next;
        }
    }// End of display function

    Node *GetTop() const
    {
        return top;
    } // End of getTop function
}; // End of Singly List Class

#endif
