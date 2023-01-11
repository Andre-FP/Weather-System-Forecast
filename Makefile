#  Universidade Federal do Rio de Janeiro
#  Escola Politecnica
#  Departamento de Eletronica e de Computacao
#  EEL670 - Ling. Prog. - Turma 2022/2
#  Prof. Miguel Elias Mitre Campista
#  Autores: Andre de Farias Pereira e Gabriela Sasso Viegas Rego
#  Descricao: Trabalho Final - Manipulações e Previsões Meteorológica.

CPP = g++
CPPFLAGS = -Wall -std=c++11 -I/usr/include/python3.8
LIBFLAG = -lpython3.8

# Main Program
MAIN_OBJ = main.o
TRAB_CLASSES_OBJ = predict.o cidade.o global.o
TRAB_OBJ = $(MAIN_OBJ) $(TRAB_CLASSES_OBJ)
TRAB = trab_final

c.o:
	$(CPP) $(CPPFLAGS) -c $<

##### Programa principal #####
$(TRAB): $(TRAB_OBJ)
	$(CPP) $(CPPFLAGS) $(TRAB_OBJ) -o $@ $(LIBFLAG)

clean:
	rm -rf $(TRAB) *.o 
