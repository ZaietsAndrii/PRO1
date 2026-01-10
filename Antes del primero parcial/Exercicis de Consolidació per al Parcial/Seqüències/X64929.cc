#include <iostream>
using namespace std;

int main(){
    int happinessLevel = 0, sadnessLevel = 0;
    char c1, c2, c3;
    cin >> c3 >> c2;
    while (cin >> c1)
    {
        if (c3 == ':' && c2 == '-' && c1 == ')') happinessLevel += 1;
        else if (c3 == '(' && c2 == '-' && c1 == ':') happinessLevel += 1;
        else if (c3 == ':' && c2 == '-' && c1 == '(') sadnessLevel += 1;
        else if (c3 == ')' && c2 == '-' && c1 == ':') sadnessLevel += 1;

        c3 = c2;
        c2 = c1;
    }

    cout << happinessLevel << " " << sadnessLevel << endl;
    
}