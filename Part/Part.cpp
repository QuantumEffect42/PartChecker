#include "Part.hpp"

Part::Part(){
    cutoutCount = 0;
}

void Part::addCutout(std::shared_ptr<Cutout> cutout){
    cutouts.push_back(cutout);
    cutoutCount++;
}

int Part::getCutoutSize(){
    return this->cutoutCount;
}

Part::~Part(){

}