#define BOOST_TEST_MODULE StackTests
#include <boost/test/included/unit_test.hpp>
#include "../Data_Structures/stack.h"
#include <iostream>

// Test if a new stack is empty
BOOST_AUTO_TEST_CASE(StackIsInitiallyEmpty) {
    BOOST_TEST_MESSAGE("Testing: New stack should be empty.");
    Stack s;
    std::cout << "Is empty? " << std::boolalpha << s.isEmpty() << std::endl;
    BOOST_TEST(s.isEmpty());
}

// Test push of a single element
BOOST_AUTO_TEST_CASE(PushOneElement) {
    BOOST_TEST_MESSAGE("Testing: Push one element and peek.");
    Stack s;
    s.push(42);
    std::cout << "Pushed 42. Peek: " << s.peek() << std::endl;
    BOOST_TEST(!s.isEmpty());
    BOOST_TEST(s.peek() == 42);
}

// Test push of multiple elements
BOOST_AUTO_TEST_CASE(PushMultipleElements) {
    BOOST_TEST_MESSAGE("Testing: Push multiple elements.");
    Stack s;
    s.push(10);
    s.push(20);
    std::cout << "Pushed 10 then 20. Peek: " << s.peek() << std::endl;
    BOOST_TEST(s.peek() == 20);
}

// Test pop removes top
BOOST_AUTO_TEST_CASE(PopRemovesTop) {
    BOOST_TEST_MESSAGE("Testing: Pop removes the top element.");
    Stack s;
    s.push(1);
    s.push(2);
    std::cout << "Top before pop: " << s.peek() << std::endl;
    s.pop();
    std::cout << "Top after pop: " << s.peek() << std::endl;
    BOOST_TEST(s.peek() == 1);
}

// Test pop on empty stack (check that it does not crash)
BOOST_AUTO_TEST_CASE(PopOnEmptyStack) {
    BOOST_TEST_MESSAGE("Testing: Pop on empty stack should not crash.");
    Stack s;
    std::cout << "Attempting pop on empty stack..." << std::endl;
    s.pop(); // Should not crash
    BOOST_TEST(s.isEmpty());
}

// Test peek on empty stack
BOOST_AUTO_TEST_CASE(PeekOnEmptyStackReturnsMinusOne) {
    BOOST_TEST_MESSAGE("Testing: Peek on empty stack should return -1.");
    Stack s;
    int val = s.peek();
    std::cout << "Peeked on empty stack: " << val << std::endl;
    BOOST_TEST(val == -1); // your impl returns -1 on empty
}

