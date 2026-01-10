#include <iostream>
using namespace std;

int main(){
    int k, height, width, currentNumber;
    cin >> k >> height >> width;

    for (int i = 0; i < k; i++)
    {
        currentNumber = 9;
        for (int y = 0; y < height; y++)
        {
            string line = "";
            for (int x = 0; x < width; x++)
            {
                line += (char)('0' + currentNumber);
                if (currentNumber == 0) currentNumber = 9;
                else currentNumber -= 1;
            }
            cout << line << endl;;
        }
        if (i != k - 1) cout << "" << endl;
    }
    
}