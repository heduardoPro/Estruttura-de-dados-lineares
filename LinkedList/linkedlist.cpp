#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class linkedlist {
private:
   Node* head;

public:
    linkedlist() : head(nullptr) {}
    
    void push(int element) {
        Node* newNode = new Node(element);
        if (!head) {
            head = newNode;
        }
        else {
            Node* current = head;
            while (current->next)
            {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void display() {
        Node* current = head;
        while (current)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};


int main() {
    
    linkedlist ListaEncadeada;

    ListaEncadeada.push(10);
    ListaEncadeada.push(20);
    ListaEncadeada.push(30);

    ListaEncadeada.display();   

    return 0;
}