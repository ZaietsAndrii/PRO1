#include <iostream>
using namespace std;



void skipDummyStrings(int n){
    for (int i = 0; i < n; i++)
    {
        string dummyString;
        cin >> dummyString;
    }
    
}

int main() {
    string lineInput;
    while (cin >> lineInput)
    {
        string name;
        int years = 0;
        skipDummyStrings(2);
        cin >> name;
        skipDummyStrings(3);
        cin >> years;
        skipDummyStrings(2);
        years = years - years / 10;
        cout << name << ", you look younger. I thought you were " << years <<" years old." << endl;        
    }
    
}