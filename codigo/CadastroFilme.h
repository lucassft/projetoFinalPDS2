#ifndef CADASTROFILME_H
#define CADASTROFILME_H

#include <iostream>
#include <vector>
#include <string>

class Filme {
  private:
    std::vector<Filme> _filmesCadastrados;
    int _codigoFilme;

  public:
    Filme(int codigoFilme) {this->_codigoFilme = codigoFilme;};
    int tamFilmesCadastrados() {return _filmesCadastrados.size();};
    void adicionaFilmesCadastrados(Filme filme) {
      _filmesCadastrados.push_back(filme);
    }
    void removeFilme(Filme filme) {
      std::cout << "<código>: "; int codigoFilme; std::cin >> codigoFilme;
      for (int i = 0; i < tamFilmesCadastrados(); i++) {
        if (_filmesCadastrados[i]._codigoFilme == codigoFilme) {_filmesCadastrados.erase(_filmesCadastrados.begin() + i);}
      } std::cout << "Filme <" << codigoFilme << "removido com sucesso" << std::endl;
    }
    bool verificaFilme(int codigoFilme) {
      for (int i = 0; i < tamFilmesCadastrados(); i++) {
        if (_filmesCadastrados[i]._codigoFilme == codigoFilme) {return true;} else return false;
    }
  }
};

class Dvd : public Filme {
  private:
    bool _dvd;
    std::string _categoriaDvd;
    int _valorLocacao;
    int _codigoDvd;
    std::string _titulo;
    int _quantidadeDisponivel;
  
  public:
    Dvd(int quantidadeDisponivel, int codigoFilme, std::string titulo, std::string categoriaDvd) : Filme(codigoFilme) {
      this->_dvd = true;
      this->_quantidadeDisponivel = quantidadeDisponivel;
      this->_titulo = titulo;
      this->_categoriaDvd = categoriaDvd;
    }; 
    Dvd(int codigoFilme); // Dvd alugado.
    void cadastraDvd() {
      std::cout << "<D> <quantidade> <código> <título> <categoria no caso de DVD>" << std::endl;
      bool dvd; int quantidadeDisponivel, codigoDvd; std::string titulo, categoriaDvd;
      std::cin >> quantidadeDisponivel >> codigoDvd; 
      getline(std::cin, titulo); getline(std::cin, categoriaDvd);
      Dvd dvd(true, quantidadeDisponivel, codigoDvd, titulo, categoriaDvd);
      adicionaFilmesCadastrados(dvd);
      std::cout << "Filme <" << codigoDvd << "> cadastrado com sucesso" << std::endl;
    }
    void verificaFita 
};

class Fita : public Filme {
  private:
    bool _dvd = 0;
    bool _rebobinada;
    int _valorLocacao;
    std::string _titulo;
    int _quantidadeDisponivel;

  public: 
    Fita(int quantidadeDisponivel, int codigoFilme, std::string titulo) : Filme(codigoFilme) {
      this->_dvd = false;
      this->_quantidadeDisponivel = quantidadeDisponivel;
      this->_titulo = titulo;
    }
    Fita(int codigoFilme); // Fita alugada.
    void cadastraFita() {
      std::cout << "<F> <quantidade> <código> <título>" << std::endl;
      int quantidadeDisponivel, codigoFita; std::string titulo;
      std::cin >> quantidadeDisponivel >> codigoFita; 
      getline(std::cin, titulo);
      Fita fita(quantidadeDisponivel, codigoFita, titulo);
      adicionaFilmesCadastrados(fita);
      std::cout << "Filme <" << codigoFita << "> cadastrado com sucesso" << std::endl;
    };
};

#endif