#include "atividade.h"

namespace dominio{
    atividade::atividade(int numero, string nome, bool sincrona, double cargaHoraria) {
        this->numero = numero;
        this->nome = move(nome);
        this->sincrona = sincrona;
        this->cargaHoraria = cargaHoraria;
    }

    string atividade::getNome() const {
        return this->nome;
    }

    int atividade::getNumero() const {
        return this->numero;
    }

    void atividade::addNota(const string& matricula, nota* notaDoAluno) {
        this->notas.emplace(matricula, notaDoAluno);
        this->notas.find(matricula)->second->getAluno()->incrementaAvaliacoes(notaDoAluno->getNota());
    }

    bool atividade::isSincrona() const {
        return this->sincrona;
    }

    string atividade::getData(const string& dateFormat) {
        return "";
    }

    double atividade::getCargaHoraria() const {
        return this->cargaHoraria;
    }

    bool atividade::existeNota(const string& matricula) const {
        if(notas.count(matricula) > 0) return true;
        else return false;
    }

    bool atividade::compareTo(atividade *o) {
        return (this->getData(utils::DATE_FORMAT_STRCMP) < o->getData(utils::DATE_FORMAT_STRCMP) ||
                (this->getData(utils::DATE_FORMAT_STRCMP) < o->getData(utils::DATE_FORMAT_STRCMP)) && (this->nome < o->nome));
    }

}