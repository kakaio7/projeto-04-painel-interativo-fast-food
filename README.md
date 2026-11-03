# Projeto 04 — Painel Interativo para Fast Food

## Sobre o projeto

O Painel Interativo para Fast Food é um sistema de pedidos desenvolvido com Arduino Uno, display LCD I2C 16x2 e dois botões.

O projeto permite que o usuário navegue pelo cardápio, selecione produtos, adicione itens ao pedido e acompanhe o tempo de preparação até a confirmação de que o pedido está pronto.

## Objetivo

Desenvolver um sistema interativo de pedidos utilizando programação em C++, Arduino e componentes eletrônicos, aplicando estruturas condicionais, funções, arrays e máquina de estados.

## Componentes utilizados

- Arduino Uno
- Display LCD I2C 16x2
- 2 botões
- Protoboard
- Jumpers

## Funcionamento

O sistema possui seis etapas:

1. Tela inicial: permite iniciar um pedido.
2. Seleção de produtos: permite navegar pelo cardápio e confirmar itens.
3. Pergunta adicional: permite adicionar outro produto ou finalizar o pedido.
4. Preparação: apresenta uma contagem regressiva de 10 segundos.
5. Pedido pronto: informa que o pedido está disponível para recebimento.
6. Agradecimento: apresenta uma mensagem e retorna à tela inicial.

## Recursos implementados

- Navegação por quatro produtos.
- Armazenamento de até cinco produtos por pedido.
- Utilização de dois botões com `INPUT_PULLUP`.
- Controle de pressionamento dos botões com debounce.
- Máquina de estados para controlar as telas.
- Contagem regressiva de preparação.
- Retorno automático à tela inicial.

## Tecnologias utilizadas

- Arduino
- C++
- Tinkercad
- Display LCD I2C

## Estrutura do repositório

Os arquivos do código-fonte, testes, registros de problemas e imagens do projeto serão organizados neste repositório.

## Autoria

Projeto desenvolvido como atividade prática de programação e eletrônica.
