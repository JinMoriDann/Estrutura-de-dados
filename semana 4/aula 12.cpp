/*
Tratamento de colisões

Introdução
A prsença de colisões, quando duas chaves k1 e k2 geram h(k1) = h(k2), impede que se faça imediatamente a inserção de um novo item, (k,v) diretamente em A[h(k)] no arranjo A.

para resolver as colisões, podemos utilizar tanto um espaço de memória adicional quanto um espaço no próprio arranjo

Encadeamento separado
Uma ideia simples para tratar colisões é fazer com que cada endereço A[i] seja, na verdade, um ponteiro para uma lista encadeada.
Uma boa função de hash fará com que a maior parte dos endereços esteja vazio ou com apenas um elemento

- ao colocar n elementos em N endereço, espera-se n/N entradas por endereço.
- o valor n/N (também chamado fator de carga) deveria ser limitado por uma constante, idealmente menor que 1.
- implementam-se as operações inserItem, deleteItem e retrieveItem para executarem em um tempo espertado constante

Tabela Hass com endadeamento separado
h(k) = k mod 13

Índice    Lista encadeada
----------------------------
  [0]  -> [0]  -> [39]
  [1]  -> NULL
  [2]  -> NULL
  [3]  -> [55] -> [29] -> [42]
  [4]  -> NULL
  [5]  -> NULL
  [6]  -> [19]
  [7]  -> NULL
  [8]  -> NULL
  [9]  -> NULL
 [10]  -> [10] -> [36]
 [11]  -> NULL
 [12]  -> [25] -> [38] -> [12]


Teste linear
As colisões será tratadas sem alocação de memória adicional, usaremos o próprio arranjo.
Se tentarmos inserir um item (k,v) em um endereço A[i] ocupado, com i = h(k), tenta-se de novo no endereço A[(i+1) mod N].
As tentativas continuam até se encontrar um endereço que aceite o novo item.

- assumindo que queremos colocar um elemento com chave k = 16 tendo uma função h(k) = k mod 13;
     16
| | |55|30|46| | | | |
- inicialmente, ttentamos adicionar a entrada na posição 3. Como n]ao é possível, tentamos na 4 e na 5 até chegarmos na posição 6 livre

- As operações retrieveItem e deleteItem devem também ser atualizadas.
- por exemplo, retrieveItem deverá examinar endereços consecutivos, iniciando em A[h(k)], até encontroar a chave igual a k.
- se k não existir, então a retrieveItem finalizará em uma posição vazia
- o nome "teste lienar" ocorre porque acessar A[h(k)] implica em testar a chave para verificar se encontramos a entrada desejada
- as operações deleteItem não poderão mais remover os itens, pois isso fariam com que algumas chaves não pudesse mais ser achada pelo retriveITtem.
- Por exemplo, retrieveItem não mais achará a chave 16 se remover 55, 30 ou 43
- a solução será fazer com que o deleteItem n]ao remova o elemento, mas substitua por um marcador "disponivel".
- nesse caso, as buscas pela chave k podem pular endereços 'disponiveis' e continuar até encontrar a chave ou uma célula vazia
- a operação insertItem pode usar os endereços 'disponiveis' para inserir entradas

o teste linear agrupa os elementos em posições contiguas. as pesquisas podem se tornar lentas.

outra estrategia de agrupamentyo é o teste quadratico que teste posições A[(i+f(j)) mod N]
- j = 0,1,2,...
- f(j) = j^2

Isso evita o agrupamento sequencial, mas cria novos padrões de agrupamento

se N não for primo, então o teste quadrático poderia falhar em encontrar uma posição, mesmo havendo posições livres no arranjo.

O hashing duplo consiste em encontrar uma função h' para tratamento de colisões
se A[i]ja está ocupado para alguma chave k, tal que i=h(k), então são testados os endereços:
-A[(i+f(j)) mod N], para j = 1,2,3,...
-f(j) = j . h'(k).
 A função de hashing secund[arioa h' não pode resultar em zerp. uma escolha comum é:
 - h'(k) = q - (k mod q), para algum numero priumo q<N


DEtalhe de implementação

Os unicos metodos que precisam ser mudados são o retriveItem, insertItem e o deteleteItem.
No delteItem, vamos marcar os elementos removidos com o RA igual a -2
- Isso fará com que sejam diferentes dos elementos inicialmente vazios, que possuiam RA igual a -1
O insertItem irá trratar qualquer RA negativo da mesma maneira
Em retriveItem, o ponto retornado pela função de has é visto como inicio da busca

*/

void Hash::retirveItem(Aluno& aluno, bool& found) {
  int startLoc = getHash(aluno);
  bool moreToSearch = true;
  int location = startLoc;
  do {
    if (structure[locations].getRa() == aluno.getRa() || structure[locations].getRa() == -1)
      moreToSearch = false;
    else 
      location = (location +1 % max_items);
  } while (location != startLoca && moreToSearch);

  found = (structure[locations].getRa() == aluno.getRa());
  if (found){
    aluno = structure[location]
  }
}
/*
Paramos a busca com RA igual a -1, mas não com RA igual a -2
*/

/*
Em deleteItem, faremos uma busca semelhante ao retrieveItem antes de marcar o elemento com RA -2
*/
void Hash::deleteItem(Aluno aluno) {
  int startLoc = getHash(aluno);
  bool moreToSearch = true;
  int location = startLoc;
  do {
    if (structure[locations].getRa() == aluno.getRa() || structure[locations].getRa() == -1)
      moreToSearch = false;
    else 
      location = (location +1 % max_items);
  } while (location != startLoca && moreToSearch);

  if (structure[locations].getRa() == aluno.getRa()){
    structure[location] = Aluno(-2, "");
    lenght--;
  }
}

/*
Em insertItem, tratamos os elementos com RA -1 e os elementos com RA -2 como iguais
*/

void Hash::insertItem(Aluno aluno){
  int location;
  location = getHash(aluno);
  while (structure[location].getRa() >0)
    location = (location + 1) % max_items;
  strrcuture[location] = aluno;
  lenght ++;
}
/*
Note que não tratamos o caso em que a estrutura está cheia. Isso levaria a um loopign infinito 
*/