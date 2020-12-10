#include "io/leitor.h"
#include "io/escritor.h"

using namespace dominio;
using namespace std;
using namespace io;

int main(int argc, char** argv) {
    try {
        //Pega o local do sistema operacional e inicia strings de argumentos
        setlocale(LC_ALL, "pt_BR");
        string csvPeriodos, csvDocentes, csvDisciplinas, csvEstudantes, csvMatriculas, csvAtividades, csvAvaliacoes;

        //Checa o nome dos arquivos e a existência das flags
        int achados=0;
        for(int i=0; i<argc;i++){
            if(string("-p") == argv[i] && argc > i+1 ) {
                achados++;
                csvPeriodos = argv[i + 1];
            }
            else if(string("-d") == argv[i] && argc > i+1 ) {
                achados++;
                csvDocentes = argv[i + 1];
            }
            else if(string("-o") == argv[i] && argc > i+1 ) {
                achados++;
                csvDisciplinas = argv[i + 1];
            }
            else if(string("-e") == argv[i] && argc > i+1 ) {
                achados++;
                csvEstudantes = argv[i + 1];
            }
            else if(string("-m") == argv[i] && argc > i+1 ) {
                achados++;
                csvMatriculas = argv[i + 1];
            }
            else if(string("-a") == argv[i] && argc > i+1 ) {
                achados++;
                csvAtividades = argv[i + 1];
            }
            else if(string("-n") == argv[i] && argc > i+1 ) {
                achados++;
                csvAvaliacoes = argv[i + 1];
            }
        }
        //Caso não encontre todos argumentos fecha com um IOException
        if(achados != 7) throw ioException();


        //Inicializa a memoria e lê os dados
        auto* memoriaObj = new memoria();
        auto* csvLeitor = new leitor(memoriaObj);
        csvLeitor->lerPeriodos(csvPeriodos);
        csvLeitor->lerDocentes(csvDocentes);
        csvLeitor->lerDisciplinas(csvDisciplinas);
        csvLeitor->lerEstudantes(csvEstudantes);
        csvLeitor->lerMatriculas(csvMatriculas);
        csvLeitor->lerAtividades(csvAtividades);
        csvLeitor->lerAvaliacoes(csvAvaliacoes);
        delete csvLeitor;


        //Escreve os relatórios
        auto* csvEscritor = new escritor(memoriaObj);
        csvEscritor->visaoGeralPeriodo();
        csvEscritor->estatisticaDocentes();
        csvEscritor->estatisticaEstudantes();
        csvEscritor->estatisticaDisciplinasDocente();
        delete csvEscritor;

    } catch (exception &e){
        //Imprime o erro e retorna
        cout << e.what() << endl;
    }

    return 0;
}
