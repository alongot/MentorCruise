#include <iostream>
#include "../Data_Structures/stack.h"
#include <array>
#include "../Data_Structures/queue.h"
#include "../Data_Structures/singly_linked_list.h"
#include "../Data_Structures/linear_doubly_linked_list.h"
#include "../Data_Structures/circular_doubly_linked_list.h"
#include "../Data_Structures/binary_search_tree.h"


using namespace std;

int main() {
    // Stack testing
    Stack <int> MyStack;

    MyStack.Push(10);
    MyStack.Push(20);
    MyStack.Push(30);

    MyStack.Pop();
    MyStack.Peek();
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
    SinglyLinkedList<int> MyLinkedList;

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

    /*
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
    */

    LinearDoublyLinkedList<int> MyLinearDoublyLinkedList;
    
    MyLinearDoublyLinkedList.InsertSorted(11);
    MyLinearDoublyLinkedList.InsertSorted(3);
    MyLinearDoublyLinkedList.InsertSorted(2);
    MyLinearDoublyLinkedList.InsertSorted(12);
    MyLinearDoublyLinkedList.InsertSorted(03);

    cout << "Displaying values in doubly linked list: \n";
    for(int val : MyLinearDoublyLinkedList){
        cout << val << " "; 
    }

    cout << "Displaying values in doubly linked list after deletion: \n";
    MyLinearDoublyLinkedList.Deletion(12);
    for(int val : MyLinearDoublyLinkedList){
        cout << val << " "; 
    }
    int target = 5;
    if (MyLinearDoublyLinkedList.Contains(target))
    {
        cout << "Linked list contains " << target << endl;
    }
    else
    {
        cout << "Linked list does not contain " << target << endl;
    }

    CircularDoublyLinkedList<int> MyCircularDoublyLinkedList;
    
    MyCircularDoublyLinkedList.InsertSorted(11);
    MyCircularDoublyLinkedList.InsertSorted(3);
    MyCircularDoublyLinkedList.InsertSorted(2);
    MyCircularDoublyLinkedList.InsertSorted(12);
    MyCircularDoublyLinkedList.InsertSorted(03);

    cout << "Displaying values in circular doubly linked list: \n";
    MyCircularDoublyLinkedList.Display();
    cout << "Displaying values in circular doubly linked list after deletion: \n";
    MyCircularDoublyLinkedList.Deletion(3);
    MyCircularDoublyLinkedList.Display();

    if (MyCircularDoublyLinkedList.Contains(target))
    {
        cout << "Linked list contains " << target << endl;
    }
    else
    {
        cout << "Linked list does not contain " << target << endl;
    }

    BST<int> tree;

    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    cout << "In-order traversal: ";
    tree.inorder(); // 20 30 40 50 60 70 80

    cout << "Contains 40? " << (tree.contains(40) ? "Yes" : "No") << endl;
    cout << "Contains 100? " << (tree.contains(100) ? "Yes" : "No") << endl;

    tree.remove(30);

    cout << "In-order after deleting 30: ";
    tree.inorder(); // 20 40 50 60 70 80

    return 0;
} // End of main