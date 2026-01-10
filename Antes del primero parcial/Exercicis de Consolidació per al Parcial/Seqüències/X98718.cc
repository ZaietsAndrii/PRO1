#include <iostream>
using namespace std;

int main () {
    char x,y,z;
    int pos=0;
    int aaa=0,aab=0,aba=0,abb=0, baa=0,bab=0,bba=0,bbb=0;
    bool found=false; 
    cin >> x >> y >> z;

    while (found == false){
        if (x=='a' && y=='a' && z=='a') aaa=aaa+1;
        else if (x=='a' && y=='a' && z=='b') aab=aab+1;
        else if (x=='a' && y=='b' && z=='a') aba=aba+1;
        else if (x=='a' && y=='b' && z=='b') abb=abb+1;
        else if (x=='b' && y=='a' && z=='a') baa=baa+1;
        else if (x=='b' && y=='a' && z=='b') bab=bab+1;
        else if (x=='b' && y=='b' && z=='a') bba=bba+1;
        else if (x=='b' && y=='b' && z=='b') bbb=bbb+1;

        if (aaa==2 || aab==2 || aba==2 || abb==2 || baa==2 || bab==2 || bba==2 || bbb==2) found=true;
        if (found) cout << x << y << z << " " << pos << endl;
        pos += 1;
        x=y;
        y=z;
        cin >> z;
    }
}
