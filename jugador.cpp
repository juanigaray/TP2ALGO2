#include "jugador.h"


Jugador::Jugador(std::string nom){
	this->nombre = nom;
	this->puntaje = 0;
	this->eliminado = false;
}


void Jugador::asignarPuntaje(int puntos){
	this->puntaje = puntos;
}


void Jugador::asignarEstado(bool opcion){
	this->eliminado = opcion;
}


std::string Jugador::consultarNombre(){
	return this->nombre;
}


int Jugador::consultarPuntaje(){
	return this->puntaje;
}


bool Jugador::consultarEstado(){
	return this->eliminado;
}
