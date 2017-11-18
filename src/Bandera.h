
#ifndef BANDERA_H
#define BANDERA_H
#endif

class Bandera{
private:

	int jugadorQueColoco;
	bool existe;

public:

	//Post: hayBandera() y obtenerJugador() devuelve parametro
	Bandera(int colocadaPor);

	//Post: No hayBandera() y obtenerJugador() devuelve cero
	Bandera();

	//Post: Devuelve quien coloco la bandera
	int obtenerJugador();

	//Post: Indica si hay una bandera
	bool hayBandera();

	/* Pre: No hayBandera()
	 * Post: hayBandera() y obtenerJugador() devuelve parametro
	 */
	void colocarBandera(int colocadaPor);
};
