# Previsão e informações do clima

## Primeiro Passo
Instalar as dependências do projeto

```
pip install -r requirements.txt
```

## Compilando o programa:

Para compilar o programa é necessário que o computador em questão tenha instalado o python, de preferência o python 3.8.
Caso a versão seja diferente, será necessário fazer uma alteração no Makefile na linha 10 na flag -I e na linha 11 na flag -l:
    "CPPFLAGS = -Wall -std=c++11 -I/usr/include/python3.8"
    "LIBFLAG = -lpython3.8"

Com isso já será possível compilar o programa


1) Para compilar o programa, digite:
    ```
    make trab_final
    ```