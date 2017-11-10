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

Jugador* Arbitro::devolverJugador(){
	return listaDeJugadores.obtenerCursor();
}

void Arbitro::eliminarJugador(){
		listaDeJugadores.removerNodo( devolverTurno() );
}

void Arbitro::sumarPuntaje(int puntos){
	devolverJugador()->asignarPuntaje( devolverPuntaje() + puntos  );
}

uint Arbitro::devolverPuntaje(){
	return devolverJugador()->consultarPuntaje();
}

void Arbitro::avanzarTurno(){
	listaDeJugadores.avanzarCursor();
}

void Arbitro::inicializarListaDeJugadores(cadena* nombres, uint cantidadJugadores){
	for(uint i = 0; i < cantidadJugadores; i++){
        Jugador jugador(nombres[i], i);
        listaDeJugadores.agregarElemento(jugador);
	}
	listaDeJugadores.iniciarCursor();
}

uint Arbitro::devolverTurno(){
	uint nroJugador = listaDeJugadores.obtenerCursor()->consultarNumero() + 1;
	return nroJugador;
}

bool Arbitro::murieronTodos(){
	return listaDeJugadores.estaVacia();
}
