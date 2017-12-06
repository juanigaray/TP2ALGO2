/*
 * Arbitro.cpp
 *
 *  Created on: Nov 7, 2017
 *      Author: juan
 */

#include "Arbitro.h"


Arbitro::Arbitro(std::string* nombresDeJugadores, int numeroDeJugadores){
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

							/* La segunda condicion chequea que el jugador a apilar
							 * no tenga sus valores en default,
							 * cosa que puede pasar en la primera jugada.
							 */
	if (! fueEliminado && ( devolverNumeroDeTurno() != 0 ) ){
		colaDeJugadores.acolar(actual);
	}
	if (! colaDeJugadores.estaVacia() ){
		actual = colaDeJugadores.desacolar();
	}
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

bool Arbitro::noQuedanJugadores(){
	return ( devolverNumeroDeTurno() == 0);
}


void Arbitro::anunciarGanador(){
	int puntajeMaximo = 0;
	Jugador ganador = actual;
	Jugador posibleGanador;

	while(! colaDeJugadores.estaVacia() ){

		posibleGanador = colaDeJugadores.desacolar();

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



