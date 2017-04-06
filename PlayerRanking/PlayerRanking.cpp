#include <vector>
#include <iostream>
#include <string>
using namespace std;

struct  Person
{
	string nombre;
	int puntuacion;
};

int main(){
	string name;
	int points;
	std::vector<Person> Tabla({});
	for (int i = 0; i < 4; i++) {
		
		std::cout << "Put Name Player " << i+1 <<" : \n";
		std::cin >> name;
		std::cout << "Enter your Puntuation Player " << i + 1 << " :\n";
		std::cin >> points;
		Tabla.push_back({ name, points });
	}
return (0);
}