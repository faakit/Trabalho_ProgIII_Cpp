#ifndef SISTEMACPP_MEMORIA_H
#define SISTEMACPP_MEMORIA_H

#include <map>
#include <string>
#include "../dominio/disciplina.h"

using namespace std;
using namespace dominio;

namespace io {
    class memoria {
        map<string,periodo> mapaPeriodos;
        map<string,disciplina> mapaDisciplinas;
        map<string,docente> mapaDocentes;
        map<string,estudante> mapaEstudantes;

    public:
        memoria();
        map<string,periodo> getPeriodos() const;
        map<string,disciplina> getDisciplinas() const;
        map<string,docente> getDocentes() const;
        map<string,estudante> getEstudantes() const;
        void setPeriodo(periodo* periodo);
        void setDisciplina(disciplina* disciplina);
        void setDocente(class docente* docente);
        void setEstudante(class estudante* estudante);
    };
}

#endif //SISTEMACPP_MEMORIA_H
