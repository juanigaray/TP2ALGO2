#ifndef CASILLERO_H_
#define CASILLERO_H_

#include "Bandera.h"

class Casillero{

 private:

	 bool bomba;
	 bool esVisible;
	 Bandera* bandera;

 public:

	 /*
	  * Post: Crea casillero sin bomba o bandera y tapado
	  */
	 Casillero();

	 /*
	  * Post: Crea casillero tapado, sin bandera. Si tiene o no bomba depende de conBomba
	  */
	 Casillero(bool conBomba);

	 /*
	  *Post coloca la bandera en el casillero elegido
	  */
	 void colocarBandera(int jugador);

	 /*
	  * Post quita la bandera en el casillero elegido
	  */
	 void quitarBandera();

	 /* Pre: El casillero tiene bandera
	  * Post: Devuelve quien la puso.
	  */
	 int quienPusoLaBandera();

	 /*
	  *Post Devuelve si tiene bomba el casillero
	  */
	 bool tieneBomba();

	 /*
	  *Post Devuelve si tiene Bandera el casillero
	  */
	 bool tieneBandera();

	 /*
	  *Post Devuelve si fue descubierto el casillero
	  */
	 bool estaDescubierto();

	 /*
	  *Post destapa el casillero
	  */
	 void destapar();

	 /*
	  * Post: Libera los recursos asociados, especificalente los pedidos para la bandera
	  */
	 ~Casillero();
 };



#endif /* CASILLERO_H_ */
