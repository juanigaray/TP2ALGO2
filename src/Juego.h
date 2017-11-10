/*
 * Arbitro.h
 *
 *  Created on: Oct 19, 2017
 *      Author: juan
 */
#ifndef JUEGO_H_
#define JUEGO_H_

#include <sstream>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Jugador.h"
#include "Puntaje.h"
#include "Dibujante.h"
#include "Casillero.h"
#include "Arbitro.h"
#include "Comunes.h"

class Juego{

  private:

	cadena bomba;
	cadena bandera;
	cadena casilleroCubierto;
	cadena margen;

	Dibujante* dibujante;

	Casillero*** tablero; //Es un array * de arrays * de punteros *

	uint filaMaxima;
	uint columnaMaxima;

	Arbitro* arbitro;

	uint bombasTotales;
	uint casillerosDestapados;

	uint filaDeJugada;
	uint columnaDeJugada;
	//VER DIFERENCIA DE PUNTAJE

	/*
	 * Post: Pide que el usuario ingrese un numero hasta recibir uno mayor a cero.
	 * 		 Devuelve el numero ingresado.
	 */
	uint pedirNumero(std::string mensaje);

	/*
	 * Post: Pide que el usuario ingrese un numero hasta recibir uno mayor a cero.
	 * 		 Devuelve el numero ingresado.
	 */
	uint pedirNumero(std::string mensaje, uint numeroMaximo);

	/*
	 * Post: Devuelve una cadena con el numero que se le paso
	 */
	cadena hacerCadena(int numero);

	/*
	 *
	 */
	void inicializarTablero(uint dificultad);

	/*
	 *
	 */
	uint tomarTipoDeJugada();

	/*
	 *
	 */
	void tomarUbicacionDeJugada();

	/*
	 * Asigna aleatoriamente la cantidad de bombas que reciba el parametro
	 */
	void crearBombas(uint cantBombas);

	 /*
	  * Indica si existe una bomba en ese lugar
	  */
	bool hayBomba(uint fila, uint columna);

	 /*
	  * Indica si existe una bandera en ese lugar
	  */
	bool hayBandera();

	/*
	 *
	 */
	bool noQuedanCasilleros();

	/*
	 *
	 */
	void prepararCasillero();

	/* Pre: Recibe el jugador actual.
	 * Post: Si no hay una bandera la coloca,
	 * si hay y era del mismo jugador la saca sin que pase nada,
	 * si es de otro, se toma como corregir a otro jugador y se puntua.
	 * Retorna que se va a dibujar.
	 */
	cadena jugadaBandera(uint jugadorActual);

	/* Pre: Recibe el jugador actual.
	 * Post: Si tiene una bomba elimina al jugador,
	 * si no, destapa el casillero y evalua los circundantes
	 */
	cadena jugadaDestapar(uint jugadorActual);



  public:

	/* Pre: Se le pasan numeros naturales.
	 * Post: Crea un arbitro listo para pasarle jugadas
	 */
	Juego(uint dificultadPedida, uint numeroDeJugadores, uint filas, uint columnas, cadena* listaDeNombresDeJugadores);

	/*
	 * Post: El jugador actual es el siguiente en la lista
	 */
	void avanzarTurno();

	/*
	 * Post: Le toma la jugada al usuario.
	 * 		 Decide el resultado de la jugada.
	 */
	void tomarJugada();


	/*
	 * Pre: se pasa una coordenada valida.
	 * Post: Devuelve la cantidad de bombas que rodean el casillero
	 */
	uint evaluarBombasCircundantes(uint columnaDeCasillero, uint filaDeCasillero);

	/*
	 *
	 */
	bool validarCoordenada(uint fila, uint columna);

	/*
	 * Post: Devuelve en que columna se realizo la ultima jugada tomada.
	 */
	uint devolverColumnaDeJugada();

	/*
	 * Post: Devuelve en que fila se realizo la ultima jugada tomada.
	 */
	uint devolverFilaDeJugada();

	/*
	 * Post: Devuelve string con el tipo de jugada que se realizo.
	 */
	std::string devolverTipoDeJugada();

	/*
	 *
	 */
	void declararTurno();

	/*
	 * Post: Devuelve el puntaje total del jugador que jugo ultimo.
	 *	 	 Devuelve -1 si no se modifica.
	 */
	int devolverPuntaje();

	/*
	 * Post
	 */
	void eliminarBandera(uint columna, uint fila);

	/*
	 * Post: devuelve true si termino la partida
	 */
	bool terminoLaPartida();

	/*
	 *
	 */
	~Juego();

};



#endif /* JUEGO_H_ */
