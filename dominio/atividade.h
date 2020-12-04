#ifndef SISTEMACPP_ATIVIDADE_H
#define SISTEMACPP_ATIVIDADE_H

#include <map>
#include "nota.h"
#include <cstring>

using namespace std;

namespace dominio {
    class nota;
    class atividade {
        string nome;
        int numero;
        map<string, nota*> notas;
        bool sincrona;
        double cargaHoraria;

    public:
        atividade(int numero, string nome, bool sincrona, double cargaHoraria);
        string getNome() const;
        int getNumero() const;

        void addNota(const string& matricula, nota* notaDoAluno);
        bool isSincrona() const;
        virtual string getData(const string& dateFormat);
        double getCargaHoraria() const;
        bool existeNota(const string& matricula) const;
        bool compareTo(atividade* o);
    };
}

#endif //SISTEMACPP_ATIVIDADE_H
