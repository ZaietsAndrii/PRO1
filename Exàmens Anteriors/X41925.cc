#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Person{
    int id;
    string name;
};

void merge(vector<Person>& v, int left, int mid, int right, bool shouldSortById){
    int n = right - left + 1;
    vector<Person> aux(n);
    int i = left;
    int j = mid + 1;
    int k = 0;
    while(i <= mid && j <= right){
        if(shouldSortById){
            if(v[i].id < v[j].id || (v[i].id == v[j].id && v[i].name <= v[j].name)) { aux[k] = v[i]; i++; }
            else { aux[k] = v[j]; j++; }
        }
        else{
            if(v[i].name < v[j].name || (v[i].name == v[j].name && v[i].id <= v[j].id)) { aux[k] = v[i]; i++; }
            else { aux[k] = v[j]; j++; }
        }
        k++;
    }

    while(i <= mid) { aux[k] = v[i]; k++; i++; }
    while(j <= right) { aux[k] = v[j]; k++; j++; }

    for(k = 0; k < n; k++) v[left + k] = aux[k];
}

void mergeSort(vector<Person>& v, int left, int right, bool shouldSortById){
    if(left < right){
        int m = (left + right) / 2;
        mergeSort(v, left, m, shouldSortById);
        mergeSort(v, m + 1, right, shouldSortById);
        merge(v, left, m, right, shouldSortById);
    }
}

int main() {
    // Optimize standard I/O operations for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    while (cin >> n) {
        vector<Person> v(n);
        for (int i = 0; i < n; i++) cin >> v[i].id >> v[i].name;

        // --- PHASE 1: SORT BY ID ---
        mergeSort(v, 0, n - 1, true);

        long long total_same_id_pairs = 0;
        long long repetitions = 0;

        int i = 0;
        while (i < n) {
            int j = i;
            // Find the boundary of the current ID block
            while (j < n && v[j].id == v[i].id) {
                j++;
            }
            long long id_block_size = j - i;
            total_same_id_pairs += (id_block_size * (id_block_size - 1)) / 2;

            // Inside this ID block, find sub-blocks of identical names (Repetitions)
            int k = i;
            while (k < j) {
                int l = k;
                while (l < j && v[l].name == v[k].name) {
                    l++;
                }
                long long name_sub_block_size = l - k;
                repetitions += (name_sub_block_size * (name_sub_block_size - 1)) / 2;
                k = l;
            }
            i = j;
        }
        
        long long conflicts = total_same_id_pairs - repetitions;

        // --- PHASE 2: SORT BY NAME ---
        mergeSort(v, 0, n - 1, false);
        
        long long total_same_name_pairs = 0;
        i = 0;
        while (i < n) {
            int j = i;
            // Find the boundary of the current Name block
            while (j < n && v[j].name == v[i].name) {
                j++;
            }
            long long name_block_size = j - i;
            total_same_name_pairs += (name_block_size * (name_block_size - 1)) / 2;
            i = j;
        }
        
        long long coincidences = total_same_name_pairs - repetitions;
        
        // Output results
        cout << repetitions << " " << conflicts << " " << coincidences << "\n";
    }
    return 0;
}