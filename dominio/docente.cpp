#include "docente.h"

using namespace std;

namespace dominio {

    docente::docente(string login, string nome, string website) {
        this->login = move(login);
        this->nome = move(nome);
        this->website = move(website);
        this->nDisciplinas = 0;
        this->nAtividades = 0;
        this->nAtividadesSincronas = 0;
        this->nNotas = 0;
        this->totalNotas = 0;
    }

    void docente::addDisciplina(disciplina* i) {
        this->disciplinas.push_back(i);
        this->nDisciplinas++;
        this->periodos.emplace(i->getPeriodo());
    }

    void docente::addAtividade(atividade *i) {
        this->nAtividades++;
        if(i->isSincrona()) this->nAtividadesSincronas++;
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

    int docente::getNDisciplinas() const{
        return this->nDisciplinas;
    }

    double docente::getNAtividades() const{
        return this->nAtividades;
    }

    int docente::getNAtvSincronas() const {
        return this->nAtividadesSincronas;
    }

    set<periodo *> docente::getPeriodos() const {
        return this->periodos;
    }

    void docente::addNota(nota *i) {
        this->nNotas++;
        this->totalNotas += i->getNota();
    }

    int docente::getNNotas() const{
        return this->nNotas;
    }

    double docente::getTotalNotas() const{
        return this->totalNotas;
    }

}