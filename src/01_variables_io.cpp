#include <iostream>
#include <string> // Necesitamos incluir la librería string para usar std::string

using namespace std;

int main() {
    // --- DECLARACIÓN DE VARIABLES ---
    // Declaramos una variable para guardar el nombre. std::string es el tipo de dato para texto.
    string nombre;
    
    // Declaramos una variable para guardar la edad. int es el tipo de dato para números enteros.
    int edad;

    // --- SALIDA DE DATOS (OUTPUT) ---
    // Usamos std::cout para mostrar un mensaje en la pantalla.
    // std::endl es para crear un salto de línea.
    cout << "Hola! Por favor, introduce tu nombre: ";

    // --- ENTRADA DE DATOS (INPUT) ---
    // Usamos std::cin para leer lo que el usuario escribe en el teclado y guardarlo en la variable 'nombre'.
    cin >> nombre;

    // Hacemos lo mismo para la edad.
    cout << "Gracias, " << nombre << ". Ahora, por favor, introduce tu edad: ";
    cin >> edad;

    // --- PROCESAMIENTO Y SALIDA FINAL ---
    // Mostramos un mensaje final usando las variables que hemos guardado.
    cout << endl; // Un espacio para que se vea más limpio
    cout << "Resumen:" << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Edad: " << edad << " anios" << endl;

    return 0;
}