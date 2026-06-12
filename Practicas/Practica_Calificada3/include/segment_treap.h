#pragma once
#include <vector>
#include "treap.h"

class SegmentTreap {
public:
    SegmentTreap(int n);
    ~SegmentTreap();

    void insertar(int idx, int y);
    void borrar(int idx, int y);
    int consultar(int idx_min, int y);

private:
    int tamano;
    std::vector<Treap*> nodos;

    void construir(int nodo, int inicio, int fin);
    void insertarRec(int nodo, int inicio, int fin, int idx, int y);
    void borrarRec(int nodo, int inicio, int fin, int idx, int y);
    int consultarRec(int nodo, int inicio, int fin, int idx_min, int y);
};