#include "prova.h"

namespace dominio{
    prova::prova(int numero, string nome, time_t data, string conteudo):
        atividade(numero, std::move(nome), true, 2){
        this->data = data;
        this->conteudo = std::move(conteudo);
    }

    string prova::getData() const{
        return utils::formatDate(this->data, utils::DATE_FORMAT_PT_BR_SHORT);
    }

    string prova::getConteudo() const{
        return this->conteudo;
    }
}