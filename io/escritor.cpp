#include "escritor.h"

namespace io{
    //Função facilitadora para printar as linhas do arquivo
    void escritor::printLine(ofstream& out, string * linhas) {
        for(int i = 0 ; i<linhas->size()+1; i++){
            out << linhas[i];
            if(i != linhas->size() ) out << separadorCSV;
        }
        out << endl;
    }

    escritor::escritor(memoria *memoriaObj) {
        this->memoriaObj = memoriaObj;
    }

    void escritor::visaoGeralPeriodo() {
        //Cria o arquivo e seu cabeçalho
        ofstream out("1-visao-geral.csv");
        if (! out.good()) {
            out.close();
            throw ioException();
        }
        out << cabecalhoVisaoGeral << endl;

        //Cria lista de periodos e ordena
        vector<periodo*> listaOrdenada;
        for(auto & periodo : memoriaObj->getPeriodos()){
            listaOrdenada.push_back(periodo.second);
        }

        sort(begin(listaOrdenada), end(listaOrdenada),
             [](periodo* a, periodo* b){return  a->compareTo(b);});

        for(auto & periodo : listaOrdenada){
            //Cria lista com disciplinas do período
            vector<disciplina*> disciplinasOrdenada = periodo->getDisciplinas();

            //Organiza as disciplinas com uma função lambda de acordo com seu nome
            sort(begin(disciplinasOrdenada), end(disciplinasOrdenada),
                 [](disciplina* a, disciplina* b){return utils::stringCompare(a->getNome(), b->getNome());});

            for(auto & i : disciplinasOrdenada){
                //inicia um array de strings que serão as colunas da linha
                string linhas[7];

                linhas[0] = periodo->toString();
                linhas[1] = i->getCodigo();
                linhas[2] = i->getNome();
                linhas[3] = i->getProfessor()->getNome();
                linhas[4] = i->getProfessor()->getLogin() + "@ufes.br";
                linhas[5] = to_string(i->getAlunos().size());
                linhas[6] = to_string(i->getNAtividades());

                //printa a linha
                printLine(out, linhas);
            }

        }

        //fecha o arquivo
        out.close();
    }

    void escritor::estatisticaDocentes() {
        //Cria o arquivo e seu cabeçalho
        ofstream out("2-docentes.csv");
        if (! out.good()) {
            out.close();
            throw ioException();
        }
        out << cabecalhoEstDocentes << endl;

        //cria lista de docentes e organiza em ordem decrescente de nome com função lambda
        vector<docente*> listaOrdenada;
        for(auto & i : memoriaObj->getDocentes()){
            listaOrdenada.push_back(i.second);
        }
        sort(begin(listaOrdenada), end(listaOrdenada),
             [](docente* a, docente* b){return stringCompare(b->getNome(), a->getNome());});

        for(auto & i : listaOrdenada){
            //Inicializa alguns valores, o array de linhas e um buffer para formatação de string
            double mediaAtivXDisciplina=0;
            if(i->getNDisciplinas() != 0) {
                mediaAtivXDisciplina = (double)i->getNAtividades()/i->getNDisciplinas();
            }
            double percentualSincXAssinc = 0;
            if(i->getNAtividades() != 0) {
                percentualSincXAssinc = (double)i->getNAtvSincronas()/i->getNAtividades() * 100;
            }
            double mediaNotas=0;
            if(i->getNNotas() != 0){
                mediaNotas = i->getTotalNotas()/i->getNNotas();
            }

            string linhas[7];
            char buffer[10];

            linhas[0] = i->getNome();
            linhas[1] = to_string(i->getNDisciplinas());
            linhas[2] = to_string(i->getPeriodos().size());
            sprintf(buffer, "%.1f", mediaAtivXDisciplina);
            linhas[3] = buffer;
            sprintf(buffer, "%.0f%%", percentualSincXAssinc);
            linhas[4] = buffer;
            if(i->getNAtividades() == 0) linhas[5] = "0%";
            else {
                sprintf(buffer, "%.0f%%", (100 - percentualSincXAssinc));
                linhas[5] = buffer;
            }
            sprintf(buffer, "%.1f" , round(mediaNotas * 10.)/10.);
            linhas[6] = buffer;

            //Escreve a linha       !!! printLine não está funcionando aqui, por algum motivo a linha não
            //                      !!! é passada após a primeira disciplina (SIGSEGV SEGMENTATION FAULT)
            for(int coluna = 0 ; coluna<7; coluna++){
                out << linhas[coluna];
                if(coluna != 6 ) out << separadorCSV;
            }
            out << endl;
        }

        //fecha o arquivo
        out.close();
    }

    void escritor::estatisticaEstudantes() {
        //Cria o arquivo e seu cabeçalho
        ofstream out("3-estudantes.csv");
        if (! out.good()) {
            out.close();
            throw ioException();
        }
        out << cabecalhoEstEst << endl;

        //Cria lista de estudantes e ordena
        vector<estudante*> listaOrdenada;
        for(auto& i : memoriaObj->getEstudantes()){
            listaOrdenada.push_back(i.second);
        }

        sort(begin(listaOrdenada), end(listaOrdenada),
             [](estudante* a, estudante* b) { return a->compareTo(b); });

        for(auto & i : listaOrdenada){
            //Inicializa o array de linhas e o buffer para formatação de string
            string linhas[5];
            char buffer[10];

            linhas[0] = i->getMatricula();
            linhas[1] = i->getNome();
            if ( i->getNPeriodos() == 0 ) linhas[2] = "0,0";
            else{
                sprintf(buffer, "%.1f", (double)i->getDisciplinas().size()/i->getNPeriodos());
                linhas[2] = buffer;
            }
            if (i->getDisciplinas().empty()) linhas[3] = "0,0";
            else{
                sprintf(buffer, "%.1f", round((double)i->getNAvaliacoes()/i->getDisciplinas().size() * 10.)/10.  );
                linhas[3] = buffer;
            }
            if(i->getNAvaliacoes() ==0) linhas[4] = "0,0";
            else{
                sprintf(buffer, "%.1f", (double)i->getTotalAvaliacoes()/i->getNAvaliacoes());
                linhas[4] = buffer;
            }

            //Escreve a linha       !!! printLine não está funcionando aqui, por algum motivo a linha não
            //                      !!! é passada após a primeira disciplina (SIGSEGV SEGMENTATION FAULT)
            for(int coluna = 0 ; coluna < 5; coluna++){
                out << linhas[coluna];
                if(coluna != 4 ) out << separadorCSV;
            }
            out << endl;
        }
    }

    void escritor::estatisticaDisciplinasDocente() {
        //Cria o arquivo e seu cabeçalho
        ofstream out("4-disciplinas.csv");
        if (! out.good()) {
            out.close();
            throw ioException();
        }
        out << cabecalhoEstDisDoc << endl;

        //Cria a lista e organiza com função lambda que chama função de comparação do objeto
        vector<disciplina*> listaOrdenada;
        for(auto & disciplina : memoriaObj->getDisciplinas()){
            listaOrdenada.push_back(disciplina.second);
        }

        sort(begin(listaOrdenada), end(listaOrdenada),
             [](disciplina* a, disciplina* b){return a->compareTo(b);});

        for(auto & i : listaOrdenada){
            //Cria e ordena lista de atividades
            vector<atividade*> listaAtividades;
            for(auto & j : i->getAtividades()){
                listaAtividades.push_back(j.second);
            }

            sort(begin(listaAtividades), end(listaAtividades),
                 [](atividade* a, atividade* b) { return a->compareTo(b); });

            double porcentagemSincXAsinc=0;
            if(i->getNAtividades() != 0) {
                porcentagemSincXAsinc = 100 * (double) i->getNAtvSincronas() / i->getNAtividades();
            }

            //inicia um buffer para formatar strings e um array de strings que serão as colunas da linha
            char buffer[20];
            string linhas[9];

            linhas[0] = i->getProfessor()->getLogin();
            linhas[1] = i->getPeriodo()->toString();
            linhas[2] = i->getCodigo();
            linhas[3] = i->getNome();
            linhas[4] = to_string(i->getNAtividades());
            sprintf(buffer, "%.0f%%", porcentagemSincXAsinc);
                linhas[5] = buffer;
            sprintf(buffer, "%.0f%%", (100 - porcentagemSincXAsinc));
            if (porcentagemSincXAsinc == 0) sprintf(buffer, "0%%");
                linhas[6] = buffer;
            sprintf(buffer, "%.0f", i->getCargaHoraria());
            linhas[7] = buffer;
            linhas[8] = "";
            for(auto & j : listaAtividades){
                linhas[8]+= j->getData(utils::DATE_FORMAT_PT_BR_SHORT) + " ";
            }
            trim(linhas[8]);

            //Escreve a linha       !!! printLine não está funcionando aqui, por algum motivo a linha não
            //                      !!! é passada após a primeira disciplina (SIGSEGV SEGMENTATION FAULT)
            for(int coluna = 0 ; coluna < 9; coluna++){
                out << linhas[coluna];
                if(coluna != 8 ) out << separadorCSV;
            }
            out << endl;
        }

        //fecha o arquivo
        out.close();
    }


}