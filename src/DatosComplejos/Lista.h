#ifndef LISTA_H_
#define LISTA_H_
#endif
#include "Nodo.h"
#include <iostream>
template <class T>
class Lista
{

  private:
	Nodo<T>* primero;

    unsigned int tamanio;

   Nodo<T>* cursor;


    //Devuelve el nodo de la posicion buscada
   	Nodo<T>* obtenerNodo(int posicion){
   	    Nodo<T> *actual = this->primero;
   	    for (int i = 1; i < posicion; i++) {
   	        actual = actual->obtenerSiguiente();
   	    }
   	 std::cout << "nodo obtenido" << std::endl;

   	    return actual;
   	}

  public:
    /*
     * post: Lista vacía.
     */
    Lista(){
        primero = NULL;
        tamanio = 0;
        cursor = NULL;
        std::cout << "Lista creada" << std::endl;
    }

    /*
     * post: deja el cursor de la Lista preparado para hacer un nuevo
     *       recorrido sobre sus elementos.
     */
    void iniciarCursor(){
        this->cursor = NULL;
        std::cout << "Cursor iniciado" << std::endl;
    }

    /*
     * pre : No se agregan ni se quitan elementos de la lista
     * post: Mueve al siguiente elemento, devuelve si hay proximo o no
     */
    bool avanzarCursor(){

        if (cursor == NULL) {

            cursor = primero;

        } else {

           cursor = cursor->obtenerSiguiente();
        }

        /* pudo avanzar si el cursor ahora apunta a un nodo */
        std::cout << "Cursor avanzado" << std::endl;

        return (cursor != NULL);
    }


    /*
     * pre : el cursor esta posicionado en un elemento de la lista
     * post: devuelve el elemento en la posición del cursor.
     *
     */
    T obtenerCursor(){

    T elemento;

    if (cursor != NULL) {

        elemento = cursor->obtenerDato();
    }
    std::cout << "Cursor obtenido" << std::endl;

    return elemento;
}

    /*
     * post: indica si la Lista tiene algún elemento.
     */
    bool estaVacia(){
    	std::cout << "Esta vacia?" << std::endl;
        return (primero == NULL);
    }

    /*
     * post: devuelve la cantidad de elementos que tiene la Lista.
     */
    unsigned int contarElementos(){
    	std::cout << "elementos contados" << std::endl;
    	return tamanio;

    }
    /*
     * post: agrega el elemento al final de la Lista, en la posición:
     *       contarElementos() + 1.
     */
    void agregarElemento(T elemento){
   		Nodo<T> *nuevo = new Nodo<T>(elemento);
        int posicion = tamanio;
    	if(estaVacia()){
        	this->primero = nuevo;
    	}else{
        Nodo<T> *anterior = obtenerNodo(posicion);
        anterior->cambiarSiguiente(nuevo);
    	}
        	tamanio ++;
        std::cout << "Nuevo agregado" << std::endl;

    }

    /*
     * pre : posición pertenece al intervalo: [1, contarElementos()]
     * post: devuelve el elemento en la posición indicada.
     */
    T obtener(unsigned int posicion){
    	std::cout << "Dato obtenido" << std::endl;

        return obtenerNodo(posicion)->obtenerDato();
    }

    /*
     * pre : posición pertenece al intervalo: [1, contarElementos()]
     * post: remueve de la Lista el elemento en la posición indicada.
     */
    void removerNodo(unsigned int posicion){
        Nodo<T> *nodoARemover;
        if(posicion == 1){
            nodoARemover = primero;
            primero->cambiarSiguiente(nodoARemover);
        }
        else{
            Nodo<T> * anterior = obtenerNodo(posicion - 1);
            nodoARemover = anterior->obtenerSiguiente();
            anterior->cambiarSiguiente(nodoARemover->obtenerSiguiente());
        }
        delete nodoARemover;
        tamanio --;
        std::cout << "Nodo Removido" << std::endl;

    }
      
     /*
      * post: libera los recursos asociados a la Lista.
      */
    ~Lista(){

        while (primero != NULL) {

            Nodo<T>* aBorrar = primero;
            primero = primero->obtenerSiguiente();
            std::cout << "Nodo Borrado" << std::endl;

            delete aBorrar;
        }
    }

};
