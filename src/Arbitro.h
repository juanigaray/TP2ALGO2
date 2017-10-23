/*
 * Arbitro.h
 *
 *  Created on: Oct 19, 2017
 *      Author: juan
 */
#ifndef ARBITRO_H_
#define ARBITRO_H_
#include <sstream>

typedef unsigned int uint;
typedef std::string cadena;

class Arbitro{

  private:

	uint dificultad;
	uint cantJugadores;
	uint filaMaxima;
	uint columnaMaxima;
	//Lista listaDeNombresDeJugadores;
	//Lista listaDeBombas;
	//Lista listaDeBanderas;

  public:
	/* Pre: Se le pasan numeros naturales.
	 * Post: Crea un arbitro listo para pasarle jugadas
	 */
	Arbitro(uint dificultadPedida, uint numeroDeJugadores, uint filas, uint columnas, cadena* listaDeNombresDeJugadores);
	
	/*
	 * Post: Le toma la jugada al usuario. 
	 * Decide el resultado de la jugada.
	 */
	void tomarJugada();
	
	/*
	 * Post: Devuelve en que columna se realizo la ultima jugada tomada.
	 */
	uint devolverColumnaDeJugada();
	
	/*
	 * Post: Devuelve en que columna se realizo la ultima jugada tomada.
	 */
	uint devolverFilaDeJugada();
	
	/*
	 * Post: Devuelve string con el tipo de jugada que se realizo.
	 */
	std::string devolverTipoDeJugada();
	
	/*
	 * Post: Devuelve el numero de jugador que realizo la ultima jugada.
	 */
	uint devolverTurno();
	
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

};



#endif /* ARBITRO_H_ */
