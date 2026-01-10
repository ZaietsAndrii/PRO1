#include <iostream>
using namespace std;

void info_sequencia(int& suma, int& ultim){
    int c;
    cin >> c;
    while (c != 0)
    {
        suma += c;
        ultim = c;
        cin >> c;
    }
    
}

int main(){
    int suma1 = 0, ultim1 = 0, c = 0, cmt = 1;
    info_sequencia(suma1, ultim1);
    cin >> c;
    while (c != 0)
    {
        int suma2 = c, ultim2 = c;
        info_sequencia(suma2, ultim2);
        if (suma2 == suma1 && ultim2 == ultim1) cmt += 1;
        
        cin >> c;
    }
    cout << cmt << endl;
}