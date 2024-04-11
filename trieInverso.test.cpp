#include "trieInverso.h"
#include <iostream>
#include <string>

int main() {
    TrieInverso trie;

    // Insertar palabras en el Trie
    trie.insertar("hola");
    trie.insertar("adios");
    trie.insertar("bien");
    trie.insertar("caen");
    trie.insertar("bienvenido");
    trie.insertar("hombre");
    trie.insertar("mujer");

    // Buscar palabras que terminan con un sufijo
    std::vector<std::string> palabras = trie.buscar_sufijo("en");
    std::cout << "Palabras que terminan con 'en':\n";
    for (const std::string& palabra : palabras) {
        std::cout << palabra << '\n';
    }

    // Obtener el puntaje de una palabra
    std::string palabra = "bienvenido";
    int puntaje = trie.obtener_puntaje(palabra);
    std::cout << "Puntaje de "<<palabra<<":" << puntaje << '\n';

    return 0;
}