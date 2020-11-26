#ifndef SISTEMACPP_PERIODO_H
#define SISTEMACPP_PERIODO_H

#include <string>

namespace dominio {

    class periodo {
        int ano;
        char semestre;

    public:
        periodo(int, char);

        int getAno() const;

        char getSemestre() const;

        std::string toString() const;

        ~periodo();
    };

} //fim do namespace
#endif //SISTEMACPP_PERIODO_H
