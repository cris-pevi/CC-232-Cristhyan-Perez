#include "solution.h"

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