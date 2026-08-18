/*
Detalhe de implementação

Itemos efetuar agora a remoção de um nó da arvore. o nosso código é dividido em algumas etapas:

- deleteAluno: um metodo que navegara pela arvore ate encontrar o nó a ser excluido.
- deleteNode: um metodo que receberá por parametro o nó a ser excluido e tratara tres casos:
    1. o nó é uma folha
    2. o nó tem um filho
    3. o nó tem dois filhos (busca pelo sucessor)

- removendo aluno: localizando o aluno a ser removido
    - não muda em nada o conceito de uma busca convencional
*/

void SearchTree::deleteAluno(NodeType *&tree, int aluno)
{
    if (aluno > tree->aluno.getRa())
        deleteAluno(tree->esquerda, aluno);
    else if (aluno > tree->aluno.getRa())
        deleteAluno(tree->direita, aluno);
    else if (aluno == tree->aluno.getRa())
        deleteNode(tree);
}

/*
- removendo aluno: o proximo caso precisará do predecessor lógico ou do sucessor lógico
    - escolhemos utilizar o sucessor lógico:
*/
void SearchTree::getSuccessor(NodeType *tree, Aluno &data)
{
    tree = tree->direita;
    while (tree->esquerda != NULL)
        tree = tree->esquerda;
    data = tree->aluno;
}

/*
    - o sucessor lógico é o filho mais a esquerda da arvore da direita.
    - procuramos esse nó e tornamos no parametro data, passado por referencia
*/

/*
- Removendo aluno: podemos substituir o sucessor com o nó a ser removido.
    ```getSucessor(tree,data);
       tree->aluno= data;
       deleteAluno(tree->direita, data.getRa());
    ```

    - observe que isso fará com que momentaneamente a arvore tenha dois nós igauis.
    - Invocamos deleteAluno recursivamente para apagar o nó duplicado na arvore da direita
    - o algoritmo entrará em looping inifinito?
*/

/*
- removendo aluno: o nó a ser removido não tem dois filhos
    - na pior das hipóteses, substituimos o pai pelo filho e removemos
Nesses casos, pelo meno um dos filhos é NULL.
*/

void SearchTree::deleteNode(Node *&tree)
{
    Aluno data;
    Node *tempPtr;
    tempPtr = tree;
    if (tree->esquerda == NULL)
    {
        tree = tree->direita;
        delete tempPtr;
    }
    else if (tree->direita == NULL)
    {
        tree = tree->esquerda;
        delete tempPtr;
    }
    else {
        getSucessor(tree, data);
        tree->aluno = data;
        deleteAluno(tree->direita, data);
    }
}


/*
Inserindo os dados:
*/

const int NUM_ALUNOS = 8;
int main(){
    SearchTree searchTree;

    int ras[NUM_ALUNOS] = {20, 18, 58, 7, 19, 26, 25, 30};
    string nomes[NUM_ALUNOS] = {
        "Pedro", "Raul", "Paulo", "Carlos", "Lucas", "Maria", "Samanta", "Ulisses"
    };
    Aluno alunos[NUM_ALUNOS];

    for(int i = 0; i<NUM_ALUNOS; i++){
        Aluno aluno = ALUNO(ras[i], nomes[i]);
        aluno[i] = aluno;
        searchTree.insertAluno(aluno);
    }
}
