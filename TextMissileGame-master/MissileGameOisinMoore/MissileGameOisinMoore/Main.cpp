// Name: Oisín Moore

#include<cstdlib>
#include<string.h>
#include<iostream>
#include<time.h>

typedef struct Position
{
	int x = 0;
	int y = 0;

	void print()
	{
		std::cout << x << "," << y << std::endl;
	}
}Coordinates;

enum WarheadSelection { Nuclear, Explosive };

typedef struct Enemy
{
	Coordinates enemyPosition;
}Target;

struct Missile
{
	WarheadSelection payload;

	Coordinates coordinates;

	Target target;

	bool armed;

	void arm()
	{
		if (armed)
			armed = false;
		else
			armed = true;
	}

	void update() {
		coordinates.x += 1;
		coordinates.y += 1;
	}
};

int main()
{
	srand(time(NULL));
	Missile rocket;
	int ChooseWarhead;
	int code = { rand() % 9000 + 1000};
	int inputCode;
	bool activation = false;



	std::cout << "Choose a Warhead to fire :  " << std::endl;
	std::cout << "1 = Explosive " << std::endl;
	std::cout << "2 = Nuclear " << std::endl;
	std::cin >> ChooseWarhead;
	
	while (ChooseWarhead != 1 && ChooseWarhead != 2)
	{
		{
			std::cout << "Wrong code" << std::endl;
			std::cin >> ChooseWarhead;
		}
	}
	if (ChooseWarhead == 1)
	{
		rocket.payload = WarheadSelection::Explosive;
	}
	else if (ChooseWarhead == 2)
	{
		rocket.payload = WarheadSelection::Nuclear;
	}
	
	

	rocket.target.enemyPosition.x = rand() % 50 + 1;
	rocket.target.enemyPosition.y = rand() % 50 + 1;

	std::cout << "Target at co-ordinates : ";
	rocket.target.enemyPosition.print();

	std::cout << "launch code: ";

	
		std::cout << code;
	

	std::cout << std::endl;

		std::cin >> inputCode;

		if (inputCode == code)
		{
			std::cout << "Activation code correct" << std::endl;
			activation = true;
		}
		else
		{
			std::cout << "Activation code incorrect" << std::endl;
			activation = false;
		}

	std::cout << std::endl;

	if (activation == true)
	{
		rocket.arm();

		while (true)
		{
			if (rocket.coordinates.x == rocket.target.enemyPosition.x || rocket.coordinates.y == rocket.target.enemyPosition.y)
			{	
				std::cout << "Target hit" << std::endl;
				break;
			}
			if (rocket.coordinates.x > rocket.target.enemyPosition.x || rocket.coordinates.y > rocket.target.enemyPosition.y)
			{
				std::cout << "not viable" << std::endl;
				std::cout << "Rocket disabled" << std::endl;
				rocket.arm();
				break;
			}

			rocket.update();

			std::cout << "viable" << std::endl;
		}
	}

	system("pause");
	return 0;
}