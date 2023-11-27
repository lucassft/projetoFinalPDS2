#include <iostream>
#include <string.h>
#include <algorithm>
#include <sstream>
#include <fstream>

#include <CadastroCliente.h>
#include <CadastroFilme.h>
#include <ControleLocacao.h>

void imprimeSistema() {
  std::cout << "Selecione uma opção.\n"
            << "----------------------------\n"
            << "LA: Ler Arquivo de Cadastro.\n"
            << "CF: Cadastrar Filme.\n"
            << "RF: Remover Filme.\n" 
            << "LF: Listar Filmes.\n" //ordenados por Código [C] ou Título [T].\n"
            << "CF: Cadastrar Cliente.\n"
            << "RF: Remover Cliente.\n"
            << "LC: Listar Clientes.\n"//ordenados por Código ou Nome:"
            << "AL: Aluguel Filme.\n"
            << "DV: Devolução Filme.\n"
            << "FS: Finalizar Sistema.\n"
            << "----------------------------\n"
            << std::endl;   

  std::string entradaUsuario;
  getline(std::cin, entradaUsuario);
  transform(entradaUsuario.begin(), entradaUsuario.end(), entradaUsuario.begin(), ::toupper);

  while (entradaUsuario != "FS") {

    if (entradaUsuario == "LA") {
      std::cout << "Deseja registrar Fita[F] ou DVD[N]?" << std::endl;

      std::cin >> entradaUsuario;
      getline(std::cin, entradaUsuario);
      transform(entradaUsuario.begin(), entradaUsuario.end(), entradaUsuario.begin(), ::toupper);
      std::ifstream infile("thefile.txt");

      if (entradaUsuario == "F") {
        std::string line;

        while (std::getline(infile, line))
        {
            std::istringstream iss(line);
            //CF <Tipo: F|D> <quantidade> <código> <título> <categoria no caso de DVD>
            int quantidadeDisponivel, codigoFita; std::string titulo;
            Fita fita(quantidadeDisponivel, codigoFita, titulo);
            if (!(iss >> quantidadeDisponivel >> codigoFita >> titulo)) { break; } // error
        }
      }
      if (entradaUsuario == "D") {
        std::string line;

        while (std::getline(infile, line))
        {
            std::istringstream iss(line);
            //CF <Tipo: F|D> <quantidade> <código> <título> <categoria no caso de DVD>
            int quantidadeDisponivel, codigoDvd; std::string titulo, categoriaDvd;
            Dvd dvd(quantidadeDisponivel, codigoDvd, titulo, categoriaDvd);
            if (!(iss >> quantidadeDisponivel >> codigoDvd >> titulo >> categoriaDvd)) { break; } // error
        }
      }
    }
    if (entradaUsuario == "CF") {

    }
    if (entradaUsuario == "RF") {}
    if (entradaUsuario == "LF") {}
    if (entradaUsuario == "CF") {}
    if (entradaUsuario == "RF") {}
    if (entradaUsuario == "LC") {}
    if (entradaUsuario == "AL") {}
    if (entradaUsuario == "DV") {}

    getline(std::cin, entradaUsuario);
    transform(entradaUsuario.begin(), entradaUsuario.end(), entradaUsuario.begin(), ::toupper);
  }
};

int main() {

}