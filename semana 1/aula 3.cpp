#include <stdio.h>
/*
Vetores
 - vetores são a maneira mais simples de estruturarmos um conjunto de dados
 - os elementos devem ser do mesmmo tipo
 - o tamanho é fixado na declaração do vetor
 - Elemtnso ocupam regiões consecutivas da memória
 - o acesso ao vetor é feito usando o índice
 - em C++ os índices começam em 0

 Na declaração, informamos o tipo e o numero de elemtnos
*/
int c[10];
/*
- declarando e inicializando os elementos
*/
int a[5] = {1, 2, 3};
/*
    - inicializamos os primeiros três elementos.
    - como não fornecemos valores para todos os elementos, o restante iniciará com zero.
*/

/*
 - Os elementos podem se acessador com a sintaxe de colchetes.
*/

int main() {
    int a[5] = {1, 2, 3};
    int i;
    for(i = 0; i < 5; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}

/* 
 - é comum iterarmos pelos valores com for
*/

for (int i = 0; i < 5; i++) {
    std::cout << "a[" << i << "] = " << a[i] << std::endl;
}   
/*
 - é tarefa do programador verificar os limites do vetor antes de fazer o acesso.
*/ 

/*
 - A construção a seguir é comum:
 */

 int c[] = {5, 4, 3, 2, 1};
 /*
    - O tamanho é inferido a partir do numero de elementos fornecidos
    - Não adotaremos esta notação na disciplina por ser dificil saber a quantidade de elementos

 - Em alguns casos, inicializaremos os elementos com um laco de repetição:
 */

 int c[10];
 for(int i = 0; i < 10; i++) {
    c[i] = 2*i;
 }

/*
 - espedifaremos o tamanho do vetor com uma variavel constante:
 */

 const int NUM_ELEM = 10;

 int main() {
  int c[NUM_ELEM];
  for (int i=0; i<NUM_ELEM; i++) {
    c[i] = 2*i;
  }
  for(int i = 0; i<NUM_ELEM; i++) {
    std::cout << "c[" << i << "] = " << c[i] << std::endl;
  }
 }

 /*
 - confere mais clareza ao código e torna mais escalonável.
 */

 /*
 Alocação dinamica

  - os vetores declarados até aqui eram estáticos, pois o número de elementos era fixado em tempo de compilação.
  - podemos declarar vetores em que o número de elementos é conhecido apenas durante a execução com alocação dinamica,
  - o tamanho do voter não poderá mudar após a declaração
  
  - para fazer alocação dinâmica, usaremo o operador nes que já conhecemos:
   */
 int* c = new int[n];
 
 /*
    - o comando alocará uma região de memória de tamanho suficiente para alocar n elementos inteiros contíguos
    - em outras palavras, o comando cria num_elem elementos inteiros consecutivos (um vetor).
    - a variavel c recebe o endereço do primeiro elemento do vetor. Feito isso, podemos usar a sintaxe de colchetes.
    c[5] = 30;
 */
 
int* v, n;
std::cout << "Informe o tamanho do vetor: ";
std::cin >> n;
v = new int[n];

/*
 - o tamanho do vetor pode mudar em diferentes execuções:
*/

int main() {
    int num_elem;
    std::cout << "Informe o tamanho do vetor: ";
    std::cin >> num_elem;
    int* c = new int[num_elem];
    
    for (int i = 0; i < num_elem; i++){
        c[i] = 2*i;
    }
    for (int i = 0; i< num_elem; i++){
        std::cout << "c[" << i << "] = " << c[i] << std::endl;
    }
    return 0;
}
 
/*
como a al9ocação foi feita de forma dinamica com new, precisamos desalocar a memória com o comando delete.
*/

int* c = new int[num_elem];
delete[] c;
/*
- é fundamental sempre desalocar a memória alocada com new
*/


/*
Passagem de parametro

 - no comando a seguir:
  int c[10];

   - a variavel c armazena o endereço base do vetor
   - nessa cado, c é um ponteiro.
 - O mesmo ocorre na alocação dinamica:
    int* c = new int[num_elem];

 - Quando passamo um vetoir para uma função, estamos passando um ponteiro.

 - vamos discutir a passagem de ponteiros:

*/

void valor_alocando_memoria(int* p){
    p = new int;
    *p = 7;
}

void valor_modificando_memoria(int* p){
    *p = 8;
}

void referencia(int*& p){
    p = new int;
    *p = 9;
}

// iremos invocar os métodos:

int a = 1;
int b = 2;
int c = 3;
int* p1 = &a;
int* p2 = &b;
int* p3 = &c;

std::cout << "antes: " << *p1 << " " << *p2 << " " << *p3 << std::endl;

valor_alocando_memoria(p1);
valor_modificando_memoria(p2);
referencia(p3);

// após a invocação, imprimimos na tela os valores da variaveis novamente.

std::cout << *p1 << " " << *p2 << " " << *p3 << std::endl;
delete p1;
delete p2;
delete p3;

// como conclusão do experimento:
void valor_alocando_memoria(int* p){
    p = new int;
    *p = 7;
}

/*
 - A função valor_alocando_memoria não altera o valor da variavel que estava fora da função.
 - a função também não modifica o endereço para o qual o ponteiro de fora da função estava apontando.
 - isso pode ser explicado porque o parametro foi passado por valor. nada do que foi feito internamente afeta as variaveis de fora.
*/

void valor_modificando_memoria(int* p){
    *p = 8;
}

/*
 - a função valor_modificando_memoria aletra o valor da variavel estava fora da função.
 - a passagem de parametro foi por valor, mas estamos modificando o endereço de memória para onde o ponteiro aponta.
 - a variavel b usava essa região da memória e a variavel p2 apontava para ela, nessa caso ambas foram afetadas
*/

void referencia(int*& p){
    p = new int;
    *p = 9;
}

/*
 - a funçãoreferencia altera o endereço para onde aponta a variavel p3, pois essa foi passada como referencia
 - a variavel c não é afetada, pois continua utilizando o enbdereço antigo de memória
 - nesse cao, o valor apontado por p3 se torna diferente do valor da variavel c.
*/

/* 
 - como as variaveis usadas nos vetores são ponteiros, a função sabe o endereço onde os elementos estão armazenados
 - nesse caso, as modificações dentro da função naquele endereço de memória surtirão efeito também fora da função.
 - em outras plavras, quem invoca a função passando um vetor concede acesso direto aos dados e a permissão de modifica- los
 - não dar essa permissão imnplicaria em copiar o vetor para outro lugar na memória
*/

/* 
as duas sintaxes a seguir são válidas:
*/

void modifica_vetor_sintaxe_1(int b[], int num_elem){

    for (int i =0; i<num_elem; i++){
        b[i] = b[i]*2
    }
}

void modifica_vetor_sintaxe_2(int* b, int num_elem){
    for (int i =0; i<num_elem; i++){
        b[i] = b[i]*2;
    }
}

/*
O efeito é o mesmo com vetores estáticos e vetores alocados dinamicamente
*/

// Alocação estática
int c[NUM_ELEM] = {1,2,3,4,5};

// Alocação dinamica
int *d = new int[NUM_ELEM];
for (int i = 0; i<NUM_ELEM; i ++){
    d[i] = i+1;
}

modifica_vetor_sintaxe_1(c, NUM_ELEM);
modifica_vetor_sintaxe_2(c, NUM_ELEM);


modifica_vetor_sintaxe_1(d, NUM_ELEM);
modifica_vetor_sintaxe_2(d, NUM_ELEM);

/*
o efeito é o mesmo com vetores estáticos e vetores alocados dinamicamente
*/
for (int i =0; i<NUM_ELEM; i++){
    std::cout << i << ": " << c[i] << " " << d[i] << std::endl;
}

/*
O const pode ser usado novamente
*/
void vetor_const_sintaxe_1(const int* b, int num_elem){
    // corpor sem alterar os elementos do vetor
}
void vetor_const_sintaxe_2(const int b[], int num_elem){
    // corpor sem alterar os elementos do vetor
}

/*
- impede que uma função altere o vetor
- um erro em tempo de compilação será fornecido se alguma atribuição for feita.
*/

// error: read-only variable is not assignable.
