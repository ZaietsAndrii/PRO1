#include <iostream>
#include <algorithm>
using namespace std;

int char_to_base64(char c) {
    static char _syms[65] =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz"
        "0123456789+/";
    return std::find(_syms, _syms + 64, c) - _syms;
}

int main(){
    char c1, c2, c3, c4, c;
    int d1, d2, d3, d4;
    int b1, b2, b3;
    bool existsInput = true;
    while (cin >> c)
    {
        if (c == '.') {
            cout << endl;
            if (cin >> c1 >> c2 >> c3 >> c4) existsInput = true;
            else existsInput = false;           
        }
        else {
            c1 = c;
            cin >> c2 >> c3 >> c4;
        }

        if (existsInput){
            unsigned long long x = 0;
            d1 = char_to_base64(c1);
            d2 = char_to_base64(c2);
            d3 = char_to_base64(c3);
            d4 = char_to_base64(c4);    
            if (c3 == '=' && c4 == '=') {
                d3 = 0; 
                d4 = 0;
            }
            else if (c4 == '=') d4 = 0;
            
            x = ((d1 * 64 + d2) * 64 + d3) * 64 + d4;
            b3 = x % 256; x /= 256;
            b2 = x % 256; x /= 256;
            b1 = x % 256;
            
            if (c3 == '=' && c4 == '=') cout << " " << b1;
            else if (c4 == '=') cout << " " << b1 << " " << b2;
            else cout << " " << b1 << " " << b2 << " " << b3;
        }
    }
    
    
}

