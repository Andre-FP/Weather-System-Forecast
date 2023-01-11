#include "cidade.h"
#include "global.h"
#include "predict.h"
#include <limits>
#define OK 0
using namespace std;

void printString(vector <string>);
bool valida_dia(string);

int main()
{
    Cidade RiodeJaneiro("./datas/riodejaneiro.csv");
    Cidade SaoPaulo("./datas/saopaulo.csv");
    Cidade PortoAlegre("./datas/portoalegre.csv");
    Cidade Florianopolis("./datas/florianopolis.csv");
    Cidade RioBranco("./datas/riobranco.csv");
    Cidade Manaus("./datas/manaus.csv");
    Cidade Recife ("./datas/recife.csv");
    Cidade Natal("./datas/natal.csv");
    Cidade Cuiaba("./datas/cuiaba.csv");
    Cidade Brasilia("./datas/brasilia.csv");
	Global conjuntoCidades({RiodeJaneiro,SaoPaulo,PortoAlegre,Florianopolis,RioBranco,Manaus,Recife,
	Natal, Cuiaba,Brasilia});

    conjuntoCidades.lerTodosArquivos();
    
    unsigned opcao;
    string cidade, mesInicio, mesFim, ano, primAno, segAno, caminho_dados, indice, coluna, dia, empty;
	vector <string> cidades = {"Rio de Janeiro", "Sao Paulo", "Porto Alegre", "Florianopolis", "Rio Branco", "Manaus", "Recife", "Natal", "Cuiaba", "Brasilia"};
    vector <string> mes = {"Janeiro", "Fevereiro", "Marco", "Abril", "Maio", "Junho", "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"};
	vector <string> anos = {"2018", "2019", "2020", "2021", "2022"};
	vector <string> indices = {"Temperatura maxima", "Temperatura minima", "Radiacao solar", "Volume de chuva", "Velocidade do vento"};
	vector <string> colunas_indices = {"temperature_2m_max (°C)", "temperature_2m_min (°C)", "shortwave_radiation_sum (MJ/m²)", "rain_sum (mm)", "windspeed_10m_max (km/h)"};
	vector <Cidade> globalCidades;

	while (1) //loop de execução do programa
	{
		cout << "\n\n\n\n\n\n\n\n\n\n-------------------------------------------------------------------------------------------------------" << endl;
		cout << "Cidades Brasileiras e seu Clima" << endl;
		cout << "\n1 - Apresentar dados climaticos para uma cidade brasileira dentro de um intervalo de meses" << endl;
		cout << "2 - Apresentar as cidades com os maiores indices climaticos medio durante todo o periodo"<< endl;
		cout << "3 - Evolução dos indices climaticos de uma cidade entre dois anos selecionados" << endl;
		cout << "4 - Meses que tiveram os maiores indices climaticos para uma cidade" << endl;
		cout << "5 - Exibir a previsao do clima para amanha para uma cidade" << endl;
		cout << "0 - Sair do programa" << endl;
		cout << "\n\nInsira a opcao desejada: ";
		cin >> opcao; //recebe uma opcao do usuario
		cout << "-------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << endl;
		while (opcao > 5 || opcao < 0) // enquanto o usuario nao inserir uma opcao valida
		{
			cout << "Insira uma opcao entre 0 e 5" << endl;
            cin >> opcao;
		}
		//chamando as funcoes de acordo com a opcao do usuario
		switch (opcao)
		{
			case 0:
				cout << "Saindo do programa" << endl;
				exit(1);
				break; 

			case 1:
				cout << "\n1 - Apresentar dados climaticos para uma cidade brasileira dentro de um intervalo de meses" << endl;
				cout << "\n\nInsira a cidade que deseja visualizar os dados: ";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                getline(cin, cidade);
				while (find(cidades.begin(), cidades.end(), cidade) == cidades.end())
				{
					cout << "\nCidade nao encontrada. ";
					cout << "Insira uma das cidades a seguir, como escrito abaixo:" << endl;
					printString(cidades);
					cout << "\n" << endl;
					cout << "Cidade: ";
					getline(cin, cidade);
				}
                cout << "Insira o ano que deseja visualizar os dados: ";
                getline(cin, ano);
				while (find(anos.begin(), anos.end(), ano) == anos.end())
				{
					cout << "\nAno nao encontrada. ";
					cout << "Insira um dos anos a seguir, como escrito abaixo" << endl;
					printString(anos);
					cout << "\n" << endl;
					cout << "Ano: ";
					getline(cin, ano);
				}
                cout << "Insira o mes de inicio do periodo: ";
                getline(cin, mesInicio);
				while (find(mes.begin(), mes.end(), mesInicio) == mes.end())
				{
					cout << "\nMes nao encontrado. ";
					cout << "Insira um dos meses a seguir, como escrito abaixo: " << endl;
					printString(mes); 
					cout << "\n" << endl;
					cout << "Mes: ";
					getline(cin, mesInicio);
				}
                cout << "Insira o mes do fim do periodo: ";
                getline(cin, mesFim);
				while (find(mes.begin(), mes.end(), mesFim) == mes.end())
				{
					cout << "\nMes nao encontrado. ";
					cout << "Insira um dos meses a seguir, como escrito abaixo: " << endl;
					printString(mes);
					cout << "\n" << endl;
					cout << "Mes: ";
					getline(cin, mesFim);
				}
				cout << "\n\n\n\n" << endl;
                conjuntoCidades.mostrarDadosHistoricos(cidade, mesInicio, mesFim, ano);
				break;

			case 2:
				cout << "\n2 - Apresentar as cidades com os maiores indices climaticos medio durante todo o periodo\n"<< endl;
				conjuntoCidades.mostrarMaioresIndices();
				break;

			case 3:
				cout << "\n3 - Evolução dos indices climaticos de uma cidade entre dois anos selecionados" << endl;
				
				cout << "\n\nInsira a cidade que deseja visualizar os dados: ";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                getline(cin, cidade);
				while (find(cidades.begin(), cidades.end(), cidade) == cidades.end())
				{
					cout << "\nCidade nao encontrada. ";
					cout << "Insira uma das cidades a seguir, como escrito abaixo:" << endl;
					printString(cidades);
					cout << "\n" << endl;
					cout << "Cidade: ";
					getline(cin, cidade);
				}
				cout << "Insira o primeiro ano que deseja comparar: ";
                getline(cin, primAno);
				while (find(anos.begin(), anos.end(), primAno) == anos.end())
				{
					cout << "\nAno nao encontrada. ";
					cout << "Insira um dos anos a seguir, como escrito abaixo" << endl;
					printString(anos);
					cout << "\n" << endl;
					cout << "Ano: ";
					getline(cin, primAno);
				}
				cout << "Insira o segundo ano que deseja comparar: ";
                getline(cin, segAno);
				while (find(anos.begin(), anos.end(), segAno) == anos.end())
				{
					cout << "\nAno nao encontrada. ";
					cout << "Insira um dos anos a seguir, como escrito abaixo" << endl;
					printString(anos);
					cout << "\n" << endl;
					cout << "Ano: ";
					getline(cin, segAno);
				}
				cout << "\n\n" << endl;
				conjuntoCidades.compararAnos(cidade, primAno, segAno);
				break;

			case 4:
				cout << "\n4 - Meses que tiveram os maiores indices climaticos para uma cidade" << endl;
				cout << "\n\nInsira a cidade que deseja visualizar os dados: ";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                getline(cin, cidade);
				while (find(cidades.begin(), cidades.end(), cidade) == cidades.end())
				{
					cout << "\nCidade nao encontrada. ";
					cout << "Insira uma das cidades a seguir, como escrito abaixo:" << endl;
					printString(cidades);
					cout << "\n" << endl;
					cout << "Cidade: ";
					getline(cin, cidade);
				}
                cout << "Insira o ano que deseja visualizar os dados: ";
                getline(cin, ano);
				while (find(anos.begin(), anos.end(), ano) == anos.end())
				{
					cout << "\nAno nao encontrada. ";
					cout << "Insira um dos anos a seguir, como escrito abaixo" << endl;
					printString(anos);
					cout << "\n" << endl;
					cout << "Ano: ";
					getline(cin, ano);
				}
				cout << "\n\n" << endl;
				cout << "Meses com os maiores indices climáticos medios para " << cidade << ":\n" << endl;
				conjuntoCidades.maioresIndices(cidade, ano);
				break;

			case 5:
				cout << "5 - Exibir a previsao do clima para amanha para uma cidade" << endl;
				
				cout << "\n\nInsira a cidade que deseja visualizar os dados: ";
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
                getline(cin, cidade);
				while (find(cidades.begin(), cidades.end(), cidade) == cidades.end())
				{
					cout << "\nCidade nao encontrada. ";
					cout << "Insira uma das cidades a seguir, como escrito abaixo:" << endl;
					printString(cidades);
					cout << "\n" << endl;
					cout << "Cidade: ";
					getline(cin, cidade);
				}
				
				// Encontrando a cidade para encontrar a path do dataset
				globalCidades = conjuntoCidades.getCidades();
				for (unsigned i = 0; i < cidades.size(); i++)
				{
					if (cidades.at(i) == cidade)
						caminho_dados = globalCidades.at(i).getNomeArquivo();
				}
				
				cout << "Insira o indice desejado para a previsão: ";
				
                getline(cin, indice);
				while (find(indices.begin(), indices.end(), indice) == indices.end())
				{
					cout << "\nIndice nao encontrado. ";
					cout << "Insira um dos indices a seguir, como escrito abaixo:" << endl;
					
					for (unsigned i = 0; i < indices.size(); i++){
						cout << indices[i];
						if (i < indices.size() - 1)
							cout << ", "; 
					}

					cout << "\n" << endl;
					cout << "Indice: ";
					getline(cin, indice);
				}

				for (unsigned i = 0; i < indices.size(); i++)
				{
					if (indices.at(i) == indice)
						coluna = colunas_indices.at(i);
				}

				cout << "Insira o dia desejado para a previsão (DD/MM/AAAA): ";
				
                getline(cin, dia);
				while (!valida_dia(dia)){
					cout << "\nDia (DD/MM/AAAA): ";
					getline(cin, dia);
				}

				call_wether_predictor(caminho_dados, coluna, dia);

				// Press enter to continue
				getline(cin, empty);
				break;
			}

	}
    return OK;
}
void getMaxValue()
{

}
void printString(vector<string> vetor)
{
	for(long long unsigned i=0; i <vetor.size(); i++){
		cout <<vetor.at(i);
		if (i < vetor.size() - 1)
			cout << ", ";
	}
}

vector <string> split(string linha, char separator = '/'){
	string restante_linha;
	vector <string> splitted;
	int end_position = 0;

	restante_linha = linha;
	while (end_position != -1){
		end_position = restante_linha.find_first_of(separator);
		if (end_position != -1){
			splitted.push_back(restante_linha.substr(0, end_position));
			restante_linha = restante_linha.substr(end_position + 1, restante_linha.size() - (end_position + 1));
		}
		else if (restante_linha != "" && restante_linha != "\n") // ignorar se restar só isso
			splitted.push_back(restante_linha);
	}
	return splitted;
}

bool valida_dia(string dia){
	vector <string> numeros_dia = split(dia);

	if (numeros_dia.size() != 3){
		cout << "Dia inválido. Formato correto: DD/MM/AAAA" << endl;
		return false;
	}
	if (stoi(numeros_dia[0]) > 31 || stoi(numeros_dia[0]) < 1){
		cout << "Dia inválido. Formato correto: DD/MM/AAAA" << endl;
		return false;
	}
	if (stoi(numeros_dia[1]) > 12 || stoi(numeros_dia[1]) < 1){
		cout << "Dia inválido. Formato correto: DD/MM/AAAA" << endl;
		return false;
	}
	if (stoi(numeros_dia[2]) != 2022){
		cout << "Dia inválido. Formato correto: DD/MM/AAAA. Ano deve ser de 2022." << endl;
		return false;
	}
	return true;
}