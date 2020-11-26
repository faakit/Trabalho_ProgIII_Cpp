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
    } catch (dadoException e){
        cout << e.what() << endl;
    }

    auto* novoPeriodo = new periodo(2000, '1');
    memoriaObj->setPeriodo(novoPeriodo);

    for(auto & mapaPeriodo : memoriaObj->getPeriodos()){
        cout << "chave: " << mapaPeriodo.first << endl;
        cout << "valor: " << mapaPeriodo.second.toString() << endl;
    }



}
