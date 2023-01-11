#include "cidade.h"
#define OK 0
#define erro_arquivo 1
using namespace std;

Cidade::Cidade(string arquivo)
{
    nomeArquivo = arquivo;
}

unsigned Cidade::lerArquivo()
{
    vector<vector<string>> content;
    vector<string> row;
    string line, word;
    
    ifstream file;
    file.open (nomeArquivo);

	if (!file.is_open()) //checando se foi possivel abrir o arquivo
	{
		cout << "nao foi possivel abrir: " << nomeArquivo << endl;
		return erro_arquivo;
	}

    while(!file.eof())
    {
        getline(file, line);
        row.clear();
        stringstream str(line);
        while(getline(str, word, ','))
            row.push_back(word);
        content.push_back(row);
    }
    

    file.close();
    //cout << file.rdbuf();
    for(long long unsigned i = 2; i < content.size();i++)
    {   
        for(long long unsigned j = 0; j< content[i].size(); j++)
        {
            data.push_back(content[i][0]);
            maxTemp.push_back(stod(content[i][1]));
            minTemp.push_back(stod(content[i][2]));
            radiacaoSolar.push_back(stod(content[i][3]));
            chuva.push_back(stod(content[i][4]));
            vento.push_back(stod(content[i][5]));
            //cout<<content[i][j]<<" ";
        }
        //cout<<"\n";
    }
 
    return OK;
}
unsigned Cidade::mapearMeses(string mesDesejado)
{
    const auto iter = meses.find(mesDesejado);

    if( iter != meses.cend() )
        return iter->second;
    return -1;
}
unsigned Cidade::dadosHistoricos(string mesInicio, string mesFim, string ano)
{
    int inicio = mapearMeses(mesInicio);
    int fim = mapearMeses(mesFim);
    long anoCalculo = stol(ano);
    vector <double> mediaTempMax;
    vector <double> mediaTempMin;
    vector <double> mediaRadiacao;
    vector <double> mediaChuva;
    vector <double> mediaVento;
    string empty;

    for (int i = 0; i <= (fim-inicio); i++)
    {
        mediaTempMax.push_back(calcularMedia(inicio+i, maxTemp , anoCalculo, 1));
        mediaTempMin.push_back(calcularMedia(inicio+i, minTemp, anoCalculo, 1));
        mediaRadiacao.push_back(calcularMedia(inicio+i, radiacaoSolar, anoCalculo, 1));
        mediaChuva.push_back(calcularMedia(inicio+i, chuva, anoCalculo, 1));
        mediaVento.push_back(calcularMedia(inicio+i, vento, anoCalculo, 1));
    }
    
    imprimirMedia(inicio, fim, mediaTempMax, "Temperatura Maxima (Celsius)");
    cout << endl;
    imprimirMedia(inicio, fim, mediaTempMin, "Temperatura Minima (Celsius)");
    cout << endl;
    imprimirMedia(inicio, fim, mediaRadiacao, "Radiacao Solar (MJ/m^2)");
    cout << endl;
    imprimirMedia(inicio, fim, mediaChuva, "Media de Chuva (mm)");
    cout << endl;
    imprimirMedia(inicio, fim, mediaVento, "Media da Velocidade Maxima do Vento (km/h)");
    
    // Press enter to continue
    getline(cin, empty);

    return OK;
}
void Cidade::imprimirMedia(int inicio, int fim, vector<double> vetor, string titulo)
{
    cout << setw(10) << titulo << endl;//imprimo o titulo da media que vou imprimir 
    for (int i = 0; i <= (fim-inicio); i++) //imprimo os meses
    {
        cout << setw(10);
        findMonth(inicio+i);
    }
    cout << endl;
    for (int i = 0; i <=  (fim-inicio); i++) 
    {
        cout << setw(10) << vetor[i];
    }
    cout << endl;

}
double Cidade::calcularMedia(int mes, vector <double> vetor, long int ano, int opcao)
{
    double soma = 0, count = 0;
    string aux;
   
    for (unsigned i = 0; i < data.size(); i++)
    {
        if (stoi(data[i].substr(5,2)) == mes && (stol(data[i].substr(0,4)) == ano) && opcao == 1)
        {
            soma += vetor[i];
            count++;
        }
        if ((stol(data[i].substr(0,4)) == ano) && opcao == 2)
        {
            soma += vetor[i];
            count++;
        }
    }
    return (soma/count);
}
double Cidade::valorMedio(vector<double> vetor)
{
    double sum = accumulate(vetor.begin(), vetor.end(), 0);
    return sum/vetor.size();
}
void Cidade::maioresIndices(void)
{
    mediaMaxTemp = valorMedio(maxTemp);
    mediaMinTemp = valorMedio(minTemp);
    mediaRadiacaoSolar = valorMedio(radiacaoSolar);
    mediaChuva = valorMedio(chuva);
    mediaVento = valorMedio(vento);
}

void Cidade::compararAnos(string primAno, string segAno)
{
    double maxTemp1, maxTemp2;
    double minTemp1, minTemp2;
    double radiacaoSolar1, radiacaoSolar2;
    double chuva1, chuva2;
    double vento1, vento2;
    double pct;
    long ano1= stol(primAno);
    long ano2 = stol(segAno);
    string empty;

    maxTemp1 = calcularMedia(0, maxTemp , ano1, 2);
    maxTemp2 = calcularMedia(0, maxTemp , ano2, 2);
    if (maxTemp1 > maxTemp2)
    {
        pct = ((maxTemp1/maxTemp2)*100)-100;
        cout << "A temperatura media maxima de " << maxTemp1 << " C, de " << primAno << " eh ";
        cout << pct << "% maior que " << maxTemp2 << " C, de " << segAno << endl; 
    }
    else 
    {
        pct = ((maxTemp2/maxTemp1)*100)-100;
        cout << "A temperatura media maxima de " << maxTemp2 << " C, de " << segAno << " eh "; 
        cout << pct << "% maior que " << maxTemp1 << " C, de " << primAno << endl; 
    }
    minTemp1 = calcularMedia(0, minTemp , ano1, 2);
    minTemp2 = calcularMedia(0, minTemp , ano2, 2);
    if (minTemp1 < minTemp2)
    {
        pct = 100 - (( minTemp1/ minTemp2)*100);
        cout << "A temperatura media minima de " << minTemp1 <<  " C, de " << primAno << " eh ";
        cout << pct << "% menor que " << minTemp2 << " C, de " <<segAno << endl; 
    }
    else 
    {
        pct = 100 -(( minTemp2/ minTemp1)*100);
        cout << "A temperatura media minima de " << minTemp2 <<  " C, de " << segAno << " eh ";
        cout << pct << "% menor que " << minTemp1 << " C, de " << primAno << endl; 
    }
    chuva1 = calcularMedia(0, chuva , ano1, 2);
    chuva2 = calcularMedia(0, chuva , ano2, 2);
    if (chuva1 > chuva2)
    {
        pct = ((chuva1/ chuva2)*100) - 100;
        cout << "O volume de chuva de " <<  chuva1 << " mm, de " << primAno << " eh ";
        cout << pct << "% maior que a " <<  chuva2 << " mm, de " << segAno << endl; 
    }
    else 
    {
        pct = (( chuva2/ chuva1)*100) -100;
        cout << "O volume de chuva de " <<  chuva2 << " mm, de " << segAno << " eh "; 
        cout << pct << "% maior que " <<  chuva1 << " mm, de " << primAno << endl; 
    }
    radiacaoSolar1 = calcularMedia(0, radiacaoSolar , ano1, 2);
    radiacaoSolar2 = calcularMedia(0, radiacaoSolar , ano2, 2);
    if (radiacaoSolar1 > radiacaoSolar2)
    {
        pct = (( radiacaoSolar1/ radiacaoSolar2)*100) - 100;
        cout << "A radiacao solar de " <<   radiacaoSolar1 << " MJ/m^2, de " << primAno << " eh ";
        cout << pct << "% maior que " <<   radiacaoSolar2 << " MJ/m^2, de " << segAno << endl; 
    }
    else 
    {
        pct = ((radiacaoSolar2/ radiacaoSolar1)*100) -100;
        cout << "A radiacao solar de " <<   radiacaoSolar2 << " MJ/m^2, de " << segAno << " eh "; 
        cout << pct << "% maior que " <<   radiacaoSolar1 << " MJ/m^2, de " << primAno << endl; 
    }
    vento1 = calcularMedia(0, vento , ano1, 2);
    vento2 = calcularMedia(0, vento , ano2, 2);
    if ( vento1 > vento2)
    {
        pct = ((vento1/vento2)*100) - 100;
        cout << "A velocidade media do vento de " <<   vento1 << " km/h, de " << primAno << " eh ";
        cout << pct << "% maior que " <<   vento2 << " km/h, de " << segAno << endl; 
    }
    else 
    {
        pct = ((vento2/  vento1)*100) - 100;
        cout << "A velocidade media do vento de " <<   vento2 << " km/h, de " << segAno << " eh "; 
        cout << pct << "% maior que " <<   vento1 << " km/h, de " << primAno << endl; 
    }
   
    // Press enter to continue
    getline(cin, empty);
}
void Cidade::maioresIndicesCidade(string ano)
{   
    long anoEscolhido= stol(ano);
    double max;
    vector <double> mediaTempMax;
    vector <double> mediaTempMin;
    vector <double> mediaRadiacao;
    vector <double> mediaChuva;
    vector <double> mediaVento;
    string empty;

    for (int i = 0; i < 12; i++)
    {
        mediaTempMax.push_back(calcularMedia(i+1, maxTemp , anoEscolhido , 1));
        mediaTempMin.push_back(calcularMedia(i+1, minTemp, anoEscolhido, 1));
        mediaRadiacao.push_back(calcularMedia(i+1, radiacaoSolar, anoEscolhido, 1));
        mediaChuva.push_back(calcularMedia(i+1, chuva, anoEscolhido, 1));
        mediaVento.push_back(calcularMedia(i+1, vento, anoEscolhido, 1));
    }
    
    int index;
    index = max_element(mediaTempMax.begin(),mediaTempMax.end()) - mediaTempMax.begin();
    max = *max_element(mediaTempMax.begin(), mediaTempMax.end());
    cout << "Temperatura maxima: "; 
    findMonth(index+1);
    cout << ", " << max << " °C" << endl;

    index = min_element(mediaTempMin.begin(),mediaTempMin.end()) - mediaTempMin.begin();
    max = *min_element(mediaTempMin.begin(), mediaTempMin.end());
    cout << "Temperatura minima: ";
    findMonth(index+1);
    cout << ", " << max << " °C" << endl;

    index = max_element(mediaRadiacao.begin(),mediaRadiacao.end()) - mediaRadiacao.begin();
    max = *max_element(mediaRadiacao.begin(), mediaRadiacao.end());
    cout << "Radiacao solar: ";
    findMonth(index+1);
    cout << ", " << max << " MJ/m^2" << endl;

    index = max_element(mediaChuva.begin(),mediaChuva.end()) - mediaChuva.begin();
    max = *max_element(mediaChuva.begin(), mediaChuva.end());
    cout << "Volume de chuva: ";
    findMonth(index+1);
    cout << ", " << max << " mm" << endl;

    index = max_element(mediaVento.begin(),mediaVento.end()) - mediaVento.begin();
    max = *max_element(mediaVento.begin(), mediaVento.end());
    cout << "Velocidade maxima do vento: ";
    findMonth(index+1);
    cout << ", " << max << " km/h" << endl;
    
    // Press enter to continue
    getline(cin, empty);
}
void Cidade::findMonth(int valor)
{
    for (auto it = meses.begin(); it != meses.end(); ++it)
    {
        if (it->second == valor)
            cout << it->first;
    }

}

string Cidade::getNomeArquivo(){
    return nomeArquivo;
}

   