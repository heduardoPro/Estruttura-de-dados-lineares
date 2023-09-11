from node import Node

class Stack:

    def __init__(self) -> None:
        self.topo = None
        self._tamanho = 0

    #insere dado na pilha
    def push(self, elemento):
        node = Node(elemento)
        node.proximo = self.topo
        self.topo = node
        self._tamanho = self._tamanho + 1

    #remove ultimo item da pilha
    def pop(self):
        if(self._tamanho > 0):
            node = self.topo
            self.topo = self.topo.proximo
            self._tamanho = self._tamanho - 1
            return node
        else:
            print('A Pilha está vazia.')

    #retorna ultimo item da pilha
    def peek(self):
        if(self._tamanho > 0):
            return self.topo.dado
        raise IndexError("A pilha está Vazia")
    
    #retorna o tamanho da pilha
    def len(self):
        return self._tamanho

    def __repr__(self) -> str:
        representa = ""
        ptr = self.topo
        while(ptr):
            representa = representa + str(ptr.dado) + '\n'
            ptr = ptr.proximo
        return representa

    def __str__(self) -> str:
        return self.__repr__()