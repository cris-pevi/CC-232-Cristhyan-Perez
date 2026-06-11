#include "treap.h"

static void destroy(TreapNode* node) {
    if (node == nullptr) return;
    destroy(node->left);
    destroy(node->right);
    delete node;
}

static TreapNode* merge(TreapNode* a, TreapNode* b) {
    if (a == nullptr) return b;
    if (b == nullptr) return a;

    if (a->priority > b->priority) {
        a->right = merge(a->right, b);
        return a;
    } else {
        b->left = merge(a, b->left);
        return b;
    }
}

static void split(TreapNode* node, int key, TreapNode*& left, TreapNode*& right) {
    if (node == nullptr) {
        left = nullptr;
        right = nullptr;
        return;
    }

    if (node->key <= key) {
        split(node->right, key, node->right, right);
        left = node;
    } else {
        split(node->left, key, left, node->left);
        right = node;
    }
}

Treap::Treap() : root(nullptr) {}

Treap::~Treap() {
    destroy(root);
}

void Treap::insert(int key) {
    TreapNode* left = nullptr;
    TreapNode* right = nullptr;
    split(root, key, left, right);

    TreapNode* nuevoNodo = new TreapNode(key);

    root = merge(merge(left, nuevoNodo), right);
}

void Treap::erase(int key) {
    TreapNode* left = nullptr;
    TreapNode* restante = nullptr;
    TreapNode* aBorrar = nullptr;
    TreapNode* right = nullptr;

    split(root, key - 1, left, restante);
    split(restante, key, aBorrar, right);

    delete aBorrar;

    root = merge(left, right);
}

int Treap::successor(int key) {
    TreapNode* left = nullptr;
    TreapNode* right = nullptr;
    split(root, key, left, right);

    int resultado = -1;
    if (right != nullptr) {
        TreapNode* actual = right;
        while (actual->left != nullptr) {
            actual = actual->left;
        }
        resultado = actual->key;
    }

    root = merge(left, right);
    return resultado;
}