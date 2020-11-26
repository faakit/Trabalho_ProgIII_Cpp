#include <iostream>
#include <string>
#include <map>
#include "dominio/periodo.h"
#include "dominio/disciplina.h"
#include "io/memoria.h"

using namespace dominio;
using namespace std;
using namespace io;

int main() {
    auto* memoriaObj = new memoria();
    map<string,periodo> mapaPeriodos;
    map<string,disciplina> mapaDisciplinas;
    map<string,docente> mapaDocentes;
    map<string,estudante> mapaEstudantes;

    auto* novoPeriodo = new periodo(2000, '1');
    memoriaObj->setPeriodo(novoPeriodo);

    for(auto & mapaPeriodo : memoriaObj->getPeriodos()){
        cout << "chave: " << mapaPeriodo.first << endl;
        cout << "valor: " << mapaPeriodo.second.toString() << endl;
    }

    auto* novoDocente = new docente("vitor.souza", "vitor souza", "NA");
    mapaDocentes.emplace(novoDocente->getLogin(), *novoDocente);

    for(auto & mapaDocente : mapaDocentes){
        cout << "chave: " << mapaDocente.first << endl;
        cout << "valor: " << mapaDocente.second.getNome() << endl;
    }

    auto* novaDisciplina = new disciplina("PROG0800", "Programaria", novoDocente, novoPeriodo);
    mapaDisciplinas.emplace( novaDisciplina->toString(), *novaDisciplina );

    for(auto & mapaDisciplina : mapaDisciplinas){
        cout << "Disciplina: " << mapaDisciplina.second.toString() << endl;
        cout << "Periodo: " << mapaDisciplina.second.getPeriodo()->toString() << endl;
        cout << "Professor: " << mapaDisciplina.second.getProfessor()->getNome() << endl;
    }



}
