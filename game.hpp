/*******************************************************************************
** Program Name: Birthday Adventure Game
** Authors: Kelly von Borstel
** Date: 3/19/2018
** Description: This is the declaration file for the game class, which has
** all the data and functions needed to run Ms. Whiskers' Birthday Bash game.
** To use it, create a game object in main. When the game runs, the user is 
** given instructions and then asked if they would like hints about how to win.
** Then they choose a difficulty level and begin. The game starts in the house,
** and the user moves around the other spaces in town. The interactions in each
** of the spaces are unique. The goal of the game is to purchase all the items
** on shopping list and get home before the party guests arrive. Once the game
** is over, the user is given the option to play again. The class contains
** member variables including pointers to each space, the time remaining, funds,
** a shopping bag and list, a main menu, and a menu to choose which direction
** to move. There are member functions to display instructions, get hints, set
** difficulty level, change location, brint bag contents, shopping list, or map,
** check if user has all items, and get and display the game status.
*******************************************************************************/

#include <vector>
#include <string>
using std::vector;
using std::string;

#include "house.hpp"
#include "catToyStore.hpp"
#include "plantStore.hpp"
#include "cleaningStore.hpp"
#include "postOffice.hpp"
#include "bank.hpp"
#include "menu.hpp"
#include "utility.hpp"

enum DiffcultyLevels {EASY = 1, AVERAGE, CHALLENGING};
enum GameStatus {PLAYING, WON, LOST};

class Game
{
    private:
        Space* house;
        Space* catToyStore;
        Space* plantStore;
        Space* cleaningStore;
        Space* postOffice;
        Space* bank;
        Space* currentLocation;
        int timeRemaining;
        int currentFunds;
        vector<string> shoppingBag;
        vector<string> shoppingList;
        Menu* gameMenu;
        Menu* directionMenu;

        void displayInstructions();
        void offerHelp();
        void printHints();
        void printHowToWin();
        void setDifficultyLevel();
        void buildSpaceStructure();
        void startGame();
        void changeLocation();
        void printBagContents();
        void printList();
        void printMap();
        GameStatus getGameStatus();
        void displayGameStatus(GameStatus status);
        bool haveAllItems();

    public:
        Game();
        void run();
        ~Game();
};
