#ifndef LISTA_H_
#define LISTA_H_
#endif
#include "Nodo.h"
template <class T>
class Lista
{

  private:
    Nodo<T> *primero;

    unsigned int tamanio;

    Nodo<T> *cursor;


    //Devuelve el nodo de la posicion buscada
    obtenerNodo(int posicion);

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
    T obtenerCursor();

    /*
     * post: indica si la Lista tiene algún elemento.
     */
    bool estaVacia();
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
    T obtenerDato(unsigned int posicion);

    /*
     * pre : posición pertenece al intervalo: [1, contarElementos()]
     * post: remueve de la Lista el elemento en la posición indicada.
     */
    void removerNodo(unsigned int posicion);
      
     /*
      * post: libera los recursos asociados a la Lista.
      */
    ~Lista();

}
