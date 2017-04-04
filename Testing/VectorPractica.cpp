#include <vector>
using namespace std;


struct person {
	string Nombre;
	int edad;
	string DNI;

};

int main() {
	std::vector<int>v1(5);

	std::vector<int>v2(10, 0);

	std::vector<int> v3({ 10,9,8,7,6,5,4,3,2,1 });

	std::vector<string> v4({ "Gertrudiz", "Pancracia", "Anacleto", "Hipolito", "Eustaquio", "Fulgencia" });

	std::vector<int>v5(v3);

	std::vector <person>v6({ {"Pepe", 23, "45782145J"},{"Pancracio", 754, "14578963H"},{"Joselita", 2, "45721405R"} });
	
	

	

	return(0);
}