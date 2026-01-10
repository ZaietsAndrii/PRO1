#include <iostream>
using namespace std;

int getCardValue(char c){
    if (c >= '2' && c <= '9') return c - '0';
    else if (c == '0') return 10;
    else if (c == 'J') return 11;
    else if (c == 'Q') return 12;
    else if (c == 'K') return 13;
    else if (c == 'A') return 14;
    else return 0;  
}

bool better_card(char c1, char c2){
    return getCardValue(c1) > getCardValue(c2);
}
