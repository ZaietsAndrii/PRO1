#include <iostream>
using namespace std;

struct OpNumSequence{
   string Operation;
   int n;
   int d;
};

int getGCD(int n, int d){
    if (n < 0) n = -n;
    if (d < 0) d = -d;

    while (d != 0) {
        int temp = d;
        d = n % d;
        n = temp;
    }
    return n;
}

int main(){
    OpNumSequence seq;
    char c;
    double r;
    int gcd;

    cin >> seq.n >> seq.d;

    if (seq.d < 0) {
        seq.n = -seq.n;
        seq.d = -seq.d;
    }
    gcd = getGCD(seq.n, seq.d);
    seq.n = seq.n / gcd;
    seq.d = seq.d / gcd;


    

    while (cin >> seq.Operation >> seq.n >> seq.d)
    {
        if (seq.Operation == "divide")
        {
            r = seq.n / seq.d;
        }
        else if (seq.Operation == "add")
        {
            r = seq.n + seq.d;
        }
        else if (seq.Operation == "multiply")
        {
            r = seq.n * seq.d;
        }
        else
        {
            r = seq.n - seq.d;
        }
        return;
    }
    
        cout << r;
}