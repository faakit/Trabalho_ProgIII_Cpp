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

    periodo::~periodo() = default;
}