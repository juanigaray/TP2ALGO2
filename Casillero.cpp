Casillero::Casillero(){
	this->hayMina = false;
	this->minasCircundantes = 0;
	this->hayBandera = false;
	this->esVisible = false;
}

bool Casillero::consultarMina(){
	return this->hayMina;
}

bool Casillero::consultarBandera(){
	return this->hayBandera;
}

void Casillero::hacerVisible(){
	this->esVisible = true;	
}

void Casillero::asignarMina(){
	this->hayMina = true;
}

void Casillero::asignarMinasCircundantes(unsigned int cantidad){
	this->minasCircundantes = cantidad;
}
 
void Casillero::colocarBandera(){
	this->hayBandera = true;
}

void Casillero::quitarBandera(){
	this->hayBandera = false;
}

//HAY QUE REVISAR LO DEL BMP
void Casillero::dibujar(){
	if ( this->esVisible){
		if (this->hayMina){
			std::cout << " X";
		} else{
			std::cout << " " << this->minasCircundantes;		
		}
	} else if (this->hayBandera) {
		std::cout << " ?";
	} else {
		std::cout << " -";
	}
}
