#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <cmath>
#include <vector>

using namespace std;

const int a = 2;
const float b = 2.0;

void impresion(int a,float b){
    cout << "la primera tiene un valor de " << a
        << " y la segunda variable tiene un valor de " << b << endl;
}

void dividir(int a, float b){
    cout << "El resultado de la división es " << a/b << endl;
}

void arrAleatorio(vector<int> &A){
    srand(time(0));
    for(int i=0; i<300; i++){
        A.push_back(rand()%901);
    }
}

void impArr(vector<int> &A){
    cout << "[";
    for(int i=0; i<A.size(); i++){
        cout << A[i] << " ";
    }
    cout << "]" << endl;
}

float division(float mivarflotante, int mivarentera){
    return mivarflotante/mivarentera;
}

int minimo(vector<int> &A){
    if (A.empty()) { // .empty() es la forma más clara de chequear si está vacío
        std::cerr << "Error: No se puede calcular el mínimo de un vector vacío." << std::endl;
        // ¿Qué retornar? No hay un mínimo real. Una opción es retornar el mayor
        // valor posible para un int, para señalar que algo fue mal.
        return std::numeric_limits<int>::max(); 
    }
    
    int minimo = A[0];
    for(int i=1; i<A.size(); i++){
        if (A[i]<minimo) minimo = A[i];
    }
    return minimo;
}

void impares(vector<int> &A){
    cout << "[ " ;
    for(int i=0;i<A.size();i++){
        if(A[i] > 800) break;
        if(A[i]%2 != 0){
            cout << A[i] << " ";
        }
    }
    cout << "]" << endl;
}

int main(){
    impresion(a,b);
    dividir(a,b);
    vector<int> A;
    arrAleatorio(A);
    impArr(A);
    cout << A[4] << endl;
    int long_arr = A.size();
    cout << "La longitud del arreglo es: " << long_arr << endl;

    float mivarflotante = 17.5;
    int mivarentera=5;

    cout << division(mivarflotante,mivarentera) << endl;

    cout << minimo(A) << endl;

    impares(A);

    return 0;
}

/*
1) Inicializar dos variables globales (con valores escogidos por ustedes), una entera y otra flotante.

2) Imprimir los valores de las variables en un mensaje: "la primera tiene un valor de XX y la segunda variable tiene un valor de YY"

3) Calcular el valor de la segunda variable dividida por la primera e imprimir : "El resultado es ZZ" 

4) Crear un arreglo con 300 números enteros aleatorios entre 0 y 900. 
(ejemplos en: https://www.geeksforgeeks.org/rand-and-srand-in-ccpp/ o https://www.cplusplus.com/reference/cstdlib/rand/ o rand - C++ Reference entre otros)

5) Hacer una iteración para recorrer dicho arreglo e imprimir todos sus elementos. 

6) Imprimir el quinto elemento del arreglo

7) Obtener la longitud del arreglo e imprimir: "la longitud del arreglo es XX" (use la función size(), mire cppreference)

8) Haga una función que reciba dos variables una flotante llamada mivarflotante y una entera llamada mivarentera y retorne la variable flotante dividida por la variable entera.    
                    
9) Llame su función desde la función main e imprima lo que retorna su función para mivarflotante=17.5 y mivarentera=5.

10) Haga una función que retorne el mínimo del arreglo de números aleatorios antes creado

11) Haga una función que reciba el arreglo de números aleatorios antes creado, imprima los números impares y pare de imprimir al encontrar un número mayor a 800

*/






/*para ver mas ejemplos: https://www.w3schools.com/CPP/cpp_variables.asp*/
