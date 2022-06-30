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

    void pushFront(const I&);

    void pushBack(const I&);

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
}

#endif//LISTA_DOBLE_LIGADA_H
