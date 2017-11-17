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

class Tablero{
private:
	Casillero*** matriz; //Es un array * de arrays * de punteros *

	unsigned int columnaMaxima;
	unsigned int filaMaxima;
	unsigned int bombasTotales;
	unsigned int casillerosDestapados;

public:

	//SET


	Tablero(unsigned int columnas, unsigned int filas, unsigned int dificultad);

	Tablero();

	void asignarDimensionesYDificultad(unsigned int columnas, unsigned int filas, unsigned int dificultad);

	void inicializarMatriz();

	void crearBombas(unsigned int dificultad);

	/*
	 * post: Devuelve si la bandera fue colocada sobre un casillero con bomba
	 */
	bool colocarBandera(unsigned int columnaDeJugada, unsigned int filaDeJugada, unsigned int jugadorActual);

	/*
	 * Post: devuelve 0 si el que quita la bandera es el mismo que la puso, y si es otro jugador:
	 * 		 	Devuelve -2 si no hay bomba
	 * 		 	Devuelve 2 si hay bomba
	 */
	int quitarBandera(unsigned int columnaDeJugada, unsigned int filaDeJugada, unsigned int jugadorActual);


	void descubrirCasillero(unsigned int columna, unsigned int fila);





	//GET


	unsigned int obtenerFilaMaxima();

	unsigned int obtenerColumnaMaxima();

	bool noQuedanCasilleros();

	/*
	 * Pre: se pasa una coordenada valida.
	 * Post: Devuelve la cantidad de bombas que rodean el casillero
	 */
	int obtenerNumeroDeBombasCircundantes(unsigned int columnaDeCasillero, unsigned int filaDeCasillero);

	/*
	 * Post: Crea un casillero sin bomba, sin bandera y tapado
	 */
	void prepararCasillero(int columnaDeCasillero, int filaDeCasillero);

	bool esCoordenadaValida(unsigned int columna, unsigned int fila);

	bool estaIniciado(unsigned int columna, unsigned int fila);

	bool existe(unsigned int columna, unsigned int fila);

	/*
	 *Post: Indica si el casillero tiene bomba o no
	 */
	bool hayBombaEn(unsigned int columna, unsigned int fila);

	/*
	 *Post: Indica si el casillero tiene bandera o no
	 */
	bool hayBanderaEn(unsigned int columna, unsigned int fila);

	/*
	 *Post: Indica si el casillero esta destapado
	 */
	bool estaDescubierto(unsigned int columna, unsigned int fila);

	~Tablero();


};





#endif /* TABLERO_H_ */
