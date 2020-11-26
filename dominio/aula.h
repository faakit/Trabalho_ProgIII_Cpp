#ifndef SISTEMACPP_AULA_H
#define SISTEMACPP_AULA_H

#include "atividade.h"
#include "../utils/DateUtils.h"

namespace dominio {
    class aula: public atividade {
        time_t data;

    public:
        aula(int numero, string nome, time_t data);
        string getData() const;
    };
}

#endif //SISTEMACPP_AULA_H
