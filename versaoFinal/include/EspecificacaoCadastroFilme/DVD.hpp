#ifndef DVD_HPP
#define DVD_HPP

#include "Filme.hpp"

#include <iostream>
#include <vector>

/*************************************************************
 * Subclasse da filha Filme.
 *************************************************************/
class DVD : public Filme {
	private:

	/**
	  * Vetor que armazena todos os DVDs cadastrados 
		* no sistema. 
	  **/
		std::vector<DVD> _DVDsCadastrados;

	/**
	  * Armazena a categoria do DVD que será usada para calcular
		* o valor de retorno do DVD.
	  **/
		int _categoriaDVD;

	public:

	/**
	  * Construtor default da classe DVD.
	  **/
		DVD();

	/**
	  * Construtor que recebe código, título, número de unidades 
		* disponíveis e categoria de um DVD.
	  **/
		DVD(int, std::string, int, int);

	/**
	  * Construtor que não recebe parâmetros, mas instrui "do zero"
		* que leva aos parâmetros necessários para a construção de um
		* um DVD.
	  **/
		void cadastraDVDdoZero(DVD&);

	/**
	  * Construtor que cadastra um novo filme no vetor do sistema que
		* armazena filmes cadastrados, a partir dos parâmetros que foram
		* fornecidos.
	  **/
		void cadastraDVDparametros(DVD&, int, std::string, int, int);

	/**
	  * Função que remove um DVD a partir do código de filme recebido
		* como parâmetro.
	  **/
		void removeDVD(DVD&, int);

	/**
		* Função que verifica se um DVD está cadastrado no sistema de 
		* cadastro de DVD's a partir do código de identificação.
		**/
		bool verificaCadastroDVD(DVD&, int); 

	/**
		* Função que verifica se um DVD cadastrado no sistema de 
		* cadastro de DVD's tem saldo, a partir do código de identificação.
		**/
		bool verificaSaldoDVD(DVD&, int);

	/**
		* Retorna a quantidade de DVD's cadastrados no vetor de cadastro
		* de sistema.
		**/
		int qtdDVDsCadastrados();

	/**
		* Retorna um DVD cadastrado a partir do índice.
		**/
		DVD getDVDsCadastrados(int);

	/**
		* Retorna um DVD cadastrado a partir do código de identificação como
		* um parâmetro.
		**/
		int getDVDsCadastradosCodigoFilme(int);

	/**
		* Lista um vetor de DVD's em ordem crescente a partir do código de identificação.
		**/
		void listaDVDsCodigo();

	/**
		* Lista um vetor de DVD's em ordem crescente a partir do título.
		**/
		void listaDVDsTitulo();

	/**
		* Imprime as informações de um DVD.
		**/
		void imprimeDVD();

	/**
		* Função que faz as mudanças de acordo com o aluguel de um DVD.
		**/
		void clienteAlugaDVD(DVD&, int);

	/**
		* Função que faz as mudanças de acordo com a devolução de um DVD.
		**/
		int retornaDevolucaoDVD(int, int);
		~DVD();
};

/**
	* Struct responsável pela ordenação de um vetor de DVD's a partir 
	* ou do código de filme ou do título do filme.
	**/
struct SortCodigoDVD {
  int property;
  SortCodigoDVD(int property) {this->property = property;}
  bool operator()(const DVD& d1, const DVD& d2) const {
      if (property == 1) return d1.getCodigoNumeroFilme() < d2.getCodigoNumeroFilme();
      else return d1.getTituloFilme() < d2.getTituloFilme();
  }
};

#endif