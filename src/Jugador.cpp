#include "Jugador.h"


Jugador::Jugador(std::string nom, int numJugador){
	this->eliminado = false;
	this->puntaje = 0;
	this->nombre = nom;
	this->numeroJugador = numJugador;
}

Jugador::Jugador(){
	this->eliminado = false;
	this->puntaje = 0;
	this->nombre = "JUGADOR AUXILIAR";
	this->numeroJugador = 0;
}

void Jugador::asignarEstado(bool opcion){
	this->eliminado = opcion;
}

void Jugador::sumarPuntaje(int puntos){
	this->puntaje += puntos;
}

bool Jugador::consultarEstado(){
	return this->eliminado;
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
