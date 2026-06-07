#include <iostream>
#include <vector>
using namespace std;

void doAction(int num){
    if (num == 1)
    {
        cout << '*' << endl;
    }
    else{
        doAction(num - 1);
        for (int i = 0; i < num; i++){
            for (int j = 0; j < num; j++){
                cout << '*';
            }
            cout << endl;
        }
        doAction(num - 1);
    }   
    
}

int main(){
    int num;
    while (cin >> num)
    {
        doAction(num);
        cout << endl;
    }
    
}