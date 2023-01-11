// #ifndef GLOBAL_H
// #define GLOBAL_H
#include "cidade.h"

using namespace std;

class Global
{
    public:
        Global(vector <Cidade>);
        unsigned lerTodosArquivos();
        void mostrarMaioresIndices();
        void getMaiorValor(vector <double>, string, string);
        void getMenorValor(vector <double>, string, string);
        void mostrarDadosHistoricos(string, string, string, string);
        void compararAnos(string, string, string);
        void maioresIndices(string, string);
        vector <Cidade> getCidades();
        vector <string> getNomesCidades();
    private:
        vector <Cidade> cidades;
        vector <string> nomesCidades = {"Rio de Janeiro", "Sao Paulo", "Porto Alegre", "Florianopolis", "Rio Branco", "Manaus", "Recife", "Natal", "Cuiaba", "Brasilia"};
        vector <double> maxTemp;
        vector <double> minTemp;
        vector <double> radiacaoSolar;
        vector <double> chuva;
        vector <double> vento;
};

// #endif