#include "Nodo.h"

Nodo::Nodo(T dato){
    this->dato = dato;
    this->siguiente = NULL;
}

Nodo::cambiarDato(T datoNuevo){
    this->dato = datoNuevo;
}

Nodo::cambiarSiguiente(Nodo<T> *siguienteNuevo){
    this->siguiente = siguienteNuevo;
}

Nodo::obtenerDato(){
    return this->dato;
}

Nodo::obtenerSiguiente(){
    return this->siguiente;
}
