#pragma once
#include <iostream>
#include <vector>
#include "materialClassRod.hpp"
using namespace std;

class rodModeler {
public:
    void tick(materialClassRod& rod) {
        
        vector<double> updatedRod(rod.returnVectorSize());  // Temporary vector to store new values

        for (int i = 0; i < rod.returnVectorSize(); ++i) {
            if (i == 0) {
                // First element: Use second element and treat before as 0
                updatedRod[i] = (293 + rod.getVectorElement(i + 1)) / 2;
            }
            else if (i == rod.returnVectorSize() - 1) {
                // Last element: Use second-to-last element and treat after as 0
                updatedRod[i] = (rod.getVectorElement(i - 1) + 293) / 2;
            }
            else {
                // Middle elements: Average of the previous and next elements
                updatedRod[i] = (rod.getVectorElement(i - 1) + rod.getVectorElement(i + 1)) / 2;
            }
        }

        // Update the original vector with new values
        rod.setVector(updatedRod);
    }
};


