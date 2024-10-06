#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class HeatFlow {
private:
    vector<double> rod_;

    int lengthRod_ = 0; //Only used when the specific constructor is employed.
    double K_ = 0.01;
    double Ti_ = 0;
    double medium_ = 273;
    int sources_sinks_ = 0;

public:

    HeatFlow() {}; // A constructor that doesn't need anything.

    HeatFlow(int length, double kconstant, double temperature, int sinks) {
        // This constructor needs specific parameters passed to it.
        setAttributes(length, kconstant, temperature, sinks);

        for (int i = 0; i < lengthRod_; i++) {
            rod_.push_back(Ti_);
        }
    };


    void tick() {

        vector<double> updatedRod(getVectorSize());  // Temporary vector to store new values

        for (int i = 0; i < getVectorSize(); ++i) {
            if (i == 0) {

                updatedRod[i] = (getVectorElement(i) + K_ * (getVectorElement(i + 1) - 2 * getVectorElement(i) + medium_));
            }
            else if (i == getVectorSize() - 1) {

                updatedRod[i] = (getVectorElement(i) + K_ * (medium_ - (2 * getVectorElement(i)) + getVectorElement(i - 1)));
            }
            else {

                updatedRod[i] = (getVectorElement(i) + K_ * (getVectorElement(i + 1) - 2 * getVectorElement(i) + getVectorElement(i - 1)));
            }
        }

        // Update the original vector with new values
        setVector(updatedRod);
    }

    void setAttributes(int length, double kconstant, double temperature, int sinks) {
        lengthRod_ = length;
        K_ = kconstant;
        Ti_ = temperature;
        sources_sinks_ = sinks;

    }

    void setVector(vector<double> v) {
        rod_.clear();
        for (double e : v) {
            rod_.push_back(e);
        }
    }

    void pretty_print() const {
        cout << "\n\n| ";
        for (double e : rod_) {
            //cout << "|" << static_cast<int> (e) << "|";
            cout << e << " | ";
        }
        cout << "\n\n";
    }

    void test_print() const {           // For doing start up tests.
        cout << "\nVector Values: ";
        for (double e : rod_) {
            cout << e << " ";
        }
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

    int getVectorSize() const {
        return rod_.size();
    }

    int returnRodLength() const {
        return lengthRod_;
    }

    void setMediumTemperature(double t) {
        medium_ = t;
    }

    double getK() const {
        return K_;
    }

    double getTi() const {
        return Ti_;
    }

    double getMedium() const {
        return medium_;
    }

    int getSinks() const {
        return sources_sinks_;
    }

    void applySinksandSources() {  // This function is called in order to set up sinks and sources of heat in the rod.

        vector <int> tempV;
        double tempSinkSource;
        int vPositions;

        if (sources_sinks_ == 0)
        {
            cout << "No sinks or sources specified.";
        }
        else if (rod_.size() - 1 <= sources_sinks_)
        {
            sources_sinks_ = rod_.size() - 1;
            cout << "\nSpecify rod section(s) that has sink or source: ";
            for (int i = 0; i < sources_sinks_; i++) {
                cin >> vPositions;
                while (cin.fail() || vPositions < 0 || vPositions > rod_.size() - 1) {
                    cin.clear();
                    cin.ignore();
                    cout << "\nInvalid input. Please try again: ";
                    cin >> vPositions;
                }
                tempV.push_back(vPositions);
            }

        }
        else {
            cout << "\nSpecify rod section(s) that has sink or source: ";
            for (int i = 0; i < sources_sinks_; i++) {
                cin >> vPositions;
                while (cin.fail() || vPositions < 0 || vPositions > rod_.size() - 1) {
                    cin.clear();
                    cin.ignore();
                    cout << "\nInvalid input. Please try again: ";
                    cin >> vPositions;
                }
                tempV.push_back(vPositions);
            }
        }


    }
};


