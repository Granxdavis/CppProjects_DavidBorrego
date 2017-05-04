#include <stack>
#include <iostream>
#include <string>
#include <queue>

using namespace std;


std::stack<int> s1({1, 2,3,6,7,8 });//1 2 3 6 7 8
std::stack<int> s2({ 1,5,8,9 });// 1 5 8 9

std::stack<string> p1({ "2", "9","4", "7"});
std::stack<string> p2({ "6","3", "5" });



//=============================================================================================//

std::stack<int> superMerge(std::stack<int> ST1, std::stack<int>ST2) {
	std::stack<int> Merge;
	int tamaño = ST1.size()+ST2.size();

	for (int i = 0; i < tamaño; i++) {
		if (!ST1.empty() && !ST2.empty()) {
			if (ST1.top() > ST2.top()) {
				Merge.push(ST1.top());
				ST1.pop();//Eliminamos el elemento
			}
			else {
				Merge.push(ST2.top());
				ST2.pop();//Eliminamos el elemento
			}
			
		}
		else {//Si uno de los dos es empty
			if (!ST1.empty()) {
				Merge.push(ST1.top());
				ST1.pop();//Eliminamos el elemento
			}
			else {
				Merge.push(ST2.top());
				ST2.pop();//Eliminamos el elemento
			}
		}
	}

	//Darle la vuelta al Stack
	std::stack<int> Merge2;
	tamaño = Merge.size();
	for (int i = 0; i < tamaño; i++) {
	
		Merge2.push(Merge.top());
		Merge.pop();
		//std::cout << Merge2.top() << " - ";
	}

	
	return Merge2;
}

//=============================================================================================//

std::stack<string> putHat(std::stack<string> ST1, std::stack<string>ST2) {
	std::stack<string> Hat;
	int tamaño = ST2.size();
	for (int i = 0; i < tamaño; i++) {//Añadir el segundo stack
		Hat.push(ST2.top());
		ST2.pop();
	}

	std::stack<string> Hat2;
	for (int i = 0; i < tamaño; i++) {//Dar la vuelta al stack

		Hat2.push(Hat.top());
		Hat.pop();
	}

	tamaño = ST1.size();
	for (int i = 0; i < tamaño; i++) {//Añadir el primer stack
		Hat.push(ST1.top());
		ST1.pop();
	}

	for (int i = 0; i < tamaño; i++) {//Dar la vuelta al stack

		Hat2.push(Hat.top());
		Hat.pop();
	}
	

	return Hat2;
}

//=============================================================================================//

std::queue<int> TransformToQ(std::stack<int> TQ1) {
	std::queue<int> result;
	int tamaño = TQ1.size();
	for (int i = 0; i < tamaño; i++) {
		result.push(TQ1.top());
		TQ1.pop();
	}
	return result;

}
//=============================================================================================//

int main() {



	//Printear SuperMerge
	std::stack<int> Merge({ superMerge(s1,s2) });
	int tamaño = Merge.size();
	for (int i = 0; i < tamaño; i++) {
		std::cout << Merge.top() << " - ";
		Merge.pop();

	}


	std::cout << "\n";


	//Printear putHat
	std::stack<string> Hat({ putHat(p1,p2) });
	tamaño = Hat.size();
	for (int i = 0; i < tamaño; i++) {
		std::cout << Hat.top() << " - ";
		Hat.pop();

	}

	std::cout << "\n";

	//Printear TrandformToQ
	std::queue<int> Transform({ TransformToQ(s1) });
	tamaño = Transform.size();
	for (int i = 0; i < tamaño; i++) {
		std::cout << Transform.front() << " - ";
		Transform.pop();

	}

	return 0;
}