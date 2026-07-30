// Pilhas
/*
Uma pilha é uma estrutura linear na qual inserções e remoções ocorrem no topo da
pilha.

Suponha que duas pessoas estão lavando e enxugando pratos:
    - ao terminar de lavar um prato, alguém colocará no topo da pilha de pratos
a serem enxugados.
    - ao terminar de enxugar um prato, alguém o retirará do topo da pilha de
pratos a serem enxugados.
    - se a pilha de pratos a serem enxugados estiver vazia, o trabalho deve
parar

    Vejamos as operações típicas de uma pilha:

    PUSH: Inserção de um elemento na pilha.
    POP: Remoção de um elemento da pilha.
    PEEK: Visualização do topo da pilha.
    EMPTY: Verificação se a pilha está vazia.
*/

// ver aula 5.h pra ver a implementação

/*
Aplicações da estrutura

Uma pilha é uma estrutura bastante útil, principalmente quando precisamos
garantir alinhamento de componentes em processos.
    - chamada de funções na execução de programas.
    - análise de sintaxe de linguagens de programação.
    - verificação de alinhamento de parenteses em string.
*/

/*
Detalhe de implementação

implementaremos uma pilha como um vetor.

a posição do topo da pilha depende do número de elementos que estão na pilha.

Queremos que inserções e remoções ocorram em tempo constante. Em outras
palavras, independem do número de elementos na estrutura.
*/

/*
Implementando essa ideia, temos:
*/

// Construtor e Destrutor

#include "aula 5.h"
#include <iostream>

using namespace std;

Stack::Stack() {
  lenght = 0;
  // structure (ItemType *structure;) aponta para o primeiro elemento do vetor
  // alocação dinâmica
  structure = new ItemType[MAX_ITEMS];
}

Stack::~Stack() {
  // delete vem pois é de new (structure)
  // [] porque é um array
  // nome da variavel que vai ser destruida
  delete[] structure;
}

bool Stack::isEmpty() const { return (lenght == 0); }

bool Stack::isFull() const { return (lenght == MAX_ITEMS); }

void Stack::push(ItemType item) {
  if (!isFull()) {
    structure[lenght] = item;
    lenght++;
  } else {
    throw "Stack is already full!";
  }
}

ItemType Stack::pop() {
  if (!isEmpty()) {
    ItemType aux = structure[lenght - 1];
    lenght--;
    return aux;
  } else {
    throw "Stack is empty!";
  }
}

void Stack::print() const {
  cout << "Pilha: ";
  for (int i = 0; i < lenght; i++) {
    cout << structure[i] << " ";
  }
  cout << endl;
}