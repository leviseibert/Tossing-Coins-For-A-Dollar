// Tossing Coins for a Dollar.cpp 
// Levi Seibert
// CS 318
// This program flips a nickel, dime, and quarter.  If any lands heads-up, their balance is added to the total balance.  The game is won if the total balance reaches exactly $1.00 and is lost if the balance exceeds $1.00

#include "pch.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
using namespace std;

//Open output file
ofstream output("Coin Toss Output.txt");

//Define constants
const float QUARTER = 0.25;
const float DIME = 0.10;
const float NICKEL = 0.05;
const float END_GAME = 1.00;

//Define the Coin class
class Coin
{
public:
	//Constructor
	Coin()
	{ side = rand() % 2; }

	//Setter method
	void toss()
	{ side = rand() % 2; }

	//Getter method
	int getSideUp()
	{ return side; }

private:
	//0 is tails, 1 is heads
	int side;
};

int main()
{
	output << setprecision(2) << showpoint << fixed;

	//Run the program 10 times
	for (int i = 0; i < 10; i++)
	{
		//Create the three class instances and define balance
		Coin nickel, dime, quarter;
		float balance = 0.0;

		output << "Game " << i + 1 << ": " << endl;

		//While the balance is less than $1.00
		while (balance < END_GAME)
		{
			//Toss nickel, add to balance if heads-up (1), and check if balance greater than or equal to $1.00
			nickel.toss();
			if (nickel.getSideUp() == 1)
			{
				balance += NICKEL;
				output << "Balance: $" << balance << endl;
				if (balance == END_GAME)
				{
					output << "Game Won!";
					break;
				}

				else if (balance > END_GAME)
				{
					output << "Game Lost!";
					break;
				}
			}

			//Toss dime, add to balance if heads-up (1), and check if balance greater than or equal to $1.00
			dime.toss();
			if (dime.getSideUp() == 1)
			{
				balance += DIME;
				output << "Balance: $" << balance << endl;
				if (balance == END_GAME)
				{
					output << "Game Won!";
					break;
				}

				else if (balance > END_GAME)
				{
					output << "Game Lost!";
					break;
				}
			}

			//Toss quarter, add to balance if heads-up (1), and check if balance greater than or equal to $1.00
			quarter.toss();
			if (quarter.getSideUp() == 1)
			{
				balance += QUARTER;
				output << "Balance: $" << balance << endl;
				if (balance == END_GAME)
				{
					output << "Game Won!";
					break;
				}

				else if (balance > END_GAME)
				{
					output << "Game Lost!";
					break;
				}
			}
		}

		output << endl << endl;
	}
	//Close the file
	output.close();
	return 0;
}