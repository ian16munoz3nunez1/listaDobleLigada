#include<iostream>
#include"listaDobleLigada.h"

using namespace std;

int main()
{
    ListaDobleLigada<int> enteros;

    enteros.pushFront(3);
    enteros.pushFront(2);
    enteros.pushFront(1);

    enteros.pushBack(4);
    enteros.pushBack(5);
    enteros.pushBack(6);

    enteros << 7 << 8 << 9;
    enteros.print();
    cout << "Elementos: " << enteros.size() << endl;

    enteros.insert(16, 4);
    enteros.insert(24, 8);
    enteros.print();
    cout << "Elementos: " << enteros.size() << endl;

    enteros.erase(10);
    enteros.erase(7);
    enteros.print();
    cout << "Elementos: " << enteros.size() << endl;

    enteros.~ListaDobleLigada();
    cout << "Elementos: " << enteros.size() << endl;

    return 0;
}

