#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Person{
    id;
    name;
}

void merge(vector<Person>& v, int left, int mid, int right){
    int n = right - left + 1;
    vector<Person> aux(n);
    int i = left;
    int j = mid + 1;
    int k = 0;
    while (i <= mid && j <= right){
        if(v[i] <= v[j]) { aux[k] = v[i]; i++; }
        else { aux[k] = v[j]; j++ }
        k++;
    }

    while(i <= mid) { aux[k] = v[i]; k++; i++; }
    while(j <= right) { aux[k] = v[j]; k++; j++; }

    for (k = 0; k < n; k++) v[left + k] = aux[k];
    
    
}

void mergeSort(vector<Person>& v, int left, int right){
    while (left < right)
    {
        int m = (left + right) / 2;
        mergeSort(v, left, m);
        mergeSort(v, m + 1, right);
        merge(v, left, m, right);
    }
    
}
