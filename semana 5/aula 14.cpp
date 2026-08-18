// Arvores implementação]
/*
Aplicações da estrutura

arvores binárias de busca são estruturas fundamentais usadas para construir outras estruturas
em geral, podem ser usadas em qualquer situação em que queremos organizar os dados por meio de uma chave usada nas buscas
- quando inserções e remoções são frequentes, são melhores que vetores ordenados.

vamos supor que equeremos organizar alunos em uma estrutura e posteriormente fazer buscas pelo registro academico (RA).
- a unica informação que queremos é o nome
*/
class Aluno
{
private:
    int ra;
    std::string nome;

public:
    Aluno();
    Aluno(int ra, std::string nome);
    string getNome() const;
    int getRa() const;
}

Aluno::Aluno()
{
    this->ra = -1;
    this->nome = "";
}

Aluno::Aluno(int ra, std::string nome)
{
    this->ra = ra;
    this->nome = nome;
}

string Aluno::getNome() const
{
    return nome;
}

int Aluno::getRa() const
{
    return ra;
}

/*
Estrutura do nó
contém os dados e os endereços das subarvores

estrutura usada para guardar a informação e os endereços das subarvores
*/

struct NodeType
{
    Aluno aluno;
    NodeType *esquerda;
    NodeType *direita;
};

/*
Tipo abstrato de dados

interface publica invocando metodos recrusivos privados
*/

class SearchTree
{
public:
    SearchTree() { root = NUll; }
    ~SearchTree() { destroyTree(root); };
    bool isEmpty() const;
    bool isFull() const;
    void retrieveAluno(Aluno &item, bool &found) const
    {
        retrieveAluno(root, item, found);
    };
    void insertAluno(Aluno item) { insertAluno(root, item); };
    void deleteAluno(Aluno item) { deleteAluno(root, item); };
    void printPreOrder() const { printPreOrder(root) };
    void printInOrder() const { printInOrder(root) };
    void printPosOrder() const { printPosOrder(root) };

private:
    void destroyTree(NodeType *&tree);
    void retrieveAluno(NodeType *tree, Aluno &item, bool &found) const;
    void insertAluno(NodeType *&tree, Aluno item);
    void deleteAluno(NodeType *&tree, int item);
    void deleteNode(NodeType *&tree);
    void getSucessor(NodeType *tree Aluno &data);
    void printTree(NodeType *tree) const;
    void printPreOrder(NodeType *tree) const;
    void printInOrder(NodeType *tree) const;
    void printPosOrder(NodeType *tree) const;
    // Raiz da arvore binaria de busca
    NodeType *root;
};

/*
Detalhes de implementação
o metodo destrouTree efetua um caminhamento pós-ordem:
*/
void SearchTree::destroyTree(NodeType *&tree)
{
    if (tree != NULL)
    {
        destroyTree(tree->esquerda);
        destroyTree(tree->direita);
        delete tree;
    }
}

/*
Verificação de cheio ou vazio
*/

bool SearchTree::isEmpty() const
{
    return root == NULL;
}

bool SearchTree::isFull() const
{
    NodeType *location;
    try
    {
        location = new NodeType;
        delete location;
        return false;
    }
    catch (std::bad_alloc exception)
    {
        return true;
    }
}

/*
implementando as ideias da aula passada

- buscando aluno
*/
void SearchTree::retrieveAluno(NodeType *tree, Aluno &aluno, bool &found) const
{
    if (tree == NULL)
        found = false;
    else if (aluno.getRa() < tree->aluno.getRa())
        retrieveAluno(tree->esquerda, aluno, found);
    else if (aluno.getRa() > tree->aluno.getRa())
        retrieveAluno(tree->direita, aluno, found);
    else
    {
        aluno = tree->aluno;
        found = true;
    }
}

/*
- inserindo aluno
*/

void SearchTree::insertAluno(NodeType *&tree, Aluno aluno)
{
    if (tree == NULL)
    {
        tree = new NodeType;
        tree->direita = NULL;
        tree->esquerda = NULL;
        tree->aluno = aluno;
    }
    else if (aluno.getRa() < tree->aluno.getRa())
        insertAluno(tree->esquerda, aluno);
    else
        insertAluno(tree->direita, aluno);
}

/*
- imprimindo a lista na saída padrão
*/

void SearchTree::printPreOrder(NodeType* tree) const {
    if (tree != NULL){
        std::cout << tree->aluno.getNome() << ",";
        printPreOrder(tree->esquerda);
        printPreOrder(tree->direita);
    }
}


void SearchTree::printInOrder(NodeType* tree) const {
    if (tree != NULL){
        printPreOrder(tree->esquerda);
        std::cout << tree->aluno.getNome() << ",";
        printPreOrder(tree->direita);
    }
}


void SearchTree::printPosOrder(NodeType* tree) const {
    if (tree != NULL){
        printPreOrder(tree->esquerda);
        printPreOrder(tree->direita);
        std::cout << tree->aluno.getNome() << ",";
    }
}