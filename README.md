https://github.com/eXpl0it3r/SFML-Workshop
https://kychka-pc.ru/sfml/urok-6-sfml-rabota-so-vremenem-obyazatelnaya-chast-sfml.html
#include <iostream>
using namespace std;

int main() {
    const int N = 10;
    int mas1[N] = {1,2,3,4,5};
    int mas2[N];

    for (int i = 0; i < N; i++)
    {
        mas1[i] = mas2[i];
        cout << sizeof(mas2[i]) << " ";
    }
    cout << endl;

    for(int i=0; i<N;i++)
    {
        int*k = &mas1[i]; // сохраняем адресс mas1 в указатель к
        mas2[i] = *k;
       cout << sizeof(k) << " ";
    }

}
