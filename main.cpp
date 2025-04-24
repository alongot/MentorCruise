#include <iostream>
#include "stack.h"
#include <array>
#include "queue.h"
#include "singly_linked_list.h"

using namespace std;

int main() {
    // Stack testing
    Stack MyStack;
    MyStack.push(10);
    MyStack.push(20);   
    MyStack.push(30);

    MyStack.pop();
    cout << "Top element after pop: " << MyStack.peek() << endl << endl;

    //Queue testing
    Queue MyQueue;
    MyQueue.enqueue(11);
    MyQueue.enqueue(12);

    cout << "Display queue: \n";
    MyQueue.Display();
    cout <<"Top of queue: \n";
    MyQueue.Top();

    cout << "Top of queue after dequeue: \n";
    MyQueue.dequeue();
    MyQueue.Top();

    // Singly linked list testing
    Singly_Linked_List My_Linked_List;
    My_Linked_List.append(11);
    My_Linked_List.append(0);
    My_Linked_List.append(2);

    My_Linked_List.Display();
    
    cout << "Appending more values to linked list\n";
    My_Linked_List.append(0);
    My_Linked_List.append(3);
    My_Linked_List.Display();



    return 0;
}