#ifndef DVD_HPP
#define DVD_HPP

#include "../include/EspecificacaoCadastroFilme/Filme.hpp"

#include <iostream>
#include <vector>

class DVD : public Filme {
	private:
		std::vector<DVD> _DVDsCadastrados;
		int _categoriaDVD;

	public:
		DVD();
		DVD(int, std::string, int, int);
		void cadastraDVDdoZero();
		void cadastraDVDparametros(int, std::string, int, int);
		void removeDVD(int);
		bool verificaCadastroDVD(int); 
		bool verificaSaldoDVD(int);
		int qtdDVDsCadastrados();
		DVD getDVDsCadastrados(int);
		int getDVDsCadastradosCodigoFilme(int);
		void listaDVDsCodigo();
		void listaDVDsTitulo();
		void imprimeDVD();
		void clienteAlugaDVD(int);
		int retornaDevolucaoDVD(int, int);
		~DVD();
};

struct SortCodigoDVD {
  int property;
  SortCodigoDVD(int property) {this->property = property;}
  bool operator()(const DVD& d1, const DVD& d2) const {
      if(property == 1)
          return d1.getCodigoNumeroFilme() < d2.getCodigoNumeroFilme();
      else
          return d1.getTituloFilme() < d2.getTituloFilme();
  }
};

#endif