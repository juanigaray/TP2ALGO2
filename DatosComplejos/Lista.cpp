#include "Lista.h"
typedef int NULL = 0;
Nodo<T> *primero;

unsigned int tamanio;

Nodo<T> *cursor;

template<class T> void Lista<T>::obtenerNodo(int posicion) {
    Nodo<T> *actual = this->primero;
    for (unsigned int i = 1; i < posicion; i++) {

        actual = actual->obtenerSiguiente();
    }

    return actual;
}
template<class T> Lista<T>::Lista(){
    this->primero = NULL;
    this->tamanio = 0;
    this->cursor = NULL;
}
template<class T> void Lista<T>::iniciarCursor() {

    this->cursor = NULL;
}
template<class T> bool Lista<T>::avanzarCursor() {

    if (this->cursor == NULL) {

        this->cursor = this->primero;

    } else {

        this->cursor = this->cursor->obtenerSiguiente();
    }

    /* pudo avanzar si el cursor ahora apunta a un nodo */
    return (this->cursor != NULL);
}

template<class T> T Lista<T>::obtenerCursor() {

    T elemento;

    if (this->cursor != NULL) {

        elemento = this->cursor->obtenerDato();
    }

    return elemento;
}
template<class T> bool Lista<T>::estaVacia(){
    return (this->primero == NULL);
}

template<class T> unsigned int Lista<T>::contarElementos(){
    this->tamanio;
}

template<class T> void Lista<T>::agregarElemento(T elemento){
    Nodo<T> *nuevo = new Nodo<T>(elemento);
    int posicion = (this->tamanio - 1);
    Nodo<T> *anterior = this->obtenerNodo(posicion);
    anterior.cambiarSiguiente(nuevo);
    this->tamanio ++;
}

template<class T> T Lista<T>::obtenerDato(unsigned int posicion){
    return this->obtenerNodo(posicion)->obtenerDato();
}

template<class T> void Lista<T>::removerNodo(unsigned int posicion){
    Nodo<T> *nodoARemover;
    if(posicion == 1){
        nodoARemover = this->primero;
        this->primero->cambiarSiguiente(nodoARemover);
    }
    else{
        Nodo<T> * anterior = this->obtenerNodo(posicion - 1);
        nodoARemover = anterior->obtenerSiguiente();
        anterior->cambiarSiguiente(nodoARemover->obtenerSiguiente());
    }
    delete nodoARemover;
    this->tamanio --;
}
template<class T> Lista<T>::~Lista() {

    while (this->primero != NULL) {

        Nodo<T>* aBorrar = this->primero;
        this->primero = this->primero->obtenerSiguiente();

        delete aBorrar;
    }
}