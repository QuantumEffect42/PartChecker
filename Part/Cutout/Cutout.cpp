#include "Cutout.hpp"

Cutout::Cutout(){
    flagged = false;
}

void Cutout::addPointToEdge(int x, int y){
    std::tuple point = std::make_tuple(x, y);
    edgePoints.push_back(point);
}

void Cutout::toString(){
    std::cout << "edgePoints: ";

    for(int i = 0; i < edgePoints.size(); i++){
        std::cout << "(" << std::get<0>(edgePoints[i]) << ", " << std::get<1>(edgePoints[i]) << "), ";
    }

    std::cout << std::endl;
}

std::vector<std::tuple<int, int>> Cutout::getEdgePoints(){
    return this->edgePoints;
}

/**
 * This function is to check if a cutout has been flagged for being out of spec or not.
 * Will return true if the part is out of spec, false otherwise
 */
bool Cutout::isFlagged(){
    return flagged;
}

Cutout::~Cutout(){
    
}