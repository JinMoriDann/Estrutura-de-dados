// Pilha (Lista encadeada)

/*
Estrutura do Nó
contém os dados e o endereço do sucessor na lista
typedef char ItemType;
/Estrutura usada para guarda a informação e o endereço do próximo elemento/
struct NodeType
{
    ItemType info;
    NodeType* next;
}

struct -> estrutura que vai ajudar a unir variaveis em uma unica região de memória, no caso acima, junta o valor inf, mais o endereço do proximo item.

COm essa estrutura é possivel iniciar o encadeamento

Note que basta armazenarmos um único ponteiro, aquele que aponta para o início da estrutura

Como todas as operações ocorrem na cabeça da pilha, conseguiremos efetuar em tempo constante
*/

/*
Tipo abstrato de dados
*/
class Stack{
    public:
        Stack(); //construtor
        ~Stack(); // destrutor
        bool isEmpty() const;
        bool isFull() const;
        void print () const;

        void push(ItemType);
        ItemType pop();
    private:
        NodeType* structure;
};
/*
Não mudaremos a interface pública

Mudaremos a implementação interna
*/

/*
Detalhe de implementação

Implementaremos uma pilha como lista encadeada.
O ponteiro structure sempre apontará para o elemento que está no topo da pilha.
Quertemos quee inserções e remoções ocorram em tempo constante. Em outras palavras, independem do número de elementos na estrutura.

*/
/*
Implementando as ideias da aula passada:
- Construtor e destrutor
*/

Stack::Stack(){
    structure = NULL;
}

Stack::~Stack(){
    NodeType* tempPtr;
    while (structure != NULL){
        temPtr = structure;
        structure = structure -> next; // a seta é para conseguir acessar o atributo de um ponteiro
        delete tempPtr;
    }
}

/*
- Verificação de cheio ou vazio
*/

bool Stack::isEmpty() const {
    return (structure == NULL);
};

bool Stack::isFull() const {
    NodeType* location;
    try {
        location = new NodeType;
        delete location;
        return false;
    } catch(std::bad_alloc exeption){
        return true;
    }
}

// parei em 12:20