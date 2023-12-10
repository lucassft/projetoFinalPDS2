#include "../include/EspecificacaoCadastroFilme/DVD.hpp"

void DVD::clienteAlugaDVD(int codigoFita) {
	if (verificaSaldoDVD(codigoFita)) {
		for (int i = 0; i < _DVDsCadastrados.size(); i++) {
			if (_DVDsCadastrados[i].getCodigoNumeroFilme() == codigoFita) {
				_DVDsCadastrados[i].diminuiUnidadesDisponiveis();
			}
		}
	} else std::cout << "ERRO: Filme <" << codigoFita << "> inexistente" << std::endl;
}

int DVD::retornaDevolucaoDVD(int codigoFita, int diasAlugado) {
	int total{0};
	for (int i = 0; i < _DVDsCadastrados.size(); i++) {
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

bool DVD::verificaSaldoDVD(int codigoDVD) {
	if (verificaCadastroDVD(codigoDVD) && getNumeroUnidadesDisponiveis() > 0) return true;
}

int DVD::qtdDVDsCadastrados() {
	int qtdDVDsCadastrados{0}; qtdDVDsCadastrados = _DVDsCadastrados.size();
	return qtdDVDsCadastrados;
}

DVD::DVD(int codigoNumeroFilme, std::string tituloFilme, int numeroUnidadesDisponiveis,
							int categoriaDVD) : Filme(codigoNumeroFilme, tituloFilme, numeroUnidadesDisponiveis) {
	_categoriaDVD = categoriaDVD;
	setDVD();
}

void DVD::cadastraDVDdoZero() {
	std::cout << "CF <Tipo: F|D> <quantidade> <código> <título>" << std::endl;
	int quantidadeDisponivelFitaVideo{0}, codigoDVD{0}; std::string tituloDVD{'0'};
	std::cin >> quantidadeDisponivelFitaVideo >> codigoDVD; getline(std::cin, tituloDVD);
	int lb = 0, ub = 1; bool rebobinada; rebobinada = (rand() % (ub - lb + 1)) + lb;
	if (!verificaCadastroDVD(codigoDVD)) {
		DVD dvd(codigoDVD, tituloDVD, quantidadeDisponivelFitaVideo, rebobinada);
		_DVDsCadastrados.push_back(dvd);
		std::cout << "Filme <" << codigoDVD << "> cadastrado com sucesso." << std::endl;
	} else std::cout << "ERRO: código repetido." << std::endl;
}

void DVD::cadastraDVDparametros(int codigo, std::string titulo, int quantidade, int categoriaDVD) {
	if (!verificaCadastroDVD(codigo)) {
		DVD dvd(codigo, titulo, quantidade, categoriaDVD);
		_DVDsCadastrados.push_back(dvd);
	}
}

void DVD::removeDVD(int codigoRemover) {
	int tamVetor = qtdDVDsCadastrados();
	if (verificaCadastroDVD(codigoRemover)) {
		for (int i = 0; i < tamVetor; i++) {
			if (_DVDsCadastrados[i].getCodigoNumeroFilme() == codigoRemover) { 
				_DVDsCadastrados.erase(_DVDsCadastrados.begin() + i);	
			} 
		} std::cout << "Filme <" << codigoRemover << "> removido com sucesso" << std::endl;
	} else std::cout << "ERRO: dados incorretos." << std::endl;
}

bool DVD::verificaCadastroDVD(int codigoDVD) {
	int tamVetor = qtdDVDsCadastrados();
	for (int i = 0; i < tamVetor; i++) {
		if (_DVDsCadastrados[i].getCodigoNumeroFilme() == codigoDVD) { return true;
		} else return false; // throw cpf não cadastrado
	} 
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