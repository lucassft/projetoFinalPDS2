CC=g++
CFLAGS=-std=c++11 -Wall
TARGET=program
BUILD_DIR = ./build
SRC_DIR = ./src
INCLUDE_DIR = ./include

${BUILD_DIR}/${TARGET}: ${BUILD_DIR}/DVD.o ${BUILD_DIR}/Filme.o ${BUILD_DIR}/FitaVideo.o ${BUILD_DIR}/Cliente.o ${BUILD_DIR}/ControleLocacao.o ${BUILD_DIR}/SistemaLocadora.o ${BUILD_DIR}/main.o
	${CC} ${CFLAGS} ${BUILD_DIR}/*.o -o ${BUILD_DIR}/${TARGET}

${BUILD_DIR}/DVD.o: ${INCLUDE_DIR}/EspecificacaoCadastroFilme/DVD.hpp ${INCLUDE_DIR}/EspecificacaoCadastroFilme/Filme.hpp ${SRC_DIR}/ImplementacaoCadastroFilme/DVD.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/EspecificacaoCadastroFilme/ -c ${SRC_DIR}/ImplementacaoCadastroFilme/DVD.cpp -o ${BUILD_DIR}/DVD.o

${BUILD_DIR}/Filme.o: ${INCLUDE_DIR}/EspecificacaoCadastroFilme/Filme.hpp ${SRC_DIR}/ImplementacaoCadastroFilme/Filme.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/EspecificacaoCadastroFilme/ -c ${SRC_DIR}/ImplementacaoCadastroFilme/Filme.cpp -o ${BUILD_DIR}/Filme.o
	
${BUILD_DIR}/FitaVideo.o: ${INCLUDE_DIR}/EspecificacaoCadastroFilme/FitaVideo.hpp ${INCLUDE_DIR}/EspecificacaoCadastroFilme/Filme.hpp ${SRC_DIR}/ImplementacaoCadastroFilme/FitaVideo.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/EspecificacaoCadastroFilme/ -c ${SRC_DIR}/ImplementacaoCadastroFilme/FitaVideo.cpp -o ${BUILD_DIR}/FitaVideo.o

${BUILD_DIR}/Cliente.o: ${INCLUDE_DIR}/EspecificacaoCadastroFilme/DVD.hpp ${INCLUDE_DIR}/EspecificacaoCadastroFilme/Filme.hpp ${INCLUDE_DIR}/EspecificacaoCadastroFilme/FitaVideo.hpp ${INCLUDE_DIR}/Cliente.hpp ${SRC_DIR}/Cliente.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/Cliente.hpp -c ${SRC_DIR}/Cliente.cpp -o ${BUILD_DIR}/Cliente.o

${BUILD_DIR}/ControleLocacao.o: ${INCLUDE_DIR}/EspecificacaoCadastroFilme/DVD.hpp ${INCLUDE_DIR}/EspecificacaoCadastroFilme/Filme.hpp ${INCLUDE_DIR}/EspecificacaoCadastroFilme/FitaVideo.hpp ${INCLUDE_DIR}/Cliente.hpp ${INCLUDE_DIR}/ControleLocacao.hpp  ${SRC_DIR}/ControleLocacao.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ControleLocacao.hpp -c ${SRC_DIR}/ControleLocacao.cpp -o ${BUILD_DIR}/ControleLocacao.o

${BUILD_DIR}/SistemaLocadora.o: ${INCLUDE_DIR}/EspecificacaoCadastroFilme/DVD.hpp ${INCLUDE_DIR}/EspecificacaoCadastroFilme/Filme.hpp ${INCLUDE_DIR}/EspecificacaoCadastroFilme/FitaVideo.hpp ${INCLUDE_DIR}/Cliente.hpp ${INCLUDE_DIR}/ControleLocacao.hpp ${INCLUDE_DIR}/SistemaLocadora.hpp ${SRC_DIR}/SistemaLocadora.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/SistemaLocadora.hpp -c ${SRC_DIR}/SistemaLocadora.cpp -o ${BUILD_DIR}/SistemaLocadora.o

${BUILD_DIR}/main.o: ${INCLUDE_DIR}/EspecificacaoCadastroFilme/DVD.hpp ${INCLUDE_DIR}/EspecificacaoCadastroFilme/Filme.hpp ${INCLUDE_DIR}/EspecificacaoCadastroFilme/FitaVideo.hpp ${INCLUDE_DIR}/Cliente.hpp ${INCLUDE_DIR}/ControleLocacao.hpp ${INCLUDE_DIR}/SistemaLocadora.hpp  ${SRC_DIR}/main.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/main.cpp -o ${BUILD_DIR}/main.o


# Rule for cleaning files generated during compilation.
# Call 'make clean' to use it
clean:
	rm -f ${BUILD_DIR}/