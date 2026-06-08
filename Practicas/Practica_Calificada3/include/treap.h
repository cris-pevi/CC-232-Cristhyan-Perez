#pragma once
#include <cstdlib>

struct TreapNode {
    int key;
    int priority;
    TreapNode* left;
    TreapNode* right;

    TreapNode(int k) : key(k), priority(rand()), left(nullptr), right(nullptr) {}
};

class Treap {
    public:
        Treap();
        ~Treap();

        void insert(int key);
        void erase(int key);
        int successor(int key);

    private:
        TreapNode* root;
};

