#ifndef SISTEMACPP_NOTA_H
#define SISTEMACPP_NOTA_H

#include "estudante.h"

namespace dominio {
    class estudante;
    class nota {
        estudante* aluno;
        double notaDoAluno;

    public:
        nota(estudante* aluno, double notaDoAluno);
        estudante* getAluno() const;
        double getNota() const;
    };
}

#endif //SISTEMACPP_NOTA_H
