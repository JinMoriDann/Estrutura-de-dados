// Tabela hash (implementação)
/*
Aplicações da estrutura
podemos utilizar as tabelas hahs sempre que queremos armazenar uma coleção de dados para depois obter os registros de maneira eficiente

se a função de hash foi bem estruturada, conseguiremos inserir e obter os valores em tempo constante
vamos supor que queremos organizar alunos em uma estrutura e posteriormente, fazer buscas pelo registro academico (ra)
- a unica informação que queremos é o nome
*/

class Aluno
{
private:
    int ra;
    std::string nome;

public:
    Aluno(); // vai ser usado para alocação dinamica na memória
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
Tipo abstrato de dados
criaremos uma estrutura minimalista, apenas com busca, inserção e remoção.
*/

class Hash
{
public:
    Hash(int max_items = 100);
    ~Hash();
    bool isFull() const;
    int getLenght() const;

    void retrieveItem(Aluno &aluno, bool &found);
    void insertItem(Aluno aluno);
    void deleteItem(Aluno aluno);
    void print();

private:
    int getHash(Aluno aluno);
    int max_items;
    int lenght;
    Aluno *structure;
};

using namespace std;

Hash::Hash(int max)
{
    lenght = 0;
    max_items = max;
    structure = new Aluno[max_items];
}

Hash::~Hash()
{
    delete[] structure;
}

bool Hash::isFull() const
{
    return (lenght == max_items);
}

int Hash::getLenght() const
{
    return lenght;
}

void Hash::retrieveItem(Aluno &aluno, bool &found)
{
    int location = getHash(aluno);
    Aluno aux = structure[location];
    if (aluno.getRa() != aux.getRa())
    {
        found = false;
    }
    else
    {
        found = true;
        aluno = aux;
    }
}

void Hash::print()
{
    for (int i = 0; i < max_items; i++)
    {
        cout << i << : << structure[i].getRa << ", " << structure[i].getNome() << endl;
    }
}

int Hash::getHash(Aluno aluno)
{
    return aluno.getRa() % max_items;
}

void Hash::retrieveItem(Aluno &aluno, bool &found)
{
    int location = getHash(aluno);
    Aluno aux = structure[location];
    if (aluno.getRa() != aux.getRa())
    {
        found = false;
    }
    else
    {
        found = true;
        aluno = aux;
    }
}

void Hash::insertItem(Aluno aluno)
{
    int location = getHash(aluno);
    structure[location] = aluno;
    lenght++;
}

void Hash::deleteItem(Aluno aluno)
{
    int location = getHash(aluno);
    structure[location] = Aluno();
    lenght--;
}

void Hash::print()
{
    for (int i = 0; i < max_items; i++)
    {
        cout << i << ":" << structure[i].getRa() << ", " << structure[i].getNome() << endl;
    }
}


// Abaixo segue exemplo exemplo de uso

int main(){
    Hash alunosHash(10);
        int ras[7] = {
            12704, 31300, 1234,
            49001, 52202, 65606,
            91234
        };
        string nomes[7] = {
            "Pedro", "Raul", "Paulo",
            "Carlos", "Lucas", "Maria",
            "Samanta"
        };

        for (int i = 0; i< 7; i++){
            Aluno aluno = Aluno(ras[i], nomes [i]);
            alunosHash.insertItem(aluno);
        }
        alunosHash.print();
        cout << "-----------------------------------------------" << endl;

        Aluno aluno(12704, "");
        bool found = false;
        alunosHash.retrieveItem(aluno, found);
        cout << aluno.getNome () << "->" << found << endl;
        cout << "-----------------------------------------------" << endl;
        alunosHash.deleteItem(aluno);
        alunosHash.print();
}