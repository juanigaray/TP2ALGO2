/*
 * Arbitro.h
 *
 *  Created on: Oct 19, 2017
 *      Author: juan
 */
#ifndef JUEGO_H_
#define JUEGO_H_

#include <sstream>
#include <iostream>
#include <time.h>

#include "Jugador.h"
#include "Dibujante.h"
#include "Casillero.h"
#include "Arbitro.h"
#include "Tablero.h"

class Juego{

  private:

	std::string bomba;
	std::string bandera;
	std::string casilleroCubierto;
	std::string margen;

	Tablero tablero;

	Dibujante* dibujante;

	Arbitro* arbitro;

	int filaDeJugada;
	int columnaDeJugada;
	bool seDebeEliminarJugador;

  public:

	/*
	 * Pre: filas y columnas mayores a cero. lista de nombres no vacia.
	 * Post: El juego esta listo para ejecutarse.
	 */
	Juego(int dificultadPedida, int numeroDeJugadores, int filas, int columnas, std::string* listaDeNombresDeJugadores);


	//LOGICA DE JUEGO

	/*
	 * Post: El jugador actual es el siguiente en la lista
	 */
	void avanzarTurno();

	/*
	 * Pre: fila y columna validas, dentro del tablero.
	 * Post: corre descubrirCasillero() sobre cada casillero que circunda al de las coordenadas pasadas.
	 *
	 */
	void descubrirCasillerosCircundantes(int fila, int columna);

	/* Pre: 	El casillero esta dentro del tablero
	 * Post: 	Si tiene una bomba se elimina al jugador,
	 * 			si no, revisa si tiene bombas al rededor.
	 * 			si tiene, muestra el numero de bombas
	 * 			si no tiene, actúa también sobre los casilleros de alrededor
	 */
	void descubrirCasillero(int columnaDeCasillero, int filaDeCasillero, int jugadorActual);


	/* Pre: 	El casillero de jugada existe
	 * Post: 	Si no hay una bandera la coloca,
	 * 			si hay y era del mismo jugador la saca sin que pase nada,
	 * 			si es de otro, se toma como corregir a otro jugador y se puntua.
	 */
	void cambiarBandera(int jugadorActual);

	//UI

	/*
	 * Post: Pide que el usuario ingrese un numero hasta recibir uno mayor a cero.
	 * 		 Devuelve el numero ingresado.
	 */
	int pedirNumero(std::string mensaje);

	/*
	 * Post: Pide que el usuario ingrese un numero hasta recibir uno mayor a cero y menor o igual al numero maximo
	 * 		 Devuelve el numero ingresado.
	 */
	int pedirNumero(std::string mensaje, int numeroMaximo);

	/*
	 * Post: Le toma la jugada al usuario.
	 * 		 Decide el resultado de la jugada.
	 */
	void tomarJugada();

	/*
	 *Post: Recibe el input de que tipo de jugada va a realizar, "Poner/quitar bandera", "descubrir un casillero"
	 */
	int tomarTipoDeJugada();

	/*
	 *Post Toma las coordenadas en la que se realizara la jugada
	 */
	void tomarUbicacionDeJugada();

	/*
	 *Post: indica a que jugador le corresponde hacer su jugada
	 */
	void declararTurno();

	/*
	 * Post: dibuja el tablero en su estado actual.
	 */
	void dibujarTablero();

	/* Pre: terminoLaPartida()
	 * Post: Anuncia el jugador que ha ganado.
	 * 		 Si es un solo jugador, anuncia si gano o perdio
	 */
	void anunciarResultado(bool esMultijugador);

	/*
	 * Post: devuelve true si termino la partida
	 */
	bool terminoLaPartida(bool esMultijugador);

	/*
	 * Post: indica que no quedan casilleros por descubrir
	 */
	bool noQuedanCasilleros();

	/*
	 * Post: Devuelve una std::string con el numero que se le paso
	 */
	std::string hacerCadena(int numero);

	/*
	 * Libera la memoria pedida para el DIBUJANTE y el ARBITRO.
	 *
	 */
	~Juego();

};



#endif /* JUEGO_H_ */
