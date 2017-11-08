/*
 * Arbitro.cpp
 *
 *  Created on: Nov 7, 2017
 *      Author: juan
 */

#include "Arbitro.h"


Arbitro::Arbitro(cadena* nombresDeJugadores, uint numeroDeJugadores, uint dificultadPedida){

	this->dificultad = dificultadPedida;
	this->inicializarListaDeJugadores(nombresDeJugadores, numeroDeJugadores);

}

void Arbitro::eliminarJugador(){
		listaDeJugadores.removerNodo( devolverTurno() );
}

void Arbitro::avanzarTurno(){
	listaDeJugadores.avanzarCursor();
}

void Arbitro::inicializarListaDeJugadores(cadena* nombres, uint cantidadJugadores){
	for(uint i = 0; i < cantidadJugadores; i++){
        Jugador jugador(nombres[i], i);
        listaDeJugadores.agregarElemento(jugador);
	}
}

uint Arbitro::devolverTurno(){
	return (uint)( listaDeJugadores.obtenerCursor()->consultarNumero() );
}
