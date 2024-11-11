#include <iostream>
using namespace std;

#define MAX 1000 // Maximum size of the queue

class Queue
{
    int front, rear;

public:
    int a[MAX]; // Queue array

    Queue() { front = rear = -1; } // Constructor to initialize front and rear

    // Function to enqueue an element into the queue
    bool enqueue(int x)
    {
        if (rear == MAX - 1)
        {
            cout << "Queue Overflow\n";
            return false;
        }
        else
        {
            if (front == -1)
                front = 0; // If inserting first element
            a[++rear] = x;
            cout << x << " enqueued into queue\n";
            return true;
        }
    }

    // Function to dequeue an element from the queue
    int dequeue()
    {
        if (front == -1 || front > rear)
        {
            cout << "Queue Underflow\n";
            return 0;
        }
        else
        {
            int x = a[front++];
            return x;
        }
    }

    // Function to check the front element of the queue
    int peek()
    {
        if (front == -1 || front > rear)
        {
            cout << "Queue is Empty\n";
            return 0;
        }
        else
        {
            int x = a[front];
            return x;
        }
    }

    // Function to check if the queue is empty
    bool isEmpty()
    {
        return (front == -1 || front > rear);
    }
};

// Main program
int main()
{
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    cout << q.dequeue() << " dequeued from queue\n";
    cout << "Front element is: " << q.peek() << endl;
    cout << "Is the queue empty? " << (q.isEmpty() ? "Yes" : "No") << endl;
    return 0;
}
