//
// Created by André on 25/11/2020.
//

#ifndef SISTEMACPP_TRABALHO_H
#define SISTEMACPP_TRABALHO_H

#include "atividade.h"
#include "../utils/DateUtils.h"

namespace dominio{
    class trabalho: public atividade{
        time_t data;
        int nAlunos;

    public:
        trabalho(int numero, string nome, time_t data, int nAlunos, double cargaHoraria);
        int getNAlunos() const;
        string getData() const;
    };
}

#endif //SISTEMACPP_TRABALHO_H
