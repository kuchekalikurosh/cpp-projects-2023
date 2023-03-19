#include <iostream>
#include <cmath>

using namespace std;

class ResonantCircut {
    public:  
        
        ResonantCircut() {
        k = 0;
        B = 0;
        wo = 0;
        }

        void setK(int n) {
            k = n;
        }

        void setB(int n) {
            B = n;
        }

        void setWO(int n) {
            wo = n;
        }

        void display() {
            cout << k << B << wo;
        }

    protected:
        double k;
        double B;
        double wo;
};

class SeriesResonantCircut: public ResonantCircut {
    public:
        double R;
        double C;
        double L;

        void calculate() {
            R = (1.0/k);
            L = (R/B);
            C = 1.0/((wo*wo)*L);
        }

        void display() {
            cout << "Series Resonant Circut\n" << " R = " << R << " L = " << L << " C = " << C << "\n\n";
        }
        
};

class ParallelResonantCircut: public ResonantCircut {
    public:
        double R;
        double C;
        double L;

        void calculate() {
            R = k;
            C = 1.0/(B*R);
            L = 1.0/((wo*wo)*C);
        }
        
        void display() {
            cout << "Parallel Resonant Circut\n" << " R = " << R << " L = " << L << " C = " << C << "\n\n";
        }
};

int main() {
    SeriesResonantCircut circut1;
    ParallelResonantCircut circut2;
    
    circut1.setB(2.0);
    circut1.setK(2.0);
    circut1.setWO(2.0);

    circut1.calculate();
    circut1.display();

    circut2.setB(2.0);
    circut2.setK(2.0);
    circut2.setWO(2.0);

    circut2.calculate();
    circut2.display();
}