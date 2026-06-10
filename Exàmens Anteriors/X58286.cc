#include <iostream>
#include <vector>
using namespace std;

struct Search {
    string word;
    int stime;
};

// Pre: n >= 0
// Post: lee de la entrada una secuencia S de n búsquedas y retorna
//       esa información almacenada en un vector de Search
vector<Search> read_data(int n) {
    vector<Search> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i].word >> v[i].stime;
    }
    return v;
}

// Pre: -
// Post: retorna el tiempo de respuesta más lento de la palabra p  
//       en v (si existe), o 0 en caso contrario
int tiempo_maximo(const vector<Search>& v, string p) {
    int maxTime = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if(v[i].word == p && v[i].stime > maxTime) maxTime = v[i].stime;
    }
    return maxTime;
    
}

int main() {
    int n;
    cin >> n;
    vector<Search> v = read_data(n);

    string w;
    while (cin >> w) {
        cout << w << ": " << tiempo_maximo(v, w) << endl;
    }
    
}