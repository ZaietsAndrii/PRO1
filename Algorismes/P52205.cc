#include <iostream>
#include <vector>
using namespace std;

void merge(vector<double>& v, int left, int mid, int right){
    int n = right - left + 1;
    vector<double> aux(n);
    int i = left;
    int j = mid + 1;
    int k = 0;
    while (i <= mid && j <= right){
        if (v[i] <= v[j]) { aux[k] = v[i]; i++; }
        else { aux[k] = v[j]; j++; }
        k++;
    }

    while (i <= mid) { aux[k] = v[i]; k++; i++; }
    while (j <= right) { aux[k] = v[j]; k++; j++; }

    for (k = 0; k < n; k++) v[left + k] = aux[k];
}

void merge_sort(vector<double>& v, int left, int right){
    if (left < right){
        int mid = (left + right) / 2;
        merge_sort(v, left, mid);
        merge_sort(v, mid + 1, right);
        merge(v, left, mid, right);
    }  
}

void mergesort(vector<double>& V){
    merge_sort(V, 0, V.size() - 1); 
}