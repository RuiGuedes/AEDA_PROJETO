#pragma once

#include "Includes.h"

class Data {
protected:
	unsigned int dia, mes, ano;
public:
	Data();/**< Necess�rio para o overload do operador de extra��o na classe utente*/
	Data(unsigned int dia,unsigned int mes,unsigned int ano);
	friend ostream & operator<<(ostream & o, const Data & d);
	friend istream & operator>>(istream & i, Data & d);

	//M�todos Get
	unsigned int getDia() const;
	unsigned int getMes() const;
	unsigned int getAno() const;

	//M�todos Set
	void setDia(unsigned int d);
	void setMes(unsigned int m);
	void setAno(unsigned int a);

};

/**
 * Overload do operador de insercao usado para escrever os objetos do tipo Data nos ficheiros,
 * de modo a guardar a informacao do sistema.
 */
inline ostream & operator<< (ostream & o, const Data & d){
	o << d.dia << '/' << d.mes << '/' << d.ano;
	return o;
}

/**
 * Overload do operador de extracao usado para recolher dos ficheiros os objetos do tipo Data,
 * de modo a recriar o sistema da ultima execucao.
 */
inline istream & operator>> (istream & i, Data & d)
{
	char b1, b2;
	return i >> d.dia >> b1 >> d.mes >> b2 >> d.ano;
}


class Utilizacao : protected Data{
private:
	Data data;
	unsigned int useTime;/**< Numero de horas de uso da bicicleta*/
	string bikeType;/**< Tipo de bicicleta*/
	string pontoPartilha;/**< Nome do ponto de partilha onde a bicicleta foi alugada*/
	string localizacao;/**< Nome da localizacao do ponto de partilha onde a bicicleta foi alugada*/
public:
	Utilizacao(); /**< Necess�rio para o overload do operador de extra��o na classe utente*/
	Utilizacao(string bikeType, unsigned int numHours, Data d, string pp, string loc);
	friend ostream & operator <<(ostream & o, const Utilizacao & u);
	friend istream & operator >>(istream & i, Utilizacao & u);
	void displayUtilizacao() const;

	//M�todos Get
	Data getData() const;
	unsigned int getUseTime() const;
	string getBikeType() const;
	double getPrice() const;
};

/**
 * Overload do operador de insercao usado para escrever os objetos do tipo Utilizacao nos ficheiros,
 * de modo a guardar a informacao do sistema.
 */
inline ostream& operator <<(ostream & o, const Utilizacao & u)
{
	o << u.bikeType << '-' <<  u.pontoPartilha << '-' <<  u.localizacao << '-' << u.useTime << '-' <<  u.data ;
	return o;
}

/**
 * Overload do operador de extracao usado para recolher dos ficheiros os objetos do tipo Utilizacao,
 * de modo a recriar o sistema da ultima execucao.
 */
inline istream& operator >>(istream & i, Utilizacao & u)
{
	char b1;
	getline(i,u.bikeType,'-');
	getline(i,u.pontoPartilha,'-');
	getline(i,u.localizacao,'-');
	i >> u.useTime >> b1 >> u.data;
	return i;
}
