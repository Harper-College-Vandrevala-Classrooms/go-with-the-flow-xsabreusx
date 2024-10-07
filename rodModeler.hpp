#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

class HeatFlow {
private:
    vector<double> rod_;

    int lengthRod_ = 0; //Only used when the specific constructor is employed.
    double K_ = 0.03;
    double Ti_ = 0;
    double medium_ = 273;
    int sources_sinks_ = 0;

    vector <int> tempV;                 // These variables allow for managing the sinks and sources. 
    vector <double> sinkSourceV;
    double tempSinkSource=0;
    int vPositions=0;

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
        // This algorithm obtains the new values of the vector and properly applies sinks and sources if needed.
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

            if (sources_sinks_ != 0) // Applies sinks and sources at the end of each tick, thereby remaining constant.
            {
                for (int i = 0; i < sources_sinks_; i++)
                {
                    updatedRod[tempV[i]-1] = sinkSourceV[i];
                }
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


    void pretty_print() const { // Upgraded pretty_print!
        
        int max_width = 0;
        // Convert number to string and find its length
        for (double e : rod_) {
            int num_width = to_string(static_cast<int>(e)).length();
            max_width = max(max_width, num_width);
        }

        // Add some padding 
        max_width += 2; 

        // Top border
        cout << "\n" << string((max_width + 3) * rod_.size(), '=') << "\n";
        cout << "| ";

        // Removing the decimals for neatness 
        for (double e : rod_) {
            cout << setw(max_width) << static_cast<int>(e) << " | ";
        }

        // Bottom border
        cout << "\n" << string((max_width + 3) * rod_.size(), '=') << "\n";
    }

    void test_print() const {           // For doing start up tests
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

    void setSinks(int s) {
        sources_sinks_ = s;
    }

    void ObtainandApplySinksandSources() {  // This function is called in order to set up sinks and sources of heat in the rod

        if (sources_sinks_ == 0)
        {
            cout << "No sinks or sources specified.";
        }
        else if (rod_.size() - 1 <= sources_sinks_)
        {
            sources_sinks_ = rod_.size() - 1; // Obtains sinks and sources positions in the rod
            cout << "\nSinks and sources adjusted to accomodate length of rod. \nSpecify a rod section that has a sink or source: ";
            for (int i = 0; i < sources_sinks_; i++) {
                cin >> vPositions;
                while (cin.fail() || vPositions <= 0 || vPositions > rod_.size() - 1) {
                    cin.clear();
                    cin.ignore();
                    cout << "\nInvalid input. Please try again: ";
                    cin >> vPositions;
                }
                tempV.push_back(vPositions);
            }
            // Obtains values for the sinks and sources
            cout << "\nSpecify the Temperature values of sources or sinks in the order entered one at a time: ";
            for (int i = 0; i < sources_sinks_; i++) {
                cin >> tempSinkSource;
                while (cin.fail() || tempSinkSource < 0) {
                    cin.clear();
                    cin.ignore();
                    cout << "\nInvalid input. Please try again: ";
                    cin >> tempSinkSource;
                }
                sinkSourceV.push_back(tempSinkSource);
            }

            // This for loop inputs the sinks and sources into the rod vector
            for (int i = 0; i < sources_sinks_; i++)
            {
                rod_[tempV[i]-1] = sinkSourceV[i];
            }

        }
        // Obtains sinks and sources positions in the rod also
        else {
            cout << "\nSpecify a rod section that has a sink or source. ";
            for (int i = 0; i < sources_sinks_; i++) {
                cout << "\nAwaiting sink position input: ";
                cin >> vPositions;
                while (cin.fail() || vPositions <= 0 || vPositions > rod_.size() - 1) {
                    cin.clear();
                    cin.ignore();
                    cout << "\nInvalid input. Please try again: ";
                    cin >> vPositions;
                }
                tempV.push_back(vPositions);
            }
            // Obtains values for the sinks and sources
            cout << "\nSpecify the Temperature values of sources or sinks in the order entered one at a time.";
            for (int i = 0; i < sources_sinks_; i++) {
                cout << "\nAwaiting sink Temperature input: ";
                cin >> tempSinkSource;
                while (cin.fail() || tempSinkSource < 0) {
                    cin.clear();
                    cin.ignore();
                    cout << "\nInvalid input. Please try again: ";
                    cin >> tempSinkSource;
                }
                sinkSourceV.push_back(tempSinkSource);
            }

            // This for loop inputs the sinks and sources into the rod vector
            for (int i = 0; i < sources_sinks_; i++)
            {
                rod_[tempV[i]-1] = sinkSourceV[i];
            }
        }

    }
};


