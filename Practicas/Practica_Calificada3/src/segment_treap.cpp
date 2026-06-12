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

void SegmentTreap::insertar(int idx, int y) {
    insertarRec(1, 0, tamano - 1, idx, y);
}

void SegmentTreap::insertarRec(int nodo, int inicio, int fin, int idx, int y) {
    nodos[nodo]->insert(y);

    if (inicio == fin) {
        return;
    }

    int medio = (inicio + fin) / 2;
    if (idx <= medio) {
        insertarRec(2 * nodo, inicio, medio, idx, y);
    } else {
        insertarRec(2 * nodo + 1, medio + 1, fin, idx, y);
    }
}

void SegmentTreap::borrar(int idx, int y) {
    borrarRec(1, 0, tamano - 1, idx, y);
}

void SegmentTreap::borrarRec(int nodo, int inicio, int fin, int idx, int y) {
    nodos[nodo]->erase(y);

    if (inicio == fin) {
        return;
    }

    int medio = (inicio + fin) / 2;
    if (idx <= medio) {
        borrarRec(2 * nodo, inicio, medio, idx, y);
    } else {
        borrarRec(2 * nodo + 1, medio + 1, fin, idx, y);
    }
}

int SegmentTreap::consultar(int idx_min, int y) {
    return consultarRec(1, 0, tamano - 1, idx_min, y);
}

int SegmentTreap::consultarRec(int nodo, int inicio, int fin, int idx_min, int y) {
    if (fin <= idx_min) {
        return -1;
    }

    if (nodos[nodo]->successor(y) == -1) {
        return -1;
    }

    if (inicio == fin) {
        return inicio;
    }

    int medio = (inicio + fin) / 2;

    int respuestaIzq = consultarRec(2 * nodo, inicio, medio, idx_min, y);
    if (respuestaIzq != -1) {
        return respuestaIzq;
    }

    return consultarRec(2 * nodo + 1, medio + 1, fin, idx_min, y);
}