from karatsuba import Karatsuba
from multiplicacao import Multiplicacao
import pandas as pd

# Função para multiplicação tradicional
def traditional_multiply(x, y):
    return x * y

# Pares de números
pairs = [(1234, 5678), (11111111, 22222222), (12345678, 87654321)]

# Criando um DataFrame para armazenar os resultados
data = {
    'Par de Números': pairs,
    'Karatsuba': [Karatsuba(x, y) for x, y in pairs],
    'Multiplicação Tradicional': [Multiplicacao(x, y) for x, y in pairs]
}

df = pd.DataFrame(data)

# Adicionando uma coluna para verificar se os resultados são iguais
df['Resultados Iguais'] = df['Karatsuba'] == df['Multiplicação Tradicional']

# Imprimindo o DataFrame
print(df)

