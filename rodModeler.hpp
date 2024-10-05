#pragma once
#include <iostream>
#include <vector>
#include "materialClassRod.hpp"
using namespace std;

class HeatFlow {
public:

    HeatFlow() {};
    HeatFlow(materialClassRod name, int length, double kconstant, double temperature, int sinks) {
        name.setAttributes(length, kconstant, temperature, sinks);
    };


    void tick(materialClassRod& rod) {
        
        vector<double> updatedRod(rod.returnVectorSize());  // Temporary vector to store new values

        for (int i = 0; i < rod.returnVectorSize(); ++i) {
            if (i == 0) {
                
                updatedRod[i] = (293 + rod.getVectorElement(i + 1)) / 2;
            }
            else if (i == rod.returnVectorSize() - 1) {
                
                updatedRod[i] = (rod.getVectorElement(i - 1) + 293) / 2;
            }
            else {
                
                updatedRod[i] = (rod.getVectorElement(i - 1) + rod.getVectorElement(i + 1)) / 2;
            }
        }

        // Update the original vector with new values
        rod.setVector(updatedRod);
    }
};


