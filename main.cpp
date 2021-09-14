#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    setlocale(LC_CTYPE,"Russian");
    double t;
    double P = 0.;
    std::vector<double> x = {-1., 0., 1., 2., 3., 4.};
    std::vector<double> y = {1., 0., 1., 4., 9., 16.};
    std::vector<double> L(x.size(), 1);
    cin >> t;
    if((x[0] > t) or (x.back() < t)) {
        cout << "@@@Tb";
        return -1;
    }
    for(int i = 0;i < x.size();i++){
        if(x[i] == t) {
            cout << y[i];
            return -1;
        }
        else continue;
    }
    for(int k = 0;k < x.size();k++){
        for(int i =0;i < x.size();i++){
            if(i != k) {
                L[k] = (t - x[i])/(x[k] - x[i])*L[k];
            }
        }
        P += L[k]*y[k];
    }
    cout << P;
}
