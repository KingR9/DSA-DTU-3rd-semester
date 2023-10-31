#include <iostream>
#include <stack>
using namespace std;

class MinStack {
private:
    stack<int> mainStack;
    stack<int> minStack;

public:
    // Push an element onto the stack
    void push(int value) {
        mainStack.push(value);

        if (minStack.empty() || value <= minStack.top()) {
            minStack.push(value);
        }
    }

    // Pop the top element from the stack
    void pop() {
        if (mainStack.empty()) {
            cout << "Stack is empty. Cannot pop." << endl;
            return;
        }

        if (mainStack.top() == minStack.top()) {
            minStack.pop();
        }

        mainStack.pop();
    }

    // Get the top element of the stack
    int top() {
        if (mainStack.empty()) {
            cout << "Stack is empty. No top element." << endl;
            return -1; 
        }
        return mainStack.top();
    }

    // Get the minimum element in the stack
    int getMin() {
        if (minStack.empty()) {
            cout << "Stack is empty. No minimum element." << endl;
            return -1; 
        }
        return minStack.top();
    }
};

int main() {
    MinStack stack;

    stack.push(3);
    stack.push(5);
    stack.push(2);
    stack.push(1);

    cout << "Minimum element in the stack: " << stack.getMin() << endl;

    stack.pop();
    cout << "Minimum element after pop: " << stack.getMin() << endl;

    stack.pop();
    cout << "Minimum element after another pop: " << stack.getMin() << endl;

    return 0;
}