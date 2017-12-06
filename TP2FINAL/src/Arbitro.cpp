/*
 * Arbitro.cpp
 *
 *  Created on: Nov 7, 2017
 *      Author: juan
 */

#include "Arbitro.h"


Arbitro::Arbitro(std::string* nombresDeJugadores, int numeroDeJugadores, int dificultadPedida){
	this->dificultad = dificultadPedida;
	this->inicializarListaDeJugadores(nombresDeJugadores, numeroDeJugadores);
}

Jugador Arbitro::devolverJugador(){
	return actual;
}

void Arbitro::sumarPuntaje(int puntos){
	actual.sumarPuntaje(puntos);
}

int Arbitro::devolverPuntaje(){
	return devolverJugador().consultarPuntaje();
}

void Arbitro::avanzarTurno(bool fueEliminado){
	if (! fueEliminado && (actual.consultarNumero() != 0)){
			colaDeJugadores.acolar(actual);
	}
	actual = colaDeJugadores.desacolar();
}

void Arbitro::inicializarListaDeJugadores(std::string* nombres, int cantidadJugadores){
	for(int i = 0; i < cantidadJugadores; i++){
        Jugador jugador(nombres[i], i + 1);
        colaDeJugadores.acolar(jugador);
	}
}

int Arbitro::devolverNumeroDeTurno(){
	return actual.consultarNumero();
}

bool Arbitro::quedaUno(){
	return (colaDeJugadores.estaVacia());
}

void Arbitro::anunciarGanador(){
	int puntajeMaximo = 0;
	Jugador ganador = actual;
	Jugador posibleGanador;

	while(! colaDeJugadores.estaVacia() ){

		posibleGanador = colaDeJugadores.desacolar();
		std::cout << "posible ganador: " << posibleGanador.consultarNombre() << std::endl;

		if (posibleGanador.consultarPuntaje() > puntajeMaximo ){
			ganador = posibleGanador;
			puntajeMaximo = posibleGanador.consultarPuntaje();
		}
	}

	std::cout << "El ganador es "
			  << ganador.consultarNombre()
			  << " con "
			  << ganador.consultarPuntaje()
			  << " puntos!"
			  << std::endl;
}



