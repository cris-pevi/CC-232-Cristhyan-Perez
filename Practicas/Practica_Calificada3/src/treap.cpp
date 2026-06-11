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