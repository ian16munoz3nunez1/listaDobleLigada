#ifndef LISTA_DOBLE_LIGADA_H
#define LISTA_DOBLE_LIGADA_H

#include<iostream>

using namespace std;

template<class I>
class ListaDobleLigada
{
    struct Nodo
    {
        I dato;
        Nodo *sig;
        Nodo *ant;

        Nodo(const I& dato, Nodo *sig = nullptr, Nodo *ant = nullptr)
        : dato(dato), sig(sig), ant(ant) {}
    };

    Nodo *head;
    Nodo *tail;
    size_t cont;

public:
    ListaDobleLigada();
    ~ListaDobleLigada();

    I* front();
    void pushFront(const I&);
    void popFront();

    I* back();
    void pushBack(const I&);
    void popBack();

    void print();
    void printReverse();
    size_t size();
    bool empty();

    ListaDobleLigada& operator<<(const I &dato)
    {
        pushBack(dato);

        return *this;
    }
};

template<class I>
ListaDobleLigada<I>::ListaDobleLigada()
{
    head = nullptr;
    tail = nullptr;
    cont = 0;
}

template<class I>
I* ListaDobleLigada<I>::front()
{
    if(empty())
        return nullptr;
    else
        return &head->dato;
}

template<class I>
void ListaDobleLigada<I>::pushFront(const I &dato)
{
    Nodo *nodo = new Nodo(dato, head);
    if(empty())
    {
        head = nodo;
        tail = nodo;
    }
    else
    {
        head->ant = nodo;
        head = nodo;
    }

    cont++;
}

template<class I>
void ListaDobleLigada<I>::popFront()
{
    if(empty())
    {
        cout << "Lista vacia" << endl << "No se puede eliminar al inicio" << endl;
        return;
    }
    else if(cont == 1)
    {
        delete head;
        head = nullptr;
        tail = nullptr;
        cont--;
    }
    else
    {
        Nodo *temp = head->sig;
        temp->ant = nullptr;
        delete head;
        head = temp;
        cont--;
    }
}

template<class I>
I* ListaDobleLigada<I>::back()
{
    if(empty())
        return nullptr;
    else
        return &tail->dato;
}

template<class I>
void ListaDobleLigada<I>::pushBack(const I &dato)
{
    Nodo *nodo = new Nodo(dato, nullptr, tail);
    if(empty())
    {
        head = nodo;
        tail = nodo;
    }
    else
    {
        tail->sig = nodo;
        tail = nodo;
    }

    cont++;
}

template<class I>
void ListaDobleLigada<I>::popBack()
{
    if(empty())
    {
        cout << "Lista vacia" << endl << "No se puede eliminar al final" << endl;
        return;
    }
    else if(cont == 1)
    {
        delete tail;
        head = nullptr;
        tail = nullptr;
        cont--;
    }
    else
    {
        Nodo *temp = tail->ant;
        temp->sig = nullptr;
        delete tail;
        tail = temp;

        cont--;
    }
}

template<class I>
void ListaDobleLigada<I>::print()
{
    Nodo *temp = head;
    while(temp != nullptr)
    {
        cout << temp->dato << endl;
        temp = temp->sig;
    }
}

template<class I>
void ListaDobleLigada<I>::printReverse()
{
    Nodo *temp = tail;
    while(temp != nullptr)
    {
        cout << temp->dato << endl;
        temp = temp->ant;
    }
}

template<class I>
size_t ListaDobleLigada<I>::size()
{
    return cont;
}

template<class I>
bool ListaDobleLigada<I>::empty()
{
    return cont == 0;
}

template<class I>
ListaDobleLigada<I>::~ListaDobleLigada()
{
    while(!empty())
    {
        popFront();
    }
}

#endif//LISTA_DOBLE_LIGADA_H
