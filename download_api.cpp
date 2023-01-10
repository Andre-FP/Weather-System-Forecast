#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;


int call_download_all_datasets(string end_date_str="2022-12-31")
{
    PyObject *sys_path, *download_module, *download_func;
    const char* end_date = end_date_str.c_str();

    // Inicializando o interpretador Python
    Py_Initialize();

    // Adicionando a pasta atual na sys_path
    sys_path = PySys_GetObject("path");
    PyList_Append(sys_path, PyUnicode_FromString("."));

    // Carregando o módulo do modelo 
    download_module = PyImport_ImportModule("download");
    
    // Carregando a função de previsão do tempo
    download_func = PyObject_GetAttrString(download_module, "download_all_datasets");

    // Chamando a função com os argumentos
    PyObject_CallFunction(download_func, "s", end_date);
    
    cout << "Download completo" << endl;
    
    // Finalizar o interpretador Python
    Py_Finalize();
    return 0;
}

int main(){
    call_download_all_datasets();
}