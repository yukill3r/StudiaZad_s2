#include <iostream>

using namespace std;

class Node {
public:
    Node(int data);
    ~Node();
    int data;
    Node* next;
};

Node::Node(int data) {
    this->data = data;
    this->next = nullptr;
}

Node::~Node() {
}

class List {
    public:
    List() { head = nullptr; }
    ~List();
    void push_front(int data);
    void pop_front();
    void printList();
    int size();
private:
    Node* head;
    int _size = 0;
};

List::~List(){
    while(head != nullptr){
        Node *tmp1 = head;
        head = tmp1->next;
        delete tmp1;
    }
}

void List::push_front(int data) {
    Node* newNode = new Node(data);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node* temp = head;
    newNode->next = temp;
    head = newNode;
    this->_size++;
}

void List::pop_front() {
    if (head == nullptr){
        return;
    }
    Node *tmp1 = head;
    head = tmp1->next;
    delete tmp1;
    return;
}

int List::size() {
    return this->_size;
};

void List::printList() {
    Node* temp = head; 
    if (head == nullptr) {
        cout << "List empty" << endl;
        return;
    }
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main() {
    List list;
    for (int i = 0; i <= 5; i++) {
        list.push_front(i);
        //cout << "pushed " << i << ", size: " << list.size() << endl;
    }
    cout << endl;
    cout << "Elements of the list are: ";
    list.printList();
    cout << endl;
    list.pop_front();
    cout << "Elements of the list are: ";
    list.printList();
    cout << endl;
}