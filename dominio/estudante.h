#ifndef SISTEMACPP_ESTUDANTE_H
#define SISTEMACPP_ESTUDANTE_H

#include <string>
#include "disciplina.h"
#include <list>
#include <set>
#include "../utils/StringUtils.h"

using namespace std;

namespace dominio {
    class periodo;
    class disciplina;
    class estudante {
        //Classe com variáveis a mais que auxiliam na hora de produzir relatórios
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
        bool compareTo(estudante* o);
    };
}

#endif //SISTEMACPP_ESTUDANTE_H
