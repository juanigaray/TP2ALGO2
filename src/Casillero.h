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
	 Bandera bandera;

 public:

	 /*
	  *
	  */
	 Casillero();

	 /*
	  *
	  */
	 uint quienPusoLaBandera();

	 /*
	  *
	  */
	 bool tieneBomba();


 };



#endif /* CASILLERO_H_ */
