# Relatório de Testes — Projeto 04: Painel Interativo para Fast Food

## 1. Objetivo

Este documento apresenta os casos de teste definidos para avaliar o funcionamento do Painel Interativo para Fast Food, desenvolvido com Arduino Uno, display LCD I2C 16x2 e dois botões.

Os testes verificam a navegação pelo cardápio, seleção de produtos, armazenamento dos pedidos, controle dos botões, contagem regressiva e finalização do atendimento.

## 2. Ambiente de teste

| Item | Configuração |
|---|---|
| Plataforma de simulação | Tinkercad |
| Microcontrolador | Arduino Uno |
| Display | LCD I2C 16x2 |
| Botão esquerdo | Pino digital 2 |
| Botão direito | Pino digital 3 |
| Comunicação do display | I2C |
| Endereço do display | 0x27 |
| Quantidade de produtos | 4 |
| Limite de produtos por pedido | 5 |

## 3. Casos de teste

### Teste 01 — Iniciar pedido

- **Procedimento:** pressionar o botão direito na tela inicial.
- **Resultado esperado:** o sistema deve abrir a tela de seleção de produtos.
- **Resultado obtido:** tela de seleção de produtos exibida corretamente.
- **Status:** Aprovado.

### Teste 02 — Avançar produto

- **Procedimento:** pressionar o botão esquerdo durante a seleção.
- **Resultado esperado:** o sistema deve exibir o próximo produto do cardápio.
- **Resultado obtido:** próximo produto exibido corretamente.
- **Status:** Aprovado.

### Teste 03 — Retornar ao primeiro produto

- **Procedimento:** avançar até o último produto e pressionar novamente o botão esquerdo.
- **Resultado esperado:** o cardápio deve retornar ao primeiro produto.
- **Resultado obtido:** navegação circular realizada corretamente.
- **Status:** Aprovado.

### Teste 04 — Confirmar produto

- **Procedimento:** pressionar o botão direito após selecionar um produto.
- **Resultado esperado:** o sistema deve armazenar o produto e apresentar a pergunta "Algo mais?".
- **Resultado obtido:** produto confirmado e pergunta exibida corretamente.
- **Status:** Aprovado.

### Teste 05 — Escolher Sim

- **Procedimento:** pressionar o botão esquerdo na tela "Algo mais?".
- **Resultado esperado:** o sistema deve retornar à seleção, avançando para o próximo produto.
- **Resultado obtido:** próximo produto apresentado corretamente.
- **Status:** Aprovado.

### Teste 06 — Escolher Não

- **Procedimento:** pressionar o botão direito na tela "Algo mais?".
- **Resultado esperado:** o sistema deve iniciar a preparação do pedido.
- **Resultado obtido:** tela de preparação iniciada corretamente.
- **Status:** Aprovado.

### Teste 07 — Contagem regressiva

- **Procedimento:** selecionar a opção Não e acompanhar a contagem no display.
- **Resultado esperado:** o display deve apresentar a contagem regressiva de 10 até 0.
- **Resultado obtido:** contagem regressiva apresentada corretamente.
- **Status:** Aprovado.

### Teste 08 — Botões durante a preparação

- **Procedimento:** pressionar os dois botões durante a contagem regressiva.
- **Resultado esperado:** os comandos devem ser ignorados durante a preparação.
- **Resultado obtido:** os botões não alteraram a etapa de preparação.
- **Status:** Aprovado.

### Teste 09 — Finalizar preparação

- **Procedimento:** aguardar o término da contagem regressiva.
- **Resultado esperado:** o sistema deve apresentar a mensagem "Pedido pronto!".
- **Resultado obtido:** mensagem de pedido pronto exibida corretamente.
- **Status:** Aprovado.

### Teste 10 — Confirmar recebimento

- **Procedimento:** pressionar o botão direito na tela de pedido pronto.
- **Resultado esperado:** o sistema deve apresentar a mensagem de agradecimento.
- **Resultado obtido:** mensagem de agradecimento exibida corretamente.
- **Status:** Aprovado.

### Teste 11 — Retornar à tela inicial

- **Procedimento:** aguardar o tempo de exibição da mensagem de agradecimento.
- **Resultado esperado:** o sistema deve limpar os dados do pedido e retornar à tela inicial.
- **Resultado obtido:** tela inicial apresentada novamente.
- **Status:** Aprovado.

### Teste 12 — Limite máximo de produtos

- **Procedimento:** adicionar cinco produtos ao mesmo pedido.
- **Resultado esperado:** ao atingir cinco produtos, o sistema deve iniciar automaticamente a preparação.
- **Resultado obtido:** preparação iniciada automaticamente ao atingir o limite de cinco produtos.
- **Status:** Aprovado.

## 4. Resumo dos resultados

| Indicador | Quantidade |
|---|---:|
| Total de testes | 12 |
| Testes aprovados | 12 |
| Testes reprovados | 0 |
| Testes pendentes | 0 |

## 5. Conclusão

O conjunto de testes contempla as principais funcionalidades previstas para o Painel Interativo para Fast Food.

Foram considerados os processos de inicialização, navegação pelo cardápio, confirmação de produtos, armazenamento dos itens, controle dos botões, preparação e finalização do pedido.

O relatório registra os 12 casos de teste como aprovados, indicando o atendimento aos comportamentos esperados pelo projeto.
