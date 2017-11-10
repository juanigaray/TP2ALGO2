/*
 * Dibujante.h
 *
 *  Created on: Oct 18, 2017
 *      Author: juan
 */

#ifndef DIBUJANTE_H_
#define DIBUJANTE_H_
#include "EasyBMP/EasyBMP.h"
#include <sstream>
#include "Comunes.h"

class Dibujante{

  private:

	cadena directorioDeImagenesFuente;
	cadena directorioDeCasilleros;
	cadena directorioDeMargenes;
	cadena directorioDePuntajes;
	cadena bomba;
	cadena bandera;
	cadena casilleroCubierto;
	cadena margen;

	uint numeroDeDibujo;

	uint alturaDeCuadrante;
	uint anchoDeCuadrante;

	uint columnasDelTablero;
	uint columnasMinimas;
	uint filasDelTablero;

	uint columnasTotalesImagen;
	uint filasTotalesImagen;

	BMP imagen;

	/* Pre: Es usado por el constructor. Se le pasan dos naturales.
	 * Post:
	 */
	void inicializarCasilleros();

	/*
	 * Post: Se muestran todos los jugadores con sus puntajes en 0.
	 */
	void inicializarPuntajes(uint cantidadDeJugadores);

	/*
	 * Post: El tableroo tiene un margen inferior donde se van a dibujar los puntajes.
	 */
	void inicializarMargen(uint cantidadDeJugadores);

	/*
	 * Post: La imagen tiene todos sus casilleros dibujados como cubiertos.
	 * 		 Se crean los margenes de la imagen con lugar para anotar los puntajes de los jugadores.
	 */
	void inicializarImagen(uint cantidadDeJugadores);

  public:

	/*
	 * Post: El dibujante crea su imagen lista para ser dibujada y modificada
	 *		 Crea el espacio donde poner los puntajes de los jugadores.
	 */
	Dibujante(uint cantidadDeColumnas, uint cantidadDeFilas, uint cantidadDeJugadores);

	/*
	 * Post: Devuelve el numero correspondiente al dibujo que se esta preparando.
	 */
	uint informarNumeroDeDibujo();

	/* Pre: el numero de fila (o columna) esta dentro del rango [0 .. filas (o columnas) del tablero - 1 ]
	 * 	    queDibujar es un string con el nombre del archivo fuente sin ".bmp".
	 * 		Por default, se aceptan los numeros del cero al ocho, "boom", "cubierto" y "bandera".
	 *
	 * Post: Se superpone el cuadrante en la posicion indicada con el tipo de casillero pedido.
	 *
	 */
	void cambiarCuadrante(uint fila, uint columna, cadena queDibujar, uint jugador, bool esMargen);

	/* Pre: El nroJugador esta entre 1 y el nro de jugadores pasados al crear el tablero.
	 * Post: Dibuja el puntaje pasado a la derecha del numero de jugador.
	 */
	void cambiarPuntaje(int puntaje, uint nroJugador);

	/* Post:	Guarda una nueva imagen BMP con los cambios aplicados al tablero.
	 * 			El nombre de la imagen se crea de acuerdo a cuantas veces se llamo este metodo.
	 */
	void dibujarTablero();

	/*
	 *
	 */
	void eliminarJugador(uint nroJugador);

	/*
	 *
	 */
	cadena hacerCadena(int numero);

};

#endif /* DIBUJANTE_H_ */
