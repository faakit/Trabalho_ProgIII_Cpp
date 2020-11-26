#include "leitor.h"

namespace io{
    leitor::leitor(memoria *memoriaObj) {
        this->memoriaObj = memoriaObj;
    }

    void leitor::lerPeriodos(const string& filename) {
        ifstream in(filename);
        if (! in.good()) {
            in.close();
            throw ioException();
        }
        string linha;
        getline(in, linha);
        while (getline(in, linha)) {
            Tokenizer tok(linha, ';');
            vector<string> vec = tok.remaining();
            for (int i = 0; i < vec.size(); i++) {
                vec[i] = trim(vec[i]);
                cout << vec[i];
            }

        }
        in.close();
    }

    void leitor::lerDisciplinas(const string& filename) {}

    void leitor::lerDocentes(const string& filename) {}

    void leitor::lerEstudantes(const string& filename) {}
}