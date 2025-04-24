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
            
        };
    public:
        Node* top; // Pointer to the top of the stack

        // Initialize top to nullptr
        Stack() : top(nullptr) {}

        // Destructor to free memory
        ~Stack() {
            while (!isEmpty()){
                pop();
            }
        }
        // Push operation
        void push(int value){
            Node* newNode = new Node;
            newNode->value = value;
            newNode->next = top;
            top = newNode;
        }
        

        // Pop operation, remove value at the top of stack LIFO order
        void pop(){
            if(top != nullptr) {
                Node* temp = top;
                top = top->next;
                delete temp;
            } else {
                cout << "Stack is empty" << endl;
            }
        }

        // Peek operation
        int peek(){
        if(top != nullptr) {
            return top->value;
        } else {
            cout << "Stack is empty" << endl;
            return -1;
        }
        }

        // IsEmpty operation
        bool isEmpty(){
            return top == nullptr;
        }
    };

#endif // STACK_H