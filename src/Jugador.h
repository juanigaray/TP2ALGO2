#ifndef JUGADOR_H
#define JUGADOR_H

#include <iostream>
class Jugador{

	private:

		int puntaje;
		bool eliminado;
		std::string nombre;
		int numeroJugador;
	public:

		/* pre:
		 * post: Crea un jugador con valores iniciales y su nombre
		 */
		Jugador(std::string nom, int numeroJugador);

		Jugador();


		/*
		 * post: Asigna el puntaje al jugador
		 * la variable puntos es la cantidad de pntos que hizo en el turno
		 */
		void asignarPuntaje(int puntos);

		/* pre:
		 * post: Asigna el estador del jugador
		 * si fue eliminado lo pone en TRUE, sino FALSE
		 */
		void asignarEstado(bool opcion);

		/* pre:
		 * post: Devuelve el nombre del jugador
		 */
		std::string consultarNombre();

		/* pre:
		 * post: Devuelve el puntaje del jugador
		 */
		int consultarPuntaje();

		/* pre:
		 * post: Devuelve el numero del jugador
		 */
		int consultarNumero();

		/*
		 * post Devuelve el estado del jugador
		 */
		bool consultarEstado();



		/// se puede sacar d la lista de jugadores en vez de guardarlo aca
};


#endif
