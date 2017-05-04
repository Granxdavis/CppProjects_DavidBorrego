# include <deque>
# include <queue>
# include <vector>
#include <iostream>
using namespace std;

//std::deque <float> prices(10, 10.50);

int main() {
	//DEQUE
	std::deque <float> prices(10, 10.50f);
	prices.pop_back();//Eliminar el ultimo
	prices.push_back(32.43f);//Añadir el ultimo
	prices.pop_front();//Eliminar el primer elemento
	std::deque<float> prices2(prices);//Crear otra Deque inicializa en la otra
	prices2.push_front(5.64f);//Añadir al principio
	prices2.push_front(20.31f);//Añadir al principio
	prices2.insert(prices2.begin() + 1, 10);//Añadir en la segunda posicion

	//Print Prices
	std::cout << "prices contains: \n";
	for (auto it = prices.rbegin(); it != prices.rend(); ++it) {
		std::cout << *it << " - ";
	}

	std::cout << '\n';
	std::cout << '\n';

	//Print Prices2
	std::cout << "prices2 contains: \n";
	for (int i = 0; i <= prices2.size()-1; i++) {
		
		std::cout << " - " << prices2[i];
	}
	std::cout << '\n';
	std::cout << '\n';

	//VECTOR

	std::vector <float> prices3(10, 10.5f);
	prices3[prices3.size()-1] = 32.43f;
	//prices3.pop_back();//Eliminar el ultimo
	//prices3.push_back(32.43f);//Añadir el ultimo
	prices3.erase(prices3.begin());//Eliminar el primero
	std::vector<float> prices4(prices3);
	prices4.insert(prices4.begin(), 5.64f);//Añadir al principio
	prices4.insert(prices4.begin(), 20.31f);//Añadir al principio
	prices4.insert(prices4.begin() + 1, 10);//Añadir el segundo


	//Print Prices 3

	std::cout << "prices3 contains: \n";

	/*for (std::vector<float>::iterator it = prices3.rbegin(); it != prices3.rend(); ++it) {
		std::cout << *it << " - ";
	}*/

	for (auto it = prices3.rbegin(); it != prices3.rend(); ++it) {
		std::cout << *it << " - ";
	}

	std::cout << '\n';
	std::cout << '\n';

	//Print Prices 4
	std::cout << "prices4 contains: \n";
	for (int i = 0; i <= prices4.size() - 1; i++) {

		std::cout << " - " << prices4[i];
	}
	std::cout << '\n';
	std::cout << '\n';


	//SUPERMERGE

	std::priority_queue<int> queue1;
	std::priority_queue<int> queue2;
	queue1.push(3);
	queue1.push(5);
	queue1.push(6);
	queue1.push(9);
	queue2.push(1);
	queue2.push(3);
	queue2.push(7);
	queue2.push(9);

	std::priority_queue<int> merge1_2;

	while (!queue1.empty()) {
	
		/*std::cout << queue1.top();
		queue1.pop();*/

		merge1_2.push(queue1.top());//Inserta el primer elemento del primer array
		std::cout << merge1_2.top();
		merge1_2.push(queue2.top());
		std::cout << merge1_2.top();
		queue1.pop();
		queue2.pop();
	}

	


	return(0);
}