#ifndef NODO_H_
#define NODO_H_
#endif
#ifndef NULL
#define NULL 0
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
    Nodo(T dato){
    	this->dato = dato;
       siguiente = NULL;
       std::cout << "Nodo Creado" << std::endl;
    }

/*
*Pre: -
*Post: devuelve el dato del nodo
*/
    T obtenerDato(){
        return dato;
        std::cout << "Dato devuelto" << std::endl;

    }
/*
*Post: cambia el dato del nodo
*/   
    void cambiarDato(T datoNuevo){
        dato = datoNuevo;
        std::cout << "Dato cambiado" << std::endl;

    }
/*
*Post: Devuelve el siguiente del nodo actual
*/
    Nodo<T>* obtenerSiguiente(){
        return siguiente;
        std::cout << "siguiente devuelto" << std::endl;

    }
/*
*Post: Cambia el siguiente del nodo actual
*/
    void cambiarSiguiente(Nodo<T>* siguienteNuevo){
        this->siguiente = siguienteNuevo;
        std::cout << "Siguiente cambiado" << std::endl;

    }

};
