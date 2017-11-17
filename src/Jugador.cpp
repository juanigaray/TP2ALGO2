#include "Jugador.h"


Jugador::Jugador(std::string nom, int numJugador){
	this->puntaje = 0;
	this->nombre = nom;
	this->numeroJugador = numJugador;
}

Jugador::Jugador(){
	this->puntaje = 0;
	this->nombre = "JUGADOR AUXILIAR";
	this->numeroJugador = 0;
}


void Jugador::sumarPuntaje(int puntos){
	this->puntaje += puntos;
}

int Jugador::consultarPuntaje(){
	return this->puntaje;
}

std::string Jugador::consultarNombre(){
	return this->nombre;
}

unsigned int Jugador::consultarNumero(){
    return this->numeroJugador;
}

void Jugador::operator=(Jugador* jugadorACopiar){
	 this->nombre = jugadorACopiar->consultarNombre();
	 this->puntaje = jugadorACopiar->consultarPuntaje();
	 this->numeroJugador = jugadorACopiar->consultarNumero();
}
