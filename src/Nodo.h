
#ifndef NODO_H_
#define NODO_H_
#ifndef NULL
#define NULL 0;
#endif
#include <iostream>
template <class T> class Nodo{
private:
    T dato;
    Nodo<T>* siguiente;
public:

/*
 * Pre: -
 * Post: Crea un nodo con la informacion dada, sin siguiente
 */
    Nodo(T dato);

/*
*Pre: -
*Post: devuelve el dato del nodo
*/
    T* obtenerDato();
/*
*Post: cambia el dato del nodo
*/
    void cambiarDato(T datoNuevo);
/*
*Post: Devuelve el siguiente del nodo actual
*/
    Nodo<T>* obtenerSiguiente();
/*
*Post: Cambia el siguiente del nodo actual
*/
    void cambiarSiguiente(Nodo<T>* siguienteNuevo);
};

template<class T> void Nodo<T>::cambiarSiguiente(Nodo<T>* siguienteNuevo){
        this->siguiente = siguienteNuevo;
}

template<class T> Nodo<T>* Nodo<T>::obtenerSiguiente(){
        return siguiente;
}

template<class T> void  Nodo<T>::cambiarDato(T datoNuevo){
        dato = datoNuevo;
}

template<class T> T* Nodo<T>::obtenerDato(){
        return &dato;
}

template<class T> Nodo<T>::Nodo(T dato){
    	this->dato = dato;
        siguiente = NULL;
}

#endif
