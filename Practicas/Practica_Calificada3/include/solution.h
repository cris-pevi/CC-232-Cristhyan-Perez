#pragma once
#include "segment_treap.h"
#include "treap.h"
#include <vector>

struct Point {
    int x;
    int y;
};

class PointsIngenua {
    public:
        void add(int x, int y);
        void remove(int x, int y);
        Point find(int x, int y);
    private:
        std::vector<Point> pointsAvailable;
};

class PointsEficiente {
public:
    PointsEficiente(const std::vector<int>& xsDelInput);
    ~PointsEficiente();

    void add(int x, int y);
    void remove(int x, int y);
    Point find(int x, int y);

private:
    SegmentTreap* segTree;
    std::vector<int> xsOrdenadas;
    std::vector<Treap> treapsPorX;

    int comprimir(int x);
};