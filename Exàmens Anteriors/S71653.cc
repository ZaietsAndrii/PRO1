#include <iostream>
#include <vector>

using namespace std;

#ifndef TIPUS
#define TIPUS

struct Casa {
    string nom;
    int pos;
};

struct Poble {
    int inici, fi;
    int num_cases;
};

#endif

void inserSort(vector<Casa>& v){
    for (int i = 1; i < v.size(); i++)
    {
        Casa x = v[i];
        int j = i;
        while (j > 0 && v[j - 1].pos > x.pos)
        {
            v[j] = v[j - 1];
            j--;
        }
        v[j] = x;
    }
    
}
/**
 * @brief Detecta los pueblos de la carretera.
 *
 * @pre   El vector `cases` está ordenado por nombre.
 * @post  El resultado está ordenado por posición.
 */
vector<Poble> detecta_pobles(vector<Casa>& cases){
    Poble poble;
    vector<Poble> pobles;
    inserSort(cases);
    poble.inici = cases[0].pos;
    poble.num_cases = 1;
    
    for (int i = 1; i < cases.size(); i++)
    {
        if(cases[i].pos - cases[i - 1].pos >= 3){
            poble.fi = cases[i - 1].pos;
            if(poble.num_cases > 1) pobles.push_back(poble);
            poble.inici = cases[i].pos;
            poble.num_cases = 1;
        }
        else poble.num_cases++;
    }
    poble.fi = cases[cases.size() - 1].pos;
    if(poble.num_cases > 1) pobles.push_back(poble);    
    
    return pobles;
}