#pragma once
#include <vector>
#include <iostream>
using namespace std;


class materialClassRod {
private:
    vector<double> rod_;
    friend class rodModeler;
    
    int lengthRod_ = 0;
    double K_ = 0;
    double Ti_ = 0;
    
    int numberSourcesSinks = 0;


public:

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

    void showVector() const {
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

    int returnRodLength() const{

    }
};

