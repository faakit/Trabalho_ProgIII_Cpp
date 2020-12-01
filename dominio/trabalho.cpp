#include "trabalho.h"

namespace dominio{
    trabalho::trabalho(int numero, string nome, time_t data, int nAlunos, double cargaHoraria):
        atividade(numero, std::move(nome), false, cargaHoraria){
        this->data = data;
        this->nAlunos = nAlunos;
    }

    int trabalho::getNAlunos() const {
        return this->nAlunos;
    }

    string trabalho::getData(const string& dateFormat) {
        return utils::formatDate(this->data, dateFormat);
    }
}