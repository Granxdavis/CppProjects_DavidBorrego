
#include <iostream>
using namespace std;


enum EnemyType {Zombie, Vampire, Ghost, Witch};
struct Enemy {	EnemyType type; 
				string name; 
				int health;
				};
