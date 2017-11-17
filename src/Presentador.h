/*
 * Presentador.h
 *
 *  Created on: Oct 19, 2017
 *      Author: juan
 */

#ifndef PRESENTADOR_H_
#define PRESENTADOR_H_

#include <iostream>

#include "Comunes.h"

class Presentador{
  private:

	int dificultad;
	int cantJugadores;
	cadena* listaDeNombresDeJugadores;
	int filas;
	int columnas;
	bool jugarDeNuevo;

	/*
	 * Post: Pide que el usuario ingrese un numero hasta recibir uno mayor a cero.
	 * 		 Devuelve el numero ingresado.
	 */
	int pedirNumero(std::string mensaje, int numeroMaximo);

	/*
	 * Post: Pide que el usuario ingrese un numero hasta recibir uno mayor a cero.
	 * 		 Devuelve el numero ingresado.
	 */
	int pedirNumero(std::string mensaje);

	/*
	 * Post: Pide las dimensiones del tablero hasta recibir datos validos.
	 *
	 */
	void pedirDimensionesDelTablero();

	/*
	 * Post: Pide cantidad de jugadores hasta recibir un dato valido.
	 */
	void pedirNumeroDeJugadores();

	/*
	 * Post: Pide cantidad de jugadores hasta recibir
	 * "devolverNumeroDeJugadores()" datos validos.
	 */
	void pedirNombresDeJugadores();

	/*
	 * Post: Pide cantidad y nombres de los jugadores hasta recibir datos validos.
	 */
	void pedirDatosDeJugadores();

	/*
	 * Post: Pide el nivel de dificultad  hasta recibir datos validos (1, 2 o 3).
	 */
	void pedirDificultad();


  public:

	/*
	 * Post: Se crea un presentador listo para pedir los datos del juego.
	 */
	Presentador();

	//void mostrarPresentacion();

	/* Post: Pide datos de jugadores y dimensiones de tablero hasta recibir datos validos.
	 */
	void pedirDatosDeJuego();

	/* Pre: Se corrio pedirDatosDeJuego().
	 * Post: Devuelve el numero de columnas ingresado por el usuario.
	 */
	int devolverColumnas();

	/* Pre: Se corrio pedirDatosDeJuego().
	 * Post: Devuelve el numero de filas ingresado por el usuario.
	 */
	int devolverFilas();

	/* Pre: Se corrio pedirDatosDeJuego().
	 * Post: Devuelve el numero de jugadores pedido por el usuario.
	 */
	int devolverNumeroDeJugadores();

	/* Pre: Se corrio pedirDatosDeJuego().
	 * Post: Devuelve el numero de dificultad pedido por el usuario.
	 */
	int devolverDificultad();

	/* Pre: Se corrio pedirDatosDeJuego().
	 * Post: Devuelve el array de los nombres de los jugadores.
	 */
	std::string* devolverNombresDeLosJugadores();

	void declararFinDelJuego();

	/*
	 * Post: Consulta al usuario si quiere jugar una nueva partida.
	 */
	void consultarSiJugarDeNuevo();

	/* Pre: Se corrio consultarSiJugarDeNuevo().
	 * Post: Devuelve la eleccion del usuario.
	 */
	bool devolverSiJugarDeNuevo();

	~Presentador();

};




#endif /* PRESENTADOR_H_ */
