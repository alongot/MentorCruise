#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

#include <iostream>
using namespace std;

class SinglyLinkedList
{
private:
    struct Node {
        int data;
        Node* next;

        Node(int d) : data(d), next(nullptr) {}
    }; // End of private 

    Node* top;

public:
    // Make top pointer accesable
    SinglyLinkedList() : top(nullptr) {}

    // Constructor for list
    ~SinglyLinkedList()
    {
        Node* tmp = top;
        while (tmp != nullptr) {
            Node* nextNode = tmp->next;
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
    void Append(int data)
    {
        if (top == nullptr) {
            top = new Node(data);
            return;
    }
        Node* tmp = top;
        while (tmp->next != nullptr) {
            tmp = tmp->next;
        }
        tmp->next = new Node(data);
    } // End of append function

    void Deletion(int data)
    {
        if (IsEmpty())
        {
            cout << "Singly linked list is empty\n";
            return;
        }

        if (top->data == data)
        {
            Node *temp = top;
            top = top->next;
            delete temp;
            return;
        }

        Node *previous = nullptr;
        Node *tmp = top;

        while (tmp != nullptr)
        {
            if (tmp->data == data)
            {
                previous->next = tmp->next;
                delete tmp;
                return;
            }
            previous = tmp;
            tmp = tmp->next;
        }

        cout << "Value not found in the list.\n";
    } // End of deletion function

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
