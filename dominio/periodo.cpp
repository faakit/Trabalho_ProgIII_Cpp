#include "periodo.h"

using namespace std;

namespace dominio {

    periodo::periodo(int ano, char semestre) {
        this->ano = ano;
        this->semestre = semestre;
    }

    int periodo::getAno() const {
        return this->ano;
    }

    char periodo::getSemestre() const {
        return this->semestre;
    }

    string periodo::toString() const {
        return to_string(this->ano) + "/" + this->getSemestre();
    }

    void periodo::addDisciplina(disciplina *i) {
        this->disciplinas.push_back(i);
    }

    vector<disciplina *> periodo::getDisciplinas() const {
        return this->disciplinas;
    }

    bool periodo::compareTo(periodo *o) {
        return (this->ano < o->ano ||
                (this->ano == o->ano && this->semestre < o->semestre));
    }

    periodo::~periodo() = default;
}