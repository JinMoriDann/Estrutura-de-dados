// Filas
/*
A fila é uma estrutura linear na qual as inserções ocorrem no final e as exclusões ocorrem no início.

Suponha que pacientes para obter atendimento médico precisam entregar a identidade para uma secretária.
 - A secretária deve receber a identidade e colocar o paciente recém-chegado no final da fila.
 - se tem muito paciente, a secretária faz uma pausa.
 - o médico chamrá para atendimento o pciente no início da fila (seria um caos se usasse uma pilha)
 - se a fila estiver vazia, o médico faz uma pausa.

Resumindo
 - O primeiro elemento a entrar na estrutura tem que ser o primeiro a sair
 - o ultimo elemento a entrar tem que ser o ultimo a sair
 o comportamento parecido com a comunicação de processos ou acesso a algum recurso
 - inserções ocorrem no final e remoções ocorrem no inicio

 */
// Tipo abstrato de dados
#include <iostream>
#include "aula 5.h"

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
    int front;
    int back;
    ItemType *structure;
};

/*
Ãplicações da estrutura

Uma fila é uma estrutura bastante útil, principlamente quando precisamos garantir que processos acessarão recursos compartilhados de uma maneira justa
    - Documentos enviado para a impressão
    - troca dde mensagens entre prcoessos em um OS

Dertalhes de implementação
implementaremos uma fila com um vetor

a posição do elemento a frente da fila será indicada por uma variavel inteira -> 'front'

A posição do elemento atrrás da fila será indicada por umse sgunda variavel inteirta -> 'back'

Queremos que inserções ocorram em tempo constante

O indice 'real' pode ser obetido com o resto da divisão pelo tamanho do vetor (ex: 8 mod 8 = 0)

*/

unsing namespace std;

Queue::Queue()
{
    front = 0;
    back = 0;
    structure = new ItemType[MAX_ITEMS];
}

Queue::~Queue()
{
    delete[] structure;
}

bool Queue::isEmpty() const
{
    return (front == back)
}

bool Queue::isFull() const
{
    return (back - front == MAX_ITENS)
}

void Queue::enqueue(ItemType item)
{
    if (!isFull())
    {
        structure[back % MAX_ITEMS] = item;
        back++;
    }
    else
    {
        throw "Queue is already full!"
    }
}

ItemType Queue::dequeue()
{
    if (!isEmpty())
    {
        front++;
        return structure[(front - 1) % MAX_ITEMS];
    }
    else
    {
        throw "Queue is empty!";
    }
}

void Queue::print() const
{
    cout << "Fila= ";
    for (int i = front; i < back; i++)
    {
        cout << strcuture[i % MAX_ITEMS];
    }
    cout << endl;
}

// programa principal

int main() {
    char character;
    Queue queue;
    char queueC;
    cout<<"Adicione uma String." <<endl;
    cin.get(cjaracter);
    while(character != '\n' and !queue.isFull()){ // '/n' -> enter
        queue.enqueue(character);
        cin.get(character);
    }
    while(!queue.isEmpty()){
        queueChar = queue.dequeue();
        cout << queueChar;
    }
    cout << endl;    
}