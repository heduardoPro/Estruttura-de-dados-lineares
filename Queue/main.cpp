#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    void insert(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

};

class Stack {
private:
    Node* top;

public:
    Stack() : top(nullptr) {}

    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
    }

    int pop() {
        if (isEmpty()) {
            cerr << "A pilha est vazia." << endl;
            return -1; // Valor de erro
        }

        int value = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return value;
    }

    bool isEmpty() {
        return top == nullptr;
    }
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    int dequeue() {
        if (isEmpty()) {
            cerr << "A fila esta vazia." << endl;
            return -1; // Valor de erro
        }

        int value = front->data;
        Node* temp = front;
        front = front->next;
        delete temp;
        return value;
    }

    bool isEmpty() {
        return front == nullptr;
    }
};

int main() {

    LinkedList list;
    Stack stack;
    Queue queue;

    while (true) {
        cout << "Escolha uma operacao:" << endl;
        cout << "1. Inserir na lista encadeada" << endl;
        cout << "2. Empilhar uma pilha" << endl;
        cout << "3. Enfileirar uma fila" << endl;
        cout << "4. Mostrar lista encadeada" << endl;
        cout << "5. Desempilhar da pilha" << endl;
        cout << "6. Desenfileirar da fila" << endl;
        cout << "7. Sair" << endl;

        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "\nDigite um valor para inserir na lista encadeada: ";
                int value;
                cin >> value;
                list.insert(value);
                break;
            case 2:
                cout << "\nDigite um valor para empilhar na pilha: ";
                cin >> value;
                stack.push(value);
                break;
            case 3:
                cout << "\nDigite um valor para enfileirar na fila: ";
                cin >> value;
                queue.enqueue(value);
                break;
            case 4:
                cout << "\nLista Encadeada: ";
                list.display();
                break;
            case 5:
                if (!stack.isEmpty()) {
                    cout << "\nValor desempilhado: " << stack.pop() << endl;
                } else {
                    cout << "\nA pilha esta vazia." << endl;
                }
                break;
            case 6:
                if (!queue.isEmpty()) {
                    cout << "\nValor desenfileirado: " << queue.dequeue() << endl;
                } else {
                    cout << "\nA fila esta vazia." << endl;
                }
                break;
            case 7:
                cout << "\nEncerrando o programa." << endl;
                return 0;
            default:
                cout << "\nEscolha invalida. Tente novamente." << endl;
        }
    }

    return 0;
}
