// Conceitos de tabela hash

/*
Motivação
- sabemos que:
    - busca sequencia executa em tempo O(n)
    - busca binária executa em tempo O(log(n))
    - busca binária exige vetor ordenado

- Seria possivel efetuar uma busca em tempo melhor que O(log(n))?
- Quais restrições devem existir sobre os dados?

*/

/*
Tabelas de Hash
- Tabelas de Hash (ou tabelas Hash) permitem buscas em tempo constante, satisgeitas algumas restrições.
- Essa estrutura pode ter vários nomes como: dicionários, mapas, arrarys associativos, e assim por diante.
- A principio, a chave de busca pode ser de qualquer tipo.
*/

/*
Tipo abstrato de dados
- retriveltem(k): retorna uma entrada como chave igual a K, se ela existir. Caso contrário, rretorna nulo.
- insertItem(k, v): insere uma entyrada v na chave k se a chave não existtir. caso contrário, atualiza o valor associado a k
- deleteItem(k): remove a chave k e o valor associado a ela.

Outros metodos:
- size(): retorna o numero de entradas
- keySet(): retoirna uma lista encadeada de todas as cvhaves armazenadas na tabela
- values(): retorna uma coleção contendo todos os valores associados com as chaves armazenadas na tabela
- entrySet(): retorna uma coleção contendo todas as entradas (chave-valor) da tabela
*/

/*
Implementação
- a propria chave deve ser usada para organizar os dados em memória.
- cada entrada da estrutura é composta por um par "chave-valor" (k,v). A associação entre k e v define o mapeamento.
- a chave é um identificador único e deve ser vista como um "endereço" para seu valor.
*/

/*
- a tabela pode ser organizada em memória como um vetor, dado que este permite acesso em tempo constante
- as chaves podem ser de qualquer tupo de dados, mas para efetuarmos a busca no vetor, precisaremos de uma função que mapeie chaves em números inteiros.
- seja h a função que faz o mapemaento (também chamada de fgnnção espalhamento) e k a chave, o de enderço de memória será daddo por h(k)
- se ops valores teronados por h(k) foram bem distribuidos em um intervalo entro 0 e N-1, então precisaremos de um vetor de capacidade N
- assumindo ausência de colisões, essa estrutura básica seria suficiente.
*/

/*
Funções de Hash
- a função de hash h mapeia cada chave em um intervalo de 0 a N-1, onde N é a capacidade do arrajo.
- é possivel tratar colisões, mas a melhor estratégia por enqaunto é tentar ecita-lás
- uma função de has é boa se minimiza a ocorrência de colisões.
- a primeira tarefa da função será trnasforma chaves de tipos arbitrários em inteiros.
- vamos assumir que queremos armazenar informações de funcionários de uma empresa e indexar essa informações pelo login único da pessoa.
- o login pode ser oi primeiro nome da pessoa, mas se este ja foi escolhido por alguem, então outro deve ser selecionado pelo funcionário
 Uma função de hash pode primeiramente mapear os caracteres para inteiros.

 Exemplos de valores ASCII:

 Letras maiúsculas:
 A = 65
 B = 66
 C = 67
 D = 68
 E = 69
 F = 70
 G = 71

 Letras minúsculas:
 a = 97
 b = 98
 c = 99
 d = 100
 e = 101
 f = 102
 g = 103

 Dígitos:
 '0' = 48
 '1' = 49
 '2' = 50
 '3' = 51
 '4' = 52
 '5' = 53
 '6' = 54

 Exemplo de cálculo de hash para a palavra "ulisses":

 u + l + i + e + 3 * s

 Valores ASCII:
 u = 117
 l = 108
 i = 105
 e = 101
 s = 115

 Cálculo:
 117 + 108 + 105 + 101 + 3 * 115

 117 + 108 + 105 + 101 + 345 = 776

 Resultado do hash:
 hash("ulisses") = 776

 - podemos mapear qualquer login em inteiro
 |Ulisses|776|
 |danielle|830|
 |amanda|610|
 |cleopatra|1218|

 - o valor inteiro encontrado pode ser o indice a entrada em um vetor
 - essa ideia ilustra uma implementação báscia da tabela hash.

 - essa estratégia gera colisões:
 |orlando|751|
 |odnalro|751|
 |adriana|751|
 |ariadna|751|

 - uma função de hash melhor levaria em conta a posição dos carateres ci na cadeia c = c0, c1, c2,...,ck-1)

- por exemplo, com a = 3, teriamos os seguintes valores para orlando e odnalro

*/


// o | 111 x 729 +
// r | 114 x 243 +
// l | 108 x 81  +
// a | 97  x 27  +
// n | 110 x 9   +
// d | 100 x 3   +
// o | 111 x 1   = 121389

// o | 111 x 729 +
// d | 100 x 243 +
// n | 110 x 81  +
// a | 97  x 27  +
// l | 108 x 9   +
// r | 114 x 3   +
// o | 111 x 1   = 118173

/*
Um valor de a alto (33, 37, 39  ou 41) tende a diminuir o numero de colisões par algumas poucas.

- nesse caso, é possivel fazer com que cada endereço tenha espaço para mais de uma entrada
- um valor de a alto (33, 37, 39  ou 41) pode levar a um overflow do intervalo dos inteiros
- a compressão dos valores pode fazer parte da função. O resto da divisão por N estabiliza os valores em um intervalo [0...N-1]
        i mod N
- o tamanho do arranjo N pode aumentar ou diminuir o numero de colisões:
    - se usarmos N=1000, teremos muito menos colisões do que com N=100

- para ajudar o espalhamento das chaves, é interessante usar um número primo para N. isso diminui a chance de ocorrer padrões na distribuição de dados.

- por exemplo, se temos as chaves {200, 205, 210, 215, 220, ..., 600}
    - com N=100, cada chave irá colidir com várias outras chaves
    - com N=101 não teremos colisões

- Na próxima aula, implementaremos esses conceitos em C++. Em seguida, veremos técnicas de tratamento de colisões
*/