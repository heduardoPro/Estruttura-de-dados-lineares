#include <iostream>

using namespace std;

class Node {
public:

    int data;
    Node* next;

    Node(int data) : data(data), next(nullptr) {}

};

class Queue {
private:
    Node* first;
    Node* last; 
    int size;

public:

    Queue() {
        first = nullptr;
        last = nullptr;
        size = 0;
    }

    bool empty() {
        return first == nullptr;
    }

    int getSize() {
        return size;
    }

    void push(int element) {
        Node*  newnode = new Node(element);
        if (empty()) {
            first = last = newnode;
        }
        else {
            last->next = newnode;
            last = newnode;
        }
        size = size + 1;
    }
    void pop() {
        if(empty()) {
            cout << "A fila está vazia." << endl;
        }
        else {
            Node* aux = first;
            first = first->next;
            delete aux;
        }
        size = size - 1;
    }

    void front() {
        if(empty()) {
            cout << "A fila está vazia." << endl;
        }
        else {
            cout << first->data << endl;
        }
    }

    void back() {
        if(empty()) {
            cout << "A fila está vazia." << endl;
        }
        else {
            cout << last->data << endl;
        }
    }

    void display() {
        if(empty()) {
            cout << "A fila está vazia." << endl;
        }
        else {
            Node* front = first;
            while (front != nullptr)
            {
                cout << front->data << " ";
                front = front->next;
            }
            cout << endl;
        }
    }

    ~Queue() {
    
    }

};
int main() {
    

    Queue queue;

    queue.empty();
    queue.push(1);
    queue.push(1);
    queue.push(3);

    int size = queue.getSize();
    cout << "Queue size: " << size << endl;

    cout << "\nQueue elements:" << endl;
    queue.display();
    
    cout << "\nFirst in line:" << endl;
    queue.front();

    cout << "\nLast in line:" << endl;
    queue.back();

    queue.pop();

    queue.display();

    queue.pop();
    queue.pop();
    
    return 0;
}