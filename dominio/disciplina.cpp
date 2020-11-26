#include "disciplina.h"

using namespace std;

namespace dominio {

    disciplina::disciplina(string codigo, string nome, docente* professor, periodo* varPeriodo) {
        this->nome = std::move(nome);
        this->codigo = std::move(codigo);
        this->professor = professor;
        this->varPeriodo = varPeriodo;
        professor->addDisciplina(this);
    }

    docente* disciplina::getProfessor(){
        return this->professor;
    }

    periodo* disciplina::getPeriodo() {
        return this->varPeriodo;
    }

    string disciplina::toString() const {
        return this->codigo + "-" + this->varPeriodo->toString();
    }
}