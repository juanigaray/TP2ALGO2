
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

	columnaDeJugada = 0;
	filaDeJugada = 0;

	finDeJuego = false;
//	listaDeJugadores.inicializar(listaDeNombresDeJugadores);
//	listaDeBombas.inicializar(dificultad);
//	listaDeBanderas.inicializar();
}

void Arbitro::tomarJugada(){
	//modularizar
 
}

uint Arbitro::devolverColumnaDeJugada(){
	return columnaDeJugada;
}

uint Arbitro::devolverFilaDeJugada(){
	return filaDeJugada;
}
	
std::string Arbitro::devolverTipoDeJugada(){
	//Sacar del objeto Jugada
	return "poner bandera";

}
	
uint Arbitro::devolverTurno(){
	//Sacar de la lista
	return 0;
}
	
void Arbitro::declararTurno(){

}
	
int Arbitro::devolverPuntaje(){
	//Devuelve puntaje del que jugo ultimo, sacar de cola
	return 0;
}

bool Arbitro::terminoElJuego(){
	return finDeJuego;
}
