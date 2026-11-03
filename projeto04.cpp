
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int botaoEsquerdo = 2;
const int botaoDireito = 3;

const int TOTAL_PRODUTOS = 4;
const int LIMITE_PEDIDO = 5;

const unsigned long DEBOUNCE = 50;

const char* cardapio[TOTAL_PRODUTOS] = {
  "Hamburguer",
  "Batata frita",
  "Refrigerante",
  "Sorvete"
};

const char* pedido[LIMITE_PEDIDO];

int quantidadeItens = 0;
int produtoAtual = 0;

enum Estado {
  INICIO,
  SELECAO,
  PERGUNTA,
  PREPARANDO,
  PRONTO,
  AGRADECIMENTO
};

Estado estadoAtual = INICIO;

unsigned long inicioPreparo = 0;
unsigned long inicioAgradecimento = 0;

unsigned long ultimaMudancaEsquerdo = 0;
unsigned long ultimaMudancaDireito = 0;

bool leituraAnteriorEsquerdo = HIGH;
bool leituraAnteriorDireito = HIGH;

bool estadoEstavelEsquerdo = HIGH;
bool estadoEstavelDireito = HIGH;

int segundoAnterior = -1;

bool lerBotao(int pino, bool &leituraAnterior,
              bool &estadoEstavel,
              unsigned long &ultimaMudanca) {

  bool leitura = digitalRead(pino);

  if (leitura != leituraAnterior) {
    leituraAnterior = leitura;
    ultimaMudanca = millis();
  }

  if (millis() - ultimaMudanca >= DEBOUNCE) {
    if (leitura != estadoEstavel) {
      estadoEstavel = leitura;

      if (estadoEstavel == LOW) {
        return true;
      }
    }
  }

  return false;
}

bool esquerdoPressionado() {
  return lerBotao(
    botaoEsquerdo,
    leituraAnteriorEsquerdo,
    estadoEstavelEsquerdo,
    ultimaMudancaEsquerdo
  );
}

bool direitoPressionado() {
  return lerBotao(
    botaoDireito,
    leituraAnteriorDireito,
    estadoEstavelDireito,
    ultimaMudancaDireito
  );
}

void mostrarInicio() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Fast Food");
  lcd.setCursor(0, 1);
  lcd.print("Dir: Iniciar");
}

void mostrarSelecao() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Escolha o item:");
  lcd.setCursor(0, 1);
  lcd.print(cardapio[produtoAtual]);
}

void mostrarPergunta() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Algo mais?");
  lcd.setCursor(0, 1);
  lcd.print("E: Sim D: Nao");
}

void mostrarPreparacao(int segundos) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Preparando...");
  lcd.setCursor(0, 1);
  lcd.print("Aguarde: ");
  lcd.print(segundos);
}

void mostrarPronto() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Pedido pronto!");
  lcd.setCursor(0, 1);
  lcd.print("Dir: Receber");
}

void mostrarAgradecimento() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Obrigado!");
  lcd.setCursor(0, 1);
  lcd.print("Volte sempre!");
}

void iniciarPedido() {
  quantidadeItens = 0;
  produtoAtual = 0;
  estadoAtual = SELECAO;
  mostrarSelecao();
}

void avancarProduto() {
  produtoAtual++;

  if (produtoAtual >= TOTAL_PRODUTOS) {
    produtoAtual = 0;
  }

  mostrarSelecao();
}

void iniciarPreparo() {
  estadoAtual = PREPARANDO;
  inicioPreparo = millis();
  segundoAnterior = -1;
  mostrarPreparacao(10);
}

void confirmarProduto() {
  if (quantidadeItens < LIMITE_PEDIDO) {
    pedido[quantidadeItens] = cardapio[produtoAtual];
    quantidadeItens++;
  }

  if (quantidadeItens >= LIMITE_PEDIDO) {
    iniciarPreparo();
  } else {
    estadoAtual = PERGUNTA;
    mostrarPergunta();
  }
}

void atualizarContagem() {
  unsigned long tempo = millis() - inicioPreparo;
  int segundo = tempo / 1000;

  if (segundo <= 10) {
    int restante = 10 - segundo;

    if (restante != segundoAnterior) {
      segundoAnterior = restante;
      mostrarPreparacao(restante);
    }
  } else {
    estadoAtual = PRONTO;
    mostrarPronto();
  }
}

void finalizarPedido() {
  estadoAtual = AGRADECIMENTO;
  inicioAgradecimento = millis();
  mostrarAgradecimento();
}

void voltarInicio() {
  quantidadeItens = 0;
  produtoAtual = 0;
  estadoAtual = INICIO;
  mostrarInicio();
}

void setup() {
  pinMode(botaoEsquerdo, INPUT_PULLUP);
  pinMode(botaoDireito, INPUT_PULLUP);

  lcd.init();
  lcd.backlight();

  mostrarInicio();
}

void loop() {
  bool esquerdo = esquerdoPressionado();
  bool direito = direitoPressionado();

  switch (estadoAtual) {

    case INICIO:
      if (direito) {
        iniciarPedido();
      }
      break;

    case SELECAO:
      if (esquerdo) {
        avancarProduto();
      } else if (direito) {
        confirmarProduto();
      }
      break;

    case PERGUNTA:
      if (esquerdo) {
        avancarProduto();
        estadoAtual = SELECAO;
      } else if (direito) {
        iniciarPreparo();
      }
      break;

    case PREPARANDO:
      atualizarContagem();
      break;

    case PRONTO:
      if (direito) {
        finalizarPedido();
      }
      break;

    case AGRADECIMENTO:
      if (millis() - inicioAgradecimento >= 2500) {
        voltarInicio();
      }
      break;
  }
}
