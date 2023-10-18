#include <bits/stdc++.h>
using namespace std;

// Taking input of marks in 2D array and calculating total of every student and average of every subject
int main()
{
    int marks[5][5];
    int total[5] = {0};
    float average[5] = {0};

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin >> marks[i][j];
            total[i] += marks[i][j];
        }
    }

    for (int i = 0; i < 5; i++)
    {
        cout << "Total marks of student " << i + 1 << ": " << total[i] << endl;
    }

    for (int j = 0; j < 5; j++)
    {
        for (int i = 0; i < 5; i++)
        {
            average[j] += marks[i][j];
        }
        average[j] /= 5;
    }

    for (int j = 0; j < 5; j++)
    {
        cout << "Average marks of subject " << j + 1 << ": " << average[j] << endl;
    }

    return 0;
}

// palindrome
bool palindrome(string s)
{
    int i = 0, j = s.size();
    while (i <= j)
    {
        if (s[i] != s[j])
            return false;
        i++;
        j--;
    }
    return true;
}
int main()
{
    string str;
    cout << "Enter string: ";
    getline(cin, str);

    if (palindrome(str))
    {
        cout << "String is Palindrome";
    }
    else
    {
        cout << "Not palindrome";
    }

    return 0;
}

// linear and binary search
int linearSearch(int arr[], int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
            return i;
    }
    return -1;
}

// Function for binary search
int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l)
    {
        int mid = l + (r - l) / 2;

        if (arr[mid] == x)
            return mid;

        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);

        return binarySearch(arr, mid + 1, r, x);
    }

    return -1;
}
// Implement singly link list insertion deletion at start and end
class Node
{
public:
    int val;
    Node *next;
    Node(int x)
    {
        val = x;
        next = NULL;
    }
};
void insertAtStart(Node *&head, int x)
{
    Node *ne = new Node(x);
    if (head == NULL)
    {
        head = ne;
        return;
    }
    ne->next = head;
    head = ne;
}
void insertAtEnd(Node *&head, int x)
{
    Node *ne = new Node(x);
    if (head == NULL)
    {
        head = ne;
        return;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = ne;
    return;
}

// Find middle element of link list in o(n) time
Node *Middle(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    Node *slow = head;
    Node *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}

// Implement single and doubly link list along with insertion deletion
class Node
{
public:
    int val;
    Node *prev;
    Node *next;
    Node(int data)
    {
        val = data;
        prev = NULL;
        next = NULL;
    }
};
class DoublyLinkedList
{
public:
    Node *head;
    Node *tail;
    DoublyLinkedList()
    {
        head = NULL;
        tail = NULL;
    }
    void insertAtStart(int val)
    {
        Node *new_node = new Node(val);
        if (head == NULL)
        {
            head = new_node;
            tail = new_node;
            return;
        }
        new_node->next = head;
        head->prev = new_node;
        head = new_node;
    }
    void display()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->val << " ";
            temp = temp->next;
        }
    }
    void inserAtTail(int val)
    {
        Node *new_node = new Node(val);
        if (head == NULL)
        {
            head = new_node;
            tail = new_node;
            return;
        }
        tail->next = new_node;
        new_node->prev = tail;
        tail = new_node;
    }

    void insertAtPosition(int val, int k)
    {
        // assuming k is less than or equal to length of dll
        Node *temp = head;
        int count = 1;
        while (count < (k - 1))
        {
            temp = temp->next;
            count++;
        }
        // temp will be pointing to the node at (k-1)th position
        Node *new_node = new Node(val);
        new_node->next = temp->next;
        temp->next = new_node;
        new_node->prev = temp;
        new_node->next->prev = new_node;
        return;
    }
    void deleteAtStart()
    {
        if (head == NULL)
        {
            return;
        }
        Node *temp = head;
        head = head->next;
        if (head == NULL) // if dll has only one node
        {
            tail = NULL;
        }
        else
        {
            head->prev = NULL;
        }
        free(temp);
        return;
    }
    void deleteAtEnd()
    {
        if (head == NULL)
        {
            return;
        }
        Node *temp = tail;
        tail = tail->prev;
        if (tail == NULL)
        {
            head = NULL;
        }
        else
        {
            tail->next = NULL;
        }
        free(temp);
        return;
    }
    void deleteAtPosition(int k)
    {
        // assuming k is less than or equal to length of dll
        Node *temp = head;
        int counter = 1;
        while (counter < k)
        {
            temp = temp->next;
            counter++;
        }
        // mow temp is pointing to node at kth position
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        free(temp);
        return;
    }
};

// Merge two sorted linked lists
Node *Helper(Node *a, Node *b)
{
    if (a == NULL)
        return b;
    if (b == NULL)
        return a;
    if (a->val <= b->val)
    {
        a->next = Helper(a->next, b);
        return a;
    }
    else
    {
        b->next = Helper(a, b->next);
        return b;
    }
}

// Reverse a link list
Node *Reverse(Node *&head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *prev = NULL;
    Node *curr = head;
    while (curr != NULL)
    {
        Node *nex = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nex;
    }
    return prev;
}

// Check if a link list is palindrome or not
bool isPalindrome(ListNode *head)
{
    ListNode *temp = new ListNode(head->val);
    ListNode *temp2 = head->next;
    ListNode *orgh = temp;
    while (temp2 != NULL)
    {
        temp->next = new ListNode(temp2->val);
        temp2 = temp2->next;
        temp = temp->next;
    }
    ListNode *prev = NULL;
    ListNode *curr = head;
    while (curr != NULL)
    {
        ListNode *nex = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nex;
    }
    ListNode *newHead = prev;
    cout << endl;
    while (temp != NULL)
    {
        cout << temp->val;
        temp = temp->next;
    }
    cout << endl;
    while (orgh != NULL)
    {

        if (orgh->val != newHead->val)
        {
            return false;
        }
        orgh = orgh->next;
        newHead = newHead->next;
    }
    return true;
}

// Program for Nth node from the end of a Linked List
Node *KfromEnd(Node *head, int N)
{
    Node *slow = head;
    Node *fast = head;
    while (N--)
    {
        fast = fast->next;
    }
    if (fast == NULL)
        return head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }
    return slow->next;
}

// Stack queues implementation using array and link list

class Node
{
public:
    int val;
    Node *next;
    Node(int data)
    {
        this->val = data;
        this->next = NULL;
    }
};
class Stack
{
    Node *head;
    int capacity;
    int currSize;
    Stack(int c)
    {
        this->capacity = c;
        this->currSize = 0;
        head = NULL;
    }
    bool isEmpty()
    {
        return this->head == NULL;
    }
    bool isFull()
    {
        return this->currSize == this->capacity;
    }
    void push(int data)
    {
        if (this->capacity == this->currSize)
        {
            cout << "Overflow";
            return;
        }
        Node *new_node = new Node(data);
        new_node->next = this->head;
        this->head = new_node;
        this->currSize++;
    }
    int pop()
    {
        if (this->currSize == NULL)
        {
            cout << "Underflow";
            return;
        }
        Node *new_head = this->head->next;
        this->head->next = NULL;
        Node *tobeRemoved = this->head;
        int result = tobeRemoved->val;
        delete tobeRemoved;
        this->head = new_head;
        return result;
    }
    int getTop()
    {
        if (this->head == NULL)
        {
            cout << "Underflow";
            return;
        }
        return this->head->val;
    }
    int size()
    {
        return this->currSize;
    }
};

class Stack
{
    int capacity;
    int *arr;
    int top;

public:
    Stack(int c)
    {
        this->capacity = c;
        arr = new int[c];
        this->top = -1;
    }
    void push(int data)
    {
        if (this->top == this->capacity - 1)
        {
            cout << "Overflow" << endl;
            return;
        }
        this->top++;
        this->arr[this->top] = data;
    }
    int pop()
    {
        if (this->top == -1)
        {
            cout << "underflow";
            return INT_MIN;
        }
        this->top--;
    }
    int gettop()
    {
        if (this->top == -1)
        {
            cout << "Underflow";
            return INT_MIN;
        }
        return this->arr[this->top];
    }
    bool isEmpty()
    {
        return this->top == -1;
    }
    int size()
    {
        return this->top + 1;
    }
    bool isFull()
    {
        return this->top == this->capacity - 1;
    }
};

class Node
{
public:
    int val;
    Node *next;
    Node(int data)
    {
        this->val = data;
        this->next = NULL;
    }
};
class Queue
{
    Node *head;
    Node *tail;
    int size = 0;

public:
    Queue()
    {
        this->head = NULL;
        this->tail = NULL;
    }
    void enqueue(int data)
    {
        Node *newNode = new Node(data);
        if (this->head == NULL)
        {
            this->head = newNode;
            this->tail = newNode;
        }
        else
        {
            this->tail->next = newNode;
            this->tail = newNode;
        }
        this->size++;
    }
    void dequeue()
    {
        if (this->head == NULL)
        {
            return;
        }
        else
        {
            Node *oldHead = this->head;
            Node *newHead = this->head->next;
            this->head = newHead;
            if (this->head == NULL)
            {
                this->tail = NULL;
            }
            oldHead->next = NULL;
            delete oldHead;
            this->size--;
        }
    }
    int getSize()
    {
        return this->size;
    }
    bool isEmpty()
    {
        return this->head == NULL;
    }
    int front()
    {
        if (this->head == NULL)
        {
            return -1;
        }
        return this->head->val;
    }
};

class Queue
{
    int front;
    int back;
    vector<int> v;

public:
    Queue()
    {
        this->front = -1;
        this->back = -1;
    }
    void enqueue(int data)
    {
        v.push_back(data);
        this->back++;
        if (this->back == 0)
        {
            this->front++;
        }
    }
    void dequeue()
    {
        if (this->front == this->back)
        {
            this->front = -1;
            this->back = -1;
            this->v.clear();
        }
        else
        {
            this->front++;
        }
    }
    int front()
    {
        if (this->front == -1)
        {
            return -1;
        }
        return v[this->front];
    }
    bool isEmpty()
    {
        return this->front == -1;
    }
};

// Postfix
int calc(int v1, int v2, char op)
{
    if (op == '^')
    {
        return pow(v1, v2);
    }
    else if (op == '+')
    {
        return v1 + v2;
    }
    else if (op == '-')
    {
        return v1 - v2;
    }
    else if (op == '*')
    {
        return v1 * v2;
    }
    else if (op == '/')
    {
        return v1 / v2;
    }
}
int evaluate(string str)
{
    stack<int> st;
    for (int i = 0; i < str.size(); i++)
    {
        char ch = str[i];
        if (isdigit(ch))
        {
            st.push(ch - '0');
            //  subtracting '0' to get original value of the number
        }
        else
        {
            int v2 = st.top();
            st.pop();
            int v1 = st.top();
            st.pop();
            st.push(calc(v1, v2, ch));
        }
    }
    return st.top();
}
int main()
{
    string str = "231*+9-";
    cout << evaluate(str);
    return 0;
}

// Prefix
int calc(int v1, int v2, char op)
{
    if (op == '^')
    {
        return pow(v1, v2);
    }
    else if (op == '+')
    {
        return v1 + v2;
    }
    else if (op == '-')
    {
        return v1 - v2;
    }
    else if (op == '*')
    {
        return v1 * v2;
    }
    else if (op == '/')
    {
        return v1 / v2;
    }
}
int evaluate(string str)
{
    stack<int> st;
    for (int i = str.size() - 1; i >= 0; i--)
    {
        char ch = str[i];
        if (isdigit(ch))
        {
            st.push(ch - '0');
            //  subtracting '0' to get original value of the number
        }
        else
        {
            int v2 = st.top();
            st.pop();
            int v1 = st.top();
            st.pop();
            st.push(calc(v1, v2, ch));
        }
    }
    return st.top();
}
int main()
{
    string str = "-9+*132";
    cout << evaluate(str);
    return 0;
}

//  NSE, NGE
vector<int>
nge(vector<int> &arr)
{
    int n = arr.size();
    vector<int> output(n, -1);
    stack<int> st;
    // indexes
    st.push(0);
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && arr[i] > arr[st.top()])
        {
            output[st.top()] = arr[i];
            st.pop();
        }
        st.push();
    }
    // for safety check
    while (not st.top())
    {
        output[st.top()] = -1;
        st.pop();
    }
    return output;
}
// next smaller element
vector<int> nse(vector<int> &arr)
{
    int n = arr.size();
    vector<int> output(n, -1);
    stack<int> st;
    // indexes
    st.push(0);
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && arr[i] < arr[st.top()])
        {
            output[st.top()] = arr[i];
            st.pop();
        }
        st.push();
    }
    // for safety check
    while (not st.top())
    {
        output[st.top()] = -1;
        st.pop();
    }
    return output;
}

// Implement Queue using Stacks
class MyQueue
{
    stack<int> st1;
    stack<int> st2;

public:
    void push(int x)
    {
        st1.push(x);
    }

    int pop()
    {
        while (st1.size() != 1)
        {
            st2.push(st1.top());
            st1.pop();
        }
        int ans = st1.top();
        st1.pop();
        while (!st2.empty())
        {
            st1.push(st2.top());
            st2.pop();
        }
        return ans;
    }

    int peek()
    {
        while (st1.size() != 1)
        {
            st2.push(st1.top());
            st1.pop();
        }
        int ans = st1.top();
        // st1.pop();
        while (!st2.empty())
        {
            st1.push(st2.top());
            st2.pop();
        }
        return ans;
    }

    bool empty()
    {
        return st1.empty();
    }
};

// Minimum element in stack in constant space
int ME(stack<int> st)
{
    int ans = INT_MAX;
    while (!st.empty())
    {
        ans = min(ans, st.top());
        st.pop();
    }
    return ans;
}