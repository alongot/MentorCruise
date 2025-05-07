#ifndef LINEAR_DOUBLY_LINKED_LIST_H
#define LINEAR_DOUBLY_LINKED_LIST_H
#include <iostream>
#include "optional.h"
using namespace std;

template <typename T>
class LinearDoublyLinkedList
{
private:
    struct Node
    { 
        T data;     // The value of the node
        Node* next; // Pointer to the next node
        Node* previous;
        // Constructor to initialize node
        Node(const T &dataValue) : data(dataValue), next(nullptr), previous(nullptr) {}
    };
    Node *top; // Pointer to the front 


public:
    // Make top pointer accesable
    LinearDoublyLinkedList() : top(nullptr) {}

    // Constructor for list
    ~LinearDoublyLinkedList()
    {
        Node* tmp = top;
        while (tmp != nullptr) {
            Node* nextNode = tmp->next;
            delete tmp;
            tmp = nextNode;
        }
        top = nullptr;
    } // End of doubly linked list constructor

   // Check if list is empty
   bool isEmpty() const
   {
       return top == nullptr;
   } // End of isempty

   // Inserts a new node into the list while sorting
   void InsertSorted(const T& value)
   {
    //Create new node
    Node *newnode = new Node(value);
    // Insert in beginning if list is null or value is smaller
    if (!top || value < top->data) {
        newnode->next = top;
        if(top != nullptr){
            top->previous = newnode;
        }
        top = newnode;
        return;
    } 
    // Traverse to find correct position
    Node* curr = top;
    while(curr->next && curr->next->data < value){
        curr = curr->next;
    }

    // Insert new node a
    newnode->next = curr->next;
    newnode->previous = curr;
    curr->next = newnode;

    //If not inserting at end fix backward link
    if (newnode->next != nullptr) {
        newnode->next->previous = newnode;
    }

   }//InsertSorted

   // Deletion function to delete specific element as requested by user 
   Optional<T> Deletion(const T &data){
        //Stop if user tries to delete on empty list
        if(isEmpty()){
            cout << "Trying to delete on empty list: \n";
            return Optional<T> (); // Returns invalid optional
        }
        else
        {
            // Delete the top node
            if(top->data == data){
                Node* temp = top;
                top = top->next;
                if(top != nullptr){ //update head pointer to previous pointer
                    top->previous = nullptr;
                }
                T deletedData = temp->data;
                delete temp;
                return Optional<T>(deletedData); 
            }
            // Traverse through the list to find the node to delete
            Node *curr = top;
            while (curr != nullptr){
                if (curr->data == data){
                    // Deleting middle or tail node
                    if (curr->previous){
                        curr->previous->next = curr->next;
                    }
                    if (curr->next){
                        curr->next->previous = curr->previous;
                    }
                    T deletedData = curr->data;
                    delete curr;
                    return Optional<T>(deletedData);
            }
            curr = curr->next; // Move to next node
        }
        cout << "Value not found in list\n";
        return Optional<T> ();
    }
    }

    // Find out if list contains an element as requested by user
    bool Contains(const T &data){
        // Return false is list is empty
        if (isEmpty()){
            cout << "List is empty \n";
            return false;
        }
        else
        {
            // Create a node and set it to top
            Node *temp = top;
            // While temp is pointing to a node
            while (temp != nullptr){
                // If the target is found return true
                if(temp->data == data)
                {
                    return true;
                }
                // Otherwise proceed to next node
                temp = temp->next;
            }
            return false;
        }
    } // End of contains

    /*
    // Display linkedl ist
    void Display() const {
        if (isEmpty())
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
    */
   
    // Iterator class to traverse through list 
    class Iterator {
        Node* current;
    public:
        // Construcot with node
        Iterator(Node* node) : current(node) {}
        
        // Move iterator to next node
        Iterator& operator++() 
        { 
            current = current->next; return *this; 
        }
        
        // Check to see if it is poitning to different nodes
        bool operator!=(const Iterator& other) const { 
            return current != other.current; 
        }
        
        // Dereference the data
        T& operator*() const 
        { 
            return current->data; 
        }

    };

    // Return iterator pointing to first node
    Iterator begin() const
    { 
        return Iterator(top); 
    }
    // return iterator pointing to nullptr
    Iterator end() const
    {
        return Iterator(nullptr); 
    }
    

}; // End of Doubly List Class



#endif
