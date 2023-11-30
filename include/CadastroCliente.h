#ifndef CADASTROCLIENTE_H
#define CADASTROCLIENTE_H

#include <iostream>
#include <vector>
#include <string>

#include "../include/CadastroFilme.h"

class Cliente : public Fita, Dvd {
  private:
    std::vector<Cliente> _clientesCadastrados;
    std::vector<int> _dvdsAlugados;
    std::vector<int> _fitasAlugados;
    std::string _nome;
    int _cpf;


  public:
    Cliente(int cpf, std::string nome);
    int tamClientesCadastrados() {};
    void cadastraCliente() {};
    void imprimeCliente(int cpf) {};
    bool verificaCliente(int cpf) {};
    void querCadastrar() {};
    void clienteDevolveu() {};
    void removeCliente() {};
    std::string getNomeCliente() {};
    int getCpfCliente() {};
    void listaCliente() {};
};

#endif 