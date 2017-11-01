/*
 * ppal.cpp
 *
 *  Created on: Oct 23, 2017
 *      Author: juan
 */

typedef unsigned int uint;

#include "Presentador.h"
#include "Dibujante.h"
#include "Arbitro.h"


int main(){

	bool jugarDeNuevo = true;
	bool sigueLaPartida = true;

	while(jugarDeNuevo){

		Presentador presentador;
		presentador.pedirDatosDeJuego();

		Dibujante dibujante( presentador.devolverColumnas(),
							 presentador.devolverFilas(),
							 presentador.devolverNumeroDeJugadores() );

		Arbitro arbitro( presentador.devolverDificultad(),
						 presentador.devolverNumeroDeJugadores(),
						 presentador.devolverFilas(),
						 presentador.devolverColumnas(),
			       		 presentador.devolverNombresDeLosJugadores() );

		while(sigueLaPartida){
			arbitro.avanzarTurno();
			arbitro.declararTurno();
			arbitro.tomarJugada();

			if(arbitro.devolverTipoDeJugada() == "0"){
				for(int nFila = -1; nFila < 2; nFila++){
					for(int nColumna = -1; nColumna < 2; nColumna++ ){

						int columnaADescubrir = arbitro.devolverColumnaDeJugada() - nColumna;
			    		int filaADescubrir = arbitro.devolverFilaDeJugada() - nFila;
			            if( (filaADescubrir > 0 ) && (columnaADescubrir > 0) &&
			            	(filaADescubrir <= (int)arbitro.devolverFilaMaxima() ) &&
							columnaADescubrir <= (int)arbitro.devolverColumnaMaxima() ){

			            	uint cantidadDeCircundantes = arbitro.evaluarBombasCircundantes(columnaADescubrir, filaADescubrir);
							std::ostringstream ossNumeroADibujar;
							ossNumeroADibujar << cantidadDeCircundantes;
							std::string numeroADibujar = ossNumeroADibujar.str();
							dibujante.cambiarCuadrante( columnaADescubrir -1, filaADescubrir -1, numeroADibujar, 0, false);
			            }
			        }
				}
			} else {
				dibujante.cambiarCuadrante( arbitro.devolverColumnaDeJugada() -1,
											arbitro.devolverFilaDeJugada() -1,
											arbitro.devolverTipoDeJugada(),
											arbitro.devolverTurno(),
											false);
			}
			dibujante.cambiarPuntaje( 	arbitro.devolverPuntaje(),
										arbitro.devolverTurno()  );
			dibujante.dibujarTablero();
			sigueLaPartida = ( ! arbitro.terminoLaPartida() );

		}

		presentador.consultarSiJugarDeNuevo();
		jugarDeNuevo = presentador.devolverSiJugarDeNuevo();
	}
	return 0;
}
