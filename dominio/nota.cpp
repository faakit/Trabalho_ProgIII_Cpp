#include "nota.h"

namespace dominio{
    nota::nota(estudante *aluno, double notaDoAluno) {
        this->aluno = aluno;
        this->notaDoAluno = notaDoAluno;
    }

    estudante* nota::getAluno() const{
        return this->aluno;
    }

    double nota::getNota() const {
        return this->notaDoAluno;
    }
}
