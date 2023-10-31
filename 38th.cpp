#include<iostream>
#include<stack>
using namespace std;

class Queue {
    stack<int> s1, s2;

public:
    void enQueue(int x) {
        while(!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while(!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }

    int deQueue() {
        if(s1.empty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        int x = s1.top();
        s1.pop();
        return x;
    }

    bool isEmpty() {
        return s1.empty();
    }
};

int main() {
    Queue q;
    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);

    cout << q.deQueue() << endl;
    cout << q.deQueue() << endl;
    cout << q.deQueue() << endl;
    cout << q.deQueue() << endl;

    return 0;
}