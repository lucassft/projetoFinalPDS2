#include <iostream>
#include <vector>
#include <string>

#include "../include/CadastroFilme.h"


Filme::Filme(bool ehDvd, int codigoFilme, std::string tituloFilme) {
	if (!(verificaFilme(codigoFilme))) {
		this->_tituloFilme = tituloFilme;
		this->_codigoFilme = codigoFilme; 
		this->_ehDvd = ehDvd;
	} else std::cout << "Filme já cadastrado." << std::endl;
}

int Filme::tamFilmesCadastrados() {return _filmesCadastrados.size();};

void Filme::adicionaFilmesCadastrados(Filme filme) {
  _filmesCadastrados.push_back(filme);
}

void Filme::removeFilme(int codigoFilme) {
  for (int i = 0; i < tamFilmesCadastrados(); i++) {
    if (_filmesCadastrados[i]._codigoFilme == codigoFilme) {_filmesCadastrados.erase(_filmesCadastrados.begin() + i);}
  } std::cout << "Filme <" << codigoFilme << "removido com sucesso" << std::endl;
}

bool Filme::verificaFilme(int codigoFilme) {
  for (int i = 0; i < tamFilmesCadastrados(); i++) {
    if (_filmesCadastrados[i]._codigoFilme == codigoFilme) {return true;} else return false;
  }
}

void Filme::imprimeDvdOuFilme(int codigoFilme) {
  for (int i = 0; i < tamFilmesCadastrados(); i++) {
    if (_filmesCadastrados[i]._ehDvd == true) 
      std::cout << "<" << _filmesCadastrados[i]._codigoFilme << "> <" << _filmesCadastrados[i]._tituloFilme << "<DVD>" << std::endl;
    else {std::cout << "<" << _filmesCadastrados[i]._codigoFilme << "> <" << _filmesCadastrados[i]._tituloFilme << "<FITA>" << std::endl;}
  }
}

Dvd::Dvd(bool ehDvd, int quantidadeDisponivel, int codigoFilme, std::string categoriaDvd, std::string tituloFilme) : 
    Filme(ehDvd, codigoFilme, tituloFilme) {
  this->_quantidadeDisponivel = quantidadeDisponivel;
  this->_categoriaDvd = categoriaDvd;
}

void Dvd::cadastraDvd() {
  std::cout << "<D> <quantidade> <código> <título> <categoria no caso de DVD>" << std::endl;
  int quantidadeDisponivel, codigoFilme; std::string tituloFilme, categoriaDvd;
  std::cin >> quantidadeDisponivel >> codigoFilme; 
  getline(std::cin, tituloFilme); getline(std::cin, categoriaDvd);
  Dvd dvd(true, quantidadeDisponivel, codigoFilme, tituloFilme, categoriaDvd);
  adicionaFilmesCadastrados(dvd);
  std::cout << "Filme <" << codigoFilme << "> cadastrado com sucesso" << std::endl;
}


Fita::Fita(bool ehDvd, int quantidadeDisponivel, int codigoFilme, std::string tituloFilme) : 
    Filme(ehDvd, codigoFilme, tituloFilme) {
  this->_quantidadeDisponivel = quantidadeDisponivel;
}

bool Fita::verificaQuantidadeDisponivel() {
  if (this->_quantidadeDisponivel > 0) return true;
  else false;
}

void Fita::cadastraFita() {
  std::cout << "<F> <quantidade> <código> <título>" << std::endl;
  int quantidadeDisponivel, codigoFilme; std::string tituloFilme;
  std::cin >> quantidadeDisponivel >> codigoFilme; 
  getline(std::cin, tituloFilme);
  Fita fita(false, quantidadeDisponivel, codigoFilme, tituloFilme);
  adicionaFilmesCadastrados(fita);
  std::cout << "Filme <" << codigoFilme << "> cadastrado com sucesso" << std::endl;
}