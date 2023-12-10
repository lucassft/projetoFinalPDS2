#include "../include/SistemaLocadora.hpp"

/*
SistemaLocadora();
void interfaceSistemaLocadora();
void imprimeInterfaceSistemaLocadora();
void lerArquivoCadastro();
void cadastrarFilme();
void cadastrarCliente();
void removerCliente();
~SistemaLocadora();
*/

void SistemaLocadora::imprimeInterfaceSistemaLocadora() {
	std::cout << "--------------------------------------------------"
						<< "\nEscolha uma opção: "
						<< "\n< 1 > Ler Arquivo de Cadastro."
						<< "\n< 2 > Cadastrar Filme."
						<< "\n< 3 > Remover Filme."
						<< "\n< 4 > Listar Filmes ordenados por Código ou Título."
						<< "\n< 5 > Cadastrar Cliente."
						<< "\n< 6 > Remover Cliente."
						<< "\n< 7 > Listar Clientes ordenados por Código ou Nome."
						<< "\n< 8 > Aluguel Filme."
						<< "\n< 9 > Devolução Filme."
						<< "\n< 10 > Finalizar Sistema."
						<< "--------------------------------------------------"
						<< std::endl;
}

void SistemaLocadora::interfaceSistemaLocadora(DVD& sistemaDVD, 
                                               FitaVideo& sistemaFitaVideo,
																							 ControleLocacao& sistemaControleLocacao) {
	int inputOperadorLocadora{0};
	std::cin >> inputOperadorLocadora;
	while(inputOperadorLocadora > 0 && inputOperadorLocadora < 10) {
		imprimeInterfaceSistemaLocadora();
		switch (inputOperadorLocadora) {
		case 1 : lerArquivoCadastro(); break;
		case 2 : cadastrarFilme(); break;
		case 3 : removerFilme(); break;
		case 4 : listarFilmesOrdenadosCodigoTitulo(sistemaDVD, sistemaFitaVideo); break;
		case 5 : cadastrarCliente(sistemaControleLocacao);break;
		case 6 : removerCliente(sistemaControleLocacao); break;
		case 7 : listaClienteCodigoNome(sistemaControleLocacao); break;
		case 8 : aluguelFilme(sistemaControleLocacao); break;
		case 9 : devolucaoFilme(sistemaControleLocacao, sistemaDVD, sistemaFitaVideo); break;
		default:
			break;
		} std::cin >> inputOperadorLocadora;
	} std::cout << "Finalizando o sistema..." << std::endl;
}

void SistemaLocadora::lerArquivoCadastro() {
	bool ehDVD; int quantidade, codigo, categoriaDVD; std::string titulo;
	inFile.open("inputFile.txt");
	while ( inFile >> ehDVD >> quantidade >> codigo >> categoriaDVD >> titulo ) {}
		if (ehDVD) { DVD dvd(codigo, titulo, quantidade, categoriaDVD);
		} else FitaVideo fitaVideo(codigo, titulo, quantidade);
}

void SistemaLocadora::cadastrarFilme() {
	std::cout << "CF <Tipo: F|D> <quantidade> <código> <título> <categoria no caso de DVD>" << std::endl;
	bool ehDVD; int quantidade, codigo, categoriaDVD; std::string titulo;
	DVD dvdVerificador; FitaVideo fitaVideoVerificador;
	if (ehDVD) {
		dvdVerificador.cadastraDVDparametros(codigo, titulo, quantidade, categoriaDVD);
	} else {
		fitaVideoVerificador.cadastraFitaVideoParametros(codigo, titulo, quantidade);}
}

void SistemaLocadora::removerFilme() {
	int codigoRemover{0};
	std::cout << "RF <código>: "; std::cin >> codigoRemover;
	DVD dvdVerificador; FitaVideo fitaVideoVerificador;
	dvdVerificador.removeDVD(codigoRemover); fitaVideoVerificador.removeFitaVideo(codigoRemover);
}

void SistemaLocadora::listarFilmesOrdenadosCodigoTitulo(DVD& sistemaDVD, FitaVideo& sistemaFitaVideo) {
	std::cout << "Deseja listar por:"
						<<  "\n[1] Código"
						<<  "\n[2] Título"
						<< std::endl;
	int inputUsuario{0}; std::cin >> inputUsuario;
	if (inputUsuario) {
		sistemaDVD.listaDVDsCodigo();sistemaFitaVideo.listaFitaVideoCodigo();
	} else sistemaDVD.listaDVDsTitulo();sistemaFitaVideo.listaFitaVideoTitulo();
}

void SistemaLocadora::cadastrarCliente(ControleLocacao& sistemaControleLocacao) {
	sistemaControleLocacao.cadastraCliente();
}

void SistemaLocadora::removerCliente(ControleLocacao& sistemaControleLocacao) {
	std::cout << "Informe o CPF do cliente que deseja remover do sistema: ";
	int clienteCPF{0}; std::cin >> clienteCPF;
	sistemaControleLocacao.removeCliente(clienteCPF);
}

void SistemaLocadora::listaClienteCodigoNome(ControleLocacao& sistemaControleLocacao) {
	std::cout << "Deseja listar por:"
						<<  "\n[1] CPF"
						<<  "\n[2] Nome"
						<< std::endl;
	int inputUsuario{0}; std::cin >> inputUsuario;
	if (inputUsuario == 1) {
		sistemaControleLocacao.listaClienteCPF();
	} else if (inputUsuario == 2) sistemaControleLocacao.listaClienteNome();
}

void aluguelFilme(ControleLocacao& sistemaControleLocacao) {
	std::cout << "AL <CPF> <Código1> ... <Código N>";
	int inputCPF{0}, inputCodigoFilme{0};
	if (sistemaControleLocacao.verificaCPFCadastrado(inputCPF)) {
		
	} else std::cout << "ERRO: CPF inexistente" << std::endl;
}

void devolucaoFilme(ControleLocacao& sistemaControleLocacao, DVD& sistemaDVD, FitaVideo& sistemaFitaVideo) {
	std::cout << "DV <CPF>";
	int inputCPF{0};
	if (sistemaControleLocacao.verificaCPFCadastrado(inputCPF)) {
		sistemaControleLocacao.clienteDevolveu(inputCPF, sistemaDVD, sistemaFitaVideo);
	}
}