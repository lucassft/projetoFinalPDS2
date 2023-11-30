#ifndef CADASTROFILME_H
#define CADASTROFILME_H

#include <iostream>
#include <vector>
#include <string>

class Filme {
  private:
    std::vector<Filme> _filmesCadastrados;
    std::string _tituloFilme;
    int _codigoFilme;
    bool _ehDvd;


  public:
    Filme(); 
    Filme(bool ehDvd, int codigoFilme, std::string tituloFilme);
    int tamFilmesCadastrados();
    void adicionaFilmesCadastrados(Filme filme);
    void removeFilme(int codigoFilme);
    bool verificaFilme(int codigoFilme);
    void imprimeDvdOuFilme(int codigoFilme);
};

class Dvd : public Filme {
  private:
    std::string _categoriaDvd;
    int _valorLocacao;
    int _quantidadeDisponivel;
  

  public:
    Dvd();
    Dvd(bool ehDvd, int quantidadeDisponivel, int codigoFilme, std::string categoriaDvd, std::string tituloFilme) : 
        Filme(ehDvd, codigoFilme, tituloFilme){};
    void cadastraDvd() {};
};

class Fita : public Filme {
  private:
    bool _rebobinada;
    int _valorLocacao;
    std::string _titulo;
    int _quantidadeDisponivel;


  public: 
    Fita();
    Fita(bool ehDvd, int quantidadeDisponivel, int codigoFilme, std::string tituloFilme) : 
        Filme(ehDvd, codigoFilme, tituloFilme) {};
    bool verificaQuantidadeDisponivel();
    void cadastraFita();
};

#endif