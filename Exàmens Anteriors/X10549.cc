#include <iostream>
#include <string>

using namespace std;

int elimina_ceros(int x) {
    if(x > 0){
        int remainder = x % 10;
        x /= 10;
        if(remainder == 0) return elimina_ceros(x);
        else return elimina_ceros(x) * 10 + remainder;
    }
    return 0;
}

int main(){
    int n;
    while (cin >> n)
    {
        cout << elimina_ceros(n) << endl;
    }
}