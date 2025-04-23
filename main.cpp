#include <iostream>
#include <stack>
#include "stack.cpp"

using namespace std;

int main() {

    MyStack stack;
    stack.push(1);
    stack.push(2);

    cout << stack.peek() << endl;

    return 0;
}