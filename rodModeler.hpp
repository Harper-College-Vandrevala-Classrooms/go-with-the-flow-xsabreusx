#pragma once
#include <iostream>
#include <vector>
using namespace std;

class HeatFlow {
private:
    vector<double> rod_;

    int lengthRod_ = 0;
    double K_ = 0;
    double Ti_ = 0;

    int numberSourcesSinks = 0;

public:

    HeatFlow() {};
    HeatFlow(int length, double kconstant, double temperature, int sinks) {
        setAttributes(length, kconstant, temperature, sinks);
    };


    void tick() {
        
        vector<double> updatedRod(returnVectorSize());  // Temporary vector to store new values

        for (int i = 0; i < returnVectorSize(); ++i) {
            if (i == 0) {
                
                updatedRod[i] = (293 + getVectorElement(i + 1)) / 2;
            }
            else if (i == returnVectorSize() - 1) {
                
                updatedRod[i] = (getVectorElement(i - 1) + 293) / 2;
            }
            else {
                
                updatedRod[i] = (getVectorElement(i - 1) + getVectorElement(i + 1)) / 2;
            }
        }

        // Update the original vector with new values
        setVector(updatedRod);
    }

    void setAttributes(int length, double kconstant, double temperature, int sinks) {
        lengthRod_ = length;
        K_ = kconstant;
        Ti_ = temperature;
        numberSourcesSinks = sinks;

    }

    void setVector(vector<double> v) {
        rod_.clear();
        for (double e : v) {
            rod_.push_back(e);
        }
    }

    void pretty_print() const {
        cout << "\n\n";
        for (double e : rod_) {
            cout << "|" << static_cast<int> (e) << "|";
        }
        cout << "\n\n";
    }

    double getVectorElement(int i) const {
        if (i >= 0 && i < rod_.size()) {
            return rod_[i];
        }
        return -1;
    }

    void setVectorElement(int i, double d)
    {
        rod_[i] = d;
    }

    int returnVectorSize() const {
        return rod_.size();
    }

    int returnRodLength() const {

    }
};


