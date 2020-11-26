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
}

#endif //SISTEMACPP_EXCEPTION_H
