#ifndef JUGADOR_H
#define JUGADOR_H

#include <iostream>

class Jugador{

	private:

		int puntaje;
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
		void sumarPuntaje(int puntos);

		/* pre:
		 * post: Devuelve el nombre del jugador
		 */
		std::string consultarNombre() const;

		/* pre:
		 * post: Devuelve el puntaje del jugador
		 */
		int consultarPuntaje() const;

		/* pre:
		 * post: Devuelve el numero del jugador
		 */
		int consultarNumero() const;

		/*
		 *Post: Este jugador adquiere todos los atributos del jugador que se asigna.
		 */
		Jugador operator=(const Jugador& otroJugador);


		/// se puede sacar d la lista de jugadores en vez de guardarlo aca
};


#endif
