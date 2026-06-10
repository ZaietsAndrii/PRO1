#include <iostream>
#include <vector>

using namespace std;

#ifndef BOCI
#define BOCI
struct Boci
{	
    int valor;
    int inici;
    int final;
};
#endif

void insertSort(vector<Boci>& v){
    for (int i = 1; i < v.size(); i++)
    {
        Boci x = v[i];
        int j = i;
        while (j > 0 && ((v[j - 1].final - v[j - 1].inici) > (x.final - x.inici))
        || (((v[j - 1].final - v[j - 1].inici) == (x.final - x.inici)) && v[j - 1].valor > x.valor))
        {
            v[j] = v[j - 1];
            j--;
        }
        v[j] = x;
    }
    
}

vector<Boci> bocins(const vector<int>& v){
    int start = 0, end = 0, prevNum = v[0];
    Boci boci; boci.valor = v[0]; boci.inici = 0;
    vector<Boci> bc;
    for (int i = 1; i < v.size(); i++)
    {
        if(boci.valor != v[i]){
            boci.final = i - 1;
            bc.push_back(boci);
            boci.inici = i;
            boci.valor = v[i];
        }
    }
    boci.final = v.size() - 1;
    bc.push_back(boci);

    insertSort(bc);
    return bc;
}