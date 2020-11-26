#include "docente.h"

using namespace std;

namespace dominio {

    docente::docente(string login, string nome, string website) {
        this->login = move(login);
        this->nome = move(nome);
        this->website = move(website);
    }

    void docente::addDisciplina(disciplina* i) {
        this->disciplinas.push_back(i);
    }

    string docente::getLogin() const {
        return this->login;
    }

    string docente::getNome() const {
        return this->nome;
    }

    string docente::getWebsite() const {
        return this->website;
    }

}