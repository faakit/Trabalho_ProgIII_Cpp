#include <iostream>
#include <string>
#include "dominio/periodo.h"
#include "dominio/disciplina.h"
#include "io/memoria.h"
#include "io/leitor.h"
#include <clocale>

using namespace dominio;
using namespace std;
using namespace io;

int main() {
    setlocale(LC_ALL, "");
    auto* memoriaObj = new memoria();

    auto* csvLeitor = new leitor(memoriaObj);
    try {
        csvLeitor->lerPeriodos("periodos.csv");
        csvLeitor->lerDocentes("docentes.csv");
        csvLeitor->lerDisciplinas("disciplinas.csv");
        csvLeitor->lerEstudantes("estudantes.csv");
    } catch (dadoException &e){
        cout << e.what() << endl;
    }

    auto* novoPeriodo = new periodo(2000, '1');
    memoriaObj->setPeriodo(novoPeriodo);

    for(auto & mapaEstudante : memoriaObj->getEstudantes()){
        cout << "chave: " << mapaEstudante.first << endl;
        cout << "valor: " << mapaEstudante.second->getNome() << endl;
    }

    for(auto & mapaDisciplina : memoriaObj->getDisciplinas()){
        cout << "chave: " << mapaDisciplina.first << endl;
        cout << "valor: " << mapaDisciplina.second->toString() << endl;
    }



}
