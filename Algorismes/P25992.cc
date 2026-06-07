#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    while (cin >> n)
    {
        vector<int> evenNums;
        vector<int> oddNums;
        if (n != 0){
            if (n % 2 == 0) evenNums.push_back(n);
            else oddNums.push_back(n);                     
            while (cin >> n && n != 0)
            {
                if (n % 2 == 0) evenNums.push_back(n);
                else oddNums.push_back(n);
            }

            sort(evenNums.begin(), evenNums.end());
            sort(oddNums.begin(), oddNums.end());
            int sizeEvenNums = evenNums.size(), sizeOddNums = oddNums.size();
            for (int i = 0; i < sizeEvenNums; i++){
                if (i != 0) cout << " ";
                cout << evenNums[i];
            }
            cout << endl;
            for (int i = sizeOddNums - 1; i >= 0; i--){
                if (i != sizeOddNums - 1) cout << " ";
                cout << oddNums[i];
            }
            cout << endl;
        }
        else{
            cout << endl;
            cout << endl;
        }
    }
    
}