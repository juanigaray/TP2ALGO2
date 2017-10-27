#ifndef BOMBA_H
#define BOMBA_H
#endif

typedef int Coordenada[2];
class Bomba{
private:
	Coordenada coordenadas;

public:

	//POST CREA LA BOMBA CON LAS COORDENADAS
	Bomba(int coordeanadaX, int coordenadaY);

	//POST DEVUELVE COORDENADA X
	int obtenerCoordenadaX();

	//POST DEVUELVE COORDENADA Y
	int obtenerCoordenadaY();

	//POST CAMBIA LA COORDENADA X
	void cambiarCoordenadaX(int nuevaX);

	//POST CAMBIA LA COORDENADA Y
	void cambiarCoordenadaY(int nuevaY);

	//Post cambia el estado de un jugador
	void eliminarJugador(Jugador jugador);

};
