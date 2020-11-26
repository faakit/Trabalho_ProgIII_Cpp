#include "estudante.h"

using namespace std;

namespace dominio {

    estudante::estudante(string matricula, string nome) {
        this->nome = std::move(nome);
        this->matricula = std::move(matricula);
    }

    string estudante::getNome() const {
        return this->nome;
    }

    string estudante::getMatricula() const {
        return this->matricula;
    }
}