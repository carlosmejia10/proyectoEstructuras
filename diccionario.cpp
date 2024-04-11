#include "diccionario.h"
#include <fstream>
#include <vector> // Include the necessary header file

Diccionario::Diccionario() {}


Diccionario::~Diccionario() {}

int Diccionario::obtener_puntaje(const std::string& palabra) const {
    return trie.obtener_puntaje(palabra);
}

int Diccionario::obtener_puntajeInverso(const std::string& palabra) const {
    return trieInverso.obtener_puntaje(palabra);
}

bool Diccionario::cargar_diccionario(const std::string& archivo) {
    std::ifstream archivo_dicc(archivo);
    if (!archivo_dicc) {
        return false;  // Devuelve false si no se pudo abrir el archivo
    }

    std::string palabra;
    while (archivo_dicc >> palabra) {
        trie.insertar(palabra);
    }

    return true;  // Devuelve true si la carga del diccionario fue exitosa
}

bool Diccionario::cargar_diccionarioInverso(const std::string& archivo) {
    std::ifstream archivo_dicc(archivo);
    if (!archivo_dicc) {
        return false;  // Devuelve false si no se pudo abrir el archivo
    }

    std::string palabra;
    while (archivo_dicc >> palabra) {
        trieInverso.insertar(palabra);
    }

    return true;  // Devuelve true si la carga del diccionario fue exitosa
}

std::vector<std::string> Diccionario::buscar_sufijo(const std::string& sufijo) {
    return trieInverso.buscar_sufijo(sufijo);
}

std::vector<std::string> Diccionario::buscar_prefijo(const std::string& prefijo)  {
    return trie.buscar_prefijo(prefijo);
}
