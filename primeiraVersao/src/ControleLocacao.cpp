#include <iostream>
#include <string.h>
#include <algorithm>
#include <sstream>
#include <fstream>

#include "../include/ControleLocacao.h"
/*----------------------------------------------------
* Classe ControleLocacao
*-----------------------------------------------------
* Construtor default da classe ControleLocacao.     */
ControleLocacao::ControleLocacao() {}

/* Lê um arquivo .txt e cadastra filmes a partir dele,
*  verificando se é DVD/Fita, de acordo com o prímeiro 
*  dígito (que é um bool, vide o construtor).       */
void ControleLocacao::lerAquivo() {
  std::cout << "LA <Nome do Arquivo>" << std::endl;
  std::ifstream infile("thefile.txt");
  std::string line;

  while (std::getline(infile, line)) {
    std::istringstream iss(line);
    bool ehDvd; int quantidadeDisponivel, codigoFilme; std::string tituloFilme, categoriaDvd;
    if (ehDvd == true) {
      Dvd dvd(true, quantidadeDisponivel, codigoFilme, categoriaDvd, tituloFilme);
      if (!(iss >> quantidadeDisponivel >> codigoFilme >> categoriaDvd >> tituloFilme)) { break; } // error
    }
    else {
      Fita fita(false, quantidadeDisponivel, codigoFilme, tituloFilme);
      if (!(iss >> quantidadeDisponivel >> codigoFilme >> tituloFilme)) { break; } // error
    }
  }
}

/* Cadastra um filme de acordo com o que é desejado. */
void ControleLocacao::cadastrarFilme() {
  std::cout << "CF <Tipo: F|D> <quantidade> <código> <título> <categoria no caso de DVD>" << std::endl;
  bool ehDvd; int quantidadeDisponivel, codigoFilme; std::string tituloFilme, categoriaDvd;
  std::cin >> ehDvd >> quantidadeDisponivel >> codigoFilme; 
  getline(std::cin, tituloFilme); getline(std::cin, categoriaDvd);
  if (ehDvd == true) {
    Dvd dvd(true, quantidadeDisponivel, codigoFilme, categoriaDvd, tituloFilme);
    dvd.cadastraDvd();
  } else {
    Fita fita(false, quantidadeDisponivel, codigoFilme, tituloFilme);
    fita.cadastraFita();
  }
}

/* Remove um filme de acordo com o que é desejado. */
void ControleLocacao::removeFilme() {
  int codigoFilme = 0;
  std::cout << "RF <código>: " << std::endl; std::cin >> codigoFilme;
}

/* Lista os filmes cadastrados atualmente. */
void ControleLocacao::listaFilme() {
  std::cout << "LF [C|T]" << std::endl;
}

/* Realiza a devolução de um filme e aumenta a quantidade disponível. */
void ControleLocacao::devolucaoFilme() {
  std::cout << "DV <CPF>: " << std::endl;
  int cpf;
  std::cin >> cpf;
}

/* Imprime na tela as funções disponíveis para o operador. */
void ControleLocacao::imprimeSistema() {
  std::cout << "Selecione uma opção.\n"
            << "----------------------------\n"
            << "LA: Ler Arquivo de Cadastro.\n"
            << "CF: Cadastrar Filme.\n"
            << "RF: Remover Filme.\n" 
            << "LF: Listar Filmes.\n" //ordenados por Código [C] ou Título [T].\n"
            << "CF: Cadastrar Cliente.\n"
            << "RF: Remover Cliente.\n"
            << "LC: Listar Clientes.\n"//ordenados por Código ou Nome:"
            << "AL: Aluguel Filme.\n"
            << "DV: Devolução Filme.\n"
            << "FS: Finalizar Sistema.\n"
            << "----------------------------\n"
            << std::endl;   
  std::string entradaUsuario;
  getline(std::cin, entradaUsuario);
  transform(entradaUsuario.begin(), entradaUsuario.end(), entradaUsuario.begin(), ::toupper);
	if (entradaUsuario == "FS") {std::cout << "Finalizando o sisema..." << std::endl;
  while (entradaUsuario != "FS") {
    if (entradaUsuario == "LA") {lerAquivo();}
    if (entradaUsuario == "CF") {}
    if (entradaUsuario == "RF") {}
    if (entradaUsuario == "LF") {}
    if (entradaUsuario == "CF") {}
    if (entradaUsuario == "RF") {}
    if (entradaUsuario == "LC") {}
    if (entradaUsuario == "AL") {}
    if (entradaUsuario == "DV") {}
    getline(std::cin, entradaUsuario);
    transform(entradaUsuario.begin(), entradaUsuario.end(), entradaUsuario.begin(), ::toupper);
  	}
	}
}