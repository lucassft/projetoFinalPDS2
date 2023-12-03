#include <iostream>
#include <vector>
#include <string>

#include "../include/CadastroFilme.h"

/*----------------------------------------------------
* Classe Filme
*-----------------------------------------------------
* Construtor base da classe Filme.
*	verificar se o mesmo já está cadastrado no sistema, 
* se for o caso, direciona para um novo cadastro.*/
Filme::Filme(bool ehDvd, int codigoFilme, std::string tituloFilme) {
	if (!(verificaFilme(codigoFilme))) {
		this->_tituloFilme = tituloFilme;
		this->_codigoFilme = codigoFilme; 
		this->_ehDvd = ehDvd;
	} else std::cout << "Filme já cadastrado." << std::endl;
}
/* Retorna a quantidade de filmes já cadastrados. */
int Filme::tamFilmesCadastrados() {return _filmesCadastrados.size();};

/* Se o filme em questão ainda não tiver sido cadastrado, cadastra um novo. */
void Filme::adicionaFilmesCadastrados(Filme filme) {
	if (!(verificaFilme(filme._codigoFilme))) _filmesCadastrados.push_back(filme);
}

/* Remove um filme do sistema. */
void Filme::removeFilme(int codigoFilme) {
  for (int i = 0; i < tamFilmesCadastrados(); i++) {
    if (_filmesCadastrados[i]._codigoFilme == codigoFilme) {_filmesCadastrados.erase(_filmesCadastrados.begin() + i);}
  } std::cout << "Filme <" << codigoFilme << "removido com sucesso" << std::endl;
}

/* Verifica se o filme já foi cadastrado. */
bool Filme::verificaFilme(int codigoFilme) {
  for (int i = 0; i < tamFilmesCadastrados(); i++) {
    if (_filmesCadastrados[i]._codigoFilme == codigoFilme) {return true;} else return false;
  }
}

/* Impressão na tela do que foi devolvido. */
void Filme::imprimeDvdOuFilme(int codigoFilme) {
  for (int i = 0; i < tamFilmesCadastrados(); i++) {
    if (_filmesCadastrados[i]._ehDvd == true) 
      std::cout << "<" << _filmesCadastrados[i]._codigoFilme << "> <" << _filmesCadastrados[i]._tituloFilme << "<DVD>" << std::endl;
    else {std::cout << "<" << _filmesCadastrados[i]._codigoFilme << "> <" << _filmesCadastrados[i]._tituloFilme << "<FITA>" << std::endl;}
  }
}

/*----------------------------------------------------
* Classe DVD
*-----------------------------------------------------
* Construtor base da classe DVD.
*	verificar se o mesmo já está cadastrado no sistema, 
* se for o caso, direciona para um novo cadastro.*/
Dvd::Dvd(bool ehDvd, int quantidadeDisponivel, int codigoFilme, std::string categoriaDvd, std::string tituloFilme) : 
    Filme(ehDvd, codigoFilme, tituloFilme) {
	if (!(verificaFilme(codigoFilme))) {
		this->_quantidadeDisponivel = quantidadeDisponivel;
  	this->_categoriaDvd = categoriaDvd;
	} else cadastraDvd();
}

/*Cadastra um novo DVD no sistema.*/
void Dvd::cadastraDvd() {
  std::cout << "<D> <quantidade> <código> <título> <categoria no caso de DVD>" << std::endl;
  int quantidadeDisponivel, codigoFilme; std::string tituloFilme, categoriaDvd;
  std::cin >> quantidadeDisponivel >> codigoFilme; 
  getline(std::cin, tituloFilme); getline(std::cin, categoriaDvd);
  Dvd dvd(true, quantidadeDisponivel, codigoFilme, tituloFilme, categoriaDvd);
  adicionaFilmesCadastrados(dvd);
  std::cout << "Filme <" << codigoFilme << "> cadastrado com sucesso" << std::endl;
}

/*----------------------------------------------------
* Classe Fita
*-----------------------------------------------------
* Construtor base da classe Fita.
*	verificar se o mesmo já está cadastrado no sistema, 
* se for o caso, direciona para um novo cadastro.*/
Fita::Fita(bool ehDvd, int quantidadeDisponivel, int codigoFilme, std::string tituloFilme) : 
    Filme(ehDvd, codigoFilme, tituloFilme) {
	if(!verificaFilme(codigoFilme)) this->_quantidadeDisponivel = quantidadeDisponivel;
	else cadastraFita();
}

/* Verifica se há alguma unidade de fita disponível para locação.*/
bool Fita::verificaQuantidadeDisponivel() {
  if (this->_quantidadeDisponivel > 0) return true;
  else false;
}

/* Cadastra uma fita no sistema.*/
void Fita::cadastraFita() {
  std::cout << "<F> <quantidade> <código> <título>" << std::endl;
  int quantidadeDisponivel, codigoFilme; std::string tituloFilme;
  std::cin >> quantidadeDisponivel >> codigoFilme; 
  getline(std::cin, tituloFilme);
  Fita fita(false, quantidadeDisponivel, codigoFilme, tituloFilme);
  adicionaFilmesCadastrados(fita);
  std::cout << "Filme <" << codigoFilme << "> cadastrado com sucesso" << std::endl;
}