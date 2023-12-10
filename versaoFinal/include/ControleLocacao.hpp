#ifndef CONTROLELOCACAO_HPP
#define CONTROLELOCACAO_HPP

#include "../include/EspecificacaoCadastroFilme/DVD.hpp"
#include "../include/EspecificacaoCadastroFilme/Filme.hpp"
#include "../include/EspecificacaoCadastroFilme/FitaVideo.hpp"
#include "../include/Cliente.hpp"

#include <iostream>
#include <vector>

class ControleLocacao {
	private: 
		std::vector<Cliente> _ClientesCadastrados;
	
	public:
		ControleLocacao();
		int qtdClientesCadastrados() const;
		bool verificaCPFCadastrado(int);
		void cadastraCliente();
		void removeCliente(int);
		void listaClienteNome();
		void listaClienteCPF();
		void clienteDevolveu(int, DVD& ,FitaVideo&);
		~ControleLocacao();
};

struct SortClienteNomeCPF {
  int property;
  SortClienteNomeCPF(int property) {this->property = property;}
  bool operator()(const Cliente& c1, const Cliente& c2) const {
      if(property == 1)
          return c1.getCPF() < c2.getCPF();
      else
          return c1.getNome() < c2.getNome();
  }
};

#endif