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

	//METODOS DE INICIALIZACION

	/*
	 * post: se crea un tablero de tamanio columnas*filas con una cantidad de bombas que depende de la dificultad pasada.
	 * 		 Queda listo para jugar
	 */
	Tablero(int columnas, int filas,  int dificultad);

	/*
	 * post: Se crea una instancia de tablero que debe ser inicializada con asignarDimensionesYDificultad()
	 */
	Tablero();

	/*
	 * post: se inicializa un tablero de tamanio columnas*filas con una cantidad de bombas que depende de la dificultad pasada.
	 *		 Queda listo para jugar
	 */
	void asignarDimensionesYDificultad(int columnas, int filas,  int dificultad);

	/*
	 * post: queda creada la matriz de casilleros,
	 * 		 pero cada casillero no existe hasta que se corre prepararCasillero() con su coordenada
	 */
	void inicializarMatriz();

	/*
	 * post: Se le asignan bombas al tablero de acuerdo a la dificultad elgida
	 */
	void crearBombas( int dificultad);



	//SET

	/*
	 * post: Coloca una bandera en el casillero, que recuerda quién la puso
	 * 		 Devuelve si la bandera fue colocada sobre un casillero con bomba
	 */
	bool colocarBandera(int columnaDeJugada, int filaDeJugada, int jugadorActual);

	/*
	 * Post: elimina la bandera del casillero
	 * 		 Devuelve si la bandera fue quitada de un casillero con bomba
	 */
	bool quitarBandera(int columnaDeJugada, int filaDeJugada);


	/*
	 * Post Muestra el contenido del casillero deseado
	 */
	void descubrirCasillero(int columna, int fila);



	//GET

	/*
	 * post Devuelve la fila maxima
	 */
	int obtenerFilaMaxima();
	/*
	 * post devuelve la columna maxima
	 */
	 int obtenerColumnaMaxima();
	 /*
	  * Post devuelve si quedan casilleros o no
	  */
	bool noQuedanCasilleros();
	/*
	 * Post Devuelve el jugador que coloco la bandera
	 */
	int obtenerJugadorQueColocoBandera(int columnaDeJugada, int filaDeJugada);
	/*
	 * Pre: se pasa una coordenada valida.
	 * Post: Devuelve la cantidad de bombas que rodean el casillero
	 */
	int obtenerNumeroDeBombasCircundantes( int columnaDeCasillero, int filaDeCasillero);

	/*
	 * Post: Crea un casillero sin bomba, sin bandera y tapado
	 */
	void prepararCasillero(int columnaDeCasillero, int filaDeCasillero);

	/*
	 * Post: devuelve si la coordenada ingresada es valida
	 */
	bool esCoordenadaValida(int columna, int fila);

	/*
	 * Post: Devuelve si el casillero esta iniciado o no
	 */
	bool estaIniciado( int columna, int fila);

	/*
	 * Post devuelve si el casillero esta iniciado y si la coordenada es valida
	 */
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

	/*
	 * Destructor
	 */
	~Tablero();


};





#endif /* TABLERO_H_ */
