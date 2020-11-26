#ifndef SISTEMACPP_DISCIPLINA_H
#define SISTEMACPP_DISCIPLINA_H

#include <string>
#include <map>
#include "periodo.h"
#include "docente.h"
#include "estudante.h"

using namespace std;

namespace dominio {
    class docente;
    class disciplina {
        string codigo;
        string nome;
        docente* professor;
        periodo* varPeriodo;
        map<string, estudante> alunos;

    public:
        disciplina(string codigo, string nome, docente* professor, periodo* varPeriodo);
        docente* getProfessor();
        periodo* getPeriodo();
        string toString() const ;
    };
}

#endif //SISTEMACPP_DISCIPLINA_H
