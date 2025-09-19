#ifndef Cutout_HPP
#define Cutout_HPP

#include <iostream>
#include <vector>
#include <tuple>
#include <string>

class Cutout {
    public:
        Cutout();
        ~Cutout();
        void addPointToEdge(int x, int y);
        void toString();
        bool isFlagged();

        std::vector<std::tuple<int, int>> getEdgePoints();

    private:
        std::vector<std::tuple<int, int>> edgePoints;
        bool flagged;
};

#endif