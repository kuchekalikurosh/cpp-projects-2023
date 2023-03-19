#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class AssociativeArray {
    
    public:
        map<string, double> jimmy;
        double& operator[] (string key) {
            for(auto i = jimmy.begin(); i!=jimmy.end(); i++) {
                if(key.compare(i->first) == 0) {
                    return i-> second;
                }
            }
            jimmy[key] = 0.0;
            auto x = jimmy.find(key);

            return x->second;
        }
};

int main() {
    AssociativeArray prices;

    prices["Toaster Oven"] = 19.95;
    prices["Car Vacuum"] = 24.95;

    cout << "Toaster Oven: " << prices["Toaster Oven"] << endl;
    cout << "Car Vacuum: " << prices["Car Vacuum"] << endl;
}