#ifndef SISTEMACPP_ATIVIDADE_H
#define SISTEMACPP_ATIVIDADE_H

#include <string>
#include <map>
#include "nota.h"

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
        map<string, nota*> getNotas() const;
        void addNota(const string& matricula, nota* notaDoAluno);
        bool isSincrona() const;
        static string getData();
        double getCargaHoraria() const;
    };
}

#endif //SISTEMACPP_ATIVIDADE_H
