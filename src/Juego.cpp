#include "Juego.h"


void menuPrincipal();
bool validarNumeros(string cadena);


Juego::Juego(){

	this->dificultad = 1;
	this->cantJugadores = 0;
	this->filas = 0;
	this->columnas = 0;

}


void Juego::pedirJugadores(){

	string entrada;
	cout << "Ingresar la cantidad de jugadores: " ;
	cin >> entrada;

	if (validarNumeros(entrada)){
		uint numJugadores = atoi(entrada.c_str());
		this->cantJugadores = numJugadores;
	} else { // si no es un numero vuelve a llamar
		this->pedirJugadores();
	}
}


void Juego::pedirDimensiones(){

	string entrada_fil, entrada_col;
	cout << "Ingresar dimensiones del tablero: " << endl;

	cout << "Ingresar cantidad de filas: ";
	cin >> entrada_fil;
	cout << "Ingresar cantidad de columnas: ";
	cin >> entrada_col;

	if ( validarNumeros(entrada_fil) && validarNumeros(entrada_col) ){
		this->filas = atoi(entrada_fil.c_str());
		this->columnas = atoi(entrada_col.c_str());
	} else { // si no son numeros vuelve a llamar
		this->pedirDimensiones();
	}
}


void Juego::modificarDificultad(){

	string entrada;

	cout << "Niveles de dificultad:" << endl;
	cout << "  Facil: 1" << endl;
	cout << "  Medio: 2" << endl;
	cout << "  Avanzado: 3" << endl << endl;
	cout << "Ingresar dificultad: " ;
	cin >> entrada;

	if (validarNumeros(entrada)){
		uint dif = atoi(entrada.c_str());

		if ( (dif > 0) && (dif <= 3) )
			this->dificultad = dif;
		else // si no es un numero correcto vuelve a llamar
			this->modificarDificultad();

	} else { // si no es un numero vuelve a llamar
		this->modificarDificultad();
	}
}

uint Juego::devolverFilas(){
	return this->filas;
}

uint Juego::devolverColumnas(){
	return this->columnas;
}

uint Juego::devolverDificultad(){
	return this->dificultad;
}

uint Juego::devolverCantJugadores(){
	return this->cant_jugadores;
}

void Juego::iniciar(){

	titulo();
	this->pedirJugadores();
	this->pedirDimensiones();

	system("clear");
	bool salir = false;
	string input;

	do{

		titulo();
		menuPrincipal();
		cin >> input;
		int opcion = atoi(input.c_str());

		switch (opcion){

			case 1:
				this->jugar();
				break;

			case 2:
				this->modificarDificultad();
				break;

			case 3:
				system("clear");
				titulo();
				cout << endl;
				ayuda();
				break;

			case 4:
				salir = true;
				system("clear");
				titulo();
				cout << endl;
				cout << " Adios!" << endl;
				break;

			default:
				system("clear");
				cout << endl;
				cout << " Ingesar una opcion valida" << endl;
				}

	}while(!salir);
}

void Juego::jugar(){


	 bool continuarPartida = true;

	 Dibujante dibujante(this->devolverColumnas(),
			 	 	 	 this->devolverFilas(),
						 this->devolverCantJugadores());

	 Arbitro arbitro(this->devolverDificultad(),
	 	 	 	 	 this->devolverCantJugadores());


	 do{

		 arbitro.declararTurno();
		 arbitro.tomarJugada();

		 dibujante.cambiarCuadrante(arbitro.devolverColumnaDeJugada(),
		 							arbitro.devolverFilaDeJugada(),
		 							arbitro.devolverTipoDeJugada(),
		 							arbitro.devolverTurno());


		 continuarPartida = ( ! arbitro.terminoElJuego() );
	 }while (continuarPartida);

}


void titulo(){
	cout << endl;
	cout << " ******************************************************" << endl;
	cout << " ********************* BUSCAMINAS *********************" << endl;
	cout << " ******************************************************" << endl;
}


void menuPrincipal(){
	cout << endl;
	cout << " 1- Nueva partida"  << "   2- Dificultad" << "   3- Ayuda" <<  "   4- Salir" << endl;
	cout << endl;
}


bool validarNumeros(string cadena){
	for(int i = 0; i < (int)cadena.length(); i++)
		if (!isdigit(cadena[i]) && (cadena[i]!= '\n'))
			return false;
	return true;
}
