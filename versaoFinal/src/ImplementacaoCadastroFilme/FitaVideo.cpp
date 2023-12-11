#include "FitaVideo.hpp"

FitaVideo::FitaVideo() {}

void FitaVideo::clienteAlugaFitaVideo(int codigoFita) {
	if (verificaSaldoFitaVideo(codigoFita)) {
		for (unsigned int i = 0; i < _FitaVideoCadastradas.size(); i++) {
			if (_FitaVideoCadastradas[i].getCodigoNumeroFilme() == codigoFita) {
				_FitaVideoCadastradas[i].diminuiUnidadesDisponiveis();
			}
		} 
	} else std::cout << "ERRO: Filme <" << codigoFita << "> inexistente" << std::endl;
}

int FitaVideo::retornaDevolucaoFitaVideo(int codigoFitaVideo, int diasAlugado) {
	if (_rebobinada == 0) { return 7;}
	else return 5;
}

bool FitaVideo::verificaSaldoFitaVideo(int codigoFitaVideo) {
	if (verificaCadastroFitaVideo(codigoFitaVideo) && (getNumeroUnidadesDisponiveis() > 0)) return true;
}

int FitaVideo::qtdFitasVideoCadastrados() {
	int qtdFitasVideoCadastrados{0}; qtdFitasVideoCadastrados = _FitaVideoCadastradas.size();
	return qtdFitasVideoCadastrados;
}

bool FitaVideo::verificaCadastroFitaVideo(int codigoFitaVideo) {
	int tamVetor = qtdFitasVideoCadastrados();
	for (int i = 0; i < tamVetor; i++) {
		if (_FitaVideoCadastradas[i].getCodigoNumeroFilme() == codigoFitaVideo) { return true;
		} 
	} return false; // throw cpf não cadastrado
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
void FitaVideo::cadastraFitaVideoDoZero() {
	std::cout << "CF <Tipo: F|D> <quantidade> <código> <título> <categoria no caso de DVD>" << std::endl;
	int quantidadeDisponivelFitaVideo{0}, codigoFitaVideo{0}; std::string tituloFitaVideo{'0'};
	std::cin >> quantidadeDisponivelFitaVideo >> codigoFitaVideo; getline(std::cin, tituloFitaVideo);
	if (!verificaCadastroFitaVideo(codigoFitaVideo)) {
		FitaVideo fitaVideo(codigoFitaVideo, tituloFitaVideo, quantidadeDisponivelFitaVideo);
		_FitaVideoCadastradas.push_back(fitaVideo);
		std::cout << "Filme <" << codigoFitaVideo << "> cadastrado com sucesso." << std::endl;
	} else std::cout << "ERRO: código repetido." << std::endl;
}

void FitaVideo::cadastraFitaVideoParametros(FitaVideo& sistemaFitaVideo, int codigoFitaVideo, std::string tituloFitaVideo, int quantidadeDisponivelFitaVideo) {
	FitaVideo fitavideo(codigoFitaVideo, tituloFitaVideo, quantidadeDisponivelFitaVideo);
	sistemaFitaVideo._FitaVideoCadastradas.push_back(fitavideo);
}

void FitaVideo::removeFitaVideo(int codigoFitaVideoRemovido) {
	int tamVetor = _FitaVideoCadastradas.size();
	if (verificaCadastroFitaVideo(codigoFitaVideoRemovido)) {
		for (int i = 0; i < tamVetor; i++) {
			if (_FitaVideoCadastradas[i].getCodigoNumeroFilme() == codigoFitaVideoRemovido) {
				_FitaVideoCadastradas.erase(_FitaVideoCadastradas.begin() + i);
			}
		} std::cout << "Filme <" << codigoFitaVideoRemovido << "> removido com sucesso" << std::endl;
	} else std::cout << "ERRO: dados incorretos." << std::endl;
}

FitaVideo FitaVideo::getFitaVideoCadastrada(int i) {
	return _FitaVideoCadastradas[i];
}

int FitaVideo::getFitaVideoCadastradaCodigoFilme(int i) {
	return _FitaVideoCadastradas[i].getCodigoNumeroFilme();
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