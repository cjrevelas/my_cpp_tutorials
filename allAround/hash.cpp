#include <iostream>
#include <list>

class HashTable{
 private:
  int capacity;
  std::list<int> *table; // Array of lists -- declaration

 public:
  HashTable(int V);

  void insertItem(int key, int data);

  void deleteItem(int key);

  int checkPrime(int nn) {
    if (nn == 1 || nn == 0) { return 0; }

    for (int ii=2; ii<nn/2; ii++) {
      if (nn % ii == 0) { return 0; }
    }

    return 1;
  }

  int getPrime(int nn){
    if (nn % 2 == 0) { ++nn; }

    while (!checkPrime(nn)) { nn += 2; }

    return nn;
  }

  int hashFunction(int key) { return (key % capacity); }

  void displayHash();
};

HashTable::HashTable(int cc) {
  int size = getPrime(cc); //=7
  this->capacity = size;
  table = new std::list<int>[capacity]; // Array of lists -- definition
}

void HashTable::insertItem(int key, int data) {
  int index = hashFunction(key);
  table[index].push_back(data);
}

void HashTable::deleteItem(int key){
  int index = hashFunction(key); //=5

  std::list<int>::iterator ii;
  for (ii=table[index].begin(); ii!=table[index].end(); ++ii) {
    if (*ii == key) {
      break;
    }
  }

  if (ii!=table[index].end()) {
    table[index].erase(ii);
  }
}

void HashTable::displayHash(){
  for (int ii = 0; ii < capacity; ++ii){
    std::cout << "table[" << ii << "]";
    for (auto xx : table[ii]){
      std::cout << " --> " << xx;
    }
    std::cout << '\n';
  }
}

int main(){
  int key[]  = {231, 321, 212, 321, 433, 262};
  int data[] = {123, 432, 523, 43, 423, 111};
  int size   = sizeof(key) / sizeof(key[0]);

  HashTable hh(size);

  for (int ii = 0; ii < size; ++ii){
    hh.insertItem(key[ii], data[ii]);
  }

  hh.displayHash();
  std::cout << "==================================================\n";
  hh.deleteItem(12);
  hh.displayHash();

  return 0;
}
