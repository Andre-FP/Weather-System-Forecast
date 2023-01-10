#  Universidade Federal do Rio de Janeiro
#  Escola Politecnica
#  Departamento de Eletronica e de Computacao
#  EEL670 - Ling. Prog. - Turma 2022/2
#  Prof. Miguel Elias Mitre Campista
#  Autor: Andre de Farias Pereira
#  Descricao: Trabalho Final - .

CPP = g++
CPPFLAGS = -Wall -std=c++11 -I/usr/include/python3.8
LIBFLAG = -lpython3.8

# Main Program
MAIN_OBJ =
TRAB_CLASSES_OBJ = api.o download.o
TRAB_OBJ = $(MAIN_OBJ) $(TRAB_CLASSES_OBJ)
TRAB = trab_final

# Predict Program
PREDICT = predict
PREDICT_OBJ = predict.o

# Download Program
DOWNLOAD = download_data
DOWNLOAD_OBJ = download_api.o

# Todos os testes
TESTES = $(TESTE) $(TESTE_INSERIR) $(TESTE_BUSCA) $(TESTE_IMPRIME)

c.o:
	$(CPP) $(CPPFLAGS) -c $<

##### Programa principal #####
$(TRAB): $(TRAB_OBJ)
	$(CPP) $(CPPFLAGS) $(TRAB_OBJ) -o $@ $(LIBFLAG)

##### Programa Download  #####
$(DOWNLOAD): $(DOWNLOAD_OBJ)
	$(CPP) $(CPPFLAGS) $(DOWNLOAD_OBJ) -o $@ $(LIBFLAG)

##### Predict Program  #####
$(PREDICT): $(PREDICT_OBJ)
	$(CPP) $(CPPFLAGS) $(PREDICT_OBJ) -o $@ $(LIBFLAG)

clean:
	rm -rf $(TESTES) $(TRAB) $(PREDICT) $(DOWNLOAD) *.o 
