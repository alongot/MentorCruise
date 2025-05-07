#ifndef STACK_H
#define STACK_H
#include <stdexcept>
#include "optional.h"

#include <iostream>
using namespace std;

template <typename T>
class Stack
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
    // Initialize top to nullptr
    Stack() : top(nullptr) {}

    // Destructor to free memory
    ~Stack()
    {
        if (top == nullptr){
            return;
        }
        while (top != nullptr)
        {
            Node *temp = top;
            top = top->next;
            delete temp;
        }
    } // End of stack destructor

    // Push operation
    void Push(const T &value)
    {
        Node *newNode = new Node(value);
        newNode->next = top;
        top = newNode;
    } // End of push function

    // Pop operation, remove value at the top of stack LIFO order
    Optional<T> Pop()
    {
        if (top == nullptr)
        {
            return Optional<T>();
        }
        T poppedValue = top->data;
        Node *temp = top;
        top = top->next;
        delete temp;
        return Optional<T>(poppedValue);
    } // End of pop function

    // Peek operation
    Optional<T> Peek() const
    {
        if (top == nullptr)
        {
            return Optional<T>();
        }
        else
        {
            return Optional<T>(top->data);
        }
    } // End of peek function

    // IsEmpty operation
    bool isEmpty() const
    {
        return top == nullptr;
    } // End of IsEmtpy function

    void Display() const
    {
        if (isEmpty())
        {
            cout << "Stack is empty\n";
            return;
        }
        Node *tmp = top;
        while (tmp != nullptr)
        {
            cout << tmp->data << endl;
            tmp = tmp->next;
        }

    } // End of display function

}; // End of stack class

#endif // STACK_H