#include <iostream>
#include <vector>
using namespace std;

bool is_palindrome(const string& s){
    int sSize = s.size();
    bool isPalindrome = true;
    for (int i = 0; i <= sSize / 2 && isPalindrome; i++)
    {
        isPalindrome = s[i] == s[sSize - i - 1];
    }
    return isPalindrome;
}