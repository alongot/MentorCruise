#include <iostream>
#include "stack.h"
#include <array>

using namespace std;

int main() {

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