#include "Bicicleta.h"

// ATRIBUTOS ESTATICOS //

int Urbana::id = 1;
int UrbanaSimples::id = 1;
int Corrida::id = 1;
int Infantil::id = 1;


//////////////////////
// CLASSE BICICLETA //
//////////////////////

/**
 * Construtor padrao da classe Bicicleta.
 */
Bicicleta::Bicicleta(){};

/**
 * Construtor da classe Bicicleta.
 * @param name nome da bicicleta
 */
Bicicleta::Bicicleta(string name) : price(0) {
	bikeName = name;
	abate = Data (0,0,0);
}


// METODOS GET //

/**
 * @return Retorna o nome da bicicleta.
 */
string Bicicleta::getBikeName() const {
	return bikeName;
}

/**
 * @return Retorna o preco associado a um determinado tipo de bicicleta.
 */
int Bicicleta::getPrice() const {
	return price;
}

vector<string> Bicicleta::getAvarias() const {
	return avarias;
}

Data Bicicleta::getAbate() const {
	return abate;
}

// METODOS SET //

void Bicicleta::setAvarias(vector<string> novasAvarias) {
	avarias = novasAvarias;
}

void Bicicleta::setAbate(Data dataAbate) {
	abate = dataAbate;
}

////////////
// OTHERS //
////////////

void Bicicleta::addAvarias(string avaria){
	avarias.push_back(avaria);
}

///////////////////
// CLASSE URBANA //
///////////////////

/**
 * Construtor da classe Urbana.
 * @param bikeName nome da bicicleta
 */
Urbana::Urbana(string bikeName) : Bicicleta(bikeName){
	id++;
	price = 40;
}


// METODOS GET //

/**
 * @return Retorna o id responsavel por identificar a proxima bicicleta desta subclasse a ser adicionada.
 */
int Urbana::getID() {
	return id;
}


///////////////////////////
// CLASSE URBANA_SIMPLES //
///////////////////////////

/**
 * Construtor da classe UrbanaSimples.
 * @param bikeName nome da bicicleta
 */
UrbanaSimples::UrbanaSimples(string bikeName) : Bicicleta(bikeName){
	id++;
	price = 30;
}


// METODOS GET //

/**
 * @return Retorna o id responsavel por identificar a proxima bicicleta desta subclasse a ser adicionada.
 */
int UrbanaSimples::getID() {
	return id++;
}

////////////////////
// CLASSE CORRIDA //
////////////////////

/**
 * Construtor da classe Corrida.
 * @param bikeName nome da bicicleta
 */
Corrida::Corrida(string bikeName) : Bicicleta(bikeName){
	id++;
	price = 50;
}


// METODOS GET //

/**
 * @return Retorna o id responsavel por identificar a proxima bicicleta desta subclasse a ser adicionada.
 */
int Corrida::getID() {
	return id;
}

/////////////////////
// CLASSE INFANTIL //
/////////////////////

/**
 * Construtor da classe Infantil.
 * @param bikeName nome da bicicleta
 */
Infantil::Infantil(string bikeName) : Bicicleta(bikeName){
	id++;
	price = 20;
}


// METODOS GET //

/**
 * @return Retorna o id responsavel por identificar a proxima bicicleta desta subclasse a ser adicionada.
 */
int Infantil::getID() {
	return id;
}
