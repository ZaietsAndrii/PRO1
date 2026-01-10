#include <iostream>
#include <string>

// Función para procesar y mostrar una línea del icono
void mostrar_linea_icono(int p, int q) {
    // El icono tiene 20 píxeles de ancho. Usamos un array de char de tamaño 21 para 
    // almacenar la línea, incluyendo el terminador nulo '\0'.
    char linea[21]; 
    
    // Iteramos sobre los 20 bits, desde el MSB (posición 19) al LSB (posición 0).
    // El bit 19 corresponde al primer píxel (izquierda) y el bit 0 al último (derecha).
    for (int i = 19; i >= 0; --i) {
        // La máscara para el bit actual es 2^i. Usamos 1U para asegurar el tipo unsigned int.
        unsigned int mask = i;

        // La posición en el array 'linea' es 0 para el bit 19, 1 para el bit 18, etc.
        // La fórmula es: 19 - i.
        
        // Regla 1: Si p tiene el bit activo, es '#' (color primario, tiene prioridad)
        if (p & mask) {
            linea[19 - i] = '#'; 
        } 
        // Regla 2: Si p NO tiene el bit activo, pero q SÍ, es '.' (color secundario)
        else if (q & mask) {
            linea[19 - i] = '.';
        } 
        // Regla 3: Si ninguno tiene el bit activo, es ' ' (espacio en blanco)
        else {
            linea[19 - i] = ' ';
        }
    }

    // Parte crucial: Eliminar los espacios en blanco al final de la línea.
    int ultimo_no_espacio = -1;
    for (int j = 19; j >= 0; --j) {
        if (linea[j] != ' ') {
            ultimo_no_espacio = j;
            break;
        }
    }

    // Si ultimo_no_espacio sigue siendo -1, la línea entera son espacios. 
    // No se imprime nada, solo un salto de línea.
    if (ultimo_no_espacio == -1) {
        // Imprime solo el salto de línea. std::cout << "" << '\n'
    } else {
        // Colocamos el terminador nulo después del último carácter a imprimir.
        linea[ultimo_no_espacio + 1] = '\0';
        // Imprimimos la subcadena.
        std::cout << linea;
    }
    
    // Pasamos a la siguiente línea del icono o la línea en blanco después del icono.
    std::cout << '\n';
}

void resolver() {
    // Desactivamos la sincronización de C++ iostream con C stdio
    std::ios_base::sync_with_stdio(false);
    // Desvinculamos cin de cout
    std::cin.tie(NULL);

    // Leemos el número de iconos 'n'
    int n;
    // Si la lectura falla (e.g., EOF inesperado), terminamos
    if (!(std::cin >> n)) return;

    // Procesamos cada icono
    for (int icono = 0; icono < n; ++icono) {
        // Cada icono tiene 20 líneas
        for (int linea = 0; linea < 20; ++linea) {
            int p, q;
            if (!(std::cin >> p >> q)) return;
            mostrar_linea_icono(p, q);
        }
        
        // El enunciado requiere una línea en blanco después de cada icono.
        // La condición garantiza que la línea en blanco se imprime después de las 20 líneas del icono.
        if (icono < n) { 
             std::cout << '\n';
        }
    }
}

// Función principal
int main() {
    resolver();
    return 0;
}