#include <iostream>
using namespace std;

// In this class I have defined the stack data structure using a single linked list
class MyStack {
    private:
        // Node structure as defined in our exercise
        struct Node {
            int value;
            Node* next;
        
        // Create a constructor, which we will initialize the value and set the pointer
            Node(int value, Node* next = nullptr) {
                this->value = value;
                this->next = next;
            }
        };
    public:
        Node* top; // Pointer to the top of the stack
        // Push operation
        void push(int value){
            Node* newNode = new Node(value, top);
            top = newNode;
        }

        // Peek operation
        int peek(){
        if(top != nullptr) {
            return top->value;
        } else {
            cout << "Stack is empty" << endl;
        }
    }

    };
    