#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node() : data(), next(nullptr) {}
};

class Stack {
private:
    Node* top;
    int size;

public:
    Stack() {
        top = nullptr;
        size = 0;
    }

    void push(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = top;
        top = newNode;

        size = size + 1;
    }
    void pop() {
        if(empty()) {
            cout << "A pilha esta vazia." << endl;
            return;
        }
        Node* aux = top;
        top = top->next;
        delete aux;

    }

    bool empty() {
        return top == nullptr; 
    }

    int peek() {
        return top->data;
    }

    void display() {
        if(empty()) {
            cout << "A pilha esta vazia. " << endl; 
        }
        Node* current = top;
        while (current != nullptr)
        {
            cout << current->data << endl;
            current = current->next;
        }
    }

    ~Stack() {}
};

int main() {

    Stack pilha;


    pilha.push(10);
    pilha.push(20);
    pilha.push(30);

    cout << "\nTOPO" << endl;
    pilha.display();
    cout << "BASE" << endl;

    cout << "\nA pilha esta vazia: SIM = 1 NAO = 0: " << pilha.empty() << endl;

    cout << "\nElemento do topo da pilha: " << pilha.peek() << endl;

    cout << "\nRemovendo o ultimo elemento da pilha: " << pilha.peek() << endl;
    pilha.pop();

    cout << "\nApos retirar elemento do topo." << endl;
    cout << "\nTOPO" << endl;
    pilha.display();
    cout << "BASE" << endl;

    return 0;
}