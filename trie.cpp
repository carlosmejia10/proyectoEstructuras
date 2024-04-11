#include "trie.h"
#include <string>
#include <vector> // Include the necessary header file

Trie::Trie()
{
    raiz = new Nodo('\0', 0); // Inicializa la raíz como un nuevo Nodo
}

Trie::~Trie()
{
    delete raiz;
}

int Trie::calcular_puntaje(char letra) const
{
    switch (letra)
    {
    case 'E':
    case 'e':
    case 'A':
    case 'a':
    case 'I':
    case 'i':
    case 'O':
    case 'o':
    case 'N':
    case 'n':
    case 'R':
    case 'r':
    case 'T':
    case 't':
    case 'L':
    case 'l':
    case 'S':
    case 's':
    case 'U':
    case 'u':
        return 1;
    case 'D':
    case 'd':
    case 'G':
    case 'g':
        return 2;
    case 'B':
    case 'b':
    case 'C':
    case 'c':
    case 'M':
    case 'm':
    case 'P':
    case 'p':
        return 3;
    case 'F':
    case 'f':
    case 'H':
    case 'h':
    case 'V':
    case 'v':
    case 'W':
    case 'w':
    case 'Y':
    case 'y':
        return 4;
    case 'K':
    case 'k':
        return 5;
    case 'J':
    case 'j':
    case 'X':
    case 'x':
        return 8;
    case 'Q':
    case 'q':
    case 'Z':
    case 'z':
        return 10;
    default:
        return 0;
    }
}

void Trie::insertar(const std::string &palabra)
{
    Nodo *nodoActual = raiz;
    for (char letra : palabra)
    {
        int puntaje = calcular_puntaje(letra);
        if (nodoActual->hijos.find(letra) == nodoActual->hijos.end())
        {
            nodoActual->hijos[letra] = new Nodo(letra, puntaje);
        }
        nodoActual = nodoActual->hijos[letra];
    }
    nodoActual->es_final = true;
    nodoActual->puntaje = 1;
}

bool Trie::buscar(const std::string &palabra) const {
    Nodo *nodoActual = raiz;
    for (char letra : palabra) {
        auto it = nodoActual->hijos.find(letra);
        if (it == nodoActual->hijos.end()) {
            return false;
        }
        nodoActual = it->second;
    }
    return nodoActual->puntaje > 0;
}
int Trie::obtener_puntaje(const std::string &palabra) const {
    Nodo *nodoActual = raiz;
    int puntajeTotal = 0;
    for (char letra : palabra) {
        auto it = nodoActual->hijos.find(letra);
        if (it == nodoActual->hijos.end()) {
            return 0; // Return 0 if the letter is not found in the trie
        } else {
            nodoActual = it->second;
            puntajeTotal += nodoActual->puntaje;
        }
    }
    return puntajeTotal;
}



std::vector<std::string> Trie::buscar_prefijo(const std::string& prefijo) {
    Nodo* nodoActual = raiz;
    for (char letra : prefijo) {
        if (nodoActual->hijos.count(letra) == 0) {
            return std::vector<std::string>();  // Devuelve un vector vacío
        }
        nodoActual = nodoActual->hijos[letra];
    }

    // Si llegamos aquí, el prefijo existe en el Trie
    std::vector<std::string> palabras;
    buscar_palabras(nodoActual, prefijo, palabras);
    return palabras;
}

void Trie::buscar_palabras(Nodo* nodo, const std::string& palabra, std::vector<std::string>& palabras) {
    if (nodo->es_final) {
        palabras.push_back(palabra);
    }

    for (auto& par : nodo->hijos) {
        buscar_palabras(par.second, palabra + par.first, palabras);
    }
}