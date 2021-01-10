#include <iostream>
#include <random>
#include <array>
using namespace std;

int main(int argc, char* argv[])
{
	char newGame = 'y';
	while (newGame != 'n')
	{
		// Local Variables
		int userPick;
		int winningDoor;
		int prizeNum;
		char decision;
		random_device rand{};
		default_random_engine engine{ rand() };
		uniform_int_distribution <int> prizeDoor{ 1,3 };
		//Prize Pool: 1 = Brand New Car , 2 = A Trip to Hawaii, 3 = 1 Million Dollars , 4 = A Trip to Rome, 5 = 2 Night Disney Cruise
		array<string, 5> prizes = { "Brand New Car", "A Trip to Hawaii", "$1,000,000", "A Trip to Rome", "2 Night Disney Cruise" };
		uniform_int_distribution <int> prizesIndex{ 1,5 };

		// Randomly selects a winning door
		winningDoor = prizeDoor(engine);
		cout << "Please Choose A Door: 1 2 3" << endl;
		cin >> userPick;

		// User Must Select 1 2 3
		while (userPick > 3 || userPick < 1)
		{
			cout << "Please Choose A Door: 1 2 3" << endl;
			cin >> userPick;
		}

		// Case: User Selects First Door
		if (userPick == 1)
		{
			// Reveals One of the Doors with a goat
			if (winningDoor == 3)
			{
				cout << "Behind Door 2 is a goat. Would you like to switch to Door 3 or stay with Door 1? ( y or n )" << endl;
				cin >> decision;
				if (decision == 'y')
				{
					userPick = 3;
				}
			}
			else
			{
				cout << "Behind Door 3 is a goat. Would you like to switch to Door 2 or stay with Door 1?" << endl;
				cin >> decision;
				if (decision == 'y')
				{
					userPick = 2;
				}
			}
		}
		// Case: User selects Second Door
		else if (userPick == 2)
		{
			// Reveals One of the Doors with a goat
			if (winningDoor == 3)
			{
				cout << "Behind Door 1 is a goat. Would you like to switch to Door 3 or stay with Door 2?" << endl;
				cin >> decision;
				if (decision == 'y')
				{
					userPick = 3;
				}
			}
			else
			{
				cout << "Behind Door 3 is a goat. Would you like to switch to Door 1 or stay with Door 2?" << endl;
				cin >> decision;
				if (decision == 'y')
				{
					userPick = 1;
				}
			}
		}
		// Case: User Selects Door 3
		else if (userPick == 3)
		{
			// Reveals One of the Doors with a goat
			if (winningDoor == 2)
			{
				cout << "Behind Door 1 is a goat. Would you like to switch to Door 2 or stay with Door 3?" << endl;
				cin >> decision;
				if (decision == 'y')
				{
					userPick = 2;
				}
			}
			else
			{
				cout << "Behind Door 2 is a goat. Would you like to switch to Door 1 or stay with Door 3?" << endl;
				cin >> decision;
				if (decision == 'y')
				{
					userPick = 1;
				}
			}
		}

		// If user wins or loses
		if (userPick != winningDoor)
		{
			cout << "You have choosen the goat. Better luck next time";
		}
		else
		{
			cout << "You have choosen the winning door.";
			// Randomly Generates a Num from 1 - 5 INCLUSIVE
			prizeNum = prizesIndex(engine);
			// Gives A Random Prize
			cout << " You won " << prizes[prizeNum] << endl;
		}
		cout << "\nPlay New Game? (y or n)" << endl;
		cin >> newGame;
	}
}
