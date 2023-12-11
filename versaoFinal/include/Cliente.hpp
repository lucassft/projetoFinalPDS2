#ifndef CLIENTE_HPP
#define CLIENTE_HPP

#include "../include/EspecificacaoCadastroFilme/DVD.hpp"
#include "../include/EspecificacaoCadastroFilme/Filme.hpp"
#include "../include/EspecificacaoCadastroFilme/FitaVideo.hpp"

#include <iostream>
#include <vector>

/*************************************************************
 * Classe Cliente que irá armazenar todas as informações que 
 * são pertinentes a um cliente..
 *************************************************************/
class Cliente {
	private:

	/**
	  * Nome de um cliente que será cadastrado.
	  **/
		std::string _nome;

	/**
	  * CPF de um cliente que será cadastrado.
	  **/
		int _cpf;

	/**
	  * Vetor que armazena todas as fitas de vídeo que foram 
		* alugadas por um determinado cliente.
	  **/
		std::vector<int> _FitaVideoAlugadas;

	/**
	  * Vetor que armazena todas os DVD's que foram alugadas 
		* por um determinado cliente.
	  **/
		std::vector<int> _DVDsAlugados;
	
	public:

	/**
	  * Construtor default da classe cliente.
	  **/
		Cliente();

	/**
	  * Construtor que receba como parâmetro o nome e CPF de 
		* um cliente.
	  **/
		Cliente(std::string nome, int cpf);

	/**
	  * Função que faz todas as operações acerca do aluguel 
		* de um filme, como diminuir a quantidade disponível 
		* e o armazenar no vetor de DVD's alugados, se for um
		* DVD, ou no vetor de fitas de vídeo alugadas, se for 
		* uma fita de vídeo.
	  **/
		void clienteAluga(DVD&, FitaVideo&);

	/**
	  * Função que verifica se um código de identificação do 
		* filme está armazenado nos vetores que armazenam os 
		* DVD's/Fitas de vídeo cadastradas.
	  **/
		void clienteAlugaCodigo(int, DVD&, FitaVideo&);

	/**
	  * Função que aumenta a quantidade disponível de DVD's ou
		* fitas de vídeo que foram alugadas, de volta ao vetor de
		* mídia cadastrados.
	  **/
		void clienteDevolve(DVD&, FitaVideo&);
	
	/**
	  * Função que retorna o CPF de um cliente cadastrado.
	  **/
		int getCPF() const;

	/**
	  * Função que retorna o nome de um cliente cadastrado.
	  **/
		std::string getNome() const;

	/**
	  * Função que imprime as informações de um cliente 
		* cadastrado.
	  **/
		void imprimeCliente() const;

	/**
	  * Destrutor default da classe Cliente.
	  **/
		~Cliente();
};

#endif