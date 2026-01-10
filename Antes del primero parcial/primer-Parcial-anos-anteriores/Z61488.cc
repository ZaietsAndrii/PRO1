#include <iostream>
using namespace std;

void Outputmessage(char c, int repetiton){
    if (repetiton == 2) cout << "Pair of " << c << "s" << endl;
    else if(repetiton == 3) cout << "Trio of " << c << "s" << endl;
    else if(repetiton == 4) cout << "Poker of " << c << "s" << endl;
    else cout << repetiton << " " << c << "s!" << endl;
    
}

int main(){
    char curC, prevC;
    int repetition = 1;
    cin >> curC;
    while (curC != '.')
    {
        prevC = curC;
        cin >> curC;
        if (curC == prevC) repetition += 1;
        else if (repetition > 1) {
            Outputmessage(prevC, repetition);
            repetition = 1;
        }
    }
}