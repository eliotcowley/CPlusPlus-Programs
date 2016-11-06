/* 
	11.x.3.cpp : Challenge time! The following quiz question is more difficult and lengthy. We're going to write a simple game where you fight monsters.
	The goal of the game is to collect as much gold as you can before you die or get to level 20.

	Our program is going to consist of 3 classes: A Creature class, a Player class, and a Monster class. Player and Monster both inherit from Creature.

	a) First create the Creature class. Creatures have 5 attributes: A name (std::string), a symbol (a char), an amount of health (int), the amount of
	damage they do per attack (int), and the amount of gold they are carrying (int). Implement these as class members. Write a full set of getters (a
	get function for each member). Add three other functions: void reduceHealth(int) reduces the Creature's health by an integer amount. bool isDead()
	returns true when the Creature's health is 0 or less. void addGold(int) adds gold to the Creature.

	The following program should run:

	#include <iostream>
	#include <string>
 
	int main()
	{
		Creature o("orc", 'o', 4, 2, 10);
		o.addGold(5);
		o.reduceHealth(1);
		std::cout << "The " << o.getName() << " has " << o.getHealth() << " health and is carrying " << o.getGold() << " gold.\n.";
 
		return 0;
	}

	And produce the result:

	The orc has 3 health and is carrying 15 gold.

	b) Now we're going to create the Player class. The Player class inherits from Creature. Player has one additional member, the player's level, which
	starts at 1. The player has a custom name (entered by the user), uses symbol '@', has 10 health, does 1 damage to start, and has no gold. Write a
	function called levelUp() that increases the player's level and damage by 1. Also write a getter for the level member. Finally, write a function
	called hasWon() that returns true if the player has reached level 20.

	Write a new main() function that asks the user for their name and produces the output as follows:

	Enter your name: Alex
	Welcome, Alex.
	You have 10 health and are carrying 0 gold.

	3c) Next up is the Monster class. Monster also inherits from Creature. Monsters have no non-inherited member variables.

	First, write an empty Monster class inheriting from Creature, and then add an enum inside the Monster class named Type that contains enumerators for
	the 3 monsters that we'll have in this game: DRAGON, ORC, and SLIME (you'll also want a MAX_TYPES enumerator, as that will come in handy in a bit).

	3d) Each Monster type will have a different name, symbol, starting health, gold, and damage. Here is a table of stats for each monster Type:

	Type	Name	Symbol	Health	Damage	Gold
	DRAGON	dragon	D		20		4		100
	ORC		orc		o		4		2		25
	SLIME	slime	s		1		1		10

	Next step is to write a Monster constructor, so we can create monsters. The Monster constructor should take a Type enum as a parameter, and then
	create a Monster with the appropriate stats for that kind of monster.

	There are a number of different ways to implement this (some better, some worse). However in this case, because all of our monster attributes are
	predefined (not random), we'll use a lookup table. A lookup table is an array that holds all of the predefined attributes. We can use the lookup
	table to look up the attributes for a given monster as needed.

	So how do we implement this lookup table? It's not hard. We just need two things. First, we need an array that contains an element for each monster
	Type. Each array element will contain a struct that contains all of the predefined attribute values for that Type of Monster.

	Step 1: Create a struct type inside Monster named MonsterData. This struct should have a member for each attribute (name, symbol, health, damage,
	and gold).

	Step 2: Declare an array of that struct as a static member of the class named monsterData (define this like a normal array member, and then add the
	word static before it).

	Step 3: Add the following code outside of the class. This is the definition for our lookup table:

	Monster::MonsterData Monster::monsterData[Monster::MAX_TYPES]
	{
		{ "dragon", 'D', 20, 4, 100 },
		{ "orc", 'o', 4, 2, 25 },
		{ "slime", 's', 1, 1, 10 },
	};

	Now we can index this array to lookup any values we need! For example, to get a Dragon's gold, we can access monsterData[DRAGON].gold.

	Use this lookup table to implement your constructor:

	Monster(Type type): Creature(monsterData[type].name, ...)

	The following program should compile:

	#include <iostream>
	#include <string>
	 
	 int main()
	 {
		 Monster m(Monster::ORC);
		 std::cout << "A " << m.getName() << " (" << m.getSymbol() << ") was created.\n";
	 }

	 and print:

	 A orc (o) was created.

	 3e) Finally, add a static function to Monster named getRandomMonster(). This function should pick a random number between 0 and MAX_TYPES-1 and
	 return a monster (by value) with that Type (you'll need to static_cast the int to a Type to pass it to the Monster constructor).

	 You can use the following code to pick a random number:

	 #include <cstdlib> // for rand() and srand()
	 #include <ctime> // for time()
	  
	  // Generate a random number between min and max (inclusive)
	  // Assumes srand() has already been called
	  int getRandomNumber(int min, int max)
	  {
		  // static used for efficiency, so we only calculate this value once
		  static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
		    
		  // evenly distribute the random number across our range
		  return static_cast<int>(rand() * fraction * (max - min + 1) + min);
	  }

	  The following main function should run:

	  #include <iostream>
	  #include <string>
	  #include <cstdlib> // for rand() and srand()
	  #include <ctime> // for time()
	   
	   int main()
	   {
		   srand(static_cast<unsigned int>(time(0))); // set initial seed value to system clock
		   rand(); // get rid of first result
	    
		   for (int i = 0; i < 10; ++i)
		   {
				Monster &m = Monster::getRandomMonster();
				std::cout << "A " << m.getName() << " (" << m.getSymbol() << ") was created.\n";
		   }
		}

		The results of this program should be randomized.

	3f) We're finally set to write our game logic!

	Here are the rules for the game:

	The player encounters one randomly generated monster at a time.
	For each monster, the player has two choices: (R)un or (F)ight.
	If the player decides to Run, they have a 50% chance of escaping.
	If the player escapes, they move to the next encounter will no ill effects.
	If the player does not escape, the monster gets a free attack, and the player chooses their next action.
	If the player chooses to fight, the player attacks first. The monster's health is reduced by the player's damage.
	If the monster dies, the player levels up, increasing their level and damage by 1.
	If the monster does not die, the monster attacks the player back. The player's health is reduced by the player's damage.
	The game ends when the player has died (loss) or reached level 20 (win)
	If the player dies, the game should tell the player what level they were and how much gold they had.
	If the player wins, the game should tell the player they won, and how much gold they had

	Here's a sample game session:

	Enter your name: Alex
	Welcome, Alex
	You have encountered a slime (s).
	(R)un or (F)ight: f
	You hit the slime for 1 damage.
	You killed the slime.
	You are now level 2.
	You found 5 gold.
	You have encountered a dragon (D).
	(R)un or (F)ight: r
	You failed to flee.
	The dragon hit you for 4 damage.
	(R)un or (F)ight: r
	You successfully fled.
	You have encountered a orc (o).
	(R)un or (F)ight: f
	You hit the orc for 2 damage.
	The orc hit you for 2 damage.
	(R)un or (F)ight: f
	You hit the orc for 2 damage.
	The orc hit you for 2 damage.
	(R)un or (F)ight: f
	You hit the orc for 2 damage.
	You are now level 3.
	You found 25 gold.
	You have encountered a dragon (D).
	(R)un or (F)ight: r
	You failed to flee.
	The dragon hit you for 4 damage.
	You died at level 3 and with 30 gold.
	Too bad you can't take it with you!

	Hint: Create 4 functions:

	The main() function should handle game setup (creating the Player) and the main game loop.

	fightMonster() handles the fight between the Player and a single Monster, including asking the player what they want to do, handling the run or
	fight cases.

	attackMonster() handles the player attacking the monster, including leveling up.

	attackPlayer() handles the monster attacking the player.
*/

#include "stdafx.h"
#include "Creature.h"
#include "Player.h"
#include "Monster.h"
#include <iostream>
#include <ctime>

void attackMonster(Player &player, Monster &monster)
{
	cout << "You hit the " << monster.getName() << " for " << player.getDamage() << " damage.\n";
	monster.reduceHealth(player.getDamage());
	if (monster.isDead())
	{
		cout << "You killed the " << monster.getName() << ".\n";
		player.levelUp();
		cout << "You are now level " << player.getLevel() << ".\n";
		cout << "You found " << monster.getGold() << " gold.\n";
		player.addGold(monster.getGold());
	}
}

void attackPlayer(Player &player, Monster &monster)
{
	cout << "The " << monster.getName() << " hit you for " << monster.getDamage() << " damage.\n";
	player.reduceHealth(monster.getDamage());
}

void fightMonster(Player &player)
{
	Monster m{ Monster::getRandomMonster() };
	cout << "You have encountered a " << m.getName() << " (" << m.getSymbol() << ").\n";
	char input;
	/*while ((input != 'r') && (input != 'f'))
	{
		cout << "Sorry, I don't recognize that command. Please enter 'r' to run or 'f' to fight: ";
		cin >> input;
	}*/

	while (!player.isDead() && !m.isDead())
	{
		cout << "(R)un or (F)ight: ";
		cin >> input;

		if (input == 'r')
		{
			if (Monster::getRandomNumber(0, 1) == 0)
			{
				cout << "You successfully fled.\n";
				return;
			}
			else
			{
				cout << "You failed to flee.\n";
				attackPlayer(player, m);
			}
		}
		else
		{
			attackMonster(player, m);
			if (!m.isDead())
			{
				attackPlayer(player, m);
			}
		}
	}
}

int main()
{
	srand(static_cast<unsigned int>(time(0))); // set initial seed value to system clock
	rand(); // get rid of first result

	cout << "Enter your name: ";
	string name;
	cin >> name;
	cout << "Welcome, " << name << ".\n";
	Player player{ name };

	while (!player.isDead() && !player.hasWon())
	{
		fightMonster(player);
	}

	if (player.isDead())
	{
		cout << "You died at level " << player.getLevel() << " with " << player.getGold() << " gold.\n";
		cout << "Too bad you can't take it with you!\n";
	}
	else
	{
		cout << "You won! You have " << player.getGold() << " gold.\n";
	}

    return 0;
}

