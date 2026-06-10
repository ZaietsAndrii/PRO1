#include <iostream>
#include <vector>
using namespace std;

typedef vector <int>   Vector;
typedef vector<Vector> Matriu;

/*
 * PRE:  M.size() > 0 and M[0].size() > 0, es una matriz de enteros.
 *		 M[0][0] >= 0.
 *		 potencia > 0, objectiu > 0.
 *		 recorregut.size() > 0 y recorregut solo contiene 'N','S','E','O'.
 *
 * POST: Devuelve ACONSEGUIT si el recorrido es capaz de recoger
 *       al menos tantos premios como objectiu.
 *       Devuelve ESGOTAT si recoge tantas piedras o más que potencia.
 *       Devuelve NO HI ARRIBEM si el recorrido no consigue recoger
 *               tantos premios como objectiu.
 */

string matriu_laberint(const Matriu& M,int potencia, int objectiu, const string& recorregut) {
    int curRow = 0, curColumn = 0;
    bool moved = true;
    for (int i = 0; i < recorregut.size() && potencia > 0; i++)
    {
        moved = true;
        if (recorregut[i] == 'N' && curRow > 0) curRow--;
        else if(recorregut[i] == 'S' && curRow < M.size() - 2) curRow++;
        else if(recorregut[i] == 'E' && curColumn < M[0].size() - 2) curColumn++;
        else if(recorregut[i] == 'O' && curColumn > 0) curColumn--;
        else moved = false;

        if(moved){
            if(M[curRow][curColumn] >= 0) objectiu -= M[curRow][curColumn];
            else if(M[curRow][curColumn] < 0) potencia += M[curRow][curColumn];
        }
    }

    if(potencia <= 0) return "ESGOTAT";
    else if (objectiu <= 0) return "ACONSEGUIT";
    else return "NO HI ARRIBEM";
    
}