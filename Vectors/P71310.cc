#include <iostream>
#include <vector>
using namespace std;

double scalar_product(const vector<double>& u, const vector<double>& v){
    double result = 0;
    for (int i = 0; i < u.size(); i++)
    {
        result += u[i]*v[i];
    }
    return result;
}