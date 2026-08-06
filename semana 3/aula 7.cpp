// Listas lineares
/*
Estrutura de dados na qual cada elementos é precedido por um elemento e sucedido por outro, com exceção do último que não tem sucessor.
Isso gera um aordem nos elementos, que pode ser a ordem de inclusão.
As esstruturas Pilha e Fila são listas lineares
Implementamos a Pilha e Fila como Listas Lineares Sequenciais.
Em Listas Lineares Sequenciais a ordem lógica dos elementos (ordem 'vista' pelo usuário) é a mesma da ordem física. Isto é, elementos vizinhos na lista estão em posições visinha de memória
Essa organização confere acesso em tempo constante a qualquer elemento, dado o índice do elemento
O acesso em tempo constante, dado o índice, permite obter elementos em um vetor ordenado em tempo O(log(n)) com busca binária.
exe: buscar 23

|16|22|23|25|33|35|37|45|53|
Primeiro busca o do meio, se não é, ele procura na metade em que ele pode estar
|16|22|23|25|
o elemento do meio (22) não é 23 emtão busca na metade em que ele pode estar
| | |23|25|


Entretanto, listas lineare sequenciais possuem desvantagens:
- Precisamos alocar espaço suficiente para todos os elementos de uma vez só
    - Caso falte algum espaço, seria oneroso mover todos os elementos para uma nova posição de memória com mais espaço
- Para manter a ordem, talvez sejam necessários muito deslocamentos em memória
    - Array ordenado: precisamos deslocar vários elementos para manter o array ordenado após inserlçoes ou remoções

Deslocamento de memória
Para inserir o 27, deslocamos todos os numeros maiores um espaço para frente
|16|22|23|25|33|35|37|45|53|55|

Para remover o 22, deslocamos todos os numeros maiores para trás
|16|22|23|25|33|35|37|45|53|


Listas encadeadas

Lista linear em que a ordem lógica dos elementos não é a mesma da ordem física. Como é uma lista linear, cada elemento tem um sucessor e um predecessor.
Elementos estão espalhados na memória.
Cada elemento precisa indicar em que endereço o seu sucessor pode ser encontrado de modo a manter a ordem lógica.
Essa organização retira a grande vantagem das listas lineares sequenciasi, o acesso em tempo constante a qualquer elemento, dado indice do elemento.

lista enncadeada
Para encontrar um dado elemento na lista, precisamos percorrer todos os elementos predecessores, de um por um


Como consequencia, a busca binária deixa de fazer sentido, dado que não acessamos o elemento do meio de um array em tempo constante
    - A busca por uma chave pode exigir a comparação com todos os elementos da estrutura, mesmo com o array ordenado
Entretanto, esta nova estrutura possui vantages
    -numero de elementos pode aumentar ou diminuir durante a execução do programa
    - a manutenção da ordem lógica não exigirá deslocamento de elementos



Pilhas com listas encadeadas
Como pilhar são estruturas lineares, podemos implementa-las como listas encadeadas.
- O primeiro elemento a entrar na estrutura tem que ser o ultimo a sair. O ultimo elemento a entrar tem que ser o primeiro a sair.
- as inserções e remoções ocorrem na cabeça da pilha
- inserções e remoções devem ocorrer em tempo constante. Em outras palavras, independem do número de elementos na estrutura


Filas com listas encadeadas

como filas são estruturas lineares, podemos implementa-las como listas encadeadas.
- Estrutura de dadps e, que o primeiro elemento a entrar é o primeiro a sair
- se Pedro enviou um documento para a impressora antes de Paulo, então o documento de Pedro será impresso antes do documento de Paulo.
- Inserções e remoções devem ocorrer em tempo constante. Em outras palavras, independem do número de elementos na estrutura
*/

