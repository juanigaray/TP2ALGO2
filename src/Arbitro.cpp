/*
 * Arbitro.cpp
 *
 *  Created on: Nov 7, 2017
 *      Author: juan
 */

#include "Arbitro.h"


Arbitro::Arbitro(cadena* nombresDeJugadores, int numeroDeJugadores, int dificultadPedida){
	this->dificultad = dificultadPedida;
	this->inicializarListaDeJugadores(nombresDeJugadores, numeroDeJugadores);
}

Jugador Arbitro::devolverJugador(){
	return actual;
}

void Arbitro::sumarPuntaje(int puntos){
	devolverJugador().sumarPuntaje(puntos);
}

int Arbitro::devolverPuntaje(){
	return devolverJugador().consultarPuntaje();
}

void Arbitro::avanzarTurno(bool fueEliminado){
	if (! fueEliminado){
			colaDeJugadores.acolar(actual);
	}
	actual = colaDeJugadores.desacolar();
}

void Arbitro::inicializarListaDeJugadores(cadena* nombres, int cantidadJugadores){
	for(int i = 0; i < cantidadJugadores; i++){
        Jugador jugador(nombres[i], i + 1);
        colaDeJugadores.acolar(jugador);
	}
}

int Arbitro::devolverNumeroDeTurno(){
	int nroJugador = actual.consultarNumero();
	return nroJugador;
}

bool Arbitro::quedaUno(){
	return (colaDeJugadores.quedaUno());
}

void Arbitro::anunciarGanador(){
	Jugador* ganador = colaDeJugadores.desacolar();
	std::cout << "El ganador es "
			  << ganador->consultarNombre()
			  << " con "
			  << ganador->consultarPuntaje()
			  << " puntos!"
			  << std::endl;
}



