#include <iostream>
#include <vector>
#include <memory>
#include "Cutout/Cutout.hpp"

class Part{

    public:
        Part();
        ~Part();
        void addCutout(std::shared_ptr<Cutout>);
        int getCutoutSize();
        bool testInSpec(Part, int);
        void coalesce();

    private:
        int cutoutCount;
        std::vector<std::shared_ptr<Cutout>> cutouts;
};