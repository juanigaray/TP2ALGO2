#include "Nodo.h"

template<class T> Nodo<T>::Nodo(T dato){
    this->dato = dato;
    this->siguiente = NULL;
}

template<class T> void Nodo<T>::cambiarDato(T datoNuevo){
    this->dato = datoNuevo;
}

template<class T> void Nodo<T>::cambiarSiguiente(Nodo<T> *siguienteNuevo){
    this->siguiente = siguienteNuevo;
}

template<class T> T Nodo<T>::obtenerDato(){
    return this->dato;
}

template<class T> Nodo<T>* Nodo<T>::obtenerSiguiente(){
    return this->siguiente;
}
 