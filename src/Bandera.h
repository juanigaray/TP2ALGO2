
#ifndef BANDERA_H
#define BANDERA_H
#endif

#include "Comunes.h"

class Bandera{
private:

	int jugadorQueColoco;
	bool existe;

public:

	//Post: hayBandera() y obtenerJugador() devuelve parametro
	Bandera(uint colocadaPor);

	//Post: No hayBandera() y obtenerJugador() devuelve cero
	Bandera();

	//Post: Devuelve quien coloco la bandera
	uint obtenerJugador();

	//Post: Indica si hay una bandera
	bool hayBandera();

	//Post: No hayBandera()  y obtenerJugador() devuelve cero
	void eliminarBandera();

	/* Pre: No hayBandera()
	 * Post: hayBandera() y obtenerJugador() devuelve parametro
	 */
	void colocarBandera(uint colocadaPor);
};
