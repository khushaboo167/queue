#include<iostream>
#include<queue>
#include<stack>
using namespace std;

void reverse(queue<int>& q) {
    stack<int> st;
    while (!q.empty()) {
        st.push(q.front());
        q.pop();
    }
    while (!st.empty()) {
        q.push(st.top());
        st.pop();
    }
}

void display(queue<int>& q) {
    int n = q.size();
    for (int i = 0; i < n; i++) {
        int x = q.front();
        cout << x << " ";
        q.pop();
        q.push(x);
    }
    cout << endl;
}

int main() {
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);

    
    cout << "Front element: " << q.front() << endl;
    cout << "Back element: " << q.back() << endl;
    cout << "Queue size: " << q.size() << endl;

    cout << "Original queue: ";
    display(q);

    reverse(q);

    cout << "Reversed queue: ";
    display(q);

    return 0;
}
