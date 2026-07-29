// Ponteiros e referências
 /*
 Definição de ponteiros:
    - Um ponteiro é uma variável cujo conteúdo é um endereço de memória, não um valor no sentido tradicional.
    - Os endereços podem ser a localizxação na memória de uma varivável ou função.
    - Se a variavel x tiver como valor o endereço da variavel y, então dizemos:
        - "x aponta para y".
 */

 /*
 - O endereço de uma varivael (ou função) é a localização na memória do primeiro byte ocupado por ela
 - Conhecer o endereço de uma variavel permite criar estruturas complexas
    - Listas encadeadas são implementadas com um item conhecendo o endereço do item seguinte

 - A possibilidade trabalhar diretamente com a memória permite criar programas mais eficientes
 */

 /*
 Declaração de ponteiros
 Para declarar um ponteiro, usamos a seguinte sintaxe:
    tipo *ponteiro;

    - tipo: se refere para qual tipo de dados os ponteiro estará apontando.
    - ponteiro: é o nome da varivável.

 - Por exemplo, a seguir declaramos uma variável chamada intPointer que aponta para um valor do tipo inteiro.
 */
    int* intPointer;
 /*
 - Como a variavel acima não foi inicializada, o seu conteudo será undefined.
 - a pergunta agora é: "Como obter um endereço de memória?"
     - Isso pode ser feito de maneira estática ou dinâmica.
 */
 /*
 Inicialização de ponteiros

 o operador & nos permite obter o endereço de memória de uma variável. Feito isso, podemos inicializar um ponteiro:
    
 */

 // Declarando variaveiis
 int alpha;
 int* intPointer;

 // Incializando ponteiro
 intPointer = &alpha;
 
 /*
 - Um segunda maneira de inicializar ponteiros é com alocação dinâmica, um mecanismo pelo qual um porgrama aloca e libera memória em tempo de execução

 - vantagens:
    - elimina a necessidade de dfinir a priori e o tamanho da memória a ser utilizada.
    - é possivel aumentar ou diminuir o tamanho da memória utilizada em tempo de execução.

 - Os operadores new e delete são utilizados para efetuar a alocação e desalocação de memória, respectivamente.

 obs: se eu alocar memória dinamica, preciso desalocar depois.

 - por exemplo, alocando memória dinamicamente para armazenar um inteiro.
 */

 int* intPointer;
 intPointer = new int;

 /*
  - Características da locação dinamica
    - as variaveis residem em um local diferente das que foram alocadas estaticamente.
    - uma variavel alocada de forma dinamica com new não possui nome.
    - essa variavel precisa ser acessada indiretamente pelo ponteiro retornado por new.
 */

 /* 
 Utilização de memória
 - temos um ponteiro e queremos acessar o valor que está na memória. Nesse caso, usamos o operador * como um prefixo para o nome da variavel.
 - o operador * é um operador unário que retorna o conteúdo da variavel localizada no endereço especificado.

 - Para obter o conteúdo que está localizado no endereço apontado por intPointer:
 */

 int anotherInt;
 anotherInt = *intPointer;

 /*
  - Para alterar o conteúdo que está localizado no endereço apontado por intPointr:
 */

 *intPointer = 35;

 /*
 - um ponteiro com valor 0 (zero), po definição, aponta para o vazio, mas não queremos confundir com o inteiro 0.
 - nesse caso, usaremos a constante NULL, que esta no pacote csttdef
 */

 #include <cstddef>
 bool* truth = NULL;
 float* money = NULL;

 /*
 Vamos observar a memória após algumas operações:
    
 */

 bool* truth = new bool;
 *truth = true;
 float* money = new float;
 *money = 100.00f;
 float* mmyMoney = new float;

 /*
 truth |    |  -> |true| *truth
 money |    |  -> |100.00f| *money
 mmyMoney |    |  -> | ? | *mmyMoney

 */

 /*
 - Qualquer operação que pode ser aplicada a uma variavel do tipo int pode ser aplicada a *intPointer.
 - qualquer operação que pode ser aplicada a uma variavel do tipo float pode ser aplicada a *money.
 - qualquer operação que pode ser aplicada a uma variavel do tipo bool pode ser aplicada a *truth.
 */

 /*
 Cuidados com Ponteiros
 - as duas operações a seguir são completamente diferentes:
    - na primeira, o conteúdo de memória apontado por money é copiado para a região apontada por myMoney.
    - na segunda, myMoney passa a apontar para a mesma região apontada por money.
 
 */

 *myMoney = *money; //1
 myMoney = money;   //2

 /*
 - Sipondo que a segunda operação fosse a sua intenção, evite vazamento de memória com delete.
  */

  delete myMoney;
  myMoney = money;

  /*
  - Observe que delte não inutiliza a variavel ponteiro, apenas libera a região que ela aponta.
  */