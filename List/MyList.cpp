#include <iostream>
#include <string>
#include <list>
#include <set>
#include <unordered_set>
using namespace std;


std::list<int> s1({ 8,7,6,3,2,1 });//8 7 6 3 2 1
std::list<int> s2({ 9,8,5,1 });//9 8 5 1

std::list<int> s3({ 10,5,3,2,0 });
std::list<int> s4({ 10,5,3,2,0 });

std::list<int> s5({ 15,10,10,10,6,6,5,5,0,0 });

std::list<int> s6({ 5,5,3,3,2,2,1,1 });

std::list<int> s7({ 1,2,3,4,3,2,1});
//====================================================================//

std::list<int> superMerge(std::list<int> ST1, std::list<int>ST2) {
	std::list<int> Merge;
	int tamaño = ST1.size() + ST2.size();

	for (int i = 0; i < tamaño; i++) {
		if (!ST1.empty() && !ST2.empty()) {
			if (ST1.front() > ST2.front()) {
				Merge.push_back(ST1.front());
				ST1.pop_front();//Eliminamos el elemento
			}
			else {
				Merge.push_back(ST2.front());
				ST2.pop_front();//Eliminamos el elemento
			}

		}
		else {//Si uno de los dos es empty
			if (!ST1.empty()) {
				Merge.push_back(ST1.front());
				ST1.pop_front();//Eliminamos el elemento
			}
			else {
				Merge.push_back(ST2.front());
				ST2.pop_front();//Eliminamos el elemento
			}
		}
	}


	return Merge;
}

//====================================================================//

void Change(std::list<int> &ST3) {
	int Ultimo = ST3.back();
	ST3.pop_back();
	ST3.push_back(ST3.front());
	ST3.pop_front();
	ST3.push_front(Ultimo);
}

//====================================================================//

int GetElementPos(std::list<int> ST4, int Posicion) {
	int resultado = -1;
	if (Posicion < ST4.size()+1) {
		for (int i = 0; i < Posicion-1; i++) {
			ST4.pop_front();
		}
		resultado = ST4.front();
		
	}
	
	return resultado;
	
}

//====================================================================//S

void RemoveDuplicates(std::list<int> &ST5) {
	std::unordered_set <int> SinDuplicar;
	while (!ST5.empty())
	{
		SinDuplicar.insert(ST5.front());
		ST5.pop_front();
	}
	while (!SinDuplicar.empty())
	{
		ST5.push_back(*SinDuplicar.begin());
		SinDuplicar.erase(SinDuplicar.begin());
	}
}

//====================================================================//

void RemoveElement(std::list<int> &ST6, int Numero ){

	for (auto it = ST6.begin(); it != ST6.end(); ++it) {
		if (*it == Numero) {
			ST6.erase(it);
		}
	
	}
}

//====================================================================//

bool Palindrome(std::list<int> ST7) {
	bool Palindrom;
	while (!ST7.empty()) {
		if (ST7.front() == ST7.back()) {
			ST7.pop_back();
			if (ST7.empty()) {
				Palindrom = true;
				return Palindrom;
			}
			else {
				ST7.pop_front();
			}
		}
		else {
			Palindrom = false;
			return Palindrom;
		}
	
	}
	Palindrom = true;


	return Palindrom;
}


//====================================================================//

int main() {



	//Printear SuperMerge
	std::list<int> Merge({ superMerge(s1,s2) });
	int tamaño = Merge.size();
	for (int i = 0; i < tamaño; i++) {
		std::cout << Merge.front() << " - ";
		Merge.pop_front();

	}

	//===========================//
	std::cout << "\n ";

	Change(s3);
	tamaño = s3.size();
	for (int i = 0; i < tamaño; i++) {
		std::cout << s3.front() << " - ";
		s3.pop_front();

	}
	
	//===========================//

	std::cout << "\n ";

	int Numero = GetElementPos(s4, 5);
	if (Numero < 0) {
		std::cout << "Numero fuera de la lista" << std::endl;
	}
	else {
		std::cout << Numero << std::endl;
	}
	
	//===========================//

	std::cout << "\n ";

	RemoveDuplicates(s5);
	tamaño = s5.size();
	for (int i = 0; i < tamaño; i++) {
		std::cout << s5.front() << " - ";
		s5.pop_front();

	}
	//===========================//

	std::cout << "\n ";

	
	RemoveElement(s6,1);
	tamaño = s6.size();
	std::cout << s6.front() << " - ";
	for (int i = 0; i < tamaño; i++) {
		std::cout << s6.front() << " - ";
		s6.pop_front();
	}

	//===========================//
	std::cout << "\n ";

	std::cout << "Palindromo: " << Palindrome(s7);


	return 0;
}