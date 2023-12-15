#pragma once
#include <fstream>
#include <iostream>
#include <string>

namespace hash {
    class Hash {
    private:
        int N = 20;
        std::string* hashtable; // Хэш-таблица

    public:
        Hash() {
            hashtable = new std::string[N];
            for (int i = 0; i < N; i++) //Зануляем значения Хэш-таблицы
                hashtable[i] = "";
        }

        ~Hash() {
            if (hashtable != nullptr)
                delete[] hashtable;
        }

        int HashFunc(std::string str) { //Хэш-функция
            int index = 0;
            for (char a : str)
                index += (int)a;
            index = index % N;
            return index;
        }

        void Probing(int* index) {
            (*index)++;
            if (*index >= N) {
                *index = 0;
            }
        }

        void Duplicate() {
            auto* newTable = new std::string[2 * N];
            for (int i = 0; i < N; ++i) {
                newTable[i] = hashtable[i];
            }
            delete[] hashtable;
            hashtable = newTable;
            N *= 2;
        }

        void HashTable(const std::string& inputFile = "input.txt") {
            std::ifstream file(inputFile);
            if (!file) {
                std::cerr << "Error opening input file!" << std::endl;
                return;
            }

            std::string word;
            while (file >> word) {
                if (word != "") {
                    int index = HashFunc(word);
                    while (hashtable[index] != "")
                        Probing(&index);
                    hashtable[index] = word;
                }

                if (std::distance(hashtable, std::find(hashtable, hashtable + N, "")) < 1)
                    Duplicate();
            }
        }

        void out(const std::string& outputFile = "output.txt") {
            std::ofstream out(outputFile);
            if (!out) {
                std::cerr << "Error opening output file!" << std::endl;
                return;
            }

            for (int i = 0; i < N; i++) {
                if (hashtable[i] != "")
                    out << i << '-' << hashtable[i] << std::endl;
            }
        }
    };
}
