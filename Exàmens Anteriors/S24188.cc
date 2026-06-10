#include <iostream>
#include <vector>

using namespace std;


void inserSort(vector<int>& v){
    for (int i = 1; i < v.size(); i++)
    {
        int x = v[i];
        int j = i;
        while (j > 0 && v[j - 1] > x)
        {
            v[j] = v[j - 1];
            j--;
        }
        v[j] = x;
    }
    
}

/*
 * @pre  M es cuadrada y M.size() > 0
 *       1 <= M[i][j] <= 1000
 *       Los valores de una misma fila son todos diferentes.
 *
 * @post Devuelve `true` si y solo si la matriz satisface las 
 *       siguientes condiciones:
 *       - Todas las filas son diferentes.
 *       - Todas las filas son permutaciones entre sí.
 */
bool te_files_permutades(const vector<vector<int>>& M){
    vector<vector<int>> newM = M;
    for (int i = 0; i < M.size() - 1; i++)
    {
        for (int j = 0; j < M.size(); j++)
        {
            if(i != j){
                if(M[i] == M[j]) return false;
            }
        }
        
    }
    
    inserSort(newM[0]);
    for (int i = 1; i < M.size(); i++)
    {
        inserSort(newM[i]);
        if(newM[0] != newM[i]) return false;
    }
    return true;
}