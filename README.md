# Weather forecast and information

Program made in C++ with interface with Python. 
The main program is written in C++ and provides weather information for the target period, from the weather database: https://open-meteo.com/.
The Python part do a prediction task for weather forecast in any selected choice: Temperature max, temperature min, shortwave radiation sum, rain sum, or windspeed max. 

## First step
Install project dependencies

```
pip install -r requirements.txt
```

## Compiling the program:

To compile the program, the computer must have Python installed, preferably Python 3.8.
If the version is different, it will be necessary to make a change in the Makefile on line 10 in the -I flag and in line 11 in the -l flag:
     "CPPFLAGS = -Wall -std=c++11 -I/usr/include/python3.8"
     "LIBFLAG = -lpython3.8"

With this it will be possible to compile the program


1) To compile the program, type:
     ```
     make work_final
     ```
