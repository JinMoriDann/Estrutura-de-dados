// Fila (list encadeada)
/*
Estrutura do nó
Mesma da aula passada

typedef char ItemType;
/Estrutura usada para guarda a informação e o endereço do próximo elemento/
struct NodeType
{
    ItemType info;
    NodeType* next;
}

*/

/*
Tipo abstrato de dados
*/

class Queue
{
public:
    Queue();
    ~Queue();
    bool isEmpty() const;
    bool isFull() const;
    void print() const;

    void enqueue(ItemType);
    ItemType dequeue();

private:
    NodeType *front;
    NodeType *rear;
};
/*
Não mudaremos a interface pública
Mudaremos a implementação interna
*/

/*
Detalhe de implementação

Implementaremos uma fila como lista encadeada.
Deois ponteiros front e rear apontarão para início da fila, respectivamente.
Queremos que inserções e remoções ocorram em tempo constante. Em outras palavras, independem do número de elementos na estrutura.
*/

/*
Implementando as ideias da aula passada
- Construtor e destrutor
*/

Queue::Queue()
{
    front = NULL;
    rear = NULL;
}

Queue::~Queue()
{
    NodeType *tempPtr;
    while (front != NULL)
    {
        tempPtr = front;
        front = front->next;
        delete temPtr;
    }
    rear = NULL;
}

/*
- Verificação de cheio ou vazio
*/

bool Queue::isFull() const
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

bool Queue::isEmpty() const
{
    return (front == NULL);
}

/*
- Inserindo elementos
*/

void Queue::enqueue(ItemType newItem)
{
    if (!isFull())
    {
        NodeType *newNode;
        newNode = new NodeType;

        newNode->info = newItem;
        newNode->next = NULL;
        if (rear == NULL)
            front = newNode;
        else
            rear->next = newNode.rear = newNode;
    }
    else
    {
        throw "Queue is already full!";
    }
}

/*
- Removendo elementos
*/

ItemType Queue::dequeue()
{
    if (!isEmpty())
    {
        NodeType *tempPtr;
        temPtr = front;
        ItemType item = front->info;
        front = front->next;
        if (front == NULL)
            rear = NULL;
        delete tempPtr;
        return item;
    }
    else
    {
        throw "Queue is empty!";
    }
}

/*
- imprimindo a lista na saída padrão
*/

void Queue::print() const
{
    NodeType *tempPtr = front;
    while (tempPtr != NULL)
    {
        cout << tempPtr->info;
        tempPtr = tempPtr->next;
    }
    cout << endl;
}

/*
Usar a estrutura se assemelha ao anterior:
*/
char character;
Queue queue;
char queueChar;
cout << "Enter a string; press return." << endl;
cin.get(character);
while (character != '\n' and !queue.isFull())
{
    queue.enqueue(character);
    cin.get(character);
}
while (!queue.isEmpty())
{
    queueChar = queue.dequeue();
    cout << queueChar;
}
cout << endl;

/*
Aplicações da Estrutura

Uma fila é uma estrutura bastnate util, preincipalmente quando precisamos garantir que processos acessarão recursos compartilhados de uma maneira justa.
    - Documentos enciado para a impressão.
    - Troca de mensagens entre processos em um OS
- Para exercitar o uso de uma fila, trataremos do problema de verificar se uma string é um ppalindrome.

Uma string é um palíndrome se:
- contém zero ou mais caracteres.
- a leitura da tring de trás para frente e de frente para trás é a mesma.

Exemplos:
- ovo
- missa e assim
- arara

*/

int main()
{
    bool palindrome = true;

    char character;
    char stackChar;
    char queueChar;

    Stack stack;
    Queue queue;
    cout << "Adicione uma string." << endl;
    cin.get(character);
    while (character != '\n')
    {
        stack.push(character);
        queue.enqueue(character);
        cin.get(character);
    }
    while (palindrome && !queue.isEmpty())
    {
        stackChar = stack.pop();
        queueChar = queue.dequeue();
        if (stackChar != queueChar)
        {
            palindrome = false;
        }
    }
    if (palindrome)
    {
        cout << "String é palindrome" << endl;
    }
    else
    {
        cout << "String não é palindrome" << endl;
    }
    return 0;
}