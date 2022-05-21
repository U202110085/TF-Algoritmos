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

template<class T>
class Nodo
{
public:
    T valor;
    Nodo* siguiente;
    Nodo(T v, Nodo* sig = NULL) {
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
    Lista() { inicio = NULL; longitud = 0; };
    ~Lista();
    void insertarInicio(T v);
    void insertarFinal(T v);
    T obtenerPos(int pos);
    int obtenerLongitud();
};

template<class T>
Lista<T>::~Lista()
{
    Nodo<T>* temp;
    while (inicio != NULL) {
        temp = inicio;
        inicio = inicio->siguiente;
        delete temp;
        temp = NULL;
    }
    delete inicio;
    inicio = NULL;
}

template<class T>
void Lista<T>::insertarInicio(T v)
{
    Nodo<T>* nodo = new Nodo<T>(v);

    if (inicio == NULL)
        inicio = nodo;
    else {
        nodo->siguiente = inicio;
    }
    inicio = nodo;
    //delete nodo;
    nodo = NULL;
    longitud++;

}

template<class T>
void Lista<T>::insertarFinal(T v)
{

    if (inicio == NULL)
        insertarInicio(v);
    else {
        Nodo<T>* aux = inicio;
        for (int i = 0; i < longitud - 1; i++) aux = aux->siguiente;
        Nodo<T>* nuevo = new Nodo<T>(v, aux->siguiente);
        aux->siguiente = nuevo;
        longitud++;
        //CODIGO ORIGINAL: nose de q sirve el if
        /*if (nuevo != nullptr) {
            aux->sig = nuevo;
            longitud++;
        }*/
    }

}

template<class T>
T Lista<T>::obtenerPos(int pos)
{
    if (pos >= 0 && pos < longitud) {
        Nodo<T>* aux = inicio;
        for (int i = 0; i < pos; i++) {
            aux = aux->siguiente;
        }
        return aux->valor;
    }
    return T{};
}

template<class T>
int Lista<T>::obtenerLongitud()
{
    return longitud;
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
    T dato{};
    cin >> dato;
    if (dato<limitL || dato>limitH) {
        cout << "Ingreso un dato equivocado";
        cout << "\nIngreselo de nuevo: ";
        return verifyData(limitH, limitL);
    }
    else return dato;
}


template <class T>
class Pila
{
private:
    Nodo<T>* inicio;
    int longitud;

public:
    Pila() { inicio = NULL; };
    ~Pila() {};
    void AgregaralFinal(T v);
    void AgregaralInicio(T v);
    void AgregarenPosicion(T v, int pos);
    Nodo<T>* getHead() { return inicio; }
};

template<class T>
void Pila<T>::AgregaralFinal(T v)
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