#ifndef DICCIONARIO_H
#define DICCIONARIO_H

#include <string>
#include <unordered_map>
#include "trie.h"
#include "trieInverso.h"

class Diccionario {
private:
    Trie trie;
    TrieInverso trieInverso;

public:
    Diccionario();
    ~Diccionario();
    bool cargar_diccionario(const std::string& archivo);  // Cambiado de void a bool
    bool cargar_diccionarioInverso(const std::string& archivo);
    bool existe_palabra(const std::string& palabra) const;
    int obtener_puntaje(const std::string& palabra) const;
    int obtener_puntajeInverso(const std::string& palabra) const;
    std::vector<std::string> buscar_prefijo(const std::string& prefijo);
    std::vector<std::string> buscar_sufijo(const std::string& sufijo);
};

#endif