#include "Nodo.h"
#include <iostream>
#ifndef LISTA_H_
#define LISTA_H_

template <class T>
class Lista{

  private:
	Nodo<T>* primero;
    Nodo<T>* cursor;

    unsigned int tamanio;


    //Devuelve el nodo de la posicion buscada
   	Nodo<T>* obtenerNodo(int posicion);

  public:
    /*
     * post: Lista vacía.
     */
    Lista();

    /*
     * post: deja el cursor de la Lista preparado para hacer un nuevo
     *       recorrido sobre sus elementos.
     */
    void iniciarCursor();
    /*
     * pre : No se agregan ni se quitan elementos de la lista
     * post: Mueve al siguiente elemento, devuelve si hay proximo o no
     */
    bool avanzarCursor();


    /*
     * pre : el cursor esta posicionado en un elemento de la lista
     * post: devuelve el elemento en la posición del cursor.
     *
     */
    T* obtenerCursor();

    /*
     * post: indica si la Lista tiene algún elemento.
     */
    uint devolverTamanio();

    /*
     * post: devuelve la cantidad de elementos que tiene la Lista.
     */
    unsigned int contarElementos();
    /*
     * post: agrega el elemento al final de la Lista, en la posición:
     *       contarElementos() + 1.
     */
    void agregarElemento(T elemento);

    /*
     * pre : posición pertenece al intervalo: [1, contarElementos()]
     * post: devuelve el elemento en la posición indicada.
     */
    T* obtener(unsigned int posicion);

    /*
     * pre : posición pertenece al intervalo: [1, contarElementos()]
     * post: remueve de la Lista el elemento en la posición indicada.
     */
    void removerNodo(unsigned int posicion);
      
     /*
      * post: libera los recursos asociados a la Lista.
      */
    ~Lista();

};

template<class T>
Nodo<T>* Lista<T>::obtenerNodo(int posicion){
	iniciarCursor();

	for(int i = 1; i <= posicion; i++){
		avanzarCursor();
	}

	Nodo<T>* aDevolver = cursor;
	iniciarCursor();
	return aDevolver;
}


template<class T>
Lista<T>::Lista(){
        primero = NULL;
        tamanio = 0;
        cursor = NULL;
}


template<class T>
void Lista<T>::iniciarCursor(){
    this->cursor = NULL;
}

template<class T>
bool Lista<T>::avanzarCursor(){

        if (cursor == NULL) {
            cursor = primero;
        } else {
           cursor = cursor->obtenerSiguiente();
        }
        return (cursor != NULL);
}

template<class T>
T* Lista<T>::obtenerCursor(){
        return cursor->obtenerDato();
}


template<class T>
uint Lista<T>::devolverTamanio(){
	return tamanio;
}

template<class T>
unsigned int Lista<T>::contarElementos(){
    	return tamanio;
}

template<class T>
void Lista<T>::agregarElemento(T elemento){

		Nodo<T>* nuevo = new Nodo<T>(elemento);

    	if ( tamanio == 0 ){
        	this->primero = nuevo;
    	} else {
			Nodo<T> *anterior = obtenerNodo(tamanio);
			anterior->cambiarSiguiente(nuevo);
    	}
    	nuevo->cambiarSiguiente(primero);
        tamanio ++;
}

template<class T>
T* Lista<T>::obtener(unsigned int posicion){

      return obtenerNodo(posicion)->obtenerDato();
}

template<class T>
void Lista<T>::removerNodo(unsigned int posicion){

       Nodo<T>* nodoARemover = 0;

       if (posicion == 1){
           nodoARemover = primero;
           primero = obtenerNodo(2);
           cursor = obtenerNodo(tamanio);
       }
       else{
    	   Nodo<T>* anterior = obtenerNodo(posicion - 1);
           nodoARemover = anterior->obtenerSiguiente();
           Nodo<T>* siguiente = nodoARemover->obtenerSiguiente();
           anterior->cambiarSiguiente(siguiente);
           cursor = anterior;
       }
       delete nodoARemover;
       tamanio --;
}

template<class T>
Lista<T>:: ~Lista(){

    while (primero != NULL) {

        Nodo<T>* aBorrar = primero;
        primero = primero->obtenerSiguiente();

        delete aBorrar;
    }
}

#endif
