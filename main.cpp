/*******************************************************************************
** Program Name: Birthday Adventure Game 
** Authors: Kelly von Borstel
** Date: 3/19/2018
** Description: This program is a text-based game where the user's goal is to
** buy all the supplies for a birthday party and get home before the guests
** arrive. The user moves around town, interacting with each space, finding
** money, and buying items on their list. To run the program, type "make" at 
** the command line, then type "./game", then follow the prompts.
*******************************************************************************/

#include <iostream>
#include <vector>
#include <string>
using std::cout;
using std::endl;
using std::vector;
using std::string;

#include "menu.hpp"
#include "game.hpp"

int main()
{
    int choice = 0;

    while (choice != 2)
    {
        Game game;
        game.run();
        cout << string(55, '-') << endl;
        cout << "\nDo you want to play again?" << endl;
        vector<string> endOptions = {"Yes", "No"};
        Menu endMenu(endOptions);
        choice = endMenu.run();
    }

    return 0;
}
