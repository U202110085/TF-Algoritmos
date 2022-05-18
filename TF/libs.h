#pragma once
#include <iostream>
#include <conio.h>
#include <string>
#include <vector>
#include <functional>
#include <algorithm>
#include <stdlib.h>
#include<fstream>

using namespace std;

template <class T>
class Nodo
{
public:
    T valor;
    Nodo<T>* siguiente;

public:
    Nodo(T v, Nodo<T>* sig = NULL)
    {
        valor = v;
        siguiente = sig;
    }
};

template <class T>
class Lista
{
private:
    Nodo<T>* inicio;
    int longitud;

public:
    Lista() { inicio = NULL; };
    ~Lista() {};
    void AgregaralFinal(T v);
    void AgregaralInicio(T v);
    void AgregarenPosicion(T v, int pos);
    //void Mostrar(function<void(T)>);
    Nodo<T>* getHead() { return inicio; }
};

template <class T>
void Lista<T>::AgregaralInicio(T v)
{
    Nodo<T>* nuevo = new Nodo<T>(v);
    if (inicio == NULL)
    {
        inicio = nuevo;
        nuevo->siguiente = inicio;
    }
    else
    {
        nuevo->siguiente = inicio;
        inicio = nuevo;
    }
    longitud++;
}

template <class T>
void Lista<T>::AgregaralFinal(T v)
{
    Nodo<T>* nuevo;
    nuevo = new Nodo<T>(v);
    if (inicio == NULL)
    {
        AgregaralInicio(v);
        return;
    }
    else
    {
        Nodo<T>* aux = inicio;
        while (aux->siguiente != inicio)
        {
            aux = aux->siguiente;
        }
        aux->siguiente = nuevo;
        nuevo->siguiente = inicio;
    }
}

template <class T>
void Lista<T>::AgregarenPosicion(T v, int pos)
{
    Nodo<T>* nuevo;
    nuevo = new Nodo<T>(v);
    int i = 1;
    Nodo<T>* aux = inicio;
    while (i < pos)
    {
        aux = aux->siguiente;
        i++;
    }
    nuevo->siguiente = aux->siguiente;
    aux->siguiente = nuevo;
}

//esta funcion de seguro se usara para mostrar los datos
//aunq de forma menos generica, donde 'funcion'
//es lambda
// 
//template <class T>
//void Lista<T>::Mostrar(function<void(T)> funcion)
//{
//    Nodo<T>* aux = inicio;
//    while (aux->siguiente != inicio)
//    {
//        funcion();
//        aux = aux->siguiente;
//    }
//    aux->valor->toString();
//    cout << endl;
//}


// void mostar(lista<personas>listaP){
//      lista aux = personas;
//      cout << listaP->personas->nombre()
//      cout << listaP->personas->dni()
//      cout << listaP->personas->edad()
//      cout << endl;
//      aux = personas->sig;
//      if(aux==nullptr) return;
//      else mostrar(aux);
// }
//


template<typename T>
T getMax(vector<T>n) 
{
    T aux = n[0];
    for_each(n.begin(), n.end(), [&](T x) {aux = x > aux ? x : aux; });
    return aux;
}

template<typename T>
T getMin(vector<T>n) 
{
    T aux = n[0];
    for_each(n.begin(), n.end(), [&](T x) {aux = x < aux ? x : aux; });
    return aux;
}

template<typename T>
void printV(vector<T>n)
{
    for_each(n.begin(), n.end(), [](T x) {cout << x << " "; });
}

template<typename T>
T verifyData(T limitH, T limitL)
{
    T dato;
    cin >> dato;
    if (dato<limitL || dato>limitH) {
        cout << "Ingreso un dato equivocado";
        cout << "\nIngreselo de nuevo: ";
        return verifyData(limitH, limitL);
    }
    else return dato;
}