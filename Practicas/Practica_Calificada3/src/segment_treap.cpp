#include "segment_treap.h"

SegmentTreap::SegmentTreap(int n) : tamano(n), nodos(4 * n, nullptr) {
    construir(1, 0, n - 1);
}

void SegmentTreap::construir(int nodo, int inicio, int fin) {
    nodos[nodo] = new Treap();

    if (inicio == fin) {
        return;
    }

    int medio = (inicio + fin) / 2;
    construir(2 * nodo, inicio, medio);
    construir(2 * nodo + 1, medio + 1, fin);
}

SegmentTreap::~SegmentTreap() {
    for (size_t i = 0; i < nodos.size(); i++) {
        if (nodos[i] != nullptr) {
            delete nodos[i];
        }
    }
}