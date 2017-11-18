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

int Jugador::consultarPuntaje() const{
	return this->puntaje;
}

std::string Jugador::consultarNombre() const{
	return this->nombre;
}

int Jugador::consultarNumero() const{
    return this->numeroJugador;
}

Jugador Jugador::operator=(const Jugador& otroJugador){
	this->puntaje = otroJugador.consultarPuntaje();
	this->nombre = otroJugador.consultarNombre();
	this->numeroJugador = otroJugador.consultarNumero();
	return *this;
}
