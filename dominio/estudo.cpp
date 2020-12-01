#include "estudo.h"

namespace dominio{
    estudo::estudo(int numero, string nome):
        atividade(numero, std::move(nome), false, 2){
    }

    void estudo::addMateriais(const string& nome, const string& url) {
        this->materiais.emplace(nome, url);
    }

    map<string, string> estudo::getMateriais() const{
        return this->materiais;
    }
}