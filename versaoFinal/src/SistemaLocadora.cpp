#include "../include/SistemaLocadora.hpp"

SistemaLocadora::SistemaLocadora(){}

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
	imprimeInterfaceSistemaLocadora();
	int inputOperadorLocadora{0};
	std::cin >> inputOperadorLocadora;
	while(inputOperadorLocadora > 0 && inputOperadorLocadora < 10) {
		switch (inputOperadorLocadora) {
		case 1 : lerArquivoCadastro(sistemaDVD, sistemaFitaVideo); break;
		case 2 : cadastrarFilme(sistemaDVD,sistemaFitaVideo); break;
		case 3 : removerFilme(sistemaDVD, sistemaFitaVideo); break;
		case 4 : listarFilmesOrdenadosCodigoTitulo(sistemaDVD, sistemaFitaVideo); break;
		case 5 : cadastrarCliente(sistemaControleLocacao);break;
		case 6 : removerCliente(sistemaControleLocacao); break;
		case 7 : listaClienteCodigoNome(sistemaControleLocacao); break;
		case 8 : aluguelFilme(sistemaControleLocacao, sistemaDVD, sistemaFitaVideo); break;
		case 9 : devolucaoFilme(sistemaControleLocacao, sistemaDVD, sistemaFitaVideo); break;
		default:
			break;
		} 
		imprimeInterfaceSistemaLocadora(); std::cin >> inputOperadorLocadora;
	} std::cout << "Finalizando o sistema..." << std::endl;
}

void SistemaLocadora::lerArquivoCadastro(DVD& sistemaDVD, FitaVideo& sistemaFitaVideo) {
	bool ehDVD{0}; int quantidade{0}, codigo{0}, categoriaDVD{0}; std::string titulo{'0'};
	std::ifstream myfile; myfile.open("arquivoCadastro.txt");
	while ( myfile >> ehDVD >> quantidade >> codigo >> categoriaDVD >> titulo ) {
		if (ehDVD) {
			sistemaDVD.cadastraDVDparametros(sistemaDVD, codigo, titulo, quantidade, categoriaDVD);
		} else FitaVideo fitaVideo(codigo, titulo, quantidade);
	}
}

void SistemaLocadora::cadastrarFilme(DVD& sistemaDVD, FitaVideo& sistemaFitaVideo) {
	std::cout << "CF <Tipo: F|D> <quantidade> <código> <título> <categoria no caso de DVD>" << std::endl;
	bool ehDVD{0}; int quantidade{0}, codigo{0}, categoriaDVD{0}; std::string titulo{'0'};
	if (ehDVD) {
		sistemaDVD.cadastraDVDparametros(sistemaDVD, codigo, titulo, quantidade, categoriaDVD);
	} else {
		sistemaFitaVideo.cadastraFitaVideoParametros(sistemaFitaVideo, codigo, titulo, quantidade);}
}

void SistemaLocadora::removerFilme(DVD& sistemaDVD, FitaVideo& sistemaFitaVideo) {
	int codigoRemover{0};
	std::cout << "RF <código>: "; std::cin >> codigoRemover;
	if (sistemaDVD.verificaCadastroDVD(sistemaDVD, codigoRemover)) {
		sistemaFitaVideo.removeFitaVideo(codigoRemover);}
	else if (sistemaFitaVideo.verificaCadastroFitaVideo(codigoRemover)) {
		sistemaFitaVideo.removeFitaVideo(codigoRemover);}
}

void SistemaLocadora::listarFilmesOrdenadosCodigoTitulo(DVD& sistemaDVD, FitaVideo& sistemaFitaVideo) {
	std::cout << "Deseja listar por:"
						<<  "\n[1] Código"
						<<  "\n[2] Título"
						<< std::endl;
	int inputUsuario{0}; std::cin >> inputUsuario;
	if (inputUsuario == 1) {sistemaDVD.listaDVDsCodigo();sistemaFitaVideo.listaFitaVideoCodigo();
	} else if (inputUsuario == 2) {sistemaDVD.listaDVDsTitulo();sistemaFitaVideo.listaFitaVideoTitulo();}
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

void SistemaLocadora::aluguelFilme(ControleLocacao& sistemaControleLocacao, DVD& sistemaDVD, FitaVideo& sistemaFitaVideo) {
	std::cout << "AL <CPF> <Código1> ... <Código N>";
	int inputCPF{0}, inputCodigoFilme{0};
	if (sistemaControleLocacao.verificaCPFCadastrado(inputCPF)) {
		for (int i = 0; i < sistemaControleLocacao.qtdClientesCadastrados(); i++)
			sistemaControleLocacao.clienteAlugou(inputCPF, inputCodigoFilme, sistemaDVD, sistemaFitaVideo);
	} else std::cout << "ERRO: CPF inexistente" << std::endl;
}

void SistemaLocadora::devolucaoFilme(ControleLocacao& sistemaControleLocacao, DVD& sistemaDVD, FitaVideo& sistemaFitaVideo) {
	std::cout << "DV <CPF>";
	int inputCPF{0};
	if (sistemaControleLocacao.verificaCPFCadastrado(inputCPF)) {
		sistemaControleLocacao.clienteDevolveu(inputCPF, sistemaDVD, sistemaFitaVideo);
	}
}

SistemaLocadora::~SistemaLocadora(){}