#ifndef SISTEMACPP_DOCENTE_H
#define SISTEMACPP_DOCENTE_H

#include <string>
#include <vector>
#include <set>
#include "disciplina.h"

using namespace std;

namespace dominio {
    class atividade;
    class nota;
    class periodo;
    class disciplina;
    class docente {
        //Classe com variáveis a mais que auxiliam na hora de produzir relatórios
        string login;
        string nome;
        string website;
        vector<disciplina*> disciplinas;
        set<periodo*> periodos;
        int nDisciplinas;
        int nAtividades;
        int nAtividadesSincronas;
        int nNotas;
        double totalNotas;

    public:
        docente(string login, string nome, string website);
        void addDisciplina(disciplina* i);
        string getLogin() const;
        string getNome() const;
        string getWebsite() const;
        void addAtividade(atividade *i);
        int getNDisciplinas() const;
        int getNAtvSincronas() const;
        double getNAtividades() const;
        set<periodo*> getPeriodos () const;
        void addNota(nota* i);
        int getNNotas() const;
        double getTotalNotas() const;
    };
} //namespace

#endif //SISTEMACPP_DOCENTE_H
