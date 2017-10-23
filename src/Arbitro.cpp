
/*
 * Arbitro.cpp
 *
 *  Created on: Oct 22, 2017
 *      Author: juan
 */
 
#include "Arbitro.h"
 
Arbitro::Arbitro(uint dificultadPedida, uint numeroDeJugadores, uint filas, uint columnas, cadena* listaDeNombresDeJugadores){

	dificultad = dificultadPedida;
	cantJugadores = numeroDeJugadores;
	filaMaxima = filas;
	columnaMaxima = columnas;
//	listaDeJugadores.inicializar(listaDeNombresDeJugadores);
//	listaDeBombas.inicializar(dificultad);
//	listaDeBanderas.inicializar();
}

void Arbitro::tomarJugada(){
	//modularizar
 
}

uint Arbitro::devolverColumnaDeJugada(){

}

uint Arbitro::devolverFilaDeJugada(){

}
	
std::string Arbitro::devolverTipoDeJugada(){

}
	
uint Arbitro::devolverTurno(){

}
	
void Arbitro::declararTurno(){

}
	
int Arbitro::devolverPuntaje(){

}

bool Arbitro::terminoElJuego(){

}
