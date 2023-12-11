#include "Filme.hpp"

Filme::Filme(){}

Filme::Filme(int codigoNumeroFilme, std::string tituloFilme, int numeroUnidadesDisponiveis) {
	if (codigoNumeroFilme > 0 ) _codigoNumeroFilme = codigoNumeroFilme;
	else std::cout << "O código " << codigoNumeroFilme << " é inválido." << std::endl;
	if (!tituloFilme.empty()) _tituloFilme = tituloFilme;
	else std::cout << "O título do filme inserido é inválido." << std::endl;
	if (!(numeroUnidadesDisponiveis < 0)) _numeroUnidadesDisponiveis = numeroUnidadesDisponiveis;
	else std::cout << "Quantidade informada é inválida." << std::endl;
}

void Filme::setDVD() {bool _ehDVD = true;}

void Filme::diminuiUnidadesDisponiveis() {
	if (!_numeroUnidadesDisponiveis == 0) {_numeroUnidadesDisponiveis--;}
	else throw std::invalid_argument("Unidades disponíveis é igual a 0.");
}

void Filme::setFitaVideo() {bool _ehDVD = false;}

int Filme::getCodigoNumeroFilme() const {return _codigoNumeroFilme;}

std::string Filme::getTituloFilme() const {return _tituloFilme;}

int Filme::getNumeroUnidadesDisponiveis() {return _numeroUnidadesDisponiveis;}

Filme::~Filme(){}