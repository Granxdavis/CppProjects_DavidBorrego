#include "stdafx.h"

enum class EnemyType { zombie, vampire, ghost, witch, MAX };

struct Enemy {

	EnemyType type;
	std::string name;
	int health;

	std::string getEnemyTypeString() {
		switch (type)
		{
		case EnemyType::zombie:
			return  "zombie";
			break;
		case EnemyType::vampire:
			return  "vampire";
			break;
		case EnemyType::ghost:
			return  "ghost";
			break;
		case EnemyType::witch:
			return  "witch";
			break;
		}
	}

};

bool operator== (const Enemy &a, const Enemy &b) {
	return (a.name == b.name && a.type == b.type);
}

static Enemy createRandomEnemy() {

	static const int MIN_LIFE{ 100 };
	static const int MAX_LIFE{ 300 };

	static const std::string NAMES[] = { "Goku","Vegeta","Krillin","Cor Petit","Gohan","Trunks","Goten","Tenshinhan","Chaos" };

	return Enemy{
		static_cast<EnemyType>(rand() % static_cast<int>(EnemyType::MAX)),
		NAMES[rand() % (sizeof NAMES / sizeof std::string)],
		MIN_LIFE + rand() % (MAX_LIFE - MIN_LIFE + 1)
	};
}

int main()
{
	srand(static_cast<unsigned>(time(nullptr)));
	const int MAX_ENEMIES{ 5 };
	Enemy enemies[MAX_ENEMIES];

	{
		int i{ 0 };
		while (i < MAX_ENEMIES) {
			enemies[i] = createRandomEnemy();
			int j{ i - 1 };
			while (j >= 0) {
				if (enemies[i] == enemies[j]) {
					--i;
					break;
				};
				j--;
			}
			++i;
		}
	}

	std::cout << "List of enemies:\n";
	for (auto &enemy : enemies) {
		std::cout << enemy.name <<
			" is a " << enemy.getEnemyTypeString() <<
			" whose life is " << enemy.health << std::endl;
	}

	return 0;
}
