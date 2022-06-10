#pragma once
#include <iostream>
#include <conio.h>
#include <string>
#include <vector>
#include <functional>
#include <algorithm>
#include <stdlib.h>
#include <fstream>

using namespace std;

//.....:::::INICIO NODO:::::.....
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
    Nodo(Nodo* temp) {
        this->valor = temp->valor;
        this->siguiente = temp->siguiente;
    }
};
//.....:::::FIN NODO:::::.....

//.....:::::INICIO LISTA:::::.....
template <class T>
class Lista
{
private:
    Nodo<T>* inicio;
    int longitud;

public:
    Lista() { inicio = NULL; longitud = 0; };
    ~Lista();
    void push_front(T v);
    void push_back(T v);
    T obtenerPos(int pos);
    int obtenerLongitud();
    void print();
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
void Lista<T>::push_front(T v)
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
void Lista<T>::push_back(T v)
{

    if (inicio == NULL)
        push_front(v);
    else {
        Nodo<T>* aux = inicio;
        for (int i = 0; i < longitud - 1; i++) aux = aux->siguiente;
        Nodo<T>* nuevo = new Nodo<T>(v, aux->siguiente);
        aux->siguiente = nuevo;
        longitud++;
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
template <class T> // Uso de una funcion lambda
void Lista<T>::print()
{
    function<void(T)> funcion = [](T x) {cout << x << " "; };
    if (inicio != NULL)
    {
        Nodo<T>* temp = new Nodo<T>(inicio);
        while (temp != NULL)
        {
            funcion(temp->valor);
            temp = temp->siguiente;
        }
        cout << endl;
    }
    else cout << "No hay datos en la pila\n";
}
//.....:::::FIN LISTA:::::.....

//.....:::::INICIO PILA:::::.....
template <class T>
class Pila //en ingles se conoce como stack
{
private:
    Nodo<T>* inicio;
    int longitud;

public:
    Pila() { inicio = NULL; };
    ~Pila() {};
    void push(T v);
    T pop();
    Nodo<T>* getHead() { return inicio; }
    void print();
};
template<class T>
void Pila<T>::push(T v)
{
    Nodo<T>* nuevo = new Nodo<T>(v);
    if (inicio == NULL)
    {
        inicio = nuevo;
    }
    else
    {
        nuevo->siguiente = inicio;
        inicio = nuevo;
    }
    longitud++;
}
template<class T>
T Pila<T>::pop()
{
    T aux = inicio->valor;
	inicio = inicio->siguiente;
	longitud--;
	return aux;
}
template<class T> // Uso de una funcion lambda
void Pila<T>::print()
{
    function<void(T)> funcion = [](T x) {cout << x << " "; };
    if (inicio != NULL)
    {
        Nodo<T>* temp = new Nodo<T>(inicio);
        while (temp != NULL)
        {
			funcion(temp->valor);
            temp = temp->siguiente;
        }
        cout << endl;
    }
    else cout << "No hay datos en la pila\n";
}
//.....:::::FIN PILA:::::.....

//.....:::::FUNCIONES EXTRA:::::.....
// Uso de 3 funciones lambda
// Uso de 1 funcion recursiva
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
