#ifndef CADASTROCLIENTE_HPP
#define CADASTROCLIENTE_HPP

#include "../include/ControleLocacao.hpp"

#include <iostream>
#include <vector>

class Cliente {
	private:
		std::string _nome;
		int _cpf;
		std::vector<int> _FitaVideoAlugadas;
		std::vector<int> _DVDsAlugados;
	
	public:
		Cliente(std::string nome, int cpf);
		void clienteAluga(DVD&, FitaVideo&);
		void clienteDevolve(DVD&, FitaVideo&);
		int getCPF() const;
		std::string getNome() const;
		void imprimeCliente() const;
		~Cliente();
};

#endif