
all: Atractor_Lorenz.pdf

Atractor_Lorenz.pdf: Rkutta4.py datos_lorenz.txt
	./.venv/bin/python3 Rkutta4.py

datos_lorenz.txt: lorenz.x
	./lorenz.x > datos_lorenz.txt

lorenz.x: Rkutta4.cpp
	g++ -std=c++23 -Wall Rkutta4.cpp -o lorenz.x

clean:
	rm -f *.x datos_lorenz.txt Atractor_Lorenz.pdf *~