#ifndef JUEGO_H_
#define JUEGO_H_

#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <cstdlib>
#include "Dibujante.h"

using namespace std;

typedef unsigned int uint;

class Juego{

	private:

		uint dificultad;
		uint cantJugadores;
		uint filas;
		uint columnas;


		/*
		 * post: Juego creado con valores iniciales.
		 */
		Juego();

		/*
		 * post: Muestra mensaje de ayuda.
		void ayuda();

		/* Pide la cantidad de jugadores. se valida la entrada
		 * post: Asigna la cantidad de jugadores..
		 */
		void pedirJugadores();

		/* Pide las dimensiones del tablero. se valida la entrada.
		 * post: Asigna las dimensiones del tablero.
		 */
		void pedirDimensiones();

		/* Pide el nivel de dificultad.
		 * Valida que sean los valores 1, 2 o 3.
		 * post: Asigna la dificultad.
		 */
		void modificarDificultad();

		/*
		 * post: Devuelve cantidad de filas.
		 */
		uint devolverFilas();

		/*
		 * post: Devuelve cantidad de columnas.
		 */
		uint devolverColumnas();

		/*
		 * post: Devuelve grado de dificultad.
		 */
		uint devolverDificultad();

		/*
		 * post: Devuelve cantidad de jugadores.
		 */
		uint devolverCantJugadores();

		/*
		 * post: modifica el valor de dificultad.
		 */
		void modificarDificultad();

		/* llama a dibujante y a arbitro.
		 * post: inicia una nueva partida.
		 */
		void jugar();


	public:

		/*
		 * post: inicia el juego
		 */
		void iniciar();


};

#endif /* JUEGO_H_ */
