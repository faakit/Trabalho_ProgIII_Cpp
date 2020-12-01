#ifndef SISTEMACPP_ESTUDANTE_H
#define SISTEMACPP_ESTUDANTE_H

#include <string>
#include "disciplina.h"
#include <list>
#include <set>

using namespace std;

namespace dominio {
    class disciplina;
    class estudante {
        string matricula;
        string nome;
        int nAvaliacoes;
        double totalAvaliacoes;
        list<disciplina*> disciplinas;
        set<periodo*> periodos;

    public:
        estudante(string, string);

        string getMatricula() const;
        string getNome() const;
        void incrementaAvaliacoes(double nota);
        int getNPeriodos() const;
        double getTotalAvaliacoes() const;
        int getNAvaliacoes() const;
        list<disciplina*> getDisciplinas() const;
        void addDisciplina(disciplina* varDisciplina);
    };
}

#endif //SISTEMACPP_ESTUDANTE_H
