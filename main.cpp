#include <iostream>
#include "stack.h"
#include <array>
#include "queue.h"

using namespace std;

int main() {
    Queue MyQueue;
    MyQueue.enqueue(11);
    MyQueue.enqueue(12);

    MyQueue.Display();
    MyQueue.Top();

    MyQueue.dequeue();
    MyQueue.Top();

    Stack MyStack;
    MyStack.push(10);
    MyStack.push(20);   
    MyStack.push(30);

    if (MyStack.isEmpty()){
        cout << "Stack is empty" << endl;
    } else {
        cout << "Top element:" << MyStack.peek() << endl;
    }

    MyStack.pop();
    cout << "Top element after pop:" << MyStack.peek() << endl;


    return 0;
}