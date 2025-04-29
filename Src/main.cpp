#include <iostream>
#include "../Data_Structures/stack.h"
#include <array>
#include "../Data_Structures/queue.h"
#include "../Data_Structures/singly_linked_list.h"

using namespace std;

int main() {
    // Stack testing
    Stack MyStack;
    MyStack.push(10);
    MyStack.push(20);   
    MyStack.push(30);

    MyStack.pop();
    cout << "Top element after pop: " << MyStack.peek() << endl << endl;

    cout << "Displaying all values in my stack" << endl;
    MyStack.Display();

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

    cout << "Appending values to singly linked list\n";
    My_Linked_List.append(11);
    My_Linked_List.append(0);
    My_Linked_List.append(2);

    My_Linked_List.Display();
    
    cout << "Appending more values to linked list\n";
    My_Linked_List.append(0);
    My_Linked_List.append(3);
    My_Linked_List.Display();

    cout << "Deleting value from linked list\n";

    My_Linked_List.deletion();

    My_Linked_List.Display();
    return 0;
} // End of main