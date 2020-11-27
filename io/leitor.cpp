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

            if(memoriaObj->existePeriodo(novoPeriodo->toString())) throw repetidoException(novoPeriodo->toString());

            memoriaObj->setPeriodo(novoPeriodo);
        }
        in.close();
    }

    void leitor::lerDisciplinas(const string& filename) {
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

            string strPeriodo = vec[0];
            string codigo = vec[1];
            string nome = vec[2];
            string strProfessor = vec[3];
            string delimitador = "/";
            string semestre = strPeriodo.substr(strPeriodo.find(delimitador)+1, strPeriodo.length());

            if(semestre.length()>1) throw dadoException(semestre);
            if(!memoriaObj->existePeriodo(strPeriodo)) throw referenciaException(strPeriodo);
            if(memoriaObj->existeDisciplina(codigo + "-" + strPeriodo)) throw repetidoException(codigo + "-" + strPeriodo);
            if(!memoriaObj->existeDocente(strProfessor)) throw referenciaException(strProfessor);

            periodo* refPeriodo = memoriaObj->getPeriodos().find(strPeriodo)->second;
            docente* refDocente = memoriaObj->getDocentes().find(strProfessor)->second;

            auto* novaDisciplina = new disciplina(codigo, nome, refDocente, refPeriodo);

            memoriaObj->setDisciplina(novaDisciplina);
        }
        in.close();
    }

    void leitor::lerDocentes(const string& filename) {
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

            auto* novoDocente = new docente(vec[0], vec[1], vec[2]);

            if(memoriaObj->getPeriodos().count(novoDocente->getLogin()) == 1 ) throw repetidoException(novoDocente->getLogin());

            memoriaObj->setDocente(novoDocente);
        }
        in.close();
    }

    void leitor::lerEstudantes(const string& filename) {
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

            string matricula = vec[0];
            string nome = vec[1];

            if (! isNumber(matricula)) throw dadoException(vec[0]);
            if (memoriaObj->existeEstudante(matricula)) throw matriculaException(matricula);

            auto* novoEstudante = new estudante(matricula, nome);

            memoriaObj->setEstudante(novoEstudante);
        }
        in.close();
    }


}