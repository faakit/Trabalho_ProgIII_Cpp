#include "leitor.h"

namespace io{
    leitor::leitor(memoria *memoriaObj) {
        this->memoriaObj = memoriaObj;
    }

    void leitor::lerPeriodos(const string& filename) {

        //Tenta abrir o arquivo, caso não dê lança ioException
        ifstream in(filename, ifstream::in);
        if (! in.good()) {
            in.close();
            throw ioException();
        }
        string linha;

        //Pula a primeira linha do cabeçalho
        getline(in, linha);

        //Lê linha por linha em um vetor VEC com cada coluna, depois da um trim em cada string
        while (getline(in, linha)) {
            Tokenizer tok(linha, ';');
            vector<string> vec = tok.remaining();
            for (auto & i : vec) i = trim(i);

            if (! isNumber(vec[0])) throw dadoException(vec[0]);
            if (vec[1].size() > 2) throw dadoException(vec[0]);

            auto* novoPeriodo = new periodo(stoi(vec[0]), vec[1][0]);

            if(memoriaObj->getPeriodos().count(novoPeriodo->toString()) == 1 ) throw repetidoException(novoPeriodo->toString());

            memoriaObj->setPeriodo(novoPeriodo);

        }
        in.close();
    }

    void leitor::lerDisciplinas(const string& filename) {}

    void leitor::lerDocentes(const string& filename) {}

    void leitor::lerEstudantes(const string& filename) {}
}