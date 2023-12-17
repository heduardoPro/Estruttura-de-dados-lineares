#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
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
            cerr << "A pilha esta vazia." << endl;
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

int main() {
    int n;
    cout << "Digite a quantidade de numeros a serem lidos: ";
    cin >> n;

    Stack oddStack;  // Pilha para números ímpares
    Stack evenStack; // Pilha para números pares

    cout << "Digite os numeros inteiros e positivos:" << endl;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;

        if (num % 2 == 0) {
            evenStack.push(num);
        } else {
            oddStack.push(num);
        }
    }

    cout << "Numeros impares na ordem inversa: ";
    while (!oddStack.isEmpty()) {
        cout << oddStack.pop() << " ";
    }
    cout << endl;

    cout << "Numeros pares na ordem inversa: ";
    while (!evenStack.isEmpty()) {
        cout << evenStack.pop() << " ";
    }
    cout << endl;

    return 0;
}
