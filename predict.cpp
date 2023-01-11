#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include <iostream>
#include <string>
#include <vector>
#include "predict.h"

using namespace std;


vector<string> call_wether_predictor(string dataset_path_str, string target_column_str, string day_str)
{
    string predicted_value, real_value;
    string result_str;
    PyObject *sys_path, *model_module, *wether_predict, *result;
    const char* dataset_path = dataset_path_str.c_str();
    const char* target_column = target_column_str.c_str();
    const char* day = day_str.c_str();

    // Inicializando o interpretador Python
    Py_Initialize();

    // Adicionando a pasta atual na sys_path
    sys_path = PySys_GetObject("path");
    PyList_Append(sys_path, PyUnicode_FromString("."));

    // Carregando o módulo do modelo 
    model_module = PyImport_ImportModule("model");
    
    // Carregando a função de previsão do tempo
    wether_predict = PyObject_GetAttrString(model_module, "wether_predict");

    // Chamando a função com os argumentos
    result = PyObject_CallFunction(wether_predict, "sss", dataset_path, target_column, day);

    // Formatando o resultado para retorná-los
    result_str = PyUnicode_AsUTF8(result);
    predicted_value = result_str.substr(0, result_str.find_first_of(" ") + 1);
    real_value = result_str.substr(result_str.find_first_of(" ") + 1, result_str.size());

    cout << "\nValor predito: " << predicted_value << endl;
    cout << "Valor real: " << real_value << endl;
    
    // Finalizar o interpretador Python
    Py_Finalize();

    return {predicted_value, real_value};
}
/*
int main(){
    call_wether_predictor("./datas/archive_manaus.csv", "temperature_2m_max (°C)", "31/12/2022");
}*/