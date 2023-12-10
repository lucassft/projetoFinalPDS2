#ifndef CONTROLELOCACAO_H
#define CONTROLELOCACAO_H

#include <iostream>
#include <string.h>
#include <algorithm>
#include <sstream>
#include <fstream>

#include "../include/CadastroCliente.h"
#include "../include/CadastroFilme.h"


/* Classe que servirá de controle para a locadora. É uma classe que irá:
* - imprimir na tela quais são os comandos disponíveis;
* - ler um arquivo .txt e cadastrar os filmes nele presentes;
* - cadastrar/remover um filme e verificar se o mesmo já está cadstrado/alugado.*/

class ControleLocacao {
  public:
    ControleLocacao();
    void lerAquivo();
    void cadastrarFilme();
    void removeFilme();
    void listaFilme();
    void devolucaoFilme();
    void imprimeSistema();
};


#endif