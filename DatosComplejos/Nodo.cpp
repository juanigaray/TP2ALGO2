#include "Nodo.h"

Nodo<T>::Nodo(T dato){
    this->dato = dato;
    this->siguiente = NULL;
}

Nodo<T>::cambiarDato(T datoNuevo){
    this->dato = datoNuevo;
}

Nodo<T>::cambiarSiguiente(Nodo<T> *siguienteNuevo){
    this->siguiente = siguienteNuevo;
}

Nodo<T>::obtenerDato(){
    return this->dato;
}

Nodo<T>::obtenerSiguiente(){
    return this->siguiente;
}
 