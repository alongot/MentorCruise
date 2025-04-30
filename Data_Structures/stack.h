#ifndef STACK_H
#define STACK_H
#include <stdexcept>

#include <iostream>
using namespace std;

// In this class I have defined the stack data structure using a single linked list
class Stack {
    private:
        // Node structure as defined in our exercise
        struct Node {
            int value;
            Node* next;
            
        }; // End of struct node
    public:
        Node* top; // Pointer to the top of the stack

        // Initialize top to nullptr
        Stack() : top(nullptr) {}

        // Destructor to free memory
        ~Stack() {
            while (!IsEmpty())
            {
                Pop();
            }
        } // End of stack destructor

        // Push operation
        void Push(int value)
        {
            Node* newNode = new Node;
            newNode->value = value;
            newNode->next = top;
            top = newNode;
        } // End of push function

        // Pop operation, remove value at the top of stack LIFO order
        void Pop()
        {
           if(IsEmpty()){
            std::__throw_underflow_error("Stack is empty");
           }
            Node* temp = top;
            top = top->next;
            delete temp;
        } // End of pop function

        // Peek operation
        int Peek()
        {
            if(IsEmpty()){
                throw::underflow_error("Stack is empty");
            }
            return top->value;
        } // End of peek function

        // IsEmpty operation
        bool IsEmpty()
        {
            return top == nullptr;
        } // End of IsEmtpy function

        void Display() {
            if (IsEmpty())
            {
                cout << "Stack is empty\n";
                return;
            }
            Node* tmp = top;
            while (tmp != nullptr) {
                cout << tmp->value << endl;
                tmp = tmp->next;
            }
        
        } // End of display function

    }; // End of stack class

#endif // STACK_H