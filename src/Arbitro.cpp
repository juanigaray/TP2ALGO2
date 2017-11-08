/*
 * Arbitro.cpp
 *
 *  Created on: Nov 7, 2017
 *      Author: juan
 */

#include "Arbitro.h"


Arbitro::Arbitro(cadena* nombresDeJugadores, uint numeroDeJugadores){

	this->inicializarListaDeJugadores(nombresDeJugadores, numeroDeJugadores);

}

void Arbitro::eliminarJugador(){
		listaDeJugadores.removerNodo( devolverTurno() );
}

void Arbitro::avanzarTurno(){
	listaDeJugadores.avanzarCursor();
}
