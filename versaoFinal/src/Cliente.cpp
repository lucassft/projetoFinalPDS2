#include "../include/Cliente.hpp"

Cliente::Cliente(std::string nome, int cpf) {
			_nome = nome;
			_cpf = cpf;
		}

void Cliente::clienteAluga(DVD& dvdSistema, FitaVideo& fitaVideoSistema) {
	int inputCodigoFilmeAlugado{0}; std::cin >> inputCodigoFilmeAlugado;
	while (inputCodigoFilmeAlugado != 0) {
		if (dvdSistema.verificaSaldoDVD(inputCodigoFilmeAlugado)) {
			dvdSistema.clienteAlugaDVD(inputCodigoFilmeAlugado);
			_DVDsAlugados.push_back(inputCodigoFilmeAlugado);
		} else if (fitaVideoSistema.verificaSaldoFitaVideo(inputCodigoFilmeAlugado)) {
		fitaVideoSistema.clienteAlugaFitaVideo(inputCodigoFilmeAlugado);
		_FitaVideoAlugadas.push_back(inputCodigoFilmeAlugado);
		}
	std::cout << "ERRO: Filme <codigo> inexistente."
						<< "Digite '0' para [SAIR] ou informe um novo código para continuar";
	std::cin >> inputCodigoFilmeAlugado;
	}
}

void Cliente::clienteDevolve(DVD& dvdSistema, FitaVideo& fitaVideoSistema) {
	int tamDVDsAlugados{0}, tamFitaVideoAlugadas{0};
	tamDVDsAlugados = _DVDsAlugados.size(); tamFitaVideoAlugadas = _FitaVideoAlugadas.size();
	if (tamFitaVideoAlugadas > 0 || tamFitaVideoAlugadas > 0) {
		imprimeCliente(); std::cout << " devolveu os filmes: " << std::endl;
		if (tamDVDsAlugados > 0 ) {
			for (int i = 0; i < dvdSistema.qtdDVDsCadastrados(); i++) {
				for (int j = 0; j < _DVDsAlugados.size(); j++) {
					if (dvdSistema.getDVDsCadastradosCodigoFilme(i) == _DVDsAlugados[j])
					std::cout << _DVDsAlugados[j] << " ";
					dvdSistema.retornaDevolucaoDVD(_DVDsAlugados[j], 3);
				}
			}
		} else std::cout << "nenhum DVD foi alugado." << std::endl;
		if (tamFitaVideoAlugadas > 0) {
		for (int i = 0; i < dvdSistema.qtdDVDsCadastrados(); i++) {
				for (int j = 0; j < _FitaVideoAlugadas.size(); j++) {
					if (fitaVideoSistema.getFitaVideoCadastradaCodigoFilme(i) == _DVDsAlugados[j])
					std::cout << _FitaVideoAlugadas[j] << " ";
					dvdSistema.retornaDevolucaoDVD(_FitaVideoAlugadas[j], 3);
				}
			}
		} else std::cout << "nenhuma fita de vídeo foi alugada." << std::endl;
	}
}

int Cliente::getCPF() const {return _cpf;}

std::string Cliente::getNome() const {return _nome;};

void Cliente::imprimeCliente() const {
	std::cout << "<" << _cpf << "> <" << _nome << ">";
}