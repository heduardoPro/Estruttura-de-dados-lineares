/*
1. Crie duas classes denominadas n ́o e Lista. Na classe n ́o dever ́a ter dois atributos do tipo
inteiro e mais um ponteiro para o pr ́oximo n ́o. A classe Lista dever ́a ter os seguintes m ́etodos
p ́ublicos: (A lista dever ́a ser ordenada pelo primeiro atributo do n ́o)
(a) Construtor - Inicializa a classe
(b) ObterProximo - Recebe como argumento um nó e retorna o proximo
(c) ObterValor - Recebe como argumento um n ́o e retorna os valores armazenados dentro
dele
(d) AlterarNo - Recebe como argumento um n ́o e dois interios para alterar as informa ̧c ̃oes
do n ́o referenciado
(e) Tamanho - Retorna o tamanho da lista
(f) Existe - Retorna se um n ́o existe na lista
(g) mostrarALL - Retorna todos os elementos da lista
(h) Buscar - Retorna se o n ́o cont ́em na lista
(i) Inserir - Insere um elemento na lista
(j) Excluir - Exclui um elemento da lista
(k) Destrutor - Destr ́oi um n ́o

2. Implemente uma fun ̧c ̃ao main para manipular todas as implementa ̧c ̃oes criadas no item an-
terior
*/

#include <iostream>

using namespace std;

class Node {
public:
    int data;
    int other_data;
    Node* next;

    Node(int value, int other_value) : data(value), other_data(other_value), next(nullptr) {}
};

class List {
private:
    Node* head; // Cabeça

public:


    List() {
        head = nullptr;
    }

    void Inserir(int primeiroInt, int segundoInt) {
        Node* newNode = new Node(primeiroInt, segundoInt);
        newNode->next = head;
        head = newNode;
    }

    Node* ObterProximo(Node* atualNode) {
        if(atualNode != nullptr) {
            return atualNode->next;
        }
        else {
            return nullptr;
        }
    }   

    void ObterValor(Node* newNode) {
        if(newNode != nullptr) {
            cout << "Valores: " << newNode->data << ", " << newNode->other_data << endl;
        }
        else {
            cout << "Error" << endl;
        }
    }

    void AlterarNo(Node* newNode, int primeiroInt, int segundoInt) {
        if(newNode != nullptr) {
            newNode->data = primeiroInt;
            newNode->other_data = segundoInt;
        }
        else {
            cout << "Error" << endl;
        }
    }

    int Tamanho() {
        int count = 0;
        Node* atualNode = head;
        while (atualNode != nullptr) 
        {
            count++;
            atualNode = atualNode->next;                           
        }
        return count;
    }

    bool Existe(Node* NodeExistente) {
        Node* atualNode = head;
        while (atualNode != nullptr) {
            if (atualNode == NodeExistente) {
                return true;
            }
            atualNode = atualNode->next;
        }
        return false;
    }

    void mostrarAll() {
        Node* atualNode = head;
        while (atualNode != nullptr)
        {
            ObterValor(atualNode);
            atualNode = atualNode->next;
        }
        
    }

    void Excluir(Node* excluirNode) {
        if (head == nullptr){
            return;
        }
        if (head == excluirNode) {
            head = head->next;
            delete excluirNode;
            return;
        }

        Node* atualNode = head;
        while (atualNode->next != nullptr && atualNode->next != excluirNode)
        {
            atualNode = atualNode->next;
        }

        if (atualNode->next == excluirNode) {
            atualNode->next = excluirNode->next;
            delete excluirNode;
        }
        
    }

    Node* Buscar(int primeiroInt, int segundoInt) {
        Node* atualNode = head;
        while (atualNode != nullptr) {
            if (atualNode->data == primeiroInt && atualNode->other_data == segundoInt) {
                return atualNode;
            }
            atualNode = atualNode->next;
        }
        return nullptr;
    }

    ~List() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

};  

int main() {

    List lista;

    lista.Inserir(1, 2);
    lista.Inserir(3, 4);
    lista.Inserir(5, 6);

    lista.mostrarAll();

    cout << lista.Buscar(3, 4) << endl;
    
    return 0;
}