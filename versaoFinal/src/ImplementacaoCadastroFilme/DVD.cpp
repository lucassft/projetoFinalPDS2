#include "DVD.hpp"

DVD::DVD() {}

void DVD::clienteAlugaDVD(DVD& sistemaDVD, int codigoDVD) {
	if (verificaSaldoDVD(sistemaDVD, codigoDVD)) {
		for (unsigned int i = 0; i < sistemaDVD._DVDsCadastrados.size(); i++) {
			if (sistemaDVD._DVDsCadastrados[i].getCodigoNumeroFilme() == codigoDVD) {
				sistemaDVD._DVDsCadastrados[i].diminuiUnidadesDisponiveis();
			}
		}
	} else throw std::invalid_argument("ERRO: Filme inexistente");
}

int DVD::retornaDevolucaoDVD(DVD& sistemaDVD, int codigoFita, int diasAlugado) {
	if (verificaCadastroDVD(sistemaDVD, codigoFita)) {
		int total{0};
		for (unsigned int i = 0; i < _DVDsCadastrados.size(); i++) {
			switch (_categoriaDVD) {
			case 1:
				total += 20 * diasAlugado;
				break;
			case 2: 
				total += 10 * diasAlugado;
				break;
			default:
				total += 10;
				break;
			}
		} return total;
	}
	else throw std::invalid_argument("ERRO: Filme não cadastrado.");
}

bool DVD::verificaSaldoDVD(DVD& sistemaDVD, int codigoDVD) {
	if (verificaCadastroDVD(sistemaDVD, codigoDVD) && sistemaDVD.getNumeroUnidadesDisponiveis() > 0) return true;
	else throw std::invalid_argument("ERRO: Filme não cadastrado.");
}

int DVD::qtdDVDsCadastrados() {
	int qtdDVDsCadastrados{0}; qtdDVDsCadastrados = _DVDsCadastrados.size();
	return qtdDVDsCadastrados;
}

DVD::DVD(int codigoNumeroFilme, std::string tituloFilme, int numeroUnidadesDisponiveis,
							int categoriaDVD) : Filme(codigoNumeroFilme, tituloFilme, numeroUnidadesDisponiveis) {
	if (categoriaDVD > 0 && categoriaDVD << 4) {
		_categoriaDVD = categoriaDVD;
		setDVD();
	} else throw std::invalid_argument("Categoria DVD inválida.");
}

void DVD::cadastraDVDdoZero(DVD& sistemaDVD) {
	std::cout << "CF <Tipo: F|D> <quantidade> <código> <título>" << std::endl;
	int quantidadeDisponivelFitaVideo{0}, codigoDVD{0}; std::string tituloDVD{'0'};
	std::cin >> quantidadeDisponivelFitaVideo >> codigoDVD; getline(std::cin, tituloDVD);
	int lb = 0, ub = 1; bool rebobinada; rebobinada = (rand() % (ub - lb + 1)) + lb;
	if (!verificaCadastroDVD(sistemaDVD, codigoDVD)) {
		DVD dvd(codigoDVD, tituloDVD, quantidadeDisponivelFitaVideo, rebobinada);
		sistemaDVD._DVDsCadastrados.push_back(dvd);
		std::cout << "Filme <" << codigoDVD << "> cadastrado com sucesso." << std::endl;
	} else throw std::invalid_argument("ERRO: código repetido."); 
}

void DVD::cadastraDVDparametros(DVD& sistemaDVD, int codigoDVD, std::string tituloDVD, int quantidade, int categoriaDVD) {
	if (!verificaCadastroDVD(sistemaDVD, codigoDVD)) {
		DVD dvd(codigoDVD, tituloDVD, quantidade, categoriaDVD);
		sistemaDVD._DVDsCadastrados.push_back(dvd);
		std::cout << "Filme <" << codigoDVD << "> cadastrado com sucesso." << std::endl;
	}
}

void DVD::removeDVD(DVD& sistemaDVD, int codigoDVD) {
	int tamVetor = sistemaDVD.qtdDVDsCadastrados();
	if (verificaCadastroDVD(sistemaDVD, codigoDVD)) {
		for (unsigned int i = 0; i < tamVetor; i++) {
			if (_DVDsCadastrados[i].getCodigoNumeroFilme() == codigoDVD) { 
				_DVDsCadastrados.erase(_DVDsCadastrados.begin() + i);	
			} 
		} std::cout << "Filme <" << codigoDVD << "> removido com sucesso" << std::endl;
	} else throw std::invalid_argument("ERRO: dados incorretos.");
}

bool DVD::verificaCadastroDVD(DVD& sistemaDVD, int codigoDVD) {
	int tamVetor = sistemaDVD.qtdDVDsCadastrados();
	for (unsigned int i = 0; i < tamVetor; i++) {
		if (_DVDsCadastrados[i].getCodigoNumeroFilme() == codigoDVD) { return true;
		} 
	} throw std::invalid_argument("ERRO: CPF não cadastrado.");
}

DVD DVD::getDVDsCadastrados(int i) {
	return _DVDsCadastrados[i];
}

int DVD::getDVDsCadastradosCodigoFilme(int i) {
	return _DVDsCadastrados[i].getCodigoNumeroFilme();
}

void DVD::imprimeDVD() {
	std::cout << "< " <<getCodigoNumeroFilme() 
									  << " > < " 
									  << getTituloFilme()
									  << " > < "
									  << getNumeroUnidadesDisponiveis()
									  << " > < DVD >" 
									  << std::endl;
}

void DVD::listaDVDsCodigo() {
	std::sort(_DVDsCadastrados.begin(),_DVDsCadastrados.end(), SortCodigoDVD(0));
	for (unsigned int i = 0; i < _DVDsCadastrados.size(); i++) {
		_DVDsCadastrados.at(i).imprimeDVD();
	}
}

void DVD::listaDVDsTitulo() {
	std::sort(_DVDsCadastrados.begin(),_DVDsCadastrados.end(), SortCodigoDVD(1));
	for (unsigned int i = 0; i < _DVDsCadastrados.size(); i++) {
		_DVDsCadastrados.at(i).imprimeDVD();
	}
}

DVD::~DVD() {}