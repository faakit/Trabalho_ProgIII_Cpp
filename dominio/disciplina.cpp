#include "disciplina.h"

using namespace std;

namespace dominio {

    disciplina::disciplina(string codigo, string nome, docente* professor, periodo* varPeriodo) {
        this->nome = std::move(nome);
        this->codigo = std::move(codigo);
        this->professor = professor;
        this->varPeriodo = varPeriodo;
        professor->addDisciplina(this);
        varPeriodo->addDisciplina(this);
        this->cargaHoraria=0;
        this->nAtvSincronas=0;
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

    void disciplina::addAluno(const string& matricula, estudante *estudante) {
        this->alunos.emplace(matricula, estudante);
    }

    void disciplina::addAtividade(atividade* varAtividade) {
        this->atividades.emplace(varAtividade->getNumero()+1, varAtividade);
        if(varAtividade->isSincrona()) this->nAtvSincronas++;
        this->cargaHoraria += varAtividade->getCargaHoraria();
    }

    map<string, estudante *> disciplina::getAlunos() {
        return this->alunos;
    }

    int disciplina::getNAtividades() const {
        return this->atividades.size();
    }

    atividade* disciplina::getAtividade(int nAtividade) {
        return this->atividades.find(nAtividade)->second;
    }

    bool disciplina::existeAtividade(int nAtividade) const{
        if(this->atividades.count(nAtividade) > 0) return true;
        else return false;
    }

    bool disciplina::compareTo(disciplina *o) {
        return (this->varPeriodo->toString() < o->varPeriodo->toString() ||
                (this->varPeriodo->toString() < o->varPeriodo->toString()) && (this->codigo < o->codigo));
    }

    map<int, atividade *> disciplina::getAtividades() {
        return this->atividades;
    }

    int disciplina::getNAtvSincronas() const{
        return this->nAtvSincronas;
    }

    string disciplina::getCodigo() const {
        return this->codigo;
    }

    string disciplina::getNome() const {
        return this->nome;
    }

    double disciplina::getCargaHoraria() const {
        return this->cargaHoraria;
    }


}