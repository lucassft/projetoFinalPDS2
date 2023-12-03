#include <iostream>
#include <string.h>
#include <algorithm>
#include <sstream>
#include <fstream>

#include "../include/ControleLocacao.h"

ControleLocacao::ControleLocacao() {}

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

void ControleLocacao::removeFita() {
  int codigoFilme = 0;
  std::cout << "RF <código>: " << std::endl; std::cin >> codigoFilme;
}

void ControleLocacao::listaFilme() {
  std::cout << "LF [C|T]" << std::endl;
}

void ControleLocacao::devolucaoFilme() {
  std::cout << "DV <CPF>: " << std::endl;
  int cpf;
  std::cin >> cpf;
}

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