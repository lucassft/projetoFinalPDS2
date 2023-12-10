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

std::ifstream inFile;

class SistemaLocadora {
	public:
		SistemaLocadora();
		void interfaceSistemaLocadora(DVD&, FitaVideo&, ControleLocacao&);
		void imprimeInterfaceSistemaLocadora();
		void lerArquivoCadastro();
		void cadastrarFilme();
		void removerFilme();
		void listarFilmesOrdenadosCodigoTitulo(DVD&, FitaVideo&);
		void cadastrarCliente(ControleLocacao&);
		void removerCliente(ControleLocacao&);
		void listaClienteCodigoNome(ControleLocacao&);
		void aluguelFilme(ControleLocacao&);
		void devolucaoFilme(ControleLocacao&);
		~SistemaLocadora();
};

#endif