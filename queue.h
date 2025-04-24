#include <iostream>

using namespace std;


class Queue{

    private:
    // Create a node object
    struct Node{
        int data;
        Node* next;
    };

    Node* front;
    Node* rear;
    public:
     // Check is the queue is empty
     bool isEmpty(){
        return front == nullptr;
    }
    // Create a queue constructor
    Queue(){
        front = NULL;
        rear = NULL;
    }

    ~Queue(){
        while(!isEmpty()){
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }

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
        }
    }

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
    }

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
    }

    //Function to see top of queue
    void Top(){
        if (isEmpty()){
            cout << "Queue is empty" << endl;
            return;
        }else{
            Node* temp = front;
            cout << temp->data << endl;
        }
    }

};