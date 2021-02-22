#include <iostream>
#include <list>

class HashTable{
private:
    int capacity;
    std::list<int> *table; //this is an array of lists -- declaration

public:
    HashTable(int V);

    void insertItem(int key, int data);

    void deleteItem(int key);

    int checkPrime(int n){
        if (n == 1 || n == 0){return 0;}
        for (int i = 2; i < n / 2; i++){
            if (n % i == 0){return 0;}
        }
        return 1;
    }

    int getPrime(int n){
        if (n % 2 == 0){n++;}
        while (!checkPrime(n)){n += 2;}
        return n;
    }

    int hashFunction(int key){return (key % capacity);}

    void displayHash();
};

HashTable::HashTable(int c){
    int size = getPrime(c); //=7
    this->capacity = size;
    table = new std::list<int>[capacity]; //this is an array of lists -- definition
}

void HashTable::insertItem(int key, int data){
    int index = hashFunction(key);
    table[index].push_back(data);
}

void HashTable::deleteItem(int key){
    int index = hashFunction(key); //=5

    std::list<int>::iterator i;
    for (i=table[index].begin(); i!=table[index].end(); i++){
        if (*i == key){break;}
    }
    //std::cout << "key to be erased: " << *i << std::endl;
    if (i!=table[index].end()){table[index].erase(i);}
}

void HashTable::displayHash(){
    for (int i = 0; i < capacity; i++){
        std::cout << "table[" << i << "]";
        for (auto x : table[i]){
            std::cout << " --> " << x;
        }
        std::cout << std::endl;
    }
}

int main(){
    int key[] = {231, 321, 212, 321, 433, 262};
    int data[] = {123, 432, 523, 43, 423, 111};
    int size = sizeof(key) / sizeof(key[0]);

    HashTable h(size);

    for (int i = 0; i < size; i++){
        h.insertItem(key[i], data[i]);
    }


    h.displayHash();
    std::cout << "==================================================\n";
    h.deleteItem(12);
    h.displayHash();

    return 0;
}
