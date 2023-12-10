#ifndef FILME_HPP
#define FILME_HPP

#include <iostream>
#include <vector>
#include <algorithm>

class Filme {
	private:
		int _codigoNumeroFilme;
		std::string _tituloFilme;
		int _numeroUnidadesDisponiveis;

	public:
		Filme();
		Filme(int, std::string, int);
		void diminuiUnidadesDisponiveis();
		void setDVD();
		void setFitaVideo();
		int getCodigoNumeroFilme () const;
		void setCodigoNumeroFilme (int);
		int getNumeroUnidadesDisponiveis();
		std::string getTituloFilme () const;
		~Filme();
};

#endif