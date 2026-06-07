#include <iostream>
using namespace std;

char base64_to_char(int d){
    if (d >= 0 && d <= 25) return 65 + d;
    else if (d >= 26 && d <= 51) return 71 + d;
    else if (d >= 52 && d <= 61) return d - 4;
    else if (d == 62) return '+';
    else return '/';
}