#include "Jugador.h"


Jugador::Jugador(std::string nom){
	this->eliminado = false;
	this->puntaje = 0;
	this->nombre = nom;
}

void Jugador::asignarEstado(bool opcion){
	this->eliminado = opcion;
}

void Jugador::asignarPuntaje(int puntos){
	this->puntaje = puntos;
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

