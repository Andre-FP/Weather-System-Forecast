#ifndef CIDADES_H
#define CIDADES_H

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <map>
#include <iomanip>
#include <algorithm>
#include <iterator>
#include <numeric>

using namespace std;

class Cidade {
    public:
        Cidade(string);
        unsigned lerArquivo();
        unsigned dadosHistoricos(string, string, string);
        unsigned mapearMeses(string);
        double calcularMedia(int, vector <double>, long, int);
        void imprimirMedia(int, int, vector<double>, string);
        void findMonth(int);
        void maioresIndices(void);
        double valorMedio(vector<double> vetor);
        void compararAnos(string, string);
        void maioresIndicesCidade(string ano);
        vector <string> data;
        string getNomeArquivo();
        
        double mediaMaxTemp, mediaMinTemp, mediaRadiacaoSolar, mediaChuva, mediaVento;

    private:        
        vector <double> maxTemp, minTemp, radiacaoSolar, chuva, vento;


        string nomeArquivo;
        map <string, int> meses
        {
            { "Janeiro", 1 },
            { "Fevereiro", 2 },
            { "Marco", 3 },
            { "Abril", 4 },
            { "Maio", 5 },
            { "Junho", 6 },
            { "Julho", 7 },
            { "Agosto", 8 },
            { "Setembro", 9 },
            { "Outubro", 10 },
            { "Novembro", 11 },
            { "Dezembro", 12 }
        };

};

#endif