#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;
/*

//Fichero de salida

ofstream fsalida("Path_Del_fichero");//Ya abre fichero

fsalida.open("Path_Del_fichero");//Otra manera de abrir el fichero

//Fichero de entrada

ifstream fentrada("Path_Del_fichero");

fentrada.open("Path_Del_fichero");


//Fichero binario abierto para lectura
std::ifstream myFile3("Path_Del_fichero", std::ios::in | std::ios::binary);

//LEER

//LEER ENTEROS
//Suponemos un file que tiene
// 1 2
// 8 9
int x1, y1;
myFile1 >> x1 >> y1;

*/

int main() {
	std::fstream fichero;
	string texto;
	// Se abre para lectura
	fichero.open("elements.dat", std::ios::in);
		// Se lee una primera linea
		fichero >> texto; //lee hasta el primer espacio en blanco
						  // Mientras se haya podido leer algo
	while (!fichero.eof())
	{
		std::cout << texto << std::endl;
		fichero >> texto;
	}
	//Finalmente, se cierra
	fichero.close();	return (0);
}
