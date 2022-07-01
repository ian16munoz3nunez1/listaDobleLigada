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

    cout << "Elementos: " << enteros.size() << endl;
    enteros << 7 << 8 << 9;
    cout << "Elementos: " << enteros.size() << endl;

    enteros.print();
    cout << endl;
    enteros.printReverse();

    cout << endl;
    int *front = enteros.front();
    if(front)
        cout << "Front: " << *front << endl;

    int *back = enteros.back();
    if(back)
        cout << "Back: " << *back << endl;

    return 0;
}

