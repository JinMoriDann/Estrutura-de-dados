#include <iostream>

int main(){
  std::cout << "Hello World!" << std::endl;
  return 0;
}


// Em c++ todas as variveis precisam ter seu tipo explicito ao serem iniciadas.
int number1;
int number2;

// std::out -> jogue isso na saida (terminal)
std::cout << "Digite um numero: ";
// std::cin -> pegue um valor do teclado (console)
std::cin >> number1;
std::cout << "Digite outro numero: ";
std::cin >> number2;


// Operadores Aritmeticos

int sum = number1 + number2;
std::cout << "A soma dos numeros eh: " << sum << std::endl;

int sub = number1 - number2;
std::cout << "A subtracao dos numeros eh: " << sub << std::endl;

int mul = number1 * number2;
std::cout << "A multiplicacao dos numeros eh: " << mul << std::endl;

int div = number1 / number2;
std::cout << "A divisao dos numeros eh: " << div << std::endl;

float fdiv = (float)number1 / (float)number2;
std::cout << "A divisao float dos numeros eh: " << fdiv << std::endl;

int rest = number1 % number2;
std::cout << "O resto da divisao dos numeros eh: " << rest << std::endl;  

// Operadores Relacionais

if (number1 == number2){
  std::cout << "Os numeros sao iguais" << std::endl;
}
if (number1 != number2){
  std::cout << "Os numeros sao diferentes" << std::endl;
}
if (number1 > number2){
  std::cout << "O primeiro numero eh maior que o segundo" << std::endl;
}
if (number1 < number2){
  std::cout << "O segundo numero eh maior que o primeiro" << std::endl;
}
if (number1 >= number2){
  std::cout << "O primeiro numero eh maior ou igual ao segundo" << std::endl;
}
if (number1 <= number2){
  std::cout << "O segundo numero eh maior ou igual ao primeiro" << std::endl;
}

// Comandos de repetição
int i = 0;
while (i < 10){
  std::cout << "O numero eh: " << i << std::endl;
  i++;
}

for (int j = 0; j < 10; j++){
  std::cout << "O numero eh: " << j << std::endl;
}

int k = 0;
do {
  std::cout << "O numero eh: " << k << std::endl;
  k++;
} while (k < 10); // a verificação fica no final, ou seja, pelo menos uma vez vai rodar


// using namespace std; -> permite usar cout e cin sem o std::

// declarando funções no c++ -> int nomeFuncao(parametro1, parametro2){
//   return valorRetornado;
// }

// o uso de funções exige que digamos explicitamente a saida da função (me lembra flutter)
int soma(int a, int b){
  return a + b;
}

/*
Os parâmetros das funções podem ser passados por valor ou por referência:

Valor: a função recebe uma cópia da variável fornecida quando invocada. Alterações dentro da função não afetarão os valores originais.

Referência: a função recebe o endereço da variável fornecida quando invocada. Alterações dentro da função afetarão os valores originais.
*/

// Exemplo de função por valor:
int soma_valor(int a, int b){
  return a + b;
}

// Exemplo de função por referência:
int soma_ref(int &a, int &b){
  return a + b;
}

return 0;