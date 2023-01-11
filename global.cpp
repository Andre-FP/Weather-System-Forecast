#include "global.h"
#define OK 0;
using namespace std;

Global::Global(vector <Cidade> vetorCidades)
{
    cidades = vetorCidades;
}

unsigned Global::lerTodosArquivos()
{
    for (unsigned i = 0; i < cidades.size(); i++)
    {
        cidades[i].lerArquivo();
    }
    return OK;
}
void Global::mostrarMaioresIndices()
{
    string empty;

    for (unsigned i = 0; i < cidades.size(); i++)
    {
        cidades[i].maioresIndices();
    }

    for (unsigned i = 0; i < cidades.size(); i++)
    {
        maxTemp.push_back(cidades[i].mediaMaxTemp);
        minTemp.push_back(cidades[i].mediaMinTemp);
        chuva.push_back(cidades[i].mediaChuva);
        radiacaoSolar.push_back(cidades[i].mediaRadiacaoSolar);
        vento.push_back(cidades[i].mediaVento);
    }
    getMaiorValor(maxTemp, "Temperatura maxima: ", " ºC");
    getMenorValor(minTemp, "Temperatura minima: ", " ºC");
    getMaiorValor(radiacaoSolar, "Radiação solar: ", " MJ/m^2");
    getMaiorValor(chuva, "Volume de chuva: ", " mm");
    getMaiorValor(vento, "Velocidade do vento: ", " km/h");
    
    // Press enter to continue
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, empty);

}   

void Global::getMaiorValor(vector <double> vetor, string titulo, string unidade)
{
    int index = max_element(vetor.begin(),vetor.end()) - vetor.begin();
    double max = *max_element(vetor.begin(), vetor.end());

    cout << titulo << "\t" << nomesCidades[index] << ", " << max << unidade << endl;;
}

void Global::getMenorValor(vector <double> vetor, string titulo, string unidade)
{
    int index = min_element(vetor.begin(),vetor.end()) - vetor.begin();
    double min = *min_element(vetor.begin(), vetor.end());

    cout << titulo << "\t" << nomesCidades[index] << ", " << min << unidade << endl;;
}

void Global::mostrarDadosHistoricos(string cidade, string mesInicio, string mesFim, string ano)
{
    for (unsigned i = 0; i < cidades.size(); i++)
    {
        if (nomesCidades[i] == cidade)
            cidades[i].dadosHistoricos(mesInicio, mesFim, ano);
    }
}

void Global::compararAnos(string cidade, string primAno, string segAno)
{
    for (unsigned i = 0; i < cidades.size(); i++)
    {
        if (nomesCidades[i] == cidade)
            cidades[i].compararAnos(primAno, segAno);
    }
}

void Global::maioresIndices(string cidade, string ano)
{
    for (unsigned i = 0; i < cidades.size(); i++)
    {
        if (nomesCidades[i] == cidade)
            cidades[i].maioresIndicesCidade(ano);
    }
}

vector <Cidade> Global::getCidades(){
    return cidades;
}

vector <string> Global::getNomesCidades(){
    return nomesCidades;
}

