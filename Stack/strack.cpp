#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) : data(data), next(nullptr) {}
};

class Stack {
private:
    Node *top;
    int size;
    int MaxSize;

public:

    Stack(int max) : top(nullptr), size(0), MaxSize(max) {}

    bool isempty() {
        return top == nullptr;
    }

    bool isfull() {
        return size == MaxSize;
    }

    void push(int element) {
        if(isfull()) {
            cout << "Erro. A pilha está cheia nao e possivel adicinar elementos a ela." << endl;
            return;
        }
        Node* newNode = new Node(element);
        newNode->next = top;
        top = newNode;

        size = size + 1;
    }

    void pop() {
        if(isempty()) {
            cout << "A pilha está vazia." << endl;
        }

        int data = top->data;
        Node* aux = top;
        top = aux->next;
        delete aux;
        size = size - 1;
    }
    
    void display() {
        if (isempty()) {
            cout << "Pilha vazia." << endl;
            return;
        }
        Node* current = top;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    ~Stack() {
        while(!isempty()) {
            pop();
        }
    }
};

int main() {

    Stack pilha(5);

    pilha.isempty();

    pilha.push(1);
    pilha.push(2);
    pilha.display();
    pilha.push(3);

    pilha.display();

    pilha.isfull();

    pilha.pop();
    pilha.display();

    return 0;
}