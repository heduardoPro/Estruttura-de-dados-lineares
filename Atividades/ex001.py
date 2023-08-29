def calcular_investimento_mensal(valor_inicial, deposito_mensal, taxa_juros_anual, quantidade_anos):
    # Converter taxa de juros anual para taxa de juros mensal
    taxa_juros_mensal = (taxa_juros_anual / 100) / 12
    
    total_meses = quantidade_anos * 12
    
    valores_investimento = []
    depositos = []
    juros = []
    
    # Inicializar o valor atual
    valor_atual = valor_inicial
    
    # Calcular valores para cada mês
    for mes in range(0, total_meses + 1):
        valores_investimento.append(valor_atual)
        depositos.append(deposito_mensal)
        
        # Calcular juros para o mês atual
        novo_juros = valor_atual * taxa_juros_mensal
        juros.append(novo_juros)
        
        # Atualizar o valor atual para o próximo mês
        valor_atual += deposito_mensal + novo_juros
    
    return valores_investimento, depositos, juros


valor_inicial = 10000
deposito_mensal = 2000
taxa_juros_anual = 10
quantidade_anos = 5

# Calcular valores de investimento, depósitos e juros
valores_investimento, depositos, juros = calcular_investimento_mensal(valor_inicial, deposito_mensal, taxa_juros_anual, quantidade_anos)

# Calcular investimento total, juros totais
investimento_total = sum(depositos) + valor_inicial
juros_totais = sum(juros)


print(f"{'Mês':<15} {'Valor':<15} {'Depósito':<15} {'Juros':<15}")
print("-" * 50)

for mes in range(len(valores_investimento)):
    print(f"{mes:<10} {valores_investimento[mes]:<15.2f} {depositos[mes]:<15.2f} {juros[mes]:<15.2f}")

print("-" * 50)
print(f"Investimento Total: {investimento_total:.2f}")
print(f"Depósitos Totais: {sum(depositos):.2f}")
print(f"Juros Totais Recebidos: {juros_totais:.2f}")