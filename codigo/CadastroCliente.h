#ifndef CADASTROCLIENTE_H
#define CADASTROCLIENTE_H

#include <iostream>
#include <vector>
#include <string>

class Cliente {
  private:
    std::vector<Cliente> _clientesCadastrados;
    std::vector<Filme> _filmesAlugados;
    std::string _nome;
    int _cpf;

  public:
    Cliente(int cpf, std::string nome) {
      this->_cpf = cpf;
      this->_nome = nome;
    }
    int tamClientesCadastrados() {
      return _clientesCadastrados.size();
    };
    bool verificaCliente(int cpf) {
      for (int i = 0; i < tamClientesCadastrados(); i++) {
        if (_clientesCadastrados[i]._cpf == cpf) return true;
        else return false;
      }
    }
    void querCadastrar() {
      std::cout << "ERRO: CPF inexistente.\n" 
                << "Gostaria de cadastrar como novo cliente? [S|N]" << std::endl;
      char entradaUsuario = 0;
      std::cin >> entradaUsuario;
      if (entradaUsuario == 'S') cadastraCliente(); 
      else std::cout << "OK." << std::endl;
    }
    void clienteDevolveu() {
      std::cout << "DV <CPF>" << std::endl;
      int cpf;
        if (verificaCliente(cpf)) {
        while (1) {
        }
      } else std::cout << "ERRO: CPF inexistente.\n" << std::endl;
    }
    void cadastraCliente() {
      std::cout << "Informe o CPF e nome do cliente que deseja cadastrar no sistema:";
      int cpf; std::string nome; std::cin >> cpf >> nome;
      Cliente cliente(cpf, nome);
      _clientesCadastrados.push_back(cliente);
      std::cout << "Cliente <" << cpf << "> cadastrado com sucesso" << std::endl;
    }
    void removeCliente() {
      std::cout << "Informe o CPF do cliente que deseja remover do sistema:";
      int cpf; std::cin >> cpf;
      int tamClientesCadastrados = _clientesCadastrados.size();
      for (int i = 0; i < tamClientesCadastrados; i++) {
        if (_clientesCadastrados[i]._cpf == cpf) {_clientesCadastrados.erase(_clientesCadastrados.begin() + i);}
      } std::cout << "Cliente <" << cpf << "removido com sucesso" << std::endl;
    }
    void listaCliente() {
      char entradaUsuario = 0;
      std::cin >> entradaUsuario;
      if (entradaUsuario = 'C') {

      }
      if (entradaUsuario = 'N') {

      }
    }
};

#endif 