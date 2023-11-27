#ifndef CONTROLELOCACAO_H
#define CONTROLELOCACAO_H

#include <iostream>
#include <vector>
#include <string>

#include "CadastroCliente.h"
#include "CadastroFilme.h"

class ControleLocacao : public Cliente,
                               Filme,
                               Fita, 
                               Dvd {
  public:
    void aluguelFilme() {
      std::cout << "AL <CPF> <Código1> ... <Código N>: " << std::endl;
      int cpf, codigo;
      std::cin >> cpf >> codigo;
      if (verificaCliente(cpf)) {
        if (Fita::verificaFilme(codigo))

      } else querCadastrar();

    }
    void devolucaoFilme() {
      std::cout << "DV <CPF>: " << std::endl;
      int cpf;
      std::cin >> cpf;
      if (verificaCliente(cpf)) {

      } else querCadastrar();

    }
};

#endif