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

/**
 * This function is responsible for comparing the current part to a template part.
 * It will check the cutout count, and then check the locations of the cutouts to ensure they are within spec
 * maxDeviation is the number of pixels out compared to the template the current part can be before being flagged
 */
bool Part::testInSpec(Part templatePart, int maxDeviation){

    return true;
}

/**
 * This function is responsible for combining the cutouts that have points that are adjacent to one another. 
 * This is to ensure that no frivilous cutouts remain in the part.
 * The function will have to go through each cutout and check for adjacent points in the other cutouts and combine
 * them if necessary
 */
void Part::coalesce(){

}

Part::~Part(){

}