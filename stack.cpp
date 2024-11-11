#include <iostream>
using namespace std;

#define MAX 1000 // Maximum size of the stack

class Stack
{
    int top;

public:
    int a[MAX]; // Stack array

    Stack() { top = -1; } // Constructor to initialize top

    // Function to push an element onto the stack
    bool push(int x)
    {
        if (top >= (MAX - 1))
        {
            cout << "Stack Overflow\n";
            return false;
        }
        else
        {
            a[++top] = x;
            cout << x << " pushed into stack\n";
            return true;
        }
    }

    // Function to pop an element from the stack
    int pop()
    {
        if (top < 0)
        {
            cout << "Stack Underflow\n";
            return 0;
        }
        else
        {
            int x = a[top--];
            return x;
        }
    }

    // Function to check the top element of the stack
    int peek()
    {
        if (top < 0)
        {
            cout << "Stack is Empty\n";
            return 0;
        }
        else
        {
            int x = a[top];
            return x;
        }
    }

    // Function to check if the stack is empty
    bool isEmpty()
    {
        return (top < 0);
    }
};

// Main program
int main()
{
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << s.pop() << " popped from stack\n";
    cout << "Top element is: " << s.peek() << endl;

    if (s.isEmpty())
        cout << "Stack is empty\n";
    else
        cout << "Stack is not empty\n";

    return 0;
}
