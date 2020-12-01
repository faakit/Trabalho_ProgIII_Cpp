#include "escritor.h"


namespace io{

    escritor::escritor(memoria *memoriaObj) {
        this->memoriaObj = memoriaObj;
    }

    void escritor::visaoGeralPeriodo() {

    }

    void escritor::estatisticaDocentes() {

    }

    void escritor::estatisticaEstudantes() {

    }

    void escritor::estatisticaDisciplinasDocente() {
        //Cria o arquivo e seu cabeçalho
        ofstream out("4-disciplinas.csv");
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

            double porcentagemSincXAsinc = 100* (double)i->getNAtvSincronas()/i->getNAtividades();

            string linhas[9];
            char buffer[20];

            linhas[0] = i->getProfessor()->getLogin();
            linhas[1] = i->getPeriodo()->toString();
            linhas[2] = i->getCodigo();
            linhas[3] = i->getNome();
            linhas[4] = to_string(i->getNAtividades());
            if(i->getNAtividades() == 0) linhas[5] = "0%";
            else {sprintf(buffer, "%.0f%%", porcentagemSincXAsinc);
                linhas[5] = buffer; }
            if(i->getNAtividades() == 0) linhas[6] = "0%";
            else {sprintf(buffer, "%.0f%%", 100 - porcentagemSincXAsinc);
                linhas[6] = buffer; }
            sprintf(buffer, "%.0f", i->getCargaHoraria());
            linhas[7] = buffer;
            linhas[8] = "";
            for(auto & j : listaAtividades){
                linhas[8]+= j->getData(utils::DATE_FORMAT_PT_BR_SHORT) + " ";
            }
            trim(linhas[8]);

            //Escreve a linha inteira e pula linha ao final
            out << linhas[0] << separadorCSV << linhas[1] << separadorCSV << linhas[2] << separadorCSV <<linhas[3]<<
                separadorCSV << linhas[4] << separadorCSV << linhas[5]<< separadorCSV <<linhas[6]<< separadorCSV <<
                linhas[7] << separadorCSV << linhas[8] << endl;
        }

        out.close();
    }
}