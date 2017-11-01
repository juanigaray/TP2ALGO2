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
			              if( (filaADescubrir > -1 ) && (columnaADescubrir > -1) ){
			            	  std::string numeroADibujar = arbitro.devolverCircundantes(columnaADescubrir, filaADescubrir);
			                  dibujante.cambiarCuadrante( columnaADescubrir, filaADescubrir, numeroADibujar, 0, false);
			              }
			            }
			        }

			} else {
				dibujante.cambiarCuadrante( arbitro.devolverColumnaDeJugada(),
											arbitro.devolverFilaDeJugada(),
											arbitro.devolverTipoDeJugada(),
											arbitro.devolverTurno(),
											false);

			dibujante.cambiarPuntaje( 	arbitro.devolverPuntaje(),
										arbitro.devolverTurno()  );
			dibujante.dibujarTablero();

			sigueLaPartida = ( ! arbitro.terminoElJuego() );
		}
		presentador.consultarSiJugarDeNuevo();
		jugarDeNuevo = presentador.devolverSiJugarDeNuevo();
	}
	return 0;
}

if(arbitro.devolverTipoDeJugada() == "0"){
        for(int dFila = -1; dFila < 2; dFila++){
            for(int dColumna = -1; dColumna < 2; dColumna++ ){

                int columnaADescubrir = arbitro.devolverColumnaDeJugada() - dColumna;
                int filaADescubrir = arbitro.devolverFilaDeJugada() - dFila;
                if( (filaADescubrir > -1 ) && (columnaADescubrir > -1) ){

                    std::string numeroADibujar = arbitro.devolverCircundantes(columnaADescubrir, filaADescubrir);
                    dibujante.cambiarCuadrante( columnaADescubrir, filaADescubrir, numeroADibujar, 0, false);
                }
            }
        }
    }
