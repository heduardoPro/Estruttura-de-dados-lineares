#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;
    
    Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};

class Deck {
private:
    Node* front; // elemento a esquerda
    Node* rear; // elemento a direita
    int count;

public:
    Deck() : front(nullptr), rear(nullptr), count(0) {}

    void insertFront(int element) {
        Node* newNode = new Node(element);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }
        count++;
    }

    void insertLast(int element) {
        Node* newNode = new Node(element);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            newNode->prev = rear;
            rear->next = newNode;
            rear = newNode;
        }
        count++;
    }

    void removeFront() {
        if (!isEmpty()) {
            Node* temp = front;
            front = front->next;
            if (front) {
                front->prev = nullptr;
            } else {
                rear = nullptr;
            }
            delete temp;
            count--;
        }
    }

    void removeLast() {
        if (!isEmpty()) {
            Node* temp = rear;
            rear = rear->prev;
            if (rear) {
                rear->next = nullptr;
            } else {
                front = nullptr;
            }
            delete temp;
            count--;
        }
    }

    int first() {
        if (!isEmpty()) {
            return front->data;
        } else {
            throw std::runtime_error("Deck is empty");
        }
    }

    int last() {
        if (!isEmpty()) {
            return rear->data;
        } else {
            throw std::runtime_error("Deck is empty");
        }
    }

    int size() {
        return count;
    }

    bool isEmpty() {
        return count == 0;
    }

    void printDeque() {
        Node* current = front;
        cout << "front << ";
        while (current) {
            cout << current->data;
            if (current->next) {
                cout << " | ";
            }
            current = current->next;
        }
        cout << " >> rear" << std::endl;
    }
};

int main() {
    Deck deque;

    for(int i = 0; i <= 20; i++) {
        deque.insertFront(i);
    }

    deque.printDeque();

    cout << "\nFirst element: " << deque.first() << endl; // 100
    cout << "Last element: " << deque.last() << endl; // 100
    cout << "Size: " << deque.size() << "\n" << endl; // 6

    deque.removeFront();
    deque.removeLast();

    cout << "First element after removal: " << deque.first() << endl;
    cout << "Last element after removal: " << deque.last() << endl;
    cout << "Size after removal: " << deque.size() << "\n" << endl;

    deque.printDeque(); // front << 20 | 2 | 1 | 3 >> rear

    deque.removeFront();
    deque.removeLast();

     deque.printDeque(); // front <<  2 | 1  >> rear

    return 0;
}
