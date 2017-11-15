/*
 * Arbitro.h
 *
 *  Created on: Nov 7, 2017
 *      Author: juan
 */

#ifndef ARBITRO_H_
#define ARBITRO_H_

#include "Comunes.h"
#include "Lista.h"
#include "Jugador.h"

class Arbitro{

private:

	uint dificultad;

	Lista<Jugador> listaDeJugadores;

	/*
	 * Post: inicializa la lista de jugadores con los jugadores creados
	 */
	void inicializarListaDeJugadores(cadena* nombres, uint cantidadJugadores);

public:

	Arbitro(cadena* nombres, uint cantidadJugadores, uint dificultadPedida);

	/* Pre: La lista debe estar iniciada con el cursor iniciado
	 * Post: Devuelve puntero al jugador al que le toca jugar.
	 */
	Jugador* devolverJugador();

	/*
	 * Elimina al jugador de la listaDeJugadores
	 * lo agrega a la listaDeJugadoresEliminados
	 */
	void eliminarJugador();

	/* Pre: No fueron eliminados todos los jugadores
	 * Post: Se suma el numero pasado al puntaje del jugador actual
	 *
	 */
	void sumarPuntaje(int puntos);

	/* Pre: No fueron eliminados todos los jugadores
	 * Post: Devuelve el puntaje del jugador actual
	 *		 Si es menor que 0, devuelve 0.
	 */
	uint devolverPuntaje();

	/*
	 * Pre: La lista debe estar iniciada con el cursor iniciado
	 * Post: Devuelve el numero de jugador que realizo la ultima jugada.
	 * No avanza el cursor
	 */
	uint devolverNumeroDeTurno();

	/*
	 * Post: Es turno del jugador siguiente.
	 * 		 Si se termina la ronda, vuelve a empezar
	 * 		 Si no hay más jugadores, no hace nada
	 */
	void avanzarTurno();

	/*
	 *
	 */
	bool quedaUno();

	/*
	 *
	 */
	void anunciarGanador();
};



#endif /* ARBITRO_H_ */
