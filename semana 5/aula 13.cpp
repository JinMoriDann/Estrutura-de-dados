//Arvores
/*
Conceitos básicos

Uma arvore é um conjunbto de nós em que existe um nó raiz r, que contém zero ou mais subarvores cuja raizes são ligadas diretamente a r
 - Uma subarvore é também um arvore
Uma arvore não é uma estrutura linear, não há no máximo um sucessor por nó
 - são adequadas para representar hierarquia nos dados
 grau de um nó: numero de subarvores desse nó
 no folha: nó de garu 0 (zero)
 nó interno: nó de garu maior que 0 (zero)
 descedentes: nós abaixo de um determinado nó


Altura de um nó: comprimento do caminho main longo entre o nó até uma folha
Altura da arvire: altura do nó raiz
profundidade de um nó: distância percorrida da raiz até o nó
arvore binária: arvore em que abaixo de cada nó existem no máximo duas aubarvores

*/

/*
Arvore binária de busca

arvore binaria em que, a cada nó, todos os registros com chaves menores que a deste nó estão na subarvore da esquerda, enquanto que os registros com chaves maiores estão na subarvore da direita

inserções, remoções e buscas possuem numero de comparações proproncional a altura da arvore

*buscas em arvore binarias de busca

se chave igual a nó, então achamos. se chave maior que nó, pesquisamos na subarvore da direita. caso contrário, na esquerda. se alcançarmos um nó nulo, então paramos.

*inserção em artvore binárias de busca

supondo que não permitimos diplicação na arvore, inserimos apenas se o elemento não existe. Nesse caso, basta inserir o elemento na posição que ele estaria se fosse buscado.

*remoção em arvores binarias de busca

se o nó a ser removida não possui filhos, simplesmente remova
se o nó possui um filho, rentão remova e coloque o filho no lugar
se o nó possui mais de um filho?
- opção 1: se o nó possui mais de um filho, então substitua pelo sucessor lógico antes de remover. o sucessor lógico é sempre o elemento mais a esquerda na subarvore da direita  
- opção 2: se o nó possui mais de um filho, então substitua pelo antecessor (ou predecessor) lóigco antes de remover. o predecessor lógico é sempre o elemento mais a direita na subarvore da esquerda

Nos algoritmos de busca, inserção e remoçar, no pior caso, o numero dde comparações é proporcional á altura da arvore. 
- as buscas são eficientes em arvores balanceadas.
- em arvores degeneradas, as operações deixam de ser eficientes
(em uma próxima aula, veremos como garantir que uma arvore binaria de busca se mantenha balanceada)


Percursos

em muitos algortmos, precisamo percorrer os nós de maneira sistemática, visitando cada nó apenas uma vez
existem tres tipos de percursos mais comuns em arvores binarias:
- pre-ordem
- pos-ordem
- in-ordem

a difreneça entre os caminhamentos se refere ao momemntoo em que visitamos o nó central
- sempre visitamos a subarvores da esquerda antes de visistarmos a subarvore da direita.
- pre-rodem: visitamos a partir da raiz, primeiramente o nó raiz, depois os nós da esquerda, depois os da direita
- pos-ordem: visitamos a partir da raiz, primeiramente o nó da esquerda, depois os nós da direita e depois concluimos visitando o nós da raiz
- in-rodem: visitamos a partir da raizm primeiramente os nós da esquerda, depois visitamos o nó raiz e depois concluimos visitando os nós da direita

*/