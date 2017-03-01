#include <iostream>
#include <string>
#include <ctime>

//struct Player { Weapon weapon;  float precision; int life; };

//struct Zombie { int distanceToPlayer; float speed; float Damage; int life; };

enum class Weapon 
{	
	FISTS, 
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

				


				Player() :
					weapon(static_cast <Weapon>(rand() % static_cast<int>(Weapon::MAX))), 
					precision((rand() % 10)/10.f),//numero aleatorio entre 0 i 9 y luego dividir entre 10 con un float
					life(100) {};
													
				Player(const Weapon &t_weapon, float t_precision, int t_life) :
					weapon(t_weapon),
					precision(t_precision),
					life(t_life) {};


				void attack(Zombie &Melquiades) const;
				bool isAlive() const;
};


class Zombie { public:
				int distanceToPlayer; 
				float speed; 
				float Damage; 
				int life = 100; 

				Zombie() :
					distanceToPlayer(rand() % 180 + 20),
					speed((rand() % 20)/10.f),
					Damage((rand() % 20) / 10.f),
					life(100) {};


				Zombie(int t_distanceToPlayer, float t_speed, float t_Damage, int t_life) :
					distanceToPlayer(t_distanceToPlayer),
					speed(t_speed),
					Damage(t_Damage),
					life(t_life){};

				void attack(Player &Pepe) const;
				bool isAlive() const;

				

};

Player Pepe;

Zombie Melquiades;



//Funcion de ataaque del zombie
void Player::attack(Zombie & Melquiades) const
{
	Melquiades.life -= static_cast<int>(static_cast<int>(weapon)*precision);
}


bool Player::isAlive() const {
	return life > 0;
}

//funcion de ataque del zombie
void Zombie::attack(Player& Pepe) const {

	if (distanceToPlayer <= 0) {
		Pepe.life -= static_cast<int>(Damage);
	}
	else {
		distanceToPlayer --;
	}

}



bool Zombie::isAlive() const {
	return life > 0;
}


int main() {

	srand(static_cast <unsigned> (time(nullptr)));
	
	Player player;
	const int MAX_ZOMBIES{ 10 };
	Zombie zombies [MAX_ZOMBIES];


	std::cout << "Player\n\tinitial life: " << player.life <<
		", weapon: " << player.weapon <<
		", precision: " << player.precision << std::end;

	std::cout << "ZOMBIES ARE COMING!" << std::endl;


	bool ZombiesAreAlive;

	do
	{
		ZombiesAreAlive = false;

		std::cout << "Player\n\tlife: " << player.life << std::endl;

		for (int i{ 0 }; i < MAX_ZOMBIES; i++) {

			std::cout << "Zombie[" << i <<
				"]\n\tlife: " << zombies[i].life <<
				", distance: " << zombies[i].distanceToPlayer <<
				", speed: " << zombies[i].speed <<
				", damage: " << zombies[i].Damage << std::endl;

			if (zombies[i].isAlive()) {
				player.attack(zombies[i]);
				zombies[i].attack(player);
			}
		
		
			
		}


	} while (Pepe.isAlive && Melquiades.isAlive);

	
}
