/*
 * Arbitro.h
 *
 *  Created on: Oct 19, 2017
 *      Author: juan
 */
#ifndef JUEGO_H_
#define JUEGO_H_

#include <sstream>
#include "Jugador.h"
#include "Puntaje.h"
#include "Dibujante.h"
#include "Casillero.h"
#include "ClasesComunes.h"
#include "Arbitro.h"

class Juego{

  private:

	Dibujante* dibujante;

	Casillero* tablero;

	uint filaMaxima;
	uint columnaMaxima;

	Arbitro* arbitro;

	uint filaDeJugada;
	uint columnaDeJugada;

	Jugador* jugadorActual;
	uint diferenciaDePuntaje;

	/*
	 * Post: Pide que el usuario ingrese un numero hasta recibir uno mayor a cero.
	 * 		 Devuelve el numero ingresado.
	 */
	uint pedirNumero(std::string mensaje);

	/*
	 * Post: Pide que el usuario ingrese un numero hasta recibir uno mayor a cero.
	 * 		 Devuelve el numero ingresado.
	 */
	uint pedirNumero(std::string mensaje, uint numeroMaximo);

	/*
	 * Post: Devuelve una cadena con el numero que se le paso
	 */
	cadena hacerCadena(int numero);

	/*
	 *
	 */
	void inicializarTablero();

	/*
	 *
	 */
	uint tomarTipoDeJugada();

	/*
	 *
	 */
	void tomarUbicacionDeJugada();

	/*
	 * Asigna aleatoriamente la cantidad de bombas que reciba el parametro
	 */
	void crearBombas(uint cantBombas);

	 /*
	  * Indica si existe una bomba en ese lugar
	  */
	bool hayBomba(uint fila, uint columna);

	 /*
	  * Indica si existe una bandera en ese lugar
	  */
	bool hayBandera();


  public:

	/* Pre: Se le pasan numeros naturales.
	 * Post: Crea un arbitro listo para pasarle jugadas
	 */
	Juego(uint dificultadPedida, uint numeroDeJugadores, uint filas, uint columnas, cadena* listaDeNombresDeJugadores);

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
	uint evaluarBombasCircundantes(uint columnaDeCasillero, uint filaDeCasillero);

	/*
	 * Post: Devuelve en que columna se realizo la ultima jugada tomada.
	 */
	uint devolverColumnaDeJugada();

	/*
	 * Post: Devuelve en que fila se realizo la ultima jugada tomada.
	 */
	uint devolverFilaDeJugada();

	/*
	 * Post: Devuelve string con el tipo de jugada que se realizo.
	 */
	std::string devolverTipoDeJugada();

	/*
	 *
	 */
	void declararTurno();

	/*
	 * Post: Devuelve el puntaje total del jugador que jugo ultimo.
	 *	 	 Devuelve -1 si no se modifica.
	 */
	int devolverPuntaje();

	/*
	 * Post
	 */
	void eliminarBandera(uint columna, uint fila);

	/*
	 * Post: devuelve true si termino la partida
	 */
	bool terminoLaPartida();

};



#endif /* JUEGO_H_ */
