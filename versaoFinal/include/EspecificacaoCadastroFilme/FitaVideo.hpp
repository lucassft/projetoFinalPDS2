#ifndef FITAVIDEO_HPP
#define FITAVIDEO_HPP

#include "Filme.hpp"

#include <iostream>
#include <vector>
#include <stdexcept>
#include <bitset>    

class FitaVideo : public Filme {

	private:

	/**
	  * Vetor que armazena as fitas cadastradas no sistema.
	  **/
		std::vector<FitaVideo> _FitaVideoCadastradas;
	
	/**
	  * booleano que indica se a fita foi rebobinada ou não.
	  **/
		bool _rebobinada;
	
	public:

	/**
	  * Construtor default da classe FitaVideo.
	  **/
		FitaVideo();

	/**
	  * Construtor que receba como parâmetro o código de 
		* identificação do filme, título e quantidade de
		* unidades disponíveis.
	  **/
		FitaVideo(int, std::string, int);

	/**
	  * 
	  **/
		bool verificaSaldoFitaVideo(FitaVideo&, int);

	/**
	  * Construtor que não recebe nenhum parâmetro. Ou seja,
		* recebe eles do usuário.
	  **/
		void cadastraFitaVideoDoZero(FitaVideo&);

	/**
	  * Construtor que não recebe nenhum parâmetro. Ou seja,
		* recebe eles do usuário.
	  **/
		void cadastraFitaVideoParametros(FitaVideo&, int, std::string, int);

	/**
	  * Função que verifica o cadastro de uma fita de video
		* a partir do código de identificação.
	  **/
		bool verificaCadastroFitaVideo(FitaVideo&, int);

	/**
	  * Função que remove uma fita de vídeo a partir do código
		* de identificação.
	  **/
		void removeFitaVideo(FitaVideo&, int);

	/**
	  * Função que retorna a quantidade de fitas cadastradas em 
		* vetor de fitas de vídeo.
	  **/
		int qtdFitasVideoCadastrados();

	/**
	  * Retorna uma fita de vídeo cadastrada a partir de um 
		* parâmetro para um loop.
	  **/
		FitaVideo getFitaVideoCadastrada(int i); 

	/**
	  * Retorna uma fita de vídeo cadastrada a partir de um 
		* código de identificaçao como parâmetro.
	  **/
		int getFitaVideoCadastradaCodigoFilme(FitaVideo&, int i); 

	/**
	  * Lista um vetor de fita de vídeo em ordem crescente a
		* partir do código de identificação.
	  **/
		void listaFitaVideoCodigo();
	
	/**
	  * Lista um vetor de fita de vídeo em ordem crescente a
		* partir do título do filme.
	  **/
		void listaFitaVideoTitulo();

	/**
	  * Imprime as informações de uma fita de vídeo.
	  **/
		void imprimeFitaVideo();

	/**
	  * Função que faz as mudanças de acordo com o aluguel de uma 
		* fita de vídeo.
	  **/
		void clienteAlugaFitaVideo(FitaVideo&, int);

	/**
	  * Função que faz as mudanças de acordo com a devolução de uma 
		* fita de vídeo.
	  **/
		int retornaDevolucaoFitaVideo(int, int);

	/**
	  * Função que faz as mudanças de acordo com a devolução de um DVD.
	  **/
		~FitaVideo();
};

/**
	* Struct responsável pela ordenação de um vetor de uma fita de vídeo
	* a partir ou do código de filme ou do título do filme.
	**/
struct SortCodigoFitaVideo {
			int property;
			SortCodigoFitaVideo(int property) {this->property = property;}
			bool operator()(FitaVideo& f1, FitaVideo& f2) const {
					if (property == 1) return f1.getCodigoNumeroFilme() < f2.getCodigoNumeroFilme();
					else return f1.getTituloFilme() < f2.getTituloFilme();
  	}
};

#endif