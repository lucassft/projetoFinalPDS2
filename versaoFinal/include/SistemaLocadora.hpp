#ifndef SISTEMALOCADORA_HPP
#define SISTEMALOCADORA_HPP

#include "../include/EspecificacaoCadastroFilme/DVD.hpp"
#include "../include/EspecificacaoCadastroFilme/Filme.hpp"
#include "../include/EspecificacaoCadastroFilme/FitaVideo.hpp"
#include "../include/Cliente.hpp"
#include "../include/ControleLocacao.hpp"

#include <iostream>
#include <vector>
#include <fstream>
#include <stdexcept>
#include <bitset>    

/**********************************************************************
 * Classe SistemaLocadora que irá direcionar para todas as operações.
 **********************************************************************
 */
class SistemaLocadora {
	public:

	/**
	  * Construtor default da classe SistemaLocadora.
		**/
		SistemaLocadora();

	/**
	  * Função que imprime na tela as opções disponíveis ao operador do
		* sistema e recebe como parâmetro as classes em que iremos guardar
		* os clientes, DVD's e fitas de vídeo cadastrados.
		**/
		void interfaceSistemaLocadora(DVD&, FitaVideo&, ControleLocacao&);

	/**
	  * Imprime na tela as operações disponíveis na tela.
		**/
		void imprimeInterfaceSistemaLocadora();

	/**
	  * Lê um arquivo de cadastro e cadastra um DVD ou fita de vídeo a
		* partir de um arquivo de texto.
	  **/
		void lerArquivoCadastro(DVD&, FitaVideo&);

	/**
	  * Função que cadastra um filme nos vetores de DVD ou de fita de 
		* vídeo, de acordo com a classificação.
		**/
		void cadastrarFilme(DVD&, FitaVideo&);

	/**
	  * Função que remove um filme nos vetores de DVD ou de fita de 
		* vídeo, de acordo com a classificação.
		**/
		void removerFilme(DVD&, FitaVideo&);

	/**
	  * Função que lista os filmes armazenados nos vetores de DVD ou fita
		* de vídeo, de acordo com o código de identificação ou título.
		**/
		void listarFilmesOrdenadosCodigoTitulo(DVD&, FitaVideo&);

	/**
	  * Função que lista os clientes armazenados no vetor responsável pelo
		* armazenamento dos clientes cadastrados no sistema.
		**/
		void listaClienteCodigoNome(ControleLocacao&);

	/**
	  * Função que direciona ao cadastro de um cliente no vetor responsável
		* pelo armazenamento dos clientes cadastrados no sistema.
		**/
		void cadastrarCliente(ControleLocacao&);

	/**
	  * Função que direciona à remoção de um cliente no vetor responsável
		* pelo armazenamento dos clientes cadastrados no sistema.
		**/
		void removerCliente(ControleLocacao&);

	/**
	  * Função que direciona às operações que realizam o aluguel de um filme, 
		* de acordo com a disponibilidade dos DVD's ou fitas de aluguel e se ele 
		* está cadastrado no sistema.
		**/
		void aluguelFilme(ControleLocacao&, DVD&, FitaVideo&);

	/**
	  * Função que direciona às operações que realizam a devoluçãode um filme, 
		* de acordo com a disponibilidade dos DVD's ou fitas de aluguel e se ele 
		* está cadastrado no sistema.
		**/
		void devolucaoFilme(ControleLocacao&, DVD&, FitaVideo&);

	/**
	  * Destrutor default da classe SistemaLocadora.
		**/
		~SistemaLocadora();
};

#endif