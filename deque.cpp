#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* prev;
    Node(int val) {
        this->val = val;
        this->next = nullptr;
        this->prev = nullptr;
    }
};
class Deque { // user-defined data structure
public:
    Node* head;
    Node* tail;
    int size;
    Deque() {
        head = tail = nullptr;
        size = 0;
    }

    // Insertion at tail position
    void pushBack(int val) {
        Node* temp = new Node(val);
        if (size == 0) head = tail = temp;
        else {
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
        size++;
    }

    // Insertion at head position
    void pushFront(int val) {
        Node* temp = new Node(val);
        if (size == 0) head = tail = temp;
        else {
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
        size++;
    }

        void popFront() {
        if(size==0) return;
        head=head->next;
        if(head) head->prev=NULL;
        if(head==NULL) tail=NULL;
        size--;
    }

    void popBack() {
        if (size == 0) return;
        else if(size == 1) {
            popFront();
            return;
        }
        Node* temp=tail->prev;
        temp->next=NULL;
        tail=temp;
        size--;
    }

    int front() {
        if (size == 0) return -1;
        return head->val;
    }

    int back() {
        if (size == 0) return -1;
        return tail->val;
    }

    // Display
    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Deque dq;
    dq.pushBack(10);
    dq.pushBack(20);
    dq.pushBack(30);
    dq.pushBack(40);
    dq.display();
    dq.popBack();
    dq.display();
    dq.popFront();
    dq.display();
    dq.pushFront(50);
    dq.display();
    cout<<dq.front()<<endl;
    cout<<dq.front()<<endl;
}
