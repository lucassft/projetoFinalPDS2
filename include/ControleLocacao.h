#ifndef CONTROLELOCACAO_H
#define CONTROLELOCACAO_H

#include <iostream>
#include <string.h>
#include <algorithm>
#include <sstream>
#include <fstream>

#include "../include/CadastroCliente.h"
#include "../include/CadastroFilme.h"

class ControleLocacao {
  public:
    ControleLocacao();
    void lerAquivo();
    void cadastrarFilme();
    void removeFita();
    void listaFilme();
    void devolucaoFilme();
    void imprimeSistema();
};


#endif