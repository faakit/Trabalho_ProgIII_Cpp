#ifndef SISTEMACPP_DOCENTE_H
#define SISTEMACPP_DOCENTE_H

#include <string>
#include <vector>
#include "disciplina.h"

using namespace std;

namespace dominio {
    class disciplina;
    class docente {
        string login;
        string nome;
        string website;
        vector<disciplina*> disciplinas;

    public:
        docente(string login, string nome, string website);
        void addDisciplina(disciplina* i);
        string getLogin() const;
        string getNome() const;
        string getWebsite() const;
    };
} //namespace

#endif //SISTEMACPP_DOCENTE_H
