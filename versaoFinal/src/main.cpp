#include "../include/EspecificacaoCadastroFilme/DVD.hpp"
#include "../include/EspecificacaoCadastroFilme/Filme.hpp"
#include "../include/EspecificacaoCadastroFilme/FitaVideo.hpp"
#include "../include/Cliente.hpp"
#include "../include/ControleLocacao.hpp"
#include "../include/SistemaLocadora.hpp"

int main() {
	SistemaLocadora sysLoc;
	ControleLocacao conLoc;
	DVD sistemaDVD;
	FitaVideo sistemaFitaVideo;
	sysLoc.interfaceSistemaLocadora(sistemaDVD, sistemaFitaVideo, conLoc);

	return 0;
}