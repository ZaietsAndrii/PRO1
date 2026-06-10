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
bool te_files_permutades(const vector<vector<int>>& M) {
    int n = M.size();

    // 1) Todas las filas diferentes (comparación directa de filas)
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            if (M[i] == M[j]) return false;

    // 2) Todas son permutaciones entre sí: las filas ordenadas coinciden
    vector<int> ref = M[0];      // copia de UNA fila (M sigue const)
    inserSort(ref);
    for (int i = 1; i < n; ++i) {
        vector<int> fila = M[i]; // copia local de la fila i
        inserSort(fila);
        if (fila != ref) return false;
    }
    return true;
}
