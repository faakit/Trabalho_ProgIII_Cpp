#include "prova.h"

namespace dominio{
    prova::prova(int numero, string nome, time_t data, string conteudo):
        atividade(numero, std::move(nome), true, 2){
        this->data = data;
        this->conteudo = std::move(conteudo);
    }

    string prova::getData(const string& dateFormat){
        return utils::formatDate(this->data, dateFormat);
    }

    string prova::getConteudo() const{
        return this->conteudo;
    }
}