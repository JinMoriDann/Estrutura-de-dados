// classes

/*
A classe é um modelo usado para criar objetos, também chamados de instâncias.

A comunicação com os objetos é feita pelo uso da interface pública do objeto.

A complexidade envolvida na realização de uma tarefa fica escondida dentro da
classe.

Uma vantagem é o isolamento.

Em estruturas de dados, isso permitirá separar a visão lógica, da visão de
implementação e da visão de aplicação.

A vi~sao lógica de uma classe será sempre criada em um arquivo de extensão .h

Nesse arquivo, definiremos os membros públicos e privados de uma classe.

A implementação da classe será sempre feita em um arquivo de extensão .cpp.

O arquivo .cpp deverá sempre importar o arquivo .h com a diretiva include.

É comum tentar incluir uma definição de classes mais de uma vez. Nesse caso,
utrilizamos algumas diretivas que impedem que isso aconteça:
- #indef: se não definido
    - Pule este código se já tiver sido incluído.
- #define
    - Define um nome para evitar dupla inclusão
- #endif: fim da diretiva
*/

#indef TIME_H
#define TIME_H

#endif

/*
A classe time
Definiremos uma classe chamada Time que modela uma instância de tempo: hora,
minuto e segundo.
- três atributos (hora, min, seg)
- um contrutor publico que inicializa os atributos
- metodo "get" e "set" para gerenciar os atributos
- metodo publico 'print' para imprimir esta instancia de tempo no formato
hh:mm:ss.
- um metodo publico que adiciona um segundo.
*/

// exemplo do time.cpp
#include "aula 4.h"
#include <iostream>

using namespace std;

// getters
int Time::getHour() const { // o const aqui quer dizer que este metodo nao
                            // modifica nenhum atributo da classe
  return hour;
}

int Time::getMinute() const { return minute; }

int Time::getSecond() const { return second; }

// setters
void Time::setHour(int hour) {
  this->hour = hour; // o this aqui serve para diferenciar o atributo da classe
                     // (hour) com o parametro da função (hour)
}

void Time::setMinute(int minute) { this->minute = minute; }

void Time::setSecond(int second) { this->second = second; }

void Time::print() const {
  cout << hour << ":" << minute << ":" << second << endl;
}

void Time::nextSecond() {
  second += 1;
  if (second >= 60) {
    second = 0;
    minute += 1;
  }
  if (minute >= 60) {
    minute = 0;
    hour += 1;
  }
  if (hour >= 24) {
    hour = 0;
  }
}

/*
Agora temos a cvlasse pronta, podemos utilizá-la em algum outro ponto do código.
*/

int main() {
  Time t1(23, 59, 59);
  t1.print();
  t1.setHour(12);
  t1.setMinute(30);
  t1.setSecond(45);
  t1.print();
  t1.nextSecond();
  t1.print();

  cout << "Hora: " << t1.getHour() << endl;
  cout << "Minuto: " << t1.getMinute() << endl;
  cout << "Segundo: " << t1.getSecond() << endl;
}