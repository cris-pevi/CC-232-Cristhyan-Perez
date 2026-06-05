#pragma once
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