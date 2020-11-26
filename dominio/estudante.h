#ifndef SISTEMACPP_ESTUDANTE_H
#define SISTEMACPP_ESTUDANTE_H

#include <string>

using namespace std;

namespace dominio {
    class estudante {
        string matricula;
        string nome;

    public:
        estudante(string, string);

        string getMatricula() const;
        string getNome() const;
    };
}

#endif //SISTEMACPP_ESTUDANTE_H
