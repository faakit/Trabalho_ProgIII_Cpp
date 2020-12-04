#include "estudante.h"

using namespace std;

namespace dominio {

    estudante::estudante(string matricula, string nome) {
        this->nome = std::move(nome);
        this->matricula = std::move(matricula);
        this->nAvaliacoes = 0;
        this->totalAvaliacoes = 0;
    }

    string estudante::getNome() const {
        return this->nome;
    }

    string estudante::getMatricula() const {
        return this->matricula;
    }

    void estudante::incrementaAvaliacoes(double nota) {
        this->totalAvaliacoes += nota;
        this->nAvaliacoes++;
    }

    int estudante::getNPeriodos() const {
        return this->periodos.size();
    }

    double estudante::getTotalAvaliacoes() const {
        return this->totalAvaliacoes;
    }

    int estudante::getNAvaliacoes() const {
        return this->nAvaliacoes;
    }

    list<disciplina *> estudante::getDisciplinas() const {
        return this->disciplinas;
    }

    void estudante::addDisciplina(disciplina *varDisciplina) {
        this->disciplinas.push_back(varDisciplina);
        this->periodos.emplace(varDisciplina->getPeriodo());
    }

    bool estudante::compareTo(estudante *o) {
        return (o->nAvaliacoes <  this->nAvaliacoes ||
                 ((o->nAvaliacoes == this->nAvaliacoes) && utils::stringCompare(this->nome, o->nome)));
    }
}