#include "trieInverso.h"

TrieInverso::TrieInverso() {
    raiz = new  Nodo('\0', 0);
}

TrieInverso::~TrieInverso() {
    delete raiz;// Implementar la eliminación de todos los nodos del Trie
}

int TrieInverso::calcular_puntaje(char letra) const
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

void TrieInverso::insertar(const std::string& palabra) {
    Nodo* nodoActual = raiz;
    for (auto it = palabra.rbegin(); it != palabra.rend(); ++it) {
        char letra = *it;
        int puntaje = calcular_puntaje(letra);  // Calcular el puntaje de la letra
        if (nodoActual->hijos.count(letra) == 0) {
            nodoActual->hijos[letra] = new Nodo(letra, puntaje);
        }
        nodoActual = nodoActual->hijos[letra];
        nodoActual->puntaje = puntaje;  // Agregar el puntaje a la puntuación total del nodo
    }
    nodoActual->es_final = true;
}

std::vector<std::string> TrieInverso::buscar_sufijo(const std::string& sufijo) {
    Nodo* nodoActual = raiz;
    for (auto it = sufijo.rbegin(); it != sufijo.rend(); ++it) {
        char letra = *it;
        if (nodoActual->hijos.count(letra) == 0) {
            return std::vector<std::string>();
        }
        nodoActual = nodoActual->hijos[letra];
    }
    std::vector<std::string> palabras;
    buscar_palabras(nodoActual, std::string(sufijo.rbegin(), sufijo.rend()), palabras);
    return palabras;
}

void TrieInverso::buscar_palabras(Nodo* nodo, const std::string& palabra, std::vector<std::string>& palabras) {
    if (nodo->es_final) {
        std::string palabra_invertida = std::string(palabra.rbegin(), palabra.rend());
        palabras.push_back(palabra_invertida);
    }
    for (auto& par : nodo->hijos) {
        buscar_palabras(par.second, palabra + par.first, palabras);
    }
}


bool TrieInverso::existe(const std::string& palabra) const {
    Nodo* nodoActual = raiz;
    for (char letra : std::string(palabra.rbegin(), palabra.rend())) {
        if (nodoActual->hijos.count(letra) == 0) {
            return false;
        }
        nodoActual = nodoActual->hijos[letra];
    }
    return nodoActual->es_final;
}

int TrieInverso::obtener_puntaje(const std::string& palabra) const {
    if (!existe(palabra)) {
        return -1;
    }
    Nodo* nodoActual = raiz;
    int puntaje = 0;
    for (char letra : std::string(palabra.rbegin(), palabra.rend())) {
        nodoActual = nodoActual->hijos[letra];
        puntaje += nodoActual->puntaje;
    }
    return puntaje;
}