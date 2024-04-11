#ifndef TRIE_H
#define TRIE_H

#include "nodo.h"

class Trie {
private:
    Nodo* raiz;
    int calcular_puntaje(char letra) const;

public:
    Trie();
    ~Trie();
    void insertar(const std::string& palabra);
    bool buscar(const std::string& palabra) const;
    int obtener_puntaje(const std::string& palabra) const;
    std::vector<std::string> buscar_prefijo(const std::string& prefijo);
    void buscar_palabras(Nodo* nodo, const std::string& palabra, std::vector<std::string>& palabras);
};

#endif 