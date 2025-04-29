#define BOOST_TEST_MODULE QueueTests
#include <boost/test/included/unit_test.hpp>
#include "../Data_Structures/queue.h"
#include <iostream>

using namespace std;

// Test that a newly created queue is empty
BOOST_AUTO_TEST_CASE(QueueInitiallyEmpty) {
    Queue q;
    cout << "Testing if new queue is initially empty." << endl;
    BOOST_TEST(q.isEmpty());
}

// Test enqueueing one element
BOOST_AUTO_TEST_CASE(EnqueueOneElement) {
    Queue q;
    q.enqueue(5);
    cout << "Enqueued 5." << endl;
    BOOST_TEST(!q.isEmpty());
    BOOST_TEST(q.front->data == 5);
    BOOST_TEST(q.rear->data == 5);
}

// Test enqueueing multiple elements (order preservation)
BOOST_AUTO_TEST_CASE(EnqueueMultipleElements) {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    cout << "Enqueued 10, 20, 30." << endl;
    BOOST_TEST(q.front->data == 10);
    BOOST_TEST(q.rear->data == 30);
}

// Test dequeue removes elements in FIFO order
BOOST_AUTO_TEST_CASE(DequeueFIFOOrder) {
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    cout << "Dequeuing in FIFO order." << endl;
    BOOST_TEST(q.front->data == 1);

    q.dequeue();
    cout << "Dequeued once." << endl;
    BOOST_TEST(q.front->data == 2);

    q.dequeue();
    cout << "Dequeued twice." << endl;
    BOOST_TEST(q.front->data == 3);

    q.dequeue();
    cout << "Dequeued third time." << endl;
    BOOST_TEST(q.isEmpty());
}

// Test dequeue on empty queue does not crash
BOOST_AUTO_TEST_CASE(DequeueEmptyQueueSafe) {
    Queue q;
    cout << "Attempting to dequeue from empty queue." << endl;
    q.dequeue();  // Should print warning, not crash
    BOOST_TEST(q.isEmpty());
}

// Test Top function on non-empty and empty queue
BOOST_AUTO_TEST_CASE(TopFunctionTest) {
    Queue q;
    cout << "Testing Top() with one element." << endl;
    q.enqueue(99);
    q.Top();  // Should print 99
    BOOST_TEST(q.front->data == 99);

    cout << "Testing Top() on empty queue." << endl;
    q.dequeue(); // Now it's empty
    q.Top();     // Should print warning
    BOOST_TEST(q.isEmpty());
}

// Test Display output manually (for visual debugging)
BOOST_AUTO_TEST_CASE(DisplayQueueContents) {
    Queue q;
    q.enqueue(100);
    q.enqueue(200);
    cout << "Displaying queue contents:" << endl;
    q.Display();  // Should print 100 and 200
    BOOST_TEST(q.front->data == 100);
    BOOST_TEST(q.rear->data == 200);
}
