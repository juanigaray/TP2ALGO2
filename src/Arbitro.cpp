
/*
 * Arbitro.cpp
 *
 *  Created on: Oct 22, 2017
 *      Author: juan
 */
 
#include "Arbitro.h"
#include "Puntaje.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
 
Arbitro::Arbitro(uint dificultadPedida, uint numeroDeJugadores, uint filas, uint columnas, cadena* listaDeNombresDeJugadores){

	this->dificultad = dificultadPedida;
	this->cantJugadores = numeroDeJugadores;

	this->filaMaxima = filas;
	this->columnaMaxima = columnas;

	this->columnaDeJugada = 0;
	this->filaDeJugada = 0;

	this->finDeJuego = false;
	
	this->inicializarListaDeBombas();
}

uint Arbitro::pedirNumero(std::string mensaje){

	uint numeroIngresado;

	std::cout << mensaje << std::endl;
	std::cin >> numeroIngresado;
	if(numeroIngresado == 0){
		std::cout << "El numero debe ser mayor a cero!" << std::endl;
		this->pedirNumero(mensaje);
	}
	return numeroIngresado;
}

uint Arbitro::pedirNumero(std::string mensaje, uint numeroMaximo){

	uint numeroIngresado;

	std::cout << mensaje << std::endl;
	std::cin >> numeroIngresado;
	if(numeroIngresado == 0 || numeroIngresado > numeroMaximo){
		std::cout << "Numero no valido! " << std::endl;
		this->pedirNumero(mensaje);
	}
	return numeroIngresado;
}

uint Arbitro::tomarTipoDeJugada(){
	std::string pedido = "Ingrese el numero de la opcion elegida: \n";
	std::string opcion1 = "1) Colocar / quitar bandera \n";
	std::string opcion2 = "2) Descubrir casillero \n";
	std::string mensajeDeOpciones = pedido + opcion1 + opcion2;

	uint tipoDeJugada = pedirNumero(mensajeDeOpciones, 3);
	
	return tipoDeJugada;

}

void Arbitro::tomarUbicacionDeJugada(){
	this->filaDeJugada = pedirNumero("Por favor, ingrese la fila donde desea realizar la jugada");
	this->columnaDeJugada = pedirNumero("Por favor, ingrese la columna donde desea realizar la jugada");
	if ( (filaDeJugada > this->filaMaxima) || (columnaDeJugada > this->columnaMaxima) )
		this->tomarUbicacionDeJugada();
}

	

void Arbitro::tomarJugada(){
	Jugador jugador = this->devolverTurno();
	Puntaje puntajes(this->dificultad);
	int puntajeJugador;
	uint opcionElegida = tomarTipoDeJugada();
	/*aca ya tengo la jugada
	 1 colocar o quitar bandera
	 2 descubrir casillero*/
	tomarUbicacionDeJugada();
	//evaluar la jugada
	if (opcionElegida == 1){
		Bandera unaBandera ((int)this->filaDeJugada, this->columnaDeJugada, &jugador);
							
		//si no hay bandera poner bandera
		if (!this->existeBandera(unaBandera)){
				//agrego la bandera
				this->listaDeBanderas.agregarElemento(unaBandera);
				if (unaBandera.banderaBienColocada()){ // es una bandera donde hay bomba
					puntajeJugador = puntajes.devolverPuntos();
				} else { // no hay bomba ahi
					puntajeJugador = -puntajes.devolverPuntos();
				}
				jugador.asignarPuntaje(puntajeJugador);
			
		} else { // existe entonces 
			
				// si no pertenece a este jugador entonces la quita		
				Jugador* propietarioBandera = unaBandera.obtenerJugador();
				if (jugador.consultarNombre() == propietarioBandera->consultarNombre()){ //es el mismo
					// eliminar bandera de la lista 
					/********* hacer una funcion ******/
				} else { // es otro, caso en que corrige jugada del otro
					if (unaBandera.banderaBienColocada()){ // es una bandera donde hay bomba
						// la quita pero le resta puntos porque si habia bomba
						puntajeJugador = -puntajes.devolverPuntosEspeciales();
					
					} else { // era una bandera mal puesta
						puntajeJugador = puntajes.devolverPuntosEspeciales();
					}
					//eliminar bandera de la lista
					jugador.asignarPuntaje(puntajeJugador);
				}
		}
		
	} else { //opcion 2
		// ver si las coordenadas son validas
		
	//al destapar un casillero
	//si hay bomba
		jugador.asignarEstado(true); // (perdio)
		// sino 
			//mostrar bombas circundantes
		
		
}
}

uint Arbitro::devolverColumnaDeJugada(){
	return columnaDeJugada-1;
}

uint Arbitro::devolverFilaDeJugada(){
	return filaDeJugada-1;
}

std::string Arbitro::devolverTipoDeJugada(){
	//Sacar del objeto Jugada
	return "bandera";
}

Jugador Arbitro::devolverTurno(){
	return listaDeJugadores.obtenerCursor();
}
	
void Arbitro::declararTurno(){
	Jugador jugador = listaDeJugadores.obtenerCursor();
	std::cout << "Es el turno del jugador "<< jugador.consultarNombre() << std::endl;

}
	
int Arbitro::devolverPuntaje(int puntos, Jugador recienJugo){
	if(puntos == 0)
	return -1;
	recienJugo.asignarPuntaje(puntos); // ???
	return recienJugo.consultarPuntaje();
}

bool Arbitro::terminoElJuego(){
	return finDeJuego;
}
void Arbitro::inicializarListaDeJugadores(cadena* nombres, int cantidadJugadores){
	for(int i = 0; i < cantidadJugadores; i++){
	Jugador jugador(nombres[0], i);
	listaDeJugadores.agregarElemento(jugador);
	}
}

void Arbitro::inicializarListaDeBombas(){
	if(this->dificultad == 1){
		crearBombas((this->filaMaxima * this->columnaMaxima) * 0.15);
	} else {
		if(this->dificultad == 2){
				crearBombas((this->filaMaxima * this->columnaMaxima) * 0.25);
			} else {
				crearBombas((this->filaMaxima * this->columnaMaxima) * 0.35);
			}
	}
}

void Arbitro::crearBombas(int cantBombas)
{
	while (cantBombas != 0)
	{
		int fila = rand() % (filaMaxima);
		int columna = rand() % (columnaMaxima) ;
		Bomba bomba(fila, columna);
		if(!existeBomba(bomba)){
		this->listaDeBombas.agregarElemento(bomba);
		}
		cantBombas--;
	}
}
bool Arbitro::existeBomba(Bomba bomba){
	 this->listaDeBombas.iniciarCursor();
	 while (listaDeBombas.avanzarCursor()) {
		 Bomba bombaEnLista = listaDeBombas.obtenerCursor();
		 if(bomba.obtenerCoordenadaX() == bombaEnLista.obtenerCoordenadaX()
				 && bomba.obtenerCoordenadaY() == bombaEnLista.obtenerCoordenadaY()){
			 return true;
		 }
	 }

	return false;
}

bool Arbitro::existeBandera(Bandera bandera){
	 this->listaDeBanderas.iniciarCursor();
	 while (listaDeBanderas.avanzarCursor()) {
		 Bandera banderaEnLista = listaDeBanderas.obtenerCursor();
		 if(bandera.obtenerCoordenadaX() == banderaEnLista.obtenerCoordenadaX()
				 && bandera.obtenerCoordenadaY() == banderaEnLista.obtenerCoordenadaY()){
			 return true;
		 }
	 }

	return false;
}
