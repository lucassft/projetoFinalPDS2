#include "Filme.hpp"

Filme::Filme(){}

Filme::Filme(int codigoNumeroFilme, std::string tituloFilme, int numeroUnidadesDisponiveis) {
			_codigoNumeroFilme = codigoNumeroFilme;
			_tituloFilme = tituloFilme;
			_numeroUnidadesDisponiveis = numeroUnidadesDisponiveis;
}

void Filme::setDVD() {bool _ehDVD = true;}

void Filme::diminuiUnidadesDisponiveis() {_numeroUnidadesDisponiveis--;}

void Filme::setFitaVideo() {bool _ehDVD = false;}

int Filme::getCodigoNumeroFilme() const {return _codigoNumeroFilme;}

std::string Filme::getTituloFilme() const {return _tituloFilme;}

int Filme::getNumeroUnidadesDisponiveis() {return _numeroUnidadesDisponiveis;}

Filme::~Filme(){}