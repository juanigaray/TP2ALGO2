/*
 * Arbitro.h
 *
 *  Created on: Nov 7, 2017
 *      Author: juan
 */

#ifndef ARBITRO_H_
#define ARBITRO_H_

#include "ClasesComunes.h"
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

	Arbitro(cadena* nombres, uint cantidadJugadores);

	/* Pre: La lista debe estar iniciada con el cursor iniciado
	 * Post: Devuelve puntero al jugador al que le toca jugar.
	 */
	Jugador* devolverJugadorActual();

	/*
	 * Elimina al jugador de la listaDeJugadores
	 * lo agrega a la listaDeJugadoresEliminados
	 */
	void eliminarJugador();

	/*
	 * Post: evalua la jugada y asigna puntajes.
	 * elimina al jugador en caso que destape una bomba
	 */
	void evaluarJugada();

	/*
	 * Pre: La lista debe estar iniciada con el cursor iniciado
	 * Post: Devuelve el numero de jugador que realizo la ultima jugada.
	 * No avanza el cursor
	 */
	uint devolverTurno();

	/*
	 * Post: Es turno del jugador siguiente.
	 * 		 Si se termina la ronda, vuelve a empezar
	 * 		 Si no hay más jugadores, no hace nada
	 */
	void avanzarTurno();
};



#endif /* ARBITRO_H_ */
