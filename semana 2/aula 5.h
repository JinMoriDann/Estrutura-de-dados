typedef char ItemType; // itemType é meio que um apelido pra char

const int MAX_ITEMS = 100;

// Tipo abstrato de dados
class Stack {
public:
  Stack();  // construtor
  ~Stack(); // destrutor
  bool isEmpty() const;
  bool isFull() const;
  void print() const;

  void push(ItemType);
  ItemType pop();

private:
  int lenght;
  ItemType *structure;
  int top;
};