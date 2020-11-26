#ifndef SISTEMACPP_PROVA_H
#define SISTEMACPP_PROVA_H

#include "atividade.h"
#include "../utils/DateUtils.h"

namespace dominio {
    class prova: public atividade {
        time_t data;
        string conteudo;

    public:
        prova(int numero, string nome, time_t data, string conteudo);
        string getData() const;
        string getConteudo() const;
    };
}


#endif //SISTEMACPP_PROVA_H
