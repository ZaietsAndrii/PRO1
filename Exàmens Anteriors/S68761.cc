#include <iostream>
#include <vector>

using namespace std;

#ifndef PERSONA
#define PERSONA

struct Persona {
    string nom;
    int edat;
};

#endif

/**
 * @brief Encuentra el índice de la primera persona (con el índice mínimo)
 *        cuya edad es exactamente 'anys'.
 *
 * @returns Índice de la persona encontrada, o -1 si no hay ninguna.
 *
 * @pre   El vector de personas está ordenado por edad y puede tener
 *        varias personas con la misma edad.
 */
int cerca_per_edat(const vector<Persona>& persones, int anys){
    int left = 0, right = persones.size() - 1;
    while (left <= right)
    {
        int i = (left + right) / 2;
        if(anys < persones[i].edat) right = i - 1;
        else if(anys > persones[i].edat) left = i + 1;
        else if(anys == persones[i].edat && i > 0 && anys == persones[i - 1].edat) right = i - 1;
        else return i;
    }
    return -1;
}