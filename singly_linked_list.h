#include <iostream>

using namespace std;
// Node structure for singly linked list

class Singly_Linked_List{
    private: 
        struct Node{
            int data;
            Node* next;

            Node(int d){
                data = d;
                next = NULL;
            }
        };

    public:
        Node* top;

        //Is empty
        bool isEmpty(){
            return top = nullptr;
        }

        Singly_Linked_List(){
            top =  NULL;
        }

        ~Singly_Linked_List(){
            Node* tmp = top;
            while(tmp != nullptr){
                Node* nextNode = tmp->next;
                delete tmp;
                tmp = nextNode; 
            top = nullptr; 
            }
        }

        void append(int data){
            if(top == NULL){
                top = new Node(data);
                return;
            }else{
                Node* tmp = top;
                while(tmp->next != NULL){
                    tmp = tmp->next;
                }
                tmp ->next = new Node(data);
            }
        }

        void Display(){
            Node* tmp = top;

            if(isEmpty()){
                cout <<"Linked list is empty\n";
            }else{
            while(tmp!=NULL){
                cout << tmp->data << endl;
                tmp = tmp->next;
            }
        }
    }
};