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

typedef unsigned int uint;

class Dibujante{

  private:
	uint ordinalDeDibujo;

	uint alturaDeCuadrante;
	uint anchoDeCuadrante;

	uint anchoDeMargenLateral;
	uint alturaDeMargenSuperior;
	uint alturaDeMargenInferior;

	uint pixelesDeAncho;
	uint pixelesDeAlto;

	BMP imagen;

	std::string directorioDeImagenesFuente;

	/* Pre: Es usado por el constructor. Se le pasan dos naturales.
	 * Post:
	 */
	void inicializarCasilleros(uint cantidadDeColumnas, uint cantidadDeFilas);

	/*
	 *
	 */
	void inicializarMargenes(uint cantidadDeColumnas, uint cantidadDeFilas, uint cantidadDeJugadores);

	/*Pre: Es usado por el constructor. Se le pasan dos naturales.
	 * Post: La imagen tiene todos sus casilleros dibujados como cubiertos.
	 *	Se crean los margenes de la imagen con lugar para anotar los puntajes de los jugadores.
	 */
	void inicializarImagen(uint cantidadDeColumnas, uint cantidadDeFilas, uint cantidadDeJugadores);

  public:

	/*Pre: 	Se pasan la cantidad de filas y de columnas del tablero, que son numeros naturales.
	 * 		Si se pasa el numero de jugadores, es natural tambien.
	 * Post: Se crea un dibujante que solo va a crear la imagen con los casilleros, sin margenes
	 *		 Si se paso el numero de jugadores, crea el espacio donde poner sus puntajes.
	 */
	Dibujante(uint cantidadDeColumnas, uint cantidadDeFilas, uint cantidadDeJugadores = 1);

	/*
	 * Post: Devuelve el numero correspondiente al dibujo que se esta preparando.
	 * Es decir, la cantidad de dibujos que ya se hicieron es ( informarNumeroDeDibujo() - 1 )
	 */
	uint informarNumeroDeDibujo();

	/* Pre: el numero de fila o columna esta dentro del rango [0 ... ( filas o columnas del tablero - 1) ]
	 *
	 * Post: Se redibuja el cuadrante en la posicion indicada con el tipo de casillero pedido.
	 * 		queDibujar es un string con el nombre del archivo fuente sin ".bmp".
	 * 		Por default, se aceptan los numeros del cero al ocho, "boom", "cubierto" y "bandera".
	 */
	void cambiarCuadrante(uint fila, uint columna, std::string queDibujar, uint jugador = 0);

	/*
	 *
	 */
	void cambiarPuntaje(uint puntaje, uint jugador);

	/*Post:	Guarda una nueva imagen BMP con los cambios aplicados al tablero.
	 * El nombre de la imagen se crea de acuerdo a cuantas veces se llamo este metodo.
	 */
	void dibujarTablero();

};

#endif /* DIBUJANTE_H_ */
