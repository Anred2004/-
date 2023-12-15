#include <iostream>
#include "HashFunc.h"
#include <cstdlib>
#include <fstream>

int main() {
    hash::Hash hashTable;

    // Генерация хеш-таблиц
    hashTable.HashTable("input.txt");
    hashTable.out("output.txt");

    return 0;
}
