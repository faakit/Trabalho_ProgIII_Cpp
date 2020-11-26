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

    map<string, nota*> atividade::getNotas() const {
        return this->notas;
    }

    void atividade::addNota(const string& matricula, nota* notaDoAluno) {
        this->notas.emplace(matricula, notaDoAluno);
    }

    bool atividade::isSincrona() const {
        return this->sincrona;
    }

    string atividade::getData() {
        return "";
    }

    double atividade::getCargaHoraria() const {
        return this->cargaHoraria;
    }

}