#include "aula.h"

namespace dominio{

    aula::aula(int numero, string nome, time_t data):
        atividade(numero, std::move(nome), true, 2){
        this->data = data;
    }

    string aula::getData(const string& dateFormat) {
        return "";
    }
}