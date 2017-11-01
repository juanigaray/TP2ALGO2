/*
 * Arbitro.h
 *
 *  Created on: Oct 19, 2017
 *      Author: juan
 */
#ifndef ARBITRO_H_
#define ARBITRO_H_

#include <sstream>
#include "Lista.h"
#include "Jugador.h"
#include "Bomba.h"
#include "Bandera.h"
#include "Puntaje.h"

typedef unsigned int uint;
typedef std::string cadena;

class Arbitro{

  private:

	uint dificultad;
	uint cantJugadores;
	uint filaMaxima;
	uint columnaMaxima;

	uint columnaDeJugada;
	uint filaDeJugada;

	bool finDeJuego;
	Jugador* jugadorActual;

	Lista<Jugador> listaDeJugadores;
	Lista<Bomba> listaDeBombas;
	Lista<Bandera> listaDeBanderas;

	cadena tipoDeJugada;

	/*
	 * Post inicializa la lista de jugadores con los jugadores creados
	 */
	void inicializarListaDeJugadores(cadena* nombres, int cantidadJugadores);

	/*
	 * Post inicializa la lista de bombas acorde al nivel
	 * con la cantidad de bombas para cada nivel
	 */
	void inicializarListaDeBombas();

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

	/*para cancer de
	 *
	 */
	uint tomarTipoDeJugada();

	/*
	 *
	 */
	void tomarUbicacionDeJugada();

	/*
	 * crea aleatoriamente la cantidad de bombas que reciba el parametro
	 * mayores a cero
	 */
	void crearBombas(int cantBombas);

	 /*
	  * Checkea que no existe una bomba en ese lugar
	  */
	bool existeBomba(Bomba bomba);

	 /*
	  * Checkea que no existe una bandera en ese lugar
	  */
	bool existeBandera(Bandera bandera);

	/*
	 * Devuelve un jugador. lo obtiene de la lista
	 */
	Jugador devolverJugador();

  public:
	/* Pre: Se le pasan numeros naturales.
	 * Post: Crea un arbitro listo para pasarle jugadas
	 */
	Arbitro(uint dificultadPedida, uint numeroDeJugadores, uint filas, uint columnas, cadena* listaDeNombresDeJugadores);

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
	 * Post: evalua la jugada y asigna puntajes.
	 * elimina al jugador en caso que destape una bomba
	 */
	void evaluarJugada();

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
	 * PRE; La lista debe estar iniciada con el cursor iniciado
	 * Post: Devuelve el numero de jugador que realizo la ultima jugada.
	 * No avanza el cursor
	 */
	uint devolverTurno();

	/*
	 *
	 */
	void declararTurno();

	/*
	 * Post: Devuelve el puntaje total del jugador que jugo ultimo.
	 *	 Devuelve -1 si no se modifica.
	 */
	int devolverPuntaje();

	/*
	 * Post:
	 */
	bool terminoElJuego();

	/*
	 * Post
	 */
	void eliminarBandera(Bandera bandera);




};



#endif /* ARBITRO_H_ */
