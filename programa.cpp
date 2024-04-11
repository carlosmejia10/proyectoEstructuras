#include <iostream>
#include <string>
#include "diccionario.h"
#include <vector> // Add missing include directive

int main() {
    // Diccionario diccionario;
    // diccionario.cargar_diccionario("archivo_dicc.txt");

    // std::string palabra;
// while (true) {
//     // std::cout << "Ingrese una palabra (vacio para salir): ";
//     // std::getline(std::cin, palabra);
//     // if (palabra.empty()) {
//     //     break;
//     // }
//     // int puntaje = diccionario.obtener_puntaje(palabra);
//     // if (puntaje > 0) {
//     //     std::cout << "Puntaje: " << puntaje << std::endl;
//     // } else {
//     //     std::cout << "Palabra no encontrada" << std::endl;
//     // }




// }

Diccionario diccionario;
diccionario.cargar_diccionarioInverso("archivo_dicc.txt");

// Buscar palabras con el prefijo 'al'
std::vector<std::string> palabras = diccionario.buscar_sufijo("er");
std::cout << "Palabras con el sufijo 'er':\n";
for (const std::string& palabra : palabras) {
    std::cout << palabra << "\n";
}
    return 0;
}