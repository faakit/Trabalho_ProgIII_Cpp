#ifndef SISTEMACPP_ESCRITOR_H
#define SISTEMACPP_ESCRITOR_H

#include "memoria.h"
#include <fstream>
#include <algorithm>
#include <iostream>
#include "../utils/StringUtils.h"
#include "../dominio/aula.h"
#include "../dominio/trabalho.h"

using namespace utils;
using namespace std;

namespace io {
    class escritor {
        const string cabecalhoVisaoGeral="Período;Código Disciplina;Disciplina;Docente Responsável;E-mail Docente;Qtd. Estudantes;Qtd. Atividades";
        const string cabecalhoEstDocentes="Docente;Qtd. Disciplinas;Qtd. Períodos;Média Atividades/Disciplina;% Síncronas;% Assíncronas;Média de Notas";
        const string cabecalhoEstEst="Matrícula;Nome;Média Disciplinas/Período;Média Avaliações/Disciplina;Média Notas Avaliações";
        const string cabecalhoEstDisDoc="Docente;Período;Código;Nome;Qtd. Atividades;% Síncronas;% Assíncronas;CH;Datas Avaliações";
        const string separadorCSV=";";
        memoria* memoriaObj;

    public:
        explicit escritor(memoria* memoriaObj);
        void visaoGeralPeriodo();
        void estatisticaDocentes();
        void estatisticaEstudantes();
        void estatisticaDisciplinasDocente();
    };
}

#endif //SISTEMACPP_ESCRITOR_H
