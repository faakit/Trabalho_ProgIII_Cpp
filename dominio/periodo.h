#ifndef SISTEMACPP_PERIODO_H
#define SISTEMACPP_PERIODO_H

#include <string>
#include <vector>
#include "disciplina.h"

using namespace std;

namespace dominio {
    class disciplina;
    class periodo {
        int ano;
        char semestre;
        vector<disciplina*> disciplinas;

    public:
        periodo(int, char);

        int getAno() const;

        char getSemestre() const;

        void addDisciplina(disciplina* i);
        vector<disciplina*> getDisciplinas() const;

        bool compareTo(periodo* o);

        std::string toString() const;

        ~periodo();
    };

} //fim do namespace
#endif //SISTEMACPP_PERIODO_H
