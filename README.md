O projeto está estrutura da seguinte forma:

versaoFinal
├── Makefile
├── build
├── include
│ └── EspecificacaoCadastroFilme
|       └── DVD.hpp
|       └── Filme.hpp
|       └── FitaVideo.hpp
│ └── SistemaLocadora.hpp
│ └── ControleLocacao.hpp
│ └── Cliente.hpp
└── src
│ └── ImplementacaoCadastroFilme
|       └── DVD.cpp
|       └── Filme.cpp
|       └── FitaVideo.cpp
│ └── SistemaLocadora.cpp
│ └── ControleLocacao.cpp
│ └── Cliente.cpp

A parte de:
-  implementação está localizada no diretório src/;
-  especificação no diretório include/;
-  o programa no diretório build/;
-  os testes, em tests/;
