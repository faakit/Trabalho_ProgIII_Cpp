#include "exception.h"

namespace io{
    dataException::dataException(string motivo) {
        this->motivo = move(motivo);
    }

    const char * dataException::what() const noexcept {
        return motivo.c_str();
    }

    const char * ioException::what() const noexcept {
        return motivo.c_str();
    }

    ioException::ioException()=default;
}