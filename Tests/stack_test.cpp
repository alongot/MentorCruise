#define BOOST_TEST_MODULE StackTests
#include <boost/test/included/unit_test.hpp>
#include "../Data_Structures/stack.h"
#include <iostream>

using namespace std;

// Test if a new stack is empty
BOOST_AUTO_TEST_CASE(StackIsInitiallyEmpty) {
    BOOST_TEST_MESSAGE("Testing: New stack should be empty.");
    Stack s;
    std::cout << "Is empty? " << std::boolalpha << s.IsEmpty() << std::endl;
    BOOST_TEST(s.IsEmpty());
}

// Test if you can pop on empty stack
BOOST_AUTO_TEST_CASE(StackIsInitiallyEmpty) {
    Stack s;
    BOOST_TEST_MESSAGE("Popping on empty stack");
    s.Pop(); 
}

// Test push of a single element
BOOST_AUTO_TEST_CASE(PushOneElement) {
    BOOST_TEST_MESSAGE("Testing: Push one element and peek.");
    Stack s;
    s.Push(42);
    std::cout << "Pushed 42. Peek: " << s.Peek() << std::endl;
    BOOST_TEST(!s.IsEmpty());
    BOOST_TEST(s.Peek() == 42);
}

// Test push of multiple elements
BOOST_AUTO_TEST_CASE(PushMultipleElements) {
    BOOST_TEST_MESSAGE("Testing: Push multiple elements.");
    Stack s;
    s.Push(10);
    s.Push(20);
    std::cout << "Pushed 10 then 20. Peek: " << s.Peek() << std::endl;
    BOOST_TEST(s.Peek() == 20);
}

// Test pop removes top
BOOST_AUTO_TEST_CASE(PopRemovesTop) {
    BOOST_TEST_MESSAGE("Testing: Pop removes the top element.");
    Stack s;
    s.Push(1);
    s.Push(2);
    std::cout << "Top before pop: " << s.Peek() << std::endl;
    s.Pop();
    std::cout << "Top after pop: " << s.Peek() << std::endl;
    BOOST_TEST(s.Peek() == 1);
}

// Test pop on empty stack (check that it does not crash)
BOOST_AUTO_TEST_CASE(PopOnEmptyStack) {
    BOOST_TEST_MESSAGE("Testing: Pop on empty stack should not crash.");
    Stack s;
    std::cout << "Attempting pop on empty stack..." << std::endl;
    s.Pop(); // Should not crash
    BOOST_TEST(s.IsEmpty());
}

// Test peek on empty stack
BOOST_AUTO_TEST_CASE(PeekOnEmptyStackReturnsMinusOne) {
    BOOST_TEST_MESSAGE("Testing: Peek on empty stack should return -1.");
    Stack s;
    int val = s.Peek();
    std::cout << "Peeked on empty stack: " << val << std::endl;
    BOOST_TEST(val == -1); // your impl returns -1 on empty
}

