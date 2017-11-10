/*
 * Casillero.h
 *
 *  Created on: Nov 7, 2017
 *      Author: juan
 */

#ifndef CASILLERO_H_
#define CASILLERO_H_

#include "Bandera.h"
#include "ClasesComunes.h"

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
	  *
	  */
	 bool tieneBandera();

	 /*
	  *
	  */
	 void colocarBandera(uint jugador);

	 /*
	  *
	  */
	 void quitarBandera();

	 /* Pre: El casillero tiene bandera
	  * Post: Devuelve quien la puso.
	  */
	 uint quienPusoLaBandera();

	 /*
	  *
	  */
	 bool tieneBomba();

	 /*
	  *
	  */
	 void destapar();

 };



#endif /* CASILLERO_H_ */
