#include <iostream>
#include <vector>
using namespace std;

vector<double> merge(const vector<double>& v1, const vector<double>& v2){
    int sizeV1 = v1.size(), sizeV2 = v2.size();
    int sizeNewV = sizeV1 + sizeV2;
    vector<double> vM(sizeNewV);
    int i = 0, j = 0, k = 0;
    int rightV1 = sizeV1 - 1, rightV2 = sizeV2 - 1;

    while (i <= rightV1 && j <= rightV2){
        if (v1[i] <= v2[j]) {
            vM[k] = v1[i];
            i++;
        }
        else{
            vM[k] = v2[j];
            j++; 
        }
        k++;
    }

    while (i <= rightV1){
        vM[k] = v1[i];
        i++;
        k++;
    }
    while (j <= rightV2) { 
        vM[k] = v2[j]; 
        j++;
        k++;
    }
    
    return vM;
}