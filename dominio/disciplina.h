#ifndef SISTEMACPP_DISCIPLINA_H
#define SISTEMACPP_DISCIPLINA_H

#include <string>
#include <map>
#include "periodo.h"
#include "docente.h"
#include "estudante.h"
#include "atividade.h"
#include "../utils/DateUtils.h"

using namespace std;

namespace dominio {
    class docente;
    class estudante;
    class atividade;
    class disciplina {
        string codigo;
        string nome;
        docente* professor;
        periodo* varPeriodo;
        map<string, estudante*> alunos;
        map<int, atividade*> atividades;
        double cargaHoraria;
        int nAtvSincronas;

    public:
        disciplina(string codigo, string nome, docente* professor, periodo* varPeriodo);
        docente* getProfessor();
        periodo* getPeriodo();
        string toString() const ;
        void addAluno(const string& matricula, estudante* estudante);
        void addAtividade(atividade* varAtividade);
        map<string, estudante*> getAlunos();
        map<int, atividade*> getAtividades();
        atividade* getAtividade(int nAtividade);
        int getNAtvSincronas() const;
        int getNAtividades() const;
        bool existeAtividade(int nAtividade) const;
        bool compareTo(disciplina* o);
        string getCodigo() const;
        string getNome() const;
        double getCargaHoraria() const;
    };
}

#endif //SISTEMACPP_DISCIPLINA_H
