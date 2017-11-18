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
#include "Puntaje.h"
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

	/*
	 * Post: Pide que el usuario ingrese un numero hasta recibir uno mayor a cero.
	 * 		 Devuelve el numero ingresado.
	 */
	int pedirNumero(std::string mensaje);

	/*
	 * Post: Pide que el usuario ingrese un numero hasta recibir uno mayor a cero.
	 * 		 Devuelve el numero ingresado.
	 */
	int pedirNumero(std::string mensaje, int numeroMaximo);

	/*
	 * Post: Devuelve una std::string con el numero que se le paso
	 */
	std::string hacerCadena(int numero);

	/*
	 * Post: inicializa el tablero correspondiendo a la cantidad de filas y columnas pasadas
	 */
	void inicializarTablero();

	/*
	 *Post: Recibe el input de que tipo de jugada va a realizar, "Poner/quitar bandera", "descubrir un casillero"
	 */
	int tomarTipoDeJugada();

	/*
	 *Post Toma las coordenadas en la que se realizara la jugada
	 */
	void tomarUbicacionDeJugada();

	/*
	 * Asigna aleatoriamente la cantidad de bombas que reciba el parametro
	 */
	void crearBombas(int cantBombas);

	 /*
	  * Indica si existe una bomba en ese lugar
	  */
	bool hayBomba(int fila, int columna);

	 /*
	  * Post: Indica si existe una bandera en ese lugar
	  */
	bool hayBandera();

	/*
	 * Post: Indica true si no quedan casilleros sin bomba por descubrir
	 */
	bool noQuedanCasilleros();


	/* Pre: 	El casillero de jugada existe
	 * Post: 	Si no hay una bandera la coloca,
	 * 			si hay y era del mismo jugador la saca sin que pase nada,
	 * 			si es de otro, se toma como corregir a otro jugador y se puntua.
	 */
	void cambiarBandera(int jugadorActual);

	/* Pre: 	El casillero esta dentro del tablero
	 * Post: 	Si tiene una bomba se elimina al jugador,
	 * 			si no, revisa si tiene bombas al rededor.
	 * 			si tiene, muestra el numero de bombas
	 * 			si no tiene, actúa también sobre los casilleros de alrededor
	 */
	void descubrirCasillero(int columnaDeCasillero, int filaDeCasillero, int jugadorActual);



  public:

	/* Pre: Se le pasan numeros naturales.
	 * Post: Crea un arbitro listo para pasarle jugadas
	 */
	Juego(int dificultadPedida, int numeroDeJugadores, int filas, int columnas, std::string* listaDeNombresDeJugadores);

	/*
	 * Post: El jugador actual es el siguiente en la lista
	 */
	void avanzarTurno();

	/*
	 * Post: Le toma la jugada al usuario.
	 * 		 Decide el resultado de la jugada.
	 */
	void tomarJugada();

	/*
	 *
	 */
	void descubrirCasillerosCircundantes(int fila, int columna);

	/*
	 *Post: indica a que jugador le corresponde hacer su jugada
	 */
	void declararTurno();

	/*
	 * Post: Remueve la bandera del casillero indicado
	 */
	void eliminarBandera(int columna, int fila);

	/*
	 * Post: devuelve true si termino la partida
	 */
	bool terminoLaPartida();

	/*
	 *Destructor
	 */
	~Juego();

};



#endif /* JUEGO_H_ */
