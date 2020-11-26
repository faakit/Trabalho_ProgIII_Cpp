#ifndef SISTEMACPP_EXCEPTION_H
#define SISTEMACPP_EXCEPTION_H

#include <string>
using namespace std;

namespace io {
    class dataException : public exception {
        string motivo;

    public:
        explicit dataException(string motivo);
        const char * what() const noexcept override;
    };

    class ioException : public exception{
        string motivo="Erro de I/O.";
    public:
        ioException();
        const char * what() const noexcept override;
    };

    class dadoException : public exception{
        string motivo="Dado inválido: ";
    public:
        explicit dadoException(string dado);
        const char * what() const noexcept override;
    };

    class repetidoException : public exception{
        string motivo="Cadastro repetido: ";
    public:
        explicit repetidoException(string dado);
        const char * what() const noexcept override;
    };

    class referenciaException : public exception{
        string motivo="Referência inválida: ";
    public:
        explicit referenciaException(string dado);
        const char * what() const noexcept override;
    };

    class matriculaException : public exception{
        string motivo="Matrícula repetida: ";
    public:
        explicit matriculaException(string dado);
        const char * what() const noexcept override;
    };

    class atividadeException : public exception{
        string motivo="Avaliação repetida: estudante ";
    public:
        atividadeException(const string& matricula, const string& nAtividade, const string& disciplina);
        const char * what() const noexcept override;
    };
}

#endif //SISTEMACPP_EXCEPTION_H
