#include "../include/ControleLocacao.hpp"

ControleLocacao::ControleLocacao(){}

int ControleLocacao::qtdClientesCadastrados() const {
	int qtdClientesCadastrados{0}; qtdClientesCadastrados = _ClientesCadastrados.size();
	return qtdClientesCadastrados;
}

bool ControleLocacao::verificaCPFCadastrado(int inputCPF) {
	for (unsigned int i = 0; i < _ClientesCadastrados.size(); i++) {
		if (_ClientesCadastrados[i].getCPF() == inputCPF) return true;
	} return false;
}

void ControleLocacao::cadastraCliente() {
	std::cout << "CC <CPF> <Nome>";
	int inputCPF{0}; std::cin >> inputCPF; 
	std::string inputNome{'0'}; getline(std::cin, inputNome);
	if (!verificaCPFCadastrado(inputCPF)) {
		Cliente cliente(inputNome, inputCPF);
		_ClientesCadastrados.push_back(cliente);
	}
}

void ControleLocacao::removeCliente(int cpfClienteRemovido) {
	int tamVetor = _ClientesCadastrados.size();
	if (verificaCPFCadastrado(cpfClienteRemovido)) {
		for (int i = 0; i < tamVetor; i++) {
			if (_ClientesCadastrados[i].getCPF() == cpfClienteRemovido) {
				std::cout << "Cliente <" << _ClientesCadastrados[i].getCPF() << "> removido com sucesso" << std::endl;
				_ClientesCadastrados.erase(_ClientesCadastrados.begin() + i);
			}
		} 
	} else std::cout << "ERRO: dados incorretos." << std::endl;
}

void ControleLocacao::listaClienteCPF() {
	std::sort(_ClientesCadastrados.begin(),_ClientesCadastrados.end(), SortClienteNomeCPF(1));
	for (unsigned int i = 0; i < _ClientesCadastrados.size(); i++) {
		_ClientesCadastrados[i].imprimeCliente();
	}
}

void ControleLocacao::listaClienteNome() {
	std::sort(_ClientesCadastrados.begin(),_ClientesCadastrados.end(), SortClienteNomeCPF(0));
	for (unsigned int i = 0; i < _ClientesCadastrados.size(); i++) {
		_ClientesCadastrados[i].imprimeCliente(); 
	}
}

void ControleLocacao::clienteDevolveu(int inputCPF, DVD& dvdSistema, FitaVideo& fitaVideoSistema) {
	for (unsigned int i = 0; i < _ClientesCadastrados.size(); i++) {
		if (_ClientesCadastrados[i].getCPF() == inputCPF) {
			_ClientesCadastrados[i].imprimeCliente();
			std::cout << " devolveu os filmes:" << std::endl;
			_ClientesCadastrados[i].clienteDevolve(dvdSistema, fitaVideoSistema);
		}
	}
}

void ControleLocacao::clienteAlugou(int inputCPF, int codigoFilme, DVD& dvdSistema, FitaVideo& fitaVideoSistema) {
	if (verificaCPFCadastrado(inputCPF)) {
		for (unsigned int i = 0; i < _ClientesCadastrados.size(); i++) {
			if (_ClientesCadastrados[i].getCPF() == inputCPF) {
				_ClientesCadastrados[i].clienteAlugaCodigo(codigoFilme, dvdSistema, fitaVideoSistema);
			}
		}
	} else std::cout << "<" << inputCPF <<"> não cadastrado no sistema." << std::endl;
}

ControleLocacao::~ControleLocacao(){}