#include "solution.h"
#include <algorithm>

void PointsIngenua::add(int x , int y){
    pointsAvailable.push_back(Point{x,y});
}

void PointsIngenua::remove(int x, int y){
    for (auto it = pointsAvailable.begin(); it != pointsAvailable.end(); it++){
        if (it->x == x && it->y == y){
            pointsAvailable.erase(it);
            return;
        }
    }
}

Point PointsIngenua::find(int x, int y){
    Point best = Point{-1, -1};

    for (auto it = pointsAvailable.begin(); it != pointsAvailable.end(); it++){
        if (it->x > x && it->y > y){
            if (best.x == -1 || it->x < best.x || (it->x == best.x && it->y < best.y)){
                best = Point{it->x, it->y};
            }
        } 
    }
    return best;
}

PointsEficiente::PointsEficiente(const std::vector<int>& xsDelInput) {
    xsOrdenadas = xsDelInput;
    std::sort(xsOrdenadas.begin(), xsOrdenadas.end());
    xsOrdenadas.erase(std::unique(xsOrdenadas.begin(), xsOrdenadas.end()), xsOrdenadas.end());

    segTree = new SegmentTreap(xsOrdenadas.size());
    treapsPorX.resize(xsOrdenadas.size());
}

PointsEficiente::~PointsEficiente() {
    delete segTree;
}

int PointsEficiente::comprimir(int x) {
    auto it = std::lower_bound(xsOrdenadas.begin(), xsOrdenadas.end(), x);
    return it - xsOrdenadas.begin();
}

void PointsEficiente::add(int x, int y) {
    int idx = comprimir(x);
    segTree->insertar(idx, y);
    treapsPorX[idx].insert(y);
}

void PointsEficiente::remove(int x, int y) {
    int idx = comprimir(x);
    segTree->borrar(idx, y);
    treapsPorX[idx].erase(y);
}

Point PointsEficiente::find(int x, int y) {
    int idxConsulta = comprimir(x);

    int idxRespuesta = segTree->consultar(idxConsulta, y);

    if (idxRespuesta == -1) {
        return Point{-1, -1};
    }

    int xRespuesta = xsOrdenadas[idxRespuesta];
    int yRespuesta = treapsPorX[idxRespuesta].successor(y);

    return Point{xRespuesta, yRespuesta};
}