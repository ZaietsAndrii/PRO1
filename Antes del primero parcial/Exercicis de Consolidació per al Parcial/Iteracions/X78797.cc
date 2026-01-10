#include <iostream>
using namespace std;

/**
 * Procesa y muestra una línea del icono de 20 píxeles, codificada por p y q.
 * Mantiene la lógica de prioridad ('#' sobre '.') y elimina los espacios al final de la línea.
 */
void mostrar_linea_icono(int p, int q) {
    // Array para almacenar los 20 caracteres de la línea. No necesitamos el '\0'
    // si usamos std::cout para imprimir carácter por carácter, pero lo usaremos 
    // para buscar el último carácter pintado de forma eficiente.
    char linea[20]; 
    
    // 1. Decodificar la línea bit a bit
    // Iteramos sobre los 20 bits, de izquierda a derecha (MSB a LSB).
    // i = 19 (primer píxel) hasta i = 0 (último píxel).
    for (int i = 19; i >= 0; --i) {
        // La máscara para el bit actual es 2^i. Usamos 1U para asegurar el tipo unsigned int.
        unsigned int mask = i;

        // La posición en el array 'linea' es (19 - i), para que el bit 19 vaya al índice 0.
        int pos = 19 - i;
        
        // Regla 1: Si p tiene el bit activo, es '#' (color primario, tiene prioridad)
        if (p & mask) {
            linea[pos] = '#'; 
        } 
        // Regla 2: Si p NO tiene el bit activo, pero q SÍ, es '.' (color secundario)
        else if (q & mask) {
            linea[pos] = '.';
        } 
        // Regla 3: Si ninguno tiene el bit activo, es ' ' (espacio en blanco)
        else {
            linea[pos] = ' ';
        }
    }

    // 2. Determinar la longitud de la línea a imprimir (excluyendo espacios finales)
    int longitud_a_imprimir = 0;
    
    // Buscamos el último índice (j) que NO sea un espacio, de derecha a izquierda.
    for (int j = 19; j >= 0; --j) {
        if (linea[j] != ' ') {
            // Si encontramos un carácter pintado en el índice j, la longitud es j + 1.
            longitud_a_imprimir = j + 1;
            break; 
        }
    }

    // 3. Imprimir la línea hasta la longitud determinada
    // Si longitud_a_imprimir es 0, no se imprime nada (solo el salto de línea al final).
    for (int k = 0; k < longitud_a_imprimir; ++k) {
        cout << linea[k];
    }
    
    // Pasamos a la siguiente línea
    cout << '\n';
}

void resolver() {

    // Leemos el número de iconos 'n'
    int n;
    if (!(cin >> n)) return;

    // Procesamos cada icono
    for (int icono = 0; icono < n; ++icono) {
        // Cada icono tiene 20 líneas
        for (int linea = 0; linea < 20; ++linea) {
            int p, q;
            if (!(cin >> p >> q)) return;
            mostrar_linea_icono(p, q);
        }
        
        // Se requiere una línea en blanco después de cada icono.
        // Siempre se imprime un salto de línea extra después de las 20 líneas.
        cout << '\n';
    }
}

// Función principal
int main() {
    resolver();
    return 0;
}