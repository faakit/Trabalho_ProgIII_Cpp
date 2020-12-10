#ifndef SISTEMACPP_EXCEPTION_H
#define SISTEMACPP_EXCEPTION_H

#include <string>
using namespace std;

namespace io {
    //Para erros de I/O
    class ioException : public exception{
        string motivo="Erro de I/O.";
    public:
        ioException();
        const char * what() const noexcept override;
    };

    //Para erros de tipo de dado (Ex: letras onde são necessários números)
    class dadoException : public exception{
        string motivo="Dado inválido: ";
    public:
        explicit dadoException(string dado);
        const char * what() const noexcept override;
    };

    //Erro para cadastros/matrículas repetidas
    class repetidoException : public exception{
        string motivo="Cadastro repetido: ";
    public:
        explicit repetidoException(string dado);
        const char * what() const noexcept override;
    };


    //Erro de referência não encontrada (Ex: quando não encontra o login de um docente)
    class referenciaException : public exception{
        string motivo="Referência inválida: ";
    public:
        explicit referenciaException(string dado);
        const char * what() const noexcept override;
    };

    //Matricula repetida na matéria
    class matriculaException : public exception{
        string motivo="Matrícula repetida: ";
    public:
        explicit matriculaException(string dado, const string& codigo);
        const char * what() const noexcept override;
    };

    //Nota repetida para aluno em atividade
    class atividadeException : public exception{
        string motivo="Avaliação repetida: estudante ";
    public:
        atividadeException(const string& matricula, const string& nAtividade, const string& disciplina);
        const char * what() const noexcept override;
    };
}

#endif //SISTEMACPP_EXCEPTION_H
