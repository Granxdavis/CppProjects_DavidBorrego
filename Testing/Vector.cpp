#include <vector>
#include <iostream>
#include <string>
#include <ctime>
#include "stdafx.h"
using namespace std;



int main() {
//Constructor sin argumentos y de tamaño 0
std::vector<int> v1;

//Constructor con una lista de inicializacion
std::vector<int> v12({10,9,8,7,6,5,4,3,2,1});

//Constructor por copia. Construir un vector a partir de otro que ya existe
std::vector<int>v4(v12);

//Constructor por numero de elementos. En este caso Array de 5 elementos
std::vector<int>v9(5);

//Constructor de tamaño 5 inicializado en 10 todos
std::vector<int>v10(5, 10);

//Constructor con iteradores
std::vector<int>v7(v12.begin(), v12.end());//Begin apunta al primer elemento y el End apunta a una direccion mas de la ultima o ultima+1

//Constructor de iteradores con rango
std::vector<int>v7(v12.begin()+1, v12.end()-1);//Copia todo menos el primero y el ultimo

//Constructor de iteradores desde arrays. 
int myarray[]{ 16,2,77,29 };
std::vector<int> v20(myarray, myarray + sizeof(myarray) / sizeof(int));

//Constructor con iteradoresç


	int *pv;
	pv = new int[4]{ 1,2,3,4 };
	std::vector<int> v21(pv, pv + 4);


	std::vector<int> vector1({ 28,15,12,65,1 });

	std::cout << vector1.size();
	std::cout << vector1.capacity();
	//Inserta el elemento 2 al final
	vector1.push_back(2);

	std::cout << vector1.size();
	std::cout << vector1.capacity();
	//Inserta en la posición 0 el elemento 3, desplazando los dem
	//Crece dinámicamente
	vector1.insert(vector1.begin(), 3);

	std::cout << vector1.size();
	std::cout << vector1.capacity();
}