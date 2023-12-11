#ifndef FILME_HPP
#define FILME_HPP

#include <iostream>
#include <vector>
#include <algorithm>

/*****************************************************************
	*Superclasse Filme que irá fornecer a base para as classes DVD e
	*e FitaVideo.
	*Teremos um código de identificação do filme, um título e algum 
	*número de unidades disponíveis para locação.
	****************************************************************/
class Filme {

	private:

	/**
		*Código de identificação do filme do tipo int.
		**/
		int _codigoNumeroFilme; 

	/**
		*Título do filme do tipo string.
		**/
		std::string _tituloFilme; 

  /**
 	  * Número de unidades disponíveis para locação do tipo int.
	  **/
		int _numeroUnidadesDisponiveis;

	public:
	/** 
	  *Construtor default da classe Filme.
    **/
		Filme();

	/**
	  * Construtor que recebe o código de identificação do filme
	  **/
		Filme(int, std::string, int); 

	/**
	  * Função que diminui a quantidade de unidades disponíveis.
	  **/
		void diminuiUnidadesDisponiveis();
	
	/**
	  * Função que define o booleano 'ehDVD' como um DVD.
	  **/
		void setDVD();

	/**
	  *  Função que define o booleano 'ehDVD' como uma fita de vídeo.
	  **/
		void setFitaVideo();

	/**
	  * Função que retorna o código de identificação de um filme.
	  **/
		int getCodigoNumeroFilme () const;

	/**
	  * Função que retorna a quantidade de unidades disponíveis 
		* de um DVD ou fita de vídeo.
	  **/
		int getNumeroUnidadesDisponiveis();

	/**
	  * Função que retorna o título de um filme.
	  **/	
		std::string getTituloFilme () const;

	/**
	  * Destrutor default da classe Filme.
	  **/	
		~Filme();
};

#endif