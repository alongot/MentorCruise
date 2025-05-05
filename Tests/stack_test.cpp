#define BOOST_TEST_MODULE StackTests
#include <boost/test/included/unit_test.hpp>
#include "../Data_Structures/stack.h"
#include <iostream>

template <typename T>
std::ostream& operator<<(std::ostream& os, const Stack<T>& stack) {
    auto top = stack.Peek();
    if (top.isValid()) {  // Check if there's a value inside the optional
        os << top.get();  // Retrieve the value using get()
    } else {
        os << "Empty";
    }
    return os;
}

using namespace std;

// Test if a new stack is empty
BOOST_AUTO_TEST_CASE(StackIsInitiallyEmpty) {
    BOOST_TEST_MESSAGE("Testing: New stack should be empty.");
    Stack<int> s;
    std::cout << "Is empty? " << std::boolalpha << s.isEmpty() << std::endl;
    BOOST_TEST(s.isEmpty());
}

// Test push of a single element
BOOST_AUTO_TEST_CASE(PushOneElement) {
    BOOST_TEST_MESSAGE("Testing: Push one element and peek.");
    Stack<int> s;
    s.Push(42);
    BOOST_TEST(!s.isEmpty());
    BOOST_TEST(s.Peek().get() == 42);  // Use get() to retrieve the value
}

// Test push of multiple elements
BOOST_AUTO_TEST_CASE(PushMultipleElements) {
    BOOST_TEST_MESSAGE("Testing: Push multiple elements.");
    Stack<int> s;
    s.Push(10);
    s.Push(20);
    BOOST_TEST(s.Peek().get() == 20);  // Use get() to retrieve the value
}

// Test pop removes top
BOOST_AUTO_TEST_CASE(PopRemovesTop) {
    BOOST_TEST_MESSAGE("Testing: Pop removes the top element.");
    Stack<int> s;
    s.Push(1);
    s.Push(2);
    s.Pop();
    BOOST_TEST(s.Peek().get() == 1);  // Use get() to retrieve the value
}

// Test pop on empty stack
BOOST_AUTO_TEST_CASE(PopOnEmptyStack) {
    BOOST_TEST_MESSAGE("Testing: Pop on empty stack should return an empty Optional.");
    Stack<int> s;
    std::cout << "Attempting pop on empty stack..." << std::endl;
    BOOST_TEST(!s.Pop().isValid());  // Ensure Pop returns an empty Optional when the stack is empty
}

// Test peek on empty stack
BOOST_AUTO_TEST_CASE(PeekOnEmptyStack) {
    BOOST_TEST_MESSAGE("Testing: Peek on empty stack should return an empty Optional.");
    Stack<int> s;
    BOOST_TEST(!s.Peek().isValid());  // Ensure Peek returns an empty Optional on empty stack
}