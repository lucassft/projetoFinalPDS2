#include "FitaVideo.hpp"

FitaVideo::FitaVideo() {}

void FitaVideo::clienteAlugaFitaVideo(FitaVideo& sistemaFitaVideo, int codigoFita) {
	if (verificaSaldoFitaVideo(sistemaFitaVideo, codigoFita)) {
		for (unsigned int i = 0; i < _FitaVideoCadastradas.size(); i++) {
			if (sistemaFitaVideo._FitaVideoCadastradas[i].getCodigoNumeroFilme() == codigoFita) {
				sistemaFitaVideo._FitaVideoCadastradas[i].diminuiUnidadesDisponiveis();
			}
		} 
	} else std::cout << "ERRO: Filme <" << codigoFita << "> inexistente" << std::endl;
}

int FitaVideo::retornaDevolucaoFitaVideo(int codigoFitaVideo, int diasAlugado) {
	if (_rebobinada == 0) { return 7;}
	else return 5;
}

bool FitaVideo::verificaSaldoFitaVideo(FitaVideo& sistemaFitaVideo, int codigoFitaVideo) {
	if (sistemaFitaVideo.verificaCadastroFitaVideo(sistemaFitaVideo, codigoFitaVideo)) {
		for (unsigned int i = 0; i < sistemaFitaVideo._FitaVideoCadastradas.size(); i++) {
			if (sistemaFitaVideo._FitaVideoCadastradas[i].getCodigoNumeroFilme() == codigoFitaVideo && 
					_FitaVideoCadastradas[i].getNumeroUnidadesDisponiveis() > 0) return true;
		} 
	} else return false;
}

int FitaVideo::qtdFitasVideoCadastrados() {
	int qtdFitasVideoCadastrados{0}; qtdFitasVideoCadastrados = _FitaVideoCadastradas.size();
	return qtdFitasVideoCadastrados;
}

bool FitaVideo::verificaCadastroFitaVideo(FitaVideo& sistemaFitaVideo, int codigoFitaVideo) {
	for (unsigned int i = 0; i < sistemaFitaVideo._FitaVideoCadastradas.size(); i++) {
		if (_FitaVideoCadastradas[i].getCodigoNumeroFilme() == codigoFitaVideo) { return true;
		} 
	} std::invalid_argument("ERRO: CPF não cadastrado.");
}

FitaVideo::FitaVideo(int codigoNumeroFilme, 
										 std::string tituloFilme, 
										 int numeroUnidadesDisponiveis) 
									   : Filme(codigoNumeroFilme, tituloFilme, numeroUnidadesDisponiveis) {
	int lb = 0, ub = 1; bool rebobinada; rebobinada = (rand() % (ub - lb + 1)) + lb;
	_rebobinada = rebobinada;
	setFitaVideo();
}

// CF <Tipo: F|D> <quantidade> <código> <título> <categoria no caso de DVD>
void FitaVideo::cadastraFitaVideoDoZero(FitaVideo& sistemaFitaVideo) {
	std::cout << "CF <Tipo: F|D> <quantidade> <código> <título> <categoria no caso de DVD>" << std::endl;
	int quantidadeDisponivelFitaVideo{0}, codigoFitaVideo{0}; std::string tituloFitaVideo{'0'};
	std::cin >> quantidadeDisponivelFitaVideo >> codigoFitaVideo; getline(std::cin, tituloFitaVideo);
	if (!verificaCadastroFitaVideo(sistemaFitaVideo, codigoFitaVideo)) {
		FitaVideo fitaVideo(codigoFitaVideo, tituloFitaVideo, quantidadeDisponivelFitaVideo);
		sistemaFitaVideo._FitaVideoCadastradas.push_back(fitaVideo);
		std::cout << "Filme <" << codigoFitaVideo << "> cadastrado com sucesso." << std::endl;
	} else std::invalid_argument("ERRO: código repetido.");
}

void FitaVideo::cadastraFitaVideoParametros(FitaVideo& sistemaFitaVideo, int codigoFitaVideo, std::string tituloFitaVideo, int quantidadeDisponivelFitaVideo) {
	FitaVideo fitavideo(codigoFitaVideo, tituloFitaVideo, quantidadeDisponivelFitaVideo);
	sistemaFitaVideo._FitaVideoCadastradas.push_back(fitavideo);
}

void FitaVideo::removeFitaVideo(FitaVideo& sistemaFitaVideo, int codigoFitaVideoRemovido) {
	int tamVetor = _FitaVideoCadastradas.size();
	if (tamVetor == 0) {
		throw std::invalid_argument("Não há fita a ser removida");
	} else {
		if (verificaCadastroFitaVideo(sistemaFitaVideo, codigoFitaVideoRemovido)) {
			for (int i = 0; i < tamVetor; i++) {
				if (_FitaVideoCadastradas[i].getCodigoNumeroFilme() == codigoFitaVideoRemovido) {
					_FitaVideoCadastradas.erase(_FitaVideoCadastradas.begin() + i);
				}
			} std::cout << "Filme <" << codigoFitaVideoRemovido << "> removido com sucesso" << std::endl;
		} else std::invalid_argument("ERRO: dados incorretos");
	}
}

FitaVideo FitaVideo::getFitaVideoCadastrada(int i) {
	return _FitaVideoCadastradas[i];
}

int FitaVideo::getFitaVideoCadastradaCodigoFilme(FitaVideo& sistemaFitaVideo, int i) {
	return sistemaFitaVideo._FitaVideoCadastradas[i].getCodigoNumeroFilme();
}

void FitaVideo::listaFitaVideoCodigo() {
	std::sort(_FitaVideoCadastradas.begin(),_FitaVideoCadastradas.end(), SortCodigoFitaVideo(0));
	for (unsigned int i = 0; i < _FitaVideoCadastradas.size(); i++) {
		_FitaVideoCadastradas.at(i).imprimeFitaVideo();
	}
}

void FitaVideo::listaFitaVideoTitulo() {
	std::sort(_FitaVideoCadastradas.begin(),_FitaVideoCadastradas.end(), SortCodigoFitaVideo(1));
	for (unsigned int i = 0; i < _FitaVideoCadastradas.size(); i++) {
		_FitaVideoCadastradas.at(i).imprimeFitaVideo();
	}
}

void FitaVideo::imprimeFitaVideo() {
	std::cout << "< " << getCodigoNumeroFilme() 
									  << " > < " 
									  << getTituloFilme()
									  << " > < "
									  << getNumeroUnidadesDisponiveis()
									  << " > < FITA >" 
									  << std::endl;
}

FitaVideo::~FitaVideo(){};