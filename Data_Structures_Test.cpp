#define BOOST_TEST_MODULE DataStructureTests
#include <boost/test/included/unit_test.hpp>
#include "stack.h"
#include "queue.h"

BOOST_AUTO_TEST_CASE(PushPopPeekOperations) {
    Stack s;

    BOOST_TEST(s.isEmpty());
    s.push(10);
    BOOST_TEST(s.peek() == 10);
    s.push(20);
    BOOST_TEST(s.peek() == 20);
    BOOST_TEST(!s.isEmpty());
    s.pop();
    BOOST_TEST(s.peek() == 10);
    s.pop();
    BOOST_TEST(s.isEmpty());
}

BOOST_AUTO_TEST_CASE(EmptyStackOperations) {
    Stack s;

    BOOST_TEST(s.peek() == -1);  

    BOOST_TEST(s.isEmpty());
    s.pop();  

    BOOST_TEST(s.isEmpty());
}

BOOST_AUTO_TEST_CASE(QueueOperationsTest) {
    Queue q;

    BOOST_TEST(q.isEmpty());

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    BOOST_TEST(!q.isEmpty());

    // Check top of the queue
    BOOST_TEST(q.front->data == 10); 
    BOOST_TEST(q.rear->data == 30);   

    // Dequeue and check new top
    q.dequeue();
    BOOST_TEST(q.front->data == 20);

    // Dequeue again
    q.dequeue();
    BOOST_TEST(q.front->data == 30);

    // Dequeue 
    q.dequeue();
    BOOST_TEST(q.isEmpty());

    // Another dequeue should not crash
    q.dequeue();  // should just print "Queue is empty"
}

BOOST_AUTO_TEST_CASE(TopFunctionTest) {
    Queue q;
    q.enqueue(100);
    q.Top();  // prints 100

    BOOST_TEST(q.front->data == 100);
}