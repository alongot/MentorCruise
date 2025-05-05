#include <iostream>
#include "../Data_Structures/stack.h"
#include <array>
#include "../Data_Structures/queue.h"
#include "../Data_Structures/singly_linked_list.h"

using namespace std;

int main() {
    // Stack testing
    Stack MyStack;

    //MyStack.Pop();

    //cout << "Top element after pop: " << MyStack.Peek() << endl
     //    << endl;
         
    MyStack.Push(10);
    MyStack.Push(20);
    MyStack.Push(30);

    MyStack.Pop();
    cout << "Top element after pop: " << MyStack.Peek() << endl
         << endl;

    cout << "Displaying all values in my stack" << endl;
    MyStack.Display();

    //Queue testing
    Queue<int> MyQueue;
    //MyQueue.Dequeue();
    MyQueue.Enqueue(11);
    MyQueue.Enqueue(12);

    cout << "Display queue: \n";
    MyQueue.Display();
    cout <<"Top of queue: \n";
    MyQueue.Top();

    cout << "Top of queue after dequeue: \n";
    MyQueue.Dequeue();
    MyQueue.Top();

    // Singly linked list testing
    SinglyLinkedList MyLinkedList;

    cout << "Appending values to singly linked list\n";
    MyLinkedList.Append(11);
    MyLinkedList.Append(0);
    MyLinkedList.Append(2);

    MyLinkedList.Display();

    cout << "Appending more values to linked list\n";
    MyLinkedList.Append(0);
    MyLinkedList.Append(3);
    MyLinkedList.Display();

    cout << "Deleting value from linked list\n";
    MyLinkedList.Deletion(11);
    MyLinkedList.Display();

    int target;
    cout << "Enter a number to check if it's in the list: ";
    cin >> target;

    if (MyLinkedList.Contains(target))
    {
        cout << "Linked list contains " << target << endl;
    }
    else
    {
        cout << "Linked list does not contain " << target << endl;
    }

    return 0;
} // End of main