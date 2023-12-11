#ifndef CONTROLELOCACAO_HPP
#define CONTROLELOCACAO_HPP

#include "../include/EspecificacaoCadastroFilme/DVD.hpp"
#include "../include/EspecificacaoCadastroFilme/Filme.hpp"
#include "../include/EspecificacaoCadastroFilme/FitaVideo.hpp"
#include "../include/Cliente.hpp"

#include <iostream>
#include <vector>
#include <stdexcept>
#include <bitset>    

/*************************************************************
 * Classe Controle Locação que irá armazenar todos os clientes
 * que foram cadastrados no sistema.
 *************************************************************/
class ControleLocacao {
	private: 

	/**
	  * Vetor que armazena todos os clientes cadastrados;
	  **/
		std::vector<Cliente> _ClientesCadastrados;
	
	public:

	/**
	  * Construtor default de uma classe Controle Locação.
	  **/
		ControleLocacao();

	/**
	  * Função que retorna a quantidade de clientes cadastrados 
		* no sistema.
	  **/
		int qtdClientesCadastrados() const;

	/**
	  * Função que verifica se um cliente de determinado CPF está 
		* cadastrado no sistema.
	  **/
		bool verificaCPFCadastrado(int);
	
	/**
	  * Função que cadastra um cliente.
	  **/
		void cadastraCliente();
	
	/**
	  * Função que remove um cliente do sistema a partir do CPF.
	  **/
		void removeCliente(int);

	/**
	  * Lista um vetor de clientes cadastrados em ordem crescente
		* a partir do nome.
	  **/
		void listaClienteNome();

	/**
	  * Lista um vetor de clientes cadastrados em ordem crescente
		* a partir do CPF.
	  **/
		void listaClienteCPF();

	/**
	  * Função que retorna os filmes alugados por um cliente, de 
		* acordo com o valor devido para cada tipo de mídia e suas
		* condições.
	  **/
		void clienteDevolveu(int, DVD& ,FitaVideo&);

	/**
	  * Função que armazena os DVD's e fitas de vídeo alugadas 
		* por um determinado a cliente, passando por um verificador
		* se esse cliente já está cadastrado no sistema.
	  **/
		void clienteAlugou(int, int, DVD&, FitaVideo&);

	/**
	  * Destrutor default da classe Controle Locação.
	  **/
		~ControleLocacao();
};

/**
	* Struct responsável pela ordenação de um vetor de clientes 
	* cadastrados a partir do respectivo nome ou CPF.
	**/
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