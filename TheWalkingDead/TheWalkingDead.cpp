#include <iostream>
#include <string>
#include <ctime>

//struct Player { Weapon weapon;  float precision; int life; };

//struct Zombie { int distanceToPlayer; float speed; float Damage; int life; };

enum class Weapon {	FISTS, 
				GUN, 
				SHOTGUN,
				REVOLVER, 
				SNIPER,
				MACHINE_GUN,
				MAX
			};

class Zombie;

class Player {
public: 
				Weapon weapon;  
				float precision; 
				int life; 

				void attack(Zombie &);
				bool isAlive;


				Player() : weapon(rand() % Weapon::MAX), precision(rand() % 2), life (rand()%20+80), isAlive(true) //Precision aleatoria entre 0 i 1
				{
				}
};


class Zombie { public:
				int distanceToPlayer; 
				float speed; 
				float Damage; 
				int life = 100; 

				void attack(Player &);
				bool isAlive = true;

				Zombie() : distanceToPlayer(rand() % 180 + 20), speed(rand() % 20), Damage(rand() % 20), life(rand() % 20 + 80), isAlive(true)
				{}

};

Player Pepe;

Zombie Melquiades;



//Funcion de ataaque del zombie
void Player::attack(Zombie & Melquiades)
{
	Melquiades.life -= Pepe.weapon * Pepe.precision;
}

//funcion de ataque del zombie
void Zombie::attack(Player& Pepe) {

	if (Melquiades.distanceToPlayer <= 0) {
		Pepe.life -= Melquiades.Damage;
	}
	else {
		Melquiades.distanceToPlayer -= 1;
	}

}


int main() {
	
	Player player;
	Zombie zombies [10];

	bool ZombiesAreAlive = true;

	do
	{
		for (int i = 0; i >= 9; i++) {
		
			if (zombies[i].isAlive) {
				
			}
		}


	} while (Pepe.isAlive && Melquiades.isAlive);

	
}
