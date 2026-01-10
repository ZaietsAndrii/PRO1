#include <iostream>
using namespace std;

char opositeOperation(char operation){
    if (operation == '+') return '-';
    else return '+'; 
}
int executeOperation(char operation, int a, int b){
    if(operation == '+') return a + b;
    else return a - b;
}
int charToInt(char numberChar){
    return numberChar - '0';
}

int main() {
    int a, b, r;
    char operation, equal, aChar, bChar, rChar;
    while (cin >> aChar >> operation >> bChar >> equal >> rChar)
    {
        if (rChar == 'x')
        {
            a = charToInt(aChar);
            b = charToInt(bChar);
            cout << executeOperation(operation, a, b) << endl;
        }
        else if (aChar == 'x')
        {
            r = charToInt(rChar);
            b = charToInt(bChar);
            cout << executeOperation(opositeOperation(operation), r, b) << endl;
        }
        else{
            r = charToInt(rChar);
            a = charToInt(aChar);
            cout << executeOperation(opositeOperation(operation), r, a) << endl;
        } 
        
    }
    
}