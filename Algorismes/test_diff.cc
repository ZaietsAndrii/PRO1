#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

vector<double> difference(const vector<double>& v1, const vector<double>& v2);
vector<double> difference(const vector<double>& v1, const vector<double>& v2, double eps);

void print(const vector<double>& v){
    cout << "{";
    cout << setprecision(17);
    for (size_t i = 0; i < v.size(); ++i){
        if (i) cout << ", ";
        cout << v[i];
    }
    cout << "}" << endl;
}

int main(){
    vector<double> a{1,2,2,5,5,7};
    vector<double> b{2,3,3,7};
    auto r = difference(a,b);
    cout << "Test1: "; print(r); // expect {1, 5}

    vector<double> c; vector<double> d;
    cout << "Test2 (both empty): "; print(difference(c,d)); // {}

    vector<double> e{1,1,1}; vector<double> f;
    cout << "Test3 (v2 empty): "; print(difference(e,f)); // {1}

    vector<double> g; vector<double> h{1,2,3};
    cout << "Test4 (v1 empty): "; print(difference(g,h)); // {}

    vector<double> i{1,2,3,4}; vector<double> j{0,2,4,6};
    cout << "Test5 (mixed): "; print(difference(i,j)); // {1,3}

    // --- Floating-point tolerance tests ---
    vector<double> x{0.1 + 0.2}; // not exactly 0.3 in binary floating point
    vector<double> y{0.3};
    cout << "FP exact (difference): "; print(difference(x,y));
    cout << "FP tolerant (eps=1e-9): "; print(difference(x,y,1e-9)); // expected empty

    vector<double> u{1.000000001, 1.000000002};
    vector<double> v{1.000000000};
    cout << "Duplicates exact: "; print(difference(u,v));
    cout << "Duplicates tolerant (eps=1e-8): "; print(difference(u,v,1e-8)); // expected empty
    cout << "Duplicates tolerant small eps (1e-12): "; print(difference(u,v,1e-12)); // expected same as exact

    return 0;
}
