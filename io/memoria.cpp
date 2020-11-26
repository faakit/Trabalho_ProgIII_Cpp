#include "memoria.h"

namespace io{

    memoria::memoria()=default;

    map<string,periodo> memoria::getPeriodos() const {
        return this->mapaPeriodos;
    }

    map<string,disciplina> memoria::getDisciplinas() const {
        return this->mapaDisciplinas;
    }

    map<string,docente> memoria::getDocentes() const {
        return this->mapaDocentes;
    }

    map<string,estudante> memoria::getEstudantes() const {
        return this->mapaEstudantes;
    }

    void memoria::setPeriodo(periodo *periodo) {
        this->mapaPeriodos.emplace(periodo->toString(), *periodo);
    }

    void memoria::setDisciplina(disciplina *disciplina) {
        this->mapaDisciplinas.emplace(disciplina->toString(), *disciplina);
    }

    void memoria::setDocente(class docente *docente) {
        this->mapaDocentes.emplace(docente->getLogin(), *docente);
    }

    void memoria::setEstudante(class estudante *estudante) {
        this->mapaEstudantes.emplace(estudante->getMatricula(), *estudante);
    }

}