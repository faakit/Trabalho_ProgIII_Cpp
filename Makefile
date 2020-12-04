COMPILER=g++ -std=c++11

all: compile

compile: main

run:
	@./main -p periodos.csv -d docentes.csv -o disciplinas.csv -m matriculas.csv -a atividades.csv -n avaliacoes.csv -e estudantes.csv

clean:
	@rm -rf bin main 1-visao-geral.csv 2-docentes.csv 3-estudantes.csv 4-disciplinas.csv


########################
### Classes do Utils ###
########################
PACOTE_UTILS= bin/utils/DateUtils.o bin/utils/StringUtils.o bin/utils/Tokenizer.o

bin/utils:
	@mkdir -p bin/utils

bin/utils/DateUtils.o: bin/utils utils/DateUtils.cpp utils/DateUtils.h
	@${COMPILER} -o bin/utils/DateUtils.o -c utils/DateUtils.cpp

bin/utils/StringUtils.o: bin/utils utils/StringUtils.cpp utils/StringUtils.h
	@${COMPILER} -o bin/utils/StringUtils.o -c utils/StringUtils.cpp

bin/utils/Tokenizer.o: bin/utils utils/Tokenizer.cpp utils/Tokenizer.h
	@${COMPILER} -o bin/utils/Tokenizer.o -c utils/Tokenizer.cpp

#####################
### Classes do IO ###
#####################
PACOTE_IO= bin/io/escritor.o bin/io/exception.o bin/io/leitor.o bin/io/memoria.o

bin/io:
	@mkdir -p bin/io

bin/io/escritor.o: bin/io io/escritor.cpp io/escritor.h io/memoria.h utils/StringUtils.h dominio/aula.h dominio/trabalho.h io/exception.h
	@${COMPILER} -o bin/io/escritor.o -c io/escritor.cpp

bin/io/exception.o: bin/io io/exception.cpp io/exception.h
	@${COMPILER} -o bin/io/exception.o -c io/exception.cpp

bin/io/leitor.o: bin/io io/leitor.cpp io/leitor.h io/memoria.h utils/Tokenizer.h utils/StringUtils.h io/exception.h dominio/disciplina.h dominio/aula.h dominio/estudo.h dominio/trabalho.h dominio/prova.h
	@${COMPILER} -o bin/io/leitor.o -c io/leitor.cpp

bin/io/memoria.o: bin/io io/memoria.cpp io/memoria.h dominio/disciplina.h
	@${COMPILER} -o bin/io/memoria.o -c io/memoria.cpp

##########################
### Classes de domínio ###
##########################
PACOTE_DOMINIO= bin/dominio/atividade.o bin/dominio/aula.o bin/dominio/disciplina.o bin/dominio/docente.o bin/dominio/estudante.o bin/dominio/estudo.o bin/dominio/nota.o bin/dominio/periodo.o bin/dominio/prova.o bin/dominio/trabalho.o

bin/dominio:
	@mkdir -p bin/dominio

bin/dominio/atividade.o: bin/dominio dominio/atividade.cpp dominio/atividade.h dominio/nota.h
	@${COMPILER} -o bin/dominio/atividade.o -c dominio/atividade.cpp

bin/dominio/aula.o: bin/dominio dominio/aula.cpp dominio/aula.h dominio/atividade.h utils/DateUtils.h
	@${COMPILER} -o bin/dominio/aula.o -c dominio/aula.cpp

bin/dominio/disciplina.o: bin/dominio dominio/disciplina.cpp dominio/disciplina.h dominio/periodo.h dominio/docente.h dominio/estudante.h dominio/atividade.h utils/DateUtils.h
	@${COMPILER} -o bin/dominio/disciplina.o -c dominio/disciplina.cpp

bin/dominio/docente.o: bin/dominio dominio/docente.cpp dominio/docente.h dominio/disciplina.h
	@${COMPILER} -o bin/dominio/docente.o -c dominio/docente.cpp

bin/dominio/estudante.o: bin/dominio dominio/estudante.cpp dominio/estudante.h dominio/disciplina.h utils/StringUtils.h
	@${COMPILER} -o bin/dominio/estudante.o -c dominio/estudante.cpp

bin/dominio/estudo.o: bin/dominio dominio/estudo.cpp dominio/estudo.h dominio/atividade.h
	@${COMPILER} -o bin/dominio/estudo.o -c dominio/estudo.cpp

bin/dominio/nota.o: bin/dominio dominio/nota.cpp dominio/nota.h dominio/estudante.h
	@${COMPILER} -o bin/dominio/nota.o -c dominio/nota.cpp

bin/dominio/periodo.o: bin/dominio dominio/periodo.cpp dominio/periodo.h dominio/disciplina.h
	@${COMPILER} -o bin/dominio/periodo.o -c dominio/periodo.cpp

bin/dominio/prova.o: bin/dominio dominio/prova.cpp dominio/prova.h dominio/atividade.h utils/DateUtils.h
	@${COMPILER} -o bin/dominio/prova.o -c dominio/prova.cpp

bin/dominio/trabalho.o: bin/dominio dominio/trabalho.cpp dominio/trabalho.h dominio/atividade.h utils/DateUtils.h
	@${COMPILER} -o bin/dominio/trabalho.o -c dominio/trabalho.cpp


main: ${PACOTE_UTILS} ${PACOTE_IO} ${PACOTE_DOMINIO} main.cpp
	@${COMPILER} -o main main.cpp ${PACOTE_UTILS} ${PACOTE_IO} ${PACOTE_DOMINIO}