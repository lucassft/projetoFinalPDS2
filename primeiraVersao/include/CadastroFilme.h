#ifndef CADASTROFILME_H
#define CADASTROFILME_H

#include <iostream>
#include <vector>
#include <string>

/* Classe criada com o intuito de servir de base para o cadastro de filmes
		e suas derivadas, como Filmes e Dvd's. */

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

/* Classe filha DVD. Armazena informações
* - categoria do DVD;
* - valor da locação;
* - título da fita
* - quantidade de unidades disponíveis para posterior locação.*/

class Dvd : public Filme {
  private:
    std::string _categoriaDvd;
    int _valorLocacao;
    int _quantidadeDisponivel;
  

  public:
    Dvd(bool ehDvd, int quantidadeDisponivel, int codigoFilme, std::string categoriaDvd, std::string tituloFilme);
    void cadastraDvd();
};

/* Classe filha fita
* - armazena informações como se foi rebobinada;
* - valor da locação;
* - título da fita
* - quantidade de unidades disponíveis para posterior locação.*/

class Fita : public Filme {
  private:
    bool _rebobinada;
    int _valorLocacao;
    std::string _titulo;
    int _quantidadeDisponivel;


  public: 
    Fita(bool ehDvd, int quantidadeDisponivel, int codigoFilme, std::string tituloFilme);
    bool verificaQuantidadeDisponivel();
    void cadastraFita();
};

#endif