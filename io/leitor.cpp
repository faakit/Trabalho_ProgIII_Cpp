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
            if (memoriaObj->existeEstudante(matricula)) throw repetidoException(matricula);

            auto* novoEstudante = new estudante(matricula, nome);

            memoriaObj->setEstudante(novoEstudante);
        }
        in.close();
    }

    void leitor::lerMatriculas(const string &filename) {
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

            string codigo = vec[0];
            string matricula = vec[1];

            if(!isNumber(matricula)) throw dadoException(matricula);
            if(!memoriaObj->existeEstudante(matricula)) throw referenciaException(matricula);
            if(!memoriaObj->existeDisciplina(codigo)) throw referenciaException(codigo);
            if(memoriaObj->getDisciplinas().find(codigo)->second->getAlunos().count(matricula) > 0) throw matriculaException(matricula, codigo);

            memoriaObj->getDisciplinas().find(codigo)->second->addAluno(matricula, memoriaObj->getEstudantes().find(matricula)->second);
            memoriaObj->getEstudantes().find(matricula)->second->addDisciplina(memoriaObj->getDisciplinas().find(codigo)->second);
        }
        in.close();
    }

    void leitor::lerAtividades(const string &filename) {
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
            vector<string> linhas = tok.remaining();
            for (auto & i : linhas) i = trim(i);

            string codigo = linhas[0];
            string nome = linhas[1];

            if(!memoriaObj->existeDisciplina(codigo)) throw referenciaException(codigo);

            //Verifica tipo de atividade
            string tipo = linhas[2];

            if (tipo == "A" || tipo == "a"){
                string dataStr = linhas[3];

                if(!validDate(dataStr, DATE_FORMAT_PT_BR_SHORT)) throw dadoException(dataStr);

                time_t data = parseDate(dataStr, DATE_FORMAT_PT_BR_SHORT);

                atividade* novaAtividade = new aula(memoriaObj->getDisciplinas().find(codigo)->second->getNAtividades(),
                                                  nome,
                                                  data);
                memoriaObj->getDisciplinas().find(codigo)->second->addAtividade(novaAtividade);
            }

            else if(tipo == "T" || tipo == "t"){
                string dataStr = linhas[3];

                if(!validDate(dataStr, DATE_FORMAT_PT_BR_SHORT)) throw dadoException(dataStr);

                time_t data = parseDate(dataStr, DATE_FORMAT_PT_BR_SHORT);

                string strNAlunos = linhas[6];
                if(!isNumber(strNAlunos)) throw dadoException(strNAlunos);
                string strCargaHoraria = linhas[7];
                if(!isNumber(strCargaHoraria)) throw dadoException(strCargaHoraria);

                atividade* novaAtividade = new trabalho(memoriaObj->getDisciplinas().find(codigo)->second->getNAtividades(),
                                                        nome,
                                                        data,
                                                        stoi(linhas[6]),
                                                        stod(linhas[7]));
                memoriaObj->getDisciplinas().find(codigo)->second->addAtividade(novaAtividade);
            }

            else if(tipo == "P" || tipo == "p"){
                string dataStr = linhas[3];

                if(!validDate(dataStr, DATE_FORMAT_PT_BR_SHORT)) throw dadoException(dataStr);

                time_t data = parseDate(dataStr, DATE_FORMAT_PT_BR_SHORT);

                string conteudo = linhas[5];

                atividade* novaAtividade = new prova(memoriaObj->getDisciplinas().find(codigo)->second->getNAtividades(),
                                                     nome,
                                                     data,
                                                     conteudo);
                memoriaObj->getDisciplinas().find(codigo)->second->addAtividade(novaAtividade);
            }

            else if(tipo == "E" || tipo == "e"){
                auto* novoEstudo = new estudo(memoriaObj->getDisciplinas().find(codigo)->second->getNAtividades(),
                                              nome);

                string materiais = linhas[5];

                Tokenizer tokenNome(materiais, '[');
                vector<string> materialNome = tokenNome.remaining();

                Tokenizer tokenUrl(materiais, '(');
                vector<string> materialUrl = tokenUrl.remaining();

                for(auto & mNome : materialNome){
                    mNome = mNome.substr(0, mNome.find(']'));
                }

                for(int i=1; i<materialUrl.size() ; i++){
                    materialUrl[i] = materialUrl[i].substr(0, materialUrl[i].find(')'));
                }

                for(int i = 1 ; i<materialNome.size() ; i++){
                    novoEstudo->addMateriais(materialNome[i], materialUrl[i]);
                }

                memoriaObj->getDisciplinas().find(codigo)->second->addAtividade(novoEstudo);
            }
            else throw dadoException(tipo);

        }
        in.close();
    }

    void leitor::lerAvaliacoes(const string &filename) {
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

            string codigo = vec[0];
            string matricula = vec[1];
            string nAtividade = vec[2];
            string notaStr = vec[3];

            if (!memoriaObj->existeDisciplina(codigo)) throw referenciaException(codigo);
            if (!memoriaObj->existeEstudante(matricula)) throw referenciaException(matricula);
            if (!memoriaObj->getDisciplinas().find(codigo)->second->existeAtividade(stoi(nAtividade)) )
                throw referenciaException(nAtividade);
            if (memoriaObj->getDisciplinas().find(codigo)->second->
                getAtividade(stoi(nAtividade))->existeNota(matricula))
                throw atividadeException(matricula, nAtividade, codigo);

            auto* novaNota = new nota(memoriaObj->getEstudantes().find(matricula)->second, stod(notaStr));
            memoriaObj->getDisciplinas().find(codigo)->second->
                getAtividade(stoi(nAtividade))->addNota(matricula, novaNota);

        }
        in.close();
    }
}