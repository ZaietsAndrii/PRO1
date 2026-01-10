#include <iostream>
using namespace std;

// Funció que dibuixa la 'A' de mida n
void dibuixa_A(int n) {
    if (n <= 0) return;

    int alçada = 2 * n;
    int amplada = 4 * n - 2;

    // Bucle per les files (i: 1 a 2*n)
    for (int i = 1; i <= alçada; ++i) {
        
        // --- Regió Superior (1 <= i <= n) ---
        if (i <= n) {
            
            // 1. Espais de marge inicial (indentació)
            // La punta de la 'A' de n 'A's està centrada en 2n.
            int marge_esquerre = 2 * n - i; 
            for (int k = 0; k < marge_esquerre; ++k) {
                cout << ' ';
            }
            
            // 2. Pota esquerra (n 'A's)
            for (int k = 0; k < n; ++k) {
                cout << 'A';
            }
            
            // 3. Part Central (Espais o 'A's)
            
            // La barra horitzontal completa es troba a i=n.
            if (i == n) {
                // Ample del segment central omplert amb 'A's: 2n - 2 (per n>=2).
                if (n > 1) {
                    int ample_barra_n = 2 * (n - 1);
                    for (int k = 0; k < ample_barra_n; ++k) {
                        cout << 'A';
                    }
                }
            } 
            // La fila amb buit intern es troba a i <= n-1.
            else {
                // El buit central s'eixampla. L'ample és 2*(i-1) espais.
                int ample_buit_o_barra = 2 * (i - 1);

                // Per i=n-1 (la fila just abans de la barra base), 
                // aquesta part central S'HA d'OMPLIR d'A's segons el patró.
                if (i == n - 1 && n > 1) {
                    for (int k = 0; k < ample_buit_o_barra; ++k) {
                        cout << 'A';
                    }
                } 
                // Per i <= n-2, hi ha un buit
                else if (i < n - 1) {
                    for (int k = 0; k < ample_buit_o_barra; ++k) {
                        cout << ' ';
                    }
                }
            }

            // 4. Pota dreta (n 'A's)
            if (n == 1 && i == 1) {
                // Cas especial n=1: només una 'A' a la columna 4.
            } else {
                 for (int k = 0; k < n; ++k) {
                    cout << 'A';
                 }
            }
        } 
        
        // --- Regió Inferior (n+1 <= i <= 2n) ---
        else { 
            // Aquesta és la regió de les potes verticals que s'obren (indentació)
            int indent = i - (n + 1);
            
            // 1. Espais de marge (indentació)
            for (int k = 0; k < indent; ++k) {
                cout << ' ';
            }
            
            // 2. Pota esquerra (n 'A's)
            for (int k = 0; k < n; ++k) {
                cout << 'A';
            }
            
            // 3. Espais centrals (Buit gran)
            // L'ample del buit és (amplada - 2 * ample_pota - 2 * marge)
            int ample_buit = amplada - 2 * n - 2 * indent;
            for (int k = 0; k < ample_buit; ++k) {
                cout << ' ';
            }
            
            // 4. Pota dreta (n 'A's)
            for (int k = 0; k < n; ++k) {
                cout << 'A';
            }
        }

        // Final de la fila
        cout << '\n';
    }

    // Línia en blanc després de cada 'A'
    cout << '\n';
}

// Bucle principal per llegir múltiples casos d'entrada
int main() {
    // Optimització per a solucions ràpides (requerida per l'avaluació)
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    while (cin >> n) {
        dibuixa_A(n);
    }
    
    return 0;
}