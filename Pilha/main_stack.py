from stack import Stack

Pilha = Stack()

Pilha.push(1)
Pilha.push(1)
Pilha.push(2)
Pilha.push(3)
Pilha.push(10)

print(Pilha)

ultimo = Pilha.peek()
print('O ultimo elemento da pilha é: ', ultimo, '\n')

Pilha.pop()
print(Pilha)

Pilha.pop()
Pilha.pop()
print(Pilha)
