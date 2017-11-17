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
#include <stdlib.h>
#include <time.h>
#include "Jugador.h"
#include "Puntaje.h"
#include "Dibujante.h"
#include "Casillero.h"
#include "Arbitro.h"
#include "Comunes.h"

class Juego{

  private:

	cadena bomba;
	cadena bandera;
	cadena casilleroCubierto;
	cadena margen;

	Dibujante* dibujante;

	Casillero*** tablero; //Es un array * de arrays * de punteros *

	int filaMaxima;
	int columnaMaxima;

	Arbitro* arbitro;

	int bombasTotales;
	int casillerosDestapados;

	int filaDeJugada;
	int columnaDeJugada;
	//VER DIFERENCIA DE PUNTAJE

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
	 * Post: Devuelve una cadena con el numero que se le paso
	 */
	cadena hacerCadena(int numero);

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

	/*
	 * Post: Crea un casillero sin bomba, sin bandera y tapado
	 */
	void prepararCasillero(int columnaDeCasillero, int filaDeCasillero);

	/* Pre: 	El casillero de jugada existe
	 * Post: 	Si no hay una bandera la coloca,
	 * 			si hay y era del mismo jugador la saca sin que pase nada,
	 * 			si es de otro, se toma como corregir a otro jugador y se puntua.
	 */
	void cambiarBandera(int jugadorActual);

	/* Pre: 	El casillero esta dentro del tablero
	 * Post: 	Si tiene una bomba elimina al jugador,
	 * 			si no, destapa el casillero y evalua los circundantes
	 */
	void descubrirCasillero(int columnaDeCasillero, int filaDeCasillero, int jugadorActual);



  public:

	/* Pre: Se le pasan numeros naturales.
	 * Post: Crea un arbitro listo para pasarle jugadas
	 */
	Juego(int dificultadPedida, int numeroDeJugadores, int filas, int columnas, cadena* listaDeNombresDeJugadores);

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
	 * Pre: se pasa una coordenada valida.
	 * Post: Devuelve la cantidad de bombas que rodean el casillero
	 */
	int evaluarBombasCircundantes(int columnaDeCasillero, int filaDeCasillero);

	/*
	 *
	 */
	void descubrirCasillerosCircundantes(int fila, int columna);

	/*
	 *
	 */
	bool validarCoordenada(int fila, int columna);

	/*
	 * Post: Devuelve en que columna se realizo la ultima jugada tomada.
	 */
	int devolverColumnaDeJugada();

	/*
	 * Post: Devuelve en que fila se realizo la ultima jugada tomada.
	 */
	int devolverFilaDeJugada();

	/*
	 *Post: indica a que jugador le corresponde hacer su jugada
	 */
	void declararTurno();

	/*
	 * Post: Devuelve el puntaje total del jugador que jugo ultimo.
	 *	 	 Devuelve 0 si el puntaje es negativo
	 */
	int devolverPuntaje();

	/*
	 *Post: Indica si el casillero tiene bandera o no
	 */
	bool tieneBandera();

	/*
	 *Post: Indica si el casillero tiene bomba o no
	 */
	bool tieneBomba();

	/*
	 *Post: Indica si el casillero esta destapado
	 */
	bool estaDescubierto();

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
