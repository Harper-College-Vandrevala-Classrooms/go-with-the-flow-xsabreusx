#pragma once
#include <vector>
#include <iostream>
using namespace std;


class materialClassRod {
private:
    vector<double> rod_;
    friend class rodModeler;

public:
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
        return -1;  // Handle invalid index
    }

    int returnVectorSize() const {
        return rod_.size();
    }
};

