/*
 * Arbitro.h
 *
 *  Created on: Nov 7, 2017
 *      Author: juan
 */

#ifndef ARBITRO_H_
#define ARBITRO_H_

#include "Cola.h"
#include "Jugador.h"

class Arbitro{

private:

	Cola<Jugador> colaDeJugadores;
	Jugador actual;

	/*
	 * Post: inicializa la lista de jugadores con los jugadores creados
	 */
	void inicializarListaDeJugadores(std::string* nombres, int cantidadJugadores);

public:

	/*
	 * Post: inicializa la ronda de jugadores. Queda listo para avanzar turnos.
	 */
	Arbitro(std::string* nombres, int cantidadJugadores);

	/* Pre: La lista debe estar iniciada con el cursor iniciado
	 * Post: Devuelve puntero al jugador al que le toca jugar.
	 */
	Jugador devolverJugador();

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
	int devolverPuntaje();

	/*
	 * Pre: La lista debe estar iniciada con el cursor iniciado
	 * Post: Devuelve el numero de jugador que realizo la ultima jugada.
	 * No avanza el cursor
	 */
	int devolverNumeroDeTurno();

	/* Pre: Se pasa por parametro si quien acaba de jugar perdio
	 * Post: Es turno del jugador siguiente.
	 * 		 Si se termina la ronda, vuelve a empezar
	 * 		 Si no hay más jugadores, no hace nada
	 *
	 */
	void avanzarTurno(bool fueEliminado);

	/*
	 * Post Devuelve si queda un jugador (Este jugador queda almacenado en la variable "actual")
	 */
	bool quedaUno();

	/* Pre: Se jugo al menos un turno
	 * Post: devuelve si no queda ningun jugador
	 */
	bool noQuedanJugadores();

	/*
	 *Post Anuncia el ganador de la partida
	 */
	void anunciarGanador();
};



#endif /* ARBITRO_H_ */
