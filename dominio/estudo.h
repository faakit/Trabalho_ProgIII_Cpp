#ifndef SISTEMACPP_ESTUDO_H
#define SISTEMACPP_ESTUDO_H

#include "atividade.h"
#include <map>

namespace dominio {
    class estudo: public atividade {
        map<string, string> materiais;

    public:
        estudo(int numero, string nome, const map<string, string>& materiais);
        map<string, string> getMateriais() const;
        void addMateriais(const string& nome, const string& url);
    };
}

#endif //SISTEMACPP_ESTUDO_H
