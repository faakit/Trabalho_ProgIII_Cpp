cmake_minimum_required(VERSION 3.17)
project(sistemaCpp)

set(CMAKE_CXX_STANDARD 14)

add_executable(sistemaCpp main.cpp dominio/periodo.cpp dominio/periodo.h dominio/docente.cpp dominio/docente.h dominio/estudante.cpp dominio/estudante.h dominio/disciplina.cpp dominio/disciplina.h dominio/atividade.cpp dominio/atividade.h dominio/nota.cpp dominio/nota.h dominio/aula.cpp dominio/aula.h utils/DateUtils.cpp utils/DateUtils.h utils/Tokenizer.cpp utils/Tokenizer.h utils/StringUtils.cpp utils/StringUtils.h dominio/estudo.cpp dominio/estudo.h dominio/prova.cpp dominio/prova.h dominio/trabalho.cpp dominio/trabalho.h io/memoria.cpp io/memoria.h io/leitor.cpp io/leitor.h io/exception.cpp io/exception.h)