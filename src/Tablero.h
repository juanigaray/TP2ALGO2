/*
 * Tablero.h
 *
 *  Created on: Nov 17, 2017
 *      Author: juan
 */

#ifndef TABLERO_H_
#define TABLERO_H_
#include "Casillero.h"
#include <stdlib.h>
#include <iostream>

class Tablero{
private:
	Casillero*** matriz; //Es un array * de arrays * de punteros *

	int columnaMaxima;
	int filaMaxima;
	 int bombasTotales;
	 int casillerosDestapados;

public:

	//SET


	Tablero(int columnas, int filas,  int dificultad);

	Tablero();

	void asignarDimensionesYDificultad(int columnas, int filas,  int dificultad);

	void inicializarMatriz();

	void crearBombas( int dificultad);

	/*
	 * post: Devuelve si la bandera fue colocada sobre un casillero con bomba
	 */
	bool colocarBandera(int columnaDeJugada, int filaDeJugada, int jugadorActual);

	/*
	 * Post: devuelve 0 si el que quita la bandera es el mismo que la puso, y si es otro jugador:
	 * 		 	Devuelve -2 si no hay bomba
	 * 		 	Devuelve 2 si hay bomba
	 */
	int quitarBandera(int columnaDeJugada, int filaDeJugada,  int jugadorActual);


	void descubrirCasillero(int columna, int fila);



	//GET


	 int obtenerFilaMaxima();

	 int obtenerColumnaMaxima();

	bool noQuedanCasilleros();

	/*
	 * Pre: se pasa una coordenada valida.
	 * Post: Devuelve la cantidad de bombas que rodean el casillero
	 */
	int obtenerNumeroDeBombasCircundantes( int columnaDeCasillero, int filaDeCasillero);

	/*
	 * Post: Crea un casillero sin bomba, sin bandera y tapado
	 */
	void prepararCasillero(int columnaDeCasillero, int filaDeCasillero);

	bool esCoordenadaValida(int columna, int fila);

	bool estaIniciado( int columna, int fila);

	bool existe( int columna, int fila);

	/*
	 *Post: Indica si el casillero tiene bomba o no
	 */
	bool hayBombaEn( int columna, int fila);

	/*
	 *Post: Indica si el casillero tiene bandera o no
	 */
	bool hayBanderaEn( int columna, int fila);

	/*
	 *Post: Indica si el casillero esta destapado
	 */
	bool estaDescubierto( int columna, int fila);

	~Tablero();


};





#endif /* TABLERO_H_ */
