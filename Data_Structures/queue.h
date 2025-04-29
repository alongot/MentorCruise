#include <iostream>

using namespace std;


class Queue{
    private:
        // Create a node object
        struct Node{
            int data;
            Node* next;
        };// End of struct node

    public:
        Node* front;
        Node* rear;
        // Check is the queue is empty
        bool isEmpty(){
            return front == nullptr;
        }// end of isempty function
        
        // Create a queue constructor
        Queue(){
            front = NULL;
            rear = NULL;
        } // End of queue constructor

        ~Queue(){
            while(!isEmpty()){
                Node* temp = front;
                front = front->next;
                delete temp;
            }
        } // End of queue destructor

        // Function to enqueue values to the front of the queue
        void enqueue (int data){
            Node* newnode = new Node();
            newnode->data = data;
            newnode->next = NULL;
            if (isEmpty()){
                front = newnode;
                rear = newnode;
            }
            else{
                rear->next = newnode; 
                rear = newnode;      
            }
        } // End of enqueue function

        // Function to dequque values in FIFO order
        void dequeue(){
            if (isEmpty()){
                cout << "Queue is empty" << endl;
                return;
            }
            else{
                Node* temp = front;
                front = front->next;
                delete temp;
            }
        } // End of dequeue function

        // Function to see the queue
        void Display(){
            if (isEmpty()){
                cout << "Queue is empty" << endl;
                return;
            }else{
                Node* temp = front;
                while(temp != nullptr){
                    cout << temp->data << endl;
                    temp = temp->next;
                }
            }        
        }// End of display function

        //Function to see top of queue
        void Top(){
            if (isEmpty()){
                cout << "Queue is empty" << endl;
                return;
            }else{
                Node* temp = front;
                cout << temp->data << endl;
            }
        } // End of top function

}; // End of queue class