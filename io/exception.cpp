#include "exception.h"


namespace io{
    const char * ioException::what() const noexcept {
        return motivo.c_str();
    }

    ioException::ioException()=default;

    dadoException::dadoException(string dado) {
        this->motivo = motivo + move(dado) + ".";
    }

    const char *dadoException::what() const noexcept {
        return motivo.c_str();
    }


    repetidoException::repetidoException(string dado) {
        this->motivo = motivo + move(dado) + ".";
    }

    const char *repetidoException::what() const noexcept {
        return motivo.c_str();
    }


    referenciaException::referenciaException(string dado) {
        this->motivo = motivo + move(dado) + ".";
    }

    const char *referenciaException::what() const noexcept {
        return motivo.c_str();
    }


    matriculaException::matriculaException(string dado, const string& codigo) {
        this->motivo = motivo + move(dado) + "em" + codigo + ".";
    }

    const char *matriculaException::what() const noexcept {
        return motivo.c_str();
    }

    atividadeException::atividadeException(const string& matricula, const string& nAtividade, const string& disciplina) {
        this->motivo = motivo + matricula + " para atividade " + nAtividade + " de " + disciplina + ".";
    }

    const char *atividadeException::what() const noexcept {
        return motivo.c_str();
    }
}