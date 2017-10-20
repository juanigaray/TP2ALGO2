#ifndef JUGADOR_H_
#define JUGADOR_H_


class Jugador{

	private:

		int puntaje;
		bool eliminado;
		std::string nombre;

	public:

		/* pre:
		 * post: Crea un jugador con valores iniciales y su nombre
		 */
		Jugador(std::string nom);

		/*
		 * post: Asigna el puntaje al jugador
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

		/*
		 * post Devuelve el estado del jugador
		 */
		bool consultarEstado();



		/// se puede sacar d la lista de jugadores en vez de guardarlo aca
};

#endif /* JUGADOR_H_ */
