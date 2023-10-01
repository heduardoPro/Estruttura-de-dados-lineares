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

    void push(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
        }
        else {
            Node* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
    }

void remove_elementos_repetidos() {
    if (head == nullptr || head->next == nullptr)
        return;

    Node* current = head;

    while (current != nullptr) {
        Node* runner = current;

        while (runner->next != nullptr) {
            if (runner->next->data == current->data) {
                Node* duplicate = runner->next;
                runner->next = runner->next->next;
                delete duplicate;
            } else {
                runner = runner->next;
            }
        }

        current = current->next;
    }
}


    void inverte_lista(){
        Node* aux = nullptr;
        Node* nextNode = nullptr;
        Node* current = head;
        
        while (current != nullptr)
        {
            nextNode = current->next;
            current->next = aux;
            aux = current;
            current = nextNode;

        }
        head = aux;
        
    }

};


int main() {
    LinkedList minhaLista;

    minhaLista.push(1);
    minhaLista.push(2);
    minhaLista.push(3);
    minhaLista.push(3);
    minhaLista.push(3);

    cout << "Lista original" << endl;
    minhaLista.display();

    cout << "\n\nLista com a remocao de itens duplicados" << endl;
    minhaLista.remove_elementos_repetidos();
    minhaLista.display();  

    cout << "\n\nLista INVERTIDA" << endl;
    minhaLista.inverte_lista();
    minhaLista.display();
    
    return 0;
}