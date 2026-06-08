#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Estructura idéntica a las estudiadas en el bloque de tuplas/records
struct Person {
    int id;
    string name;
};

// Acción para fusionar dos subvectores ordenados (Algoritmo de Mezcla de PRO1)
void merge(vector<Person>& v, int left, int mid, int right, int mode) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    vector<Person> L(n1);
    vector<Person> R(n2);
    
    for (int i = 0; i < n1; ++i) L[i] = v[left + i];
    for (int j = 0; j < n2; ++j) R[j] = v[mid + 1 + j];
    
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        bool take_left = false;
        if (mode == 1) { // Modo 1: Ordenar por ID, luego por Nombre
            if (L[i].id != R[j].id) take_left = (L[i].id < R[j].id);
            else take_left = (L[i].name < R[j].name);
        } else {         // Modo 2: Ordenar solo por Nombre
            take_left = (L[i].name < R[j].name);
        }
        
        if (take_left) {
            v[k] = L[i];
            ++i;
        } else {
            v[k] = R[j];
            ++j;
        }
        ++k;
    }
    
    while (i < n1) { v[k] = L[i]; ++i; ++k; }
    while (j < n2) { v[k] = R[j]; ++j; ++k; }
}

// Algoritmo de ordenación por división y conquista: Merge Sort O(n log n)
void merge_sort(vector<Person>& v, int left, int right, int mode) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        merge_sort(v, left, mid, mode);
        merge_sort(v, mid + 1, right, mode);
        merge(v, left, mid, right, mode);
    }
}

int main() {
    int n;
    while (cin >> n) {
        vector<Person> p(n);
        for (int i = 0; i < n; ++i) {
            cin >> p[i].id >> p[i].name;
        }
        
        // --- PASO 1: Ordenar por ID y Nombre ---
        merge_sort(p, 0, n - 1, 1);
        
        long long total_same_id = 0;
        long long repetitions = 0;
        
        // Contar parejas con mismo ID
        long long count = 1;
        for (int i = 1; i < n; ++i) {
            if (p[i].id == p[i-1].id) ++count;
            else {
                total_same_id += (count * (count - 1)) / 2;
                count = 1;
            }
        }
        total_same_id += (count * (count - 1)) / 2;
        
        // Contar parejas con mismo ID y mismo Nombre (Repeticiones)
        count = 1;
        for (int i = 1; i < n; ++i) {
            if (p[i].id == p[i-1].id && p[i].name == p[i-1].name) ++count;
            else {
                repetitions += (count * (count - 1)) / 2;
                count = 1;
            }
        }
        repetitions += (count * (count - 1)) / 2;
        
        // Conflictos = (Mismo ID) - (Mismo ID y Nombre)
        long long conflicts = total_same_id - repetitions;
        
        // --- PASO 2: Ordenar por Nombre ---
        merge_sort(p, 0, n - 1, 2);
        
        long long total_same_name = 0;
        
        // Contar parejas con mismo Nombre
        count = 1;
        for (int i = 1; i < n; ++i) {
            if (p[i].name == p[i-1].name) ++count;
            else {
                total_same_name += (count * (count - 1)) / 2;
                count = 1;
            }
        }
        total_same_name += (count * (count - 1)) / 2;
        
        // Coincidencias = (Mismo Nombre) - (Mismo ID y Nombre)
        long long coincidences = total_same_name - repetitions;
        
        cout << repetitions << " " << conflicts << " " << coincidences << "\n";
    }
    return 0;
}