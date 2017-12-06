#include "Nodo.h"
#include <iostream>
#ifndef COLA_H_
#define COLA_H_

template <class T>
class Cola{

  private:

	Nodo<T>* primero;
    Nodo<T>* ultimo;

  public:
    /*
     * post: Cola vacía.
     */
    Cola();

    /*
     * post: indica si no queda ningun elemento en la cola
     */
    bool estaVacia();

    /*
     * post: indica si queda solo un elemento
     */
    bool quedaUno();

    /*
     * post: agrega el elemento al final de la Cola.
     */
    void acolar(T elemento);

    /*
     * pre : no estaVacia()
     * post: devuelve el elemento del frente de la cola
     */
    T desacolar();

     /*
      * post: libera los recursos asociados a la Cola.
      */
    ~Cola();

};

template<class T>
Cola<T>::Cola(){
        primero = NULL;
        ultimo = NULL;
}

template<class T>
bool Cola<T>::estaVacia(){
	return (primero==NULL);
}

template<class T>
bool Cola<T>::quedaUno(){
	return( primero==ultimo ) && (! estaVacia());
}


template<class T>
void Cola<T>::acolar(T elemento){

		Nodo<T>* nuevo = new Nodo<T>(elemento);

    	if ( estaVacia() ){
        	this->primero = nuevo;
    	} else {
			ultimo->cambiarSiguiente(nuevo);
    	}
    	this->ultimo = nuevo;
}

template<class T>
T Cola<T>::desacolar(){

	if ( estaVacia() ){
		throw "Error en cola: Intenta desacolar de cola vacia!";
	}
	T aDevolver = (primero->obtenerDato());
	Nodo<T>* siguiente = primero->obtenerSiguiente();
	delete primero;
	primero = siguiente;
	return aDevolver;
}


template<class T>
Cola<T>:: ~Cola(){

    while (! estaVacia() ) {
        Nodo<T>* aBorrar = primero;
        primero = primero->obtenerSiguiente();
        delete aBorrar;
    }
}

#endif
