#include <iostream>
#include "stack.h"

using namespace std;

int main() {

    Stack MyStack;


    if (MyStack.isEmpty()){
        cout << "Stack is empty" << endl;
    } else {
        cout << "Top element:" << MyStack.peek() << endl;
    }

    return 0;
}