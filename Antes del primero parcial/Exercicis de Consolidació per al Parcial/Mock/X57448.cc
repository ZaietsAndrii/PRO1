#include <iostream>
using namespace std;

int main(){
    int repetA = 0, repetC = 0, repetG = 0, repetT = 0;
    int maxRepetA = 0, maxRepetC = 0, maxRepetG = 0, maxRepetT = 0;
    int posA = 0, posC = 0, posG = 0, posT = 0;
    char c;
    int index = 0;

    // Это отвратительно, от меня просять код с огромным количеством условий который не предоставляет особой сложности, но милион if else эту сложность создают
    while (cin >> c)
    {
        if (c == '.'){            
            cout << "\"A\" = " << maxRepetA <<  "(" << posA + (maxRepetA > 0 ? 1 : 0) - maxRepetA << "), "
                << "\"C\" = " << maxRepetC <<  "(" << posC + (maxRepetC > 0 ? 1 : 0) - maxRepetC << "), "
                << "\"G\" = " << maxRepetG <<  "(" << posG + (maxRepetG > 0 ? 1 : 0) - maxRepetG << "), "
                << "\"T\" = " << maxRepetT <<  "(" << posT + (maxRepetT > 0 ? 1 : 0) - maxRepetT << ")" << endl;
            repetA = 0;
            repetC = 0;
            repetG = 0;
            repetT = 0;
            maxRepetA = 0;
            maxRepetC = 0;
            maxRepetG = 0;
            maxRepetT = 0;
            posA = 0;
            posC = 0;
            posG = 0;
            posT = 0;
            index  = 0;
        }
        else{
            index += 1;
            if (c == 'A')
            {
                repetA += 1;
                repetC = 0;
                repetG = 0;
                repetT = 0;
                if (repetA > maxRepetA)
                {
                    maxRepetA = repetA;
                    posA = index;
                }
            }
            else if(c == 'C'){
                repetC += 1;
                repetA = 0;
                repetG = 0;
                repetT = 0;
                if (repetC > maxRepetC)
                {
                    maxRepetC = repetC;
                    posC = index;
                }
                
            }
            else if(c == 'G'){
                repetG += 1;
                repetA = 0;
                repetC = 0;
                repetT = 0;
                if (repetG > maxRepetG)
                {
                    maxRepetG = repetG;
                    posG = index;
                }
            }
            else if(c == 'T'){
                repetT += 1;
                repetA = 0;
                repetC = 0;
                repetG = 0;
                if (repetT > maxRepetT)
                {
                    maxRepetT = repetT;
                    posT = index;
                }
            }
        }
    }
}