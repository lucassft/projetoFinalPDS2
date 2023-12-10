#ifndef CADASTROCLIENTE_H
#define CADASTROCLIENTE_H

#include <iostream>
#include <vector>
#include <string>

/* Classe criada com o intuito de lidar com o cadastro e outras funções
		relacionadas ao gerenciamento dos clientes */

class Cliente {
  private:
    std::vector<Cliente> _clientesCadastrados;
    std::vector<int> _dvdsAlugados;
    std::vector<int> _fitasAlugados;
    std::string _nome;
    int _cpf;


  public:
    Cliente(int cpf, std::string nome);
    int tamClientesCadastrados();
    void cadastraCliente();
    void imprimeCliente(int cpf);
    bool verificaCliente(int cpf);
    void querCadastrar();
    void clienteDevolveu();
    void removeCliente();
    std::string getNomeCliente();
    int getCpfCliente();
    void listaCliente();
};

#endif 