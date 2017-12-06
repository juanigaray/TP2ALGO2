/*
 * ppal.cpp
 *
 *  Created on: Oct 23, 2017
 *      Author: juan
 */


#include "Presentador.h"
#include "Dibujante.h"
#include "Juego.h"


int main(){

	bool jugarDeNuevo = true;
	bool finDeLaPartida;
	Presentador presentador;
	bool esMultijugador;

	while(jugarDeNuevo){

		try{

			finDeLaPartida = false;
			presentador.pedirDatosDeJuego();

			esMultijugador = (presentador.devolverNumeroDeJugadores() != 1);

			Juego juego( 	 presentador.devolverDificultad(),
							 presentador.devolverNumeroDeJugadores(),
							 presentador.devolverFilas(),
							 presentador.devolverColumnas(),
							 presentador.devolverNombresDeLosJugadores() );

			juego.avanzarTurno();

			do{

				if (esMultijugador){
					juego.declararTurno();
				}
				juego.tomarJugada();
				juego.avanzarTurno();
				finDeLaPartida = juego.terminoLaPartida();

			} while(! finDeLaPartida);

			presentador.consultarSiJugarDeNuevo();
			jugarDeNuevo = presentador.devolverSiJugarDeNuevo();

		} catch(std::string& error){

			std::cout << error << std::endl;

		}
	}
	return 0;
}

