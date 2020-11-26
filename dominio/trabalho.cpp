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

    string trabalho::getData() const {
        return utils::formatDate(this->data, utils::DATE_FORMAT_PT_BR_SHORT);
    }
}