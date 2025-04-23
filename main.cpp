#include <iostream>
#include <stack>
#include "stack.cpp"

using namespace std;

int main() {

    MyStack stack;


    if (stack.isEmpty()){
        cout << "Stack is empty" << endl;
    } else {
        cout << "Top element:" << stack.peek() << endl;
    }

    return 0;
}