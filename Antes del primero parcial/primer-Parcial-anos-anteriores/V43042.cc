#include <iostream>
using namespace std;

int main(){
    int expectedRepetitions, repetitions = 1;
    char currentC, previousC;
    bool found = false;
    cin >> expectedRepetitions;
    cin >> previousC;

    if (expectedRepetitions == 1) found = true;
    
    while (found == false && cin >> currentC)
    {   
        if (currentC == previousC) repetitions += 1;
        else repetitions = 1;

        if (repetitions == expectedRepetitions) found = true;        
        previousC = currentC;
    }

    if (found) cout  << expectedRepetitions << "-Poker of " << previousC << "!" << endl;
    else cout << "No " << expectedRepetitions << "-Poker" << endl;  
}