#ifndef FITAVIDEO_HPP
#define FITAVIDEO_HPP

#include "../include/EspecificacaoCadastroFilme/Filme.hpp"

#include <iostream>
#include <vector>

class FitaVideo : public Filme {
	private:
		std::vector<FitaVideo> _FitaVideoCadastradas;
		bool _rebobinada;
	
	public:
		FitaVideo();
		FitaVideo(int, std::string, int);
		bool verificaSaldoFitaVideo(int);
		void cadastraFitaVideoDoZero();
		void cadastraFitaVideoParametros(int, std::string, int);
		bool verificaCadastroFitaVideo(int);
		void removeFitaVideo(int);
		int qtdFitasVideoCadastrados();
		FitaVideo getFitaVideoCadastrada(int i); 
		int getFitaVideoCadastradaCodigoFilme(int i); 
		void listaFitaVideoCodigo();
		void listaFitaVideoTitulo();
		void imprimeFitaVideo();
		void clienteAlugaFitaVideo(int);
		int retornaDevolucaoFitaVideo(int, int);
		~FitaVideo();
};

struct SortCodigoFitaVideo {
  int property;
  SortCodigoFitaVideo(int property) {this->property = property;}
  bool operator()(const FitaVideo& f1, const FitaVideo& f2) const {
      if(property == 1)
          return f1.getCodigoNumeroFilme() < f2.getCodigoNumeroFilme();
      else
          return f1.getTituloFilme() < f2.getTituloFilme();
  }
};

#endif