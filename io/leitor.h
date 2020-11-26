#ifndef SISTEMACPP_LEITOR_H
#define SISTEMACPP_LEITOR_H

#include "memoria.h"
#include <fstream>
#include "../utils/Tokenizer.h"
#include "../utils/StringUtils.h"
#include "exception.h"
using namespace utils;

using namespace std;
#include <iostream>

namespace io {
    class leitor {
        memoria* memoriaObj;

    public:
        explicit leitor(memoria* memoriaObj);
        void lerPeriodos(const string& filename);
        void lerDisciplinas(const string& filename);
        void lerDocentes(const string& filename);
        void lerEstudantes(const string& filename);
    };
}

#endif //SISTEMACPP_LEITOR_H
