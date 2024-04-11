#ifndef NODO_H
#define NODO_H

#include <unordered_map>

class Nodo {
public:
    char letra;
    std::unordered_map<char, Nodo*> hijos; 
    int puntaje;
    bool es_final;

    Nodo(char letra, int puntaje);
};

#endif