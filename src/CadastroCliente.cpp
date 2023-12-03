#include <iostream>
#include <vector>
#include <string>

#include "../include/CadastroCliente.h"


Cliente::Cliente(int cpf, std::string nome) {
	if (cpf > 0) this->_cpf = cpf;
	else cadastraCliente();
  if (nome > "0") this->_nome = nome;
	else cadastraCliente();
}

int Cliente::tamClientesCadastrados() {
  return _clientesCadastrados.size();
}

void Cliente::cadastraCliente() {
  std::cout << "Informe o CPF e nome do cliente que deseja cadastrar no sistema:";
  int cpf; std::string nome; std::cin >> cpf >> nome;
  Cliente cliente(cpf, nome);
  _clientesCadastrados.push_back(cliente);
  std::cout << "Cliente <" << cpf << "> cadastrado com sucesso" << std::endl;
}

void Cliente::imprimeCliente(int cpf) {
  if(verificaCliente(cpf)) std::cout << "<" << this->_cpf << "> <" << this-> _nome << ">" << std::endl;
}

bool Cliente::verificaCliente(int cpf) {
  for (int i = 0; i < tamClientesCadastrados(); i++) {
    if (_clientesCadastrados[i]._cpf == cpf) return true;
    else return false;
  }
}

void Cliente::querCadastrar() {
  std::cout << "ERRO: CPF inexistente.\n" 
            << "Gostaria de cadastrar como novo cliente? [S|N]" << std::endl;
  char entradaUsuario = 0;
  std::cin >> entradaUsuario;
  if (entradaUsuario == 'S') cadastraCliente(); 
  else std::cout << "OK." << std::endl;
}

void Cliente::clienteDevolveu() {
  std::cout << "DV <CPF>" << std::endl;
  int cpf;
    if (verificaCliente(cpf)) {
    while (1) {
    }
  } else std::cout << "ERRO: CPF inexistente.\n" << std::endl;
}

void Cliente::removeCliente() {
  std::cout << "Informe o CPF do cliente que deseja remover do sistema:";
  int cpf; std::cin >> cpf;
  int tamClientesCadastrados = _clientesCadastrados.size();
  for (int i = 0; i < tamClientesCadastrados; i++) {
    if (_clientesCadastrados[i]._cpf == cpf) {_clientesCadastrados.erase(_clientesCadastrados.begin() + i);}
  } std::cout << "Cliente <" << cpf << "removido com sucesso" << std::endl;
}

std::string Cliente::getNomeCliente() {
  return this->_nome;
}

int Cliente::getCpfCliente() {
  return this->_cpf;
}

void Cliente::listaCliente() {}