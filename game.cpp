/*******************************************************************************
** Program Name: Birthday Adventure Game
** Authors: Kelly von Borstel
** Date: 3/19/2018
** Description: This is the implementation file for the game class, which has
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

#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <algorithm>
using std::cout;
using std::endl;

#include "game.hpp"

Game::Game()
{
}

/*******************************************************************************
** Description: The run function calls other functions to display instructions,
** offer the user option to get help before game begins, choose a difficulty
** level, and build the structure of spaces. It sets the current location to
** house, the shopping bag capacity to 8, and initializes the shopping list.
** The function has no parameters and returns nothing.
*******************************************************************************/

void Game::run()
{
    displayInstructions();
    offerHelp();
    setDifficultyLevel();
    buildSpaceStructure();
    currentLocation = house;
    shoppingBag.reserve(8);
    shoppingList = {"Ping Pong Balls", "Fresh Catnip", "Carpet Cleaner", 
        "Laser Pointer", "Potted Plant", "Lint Rollers"};
    startGame();
}


/*******************************************************************************
** Description: The displayInstructions function welcomes the player and tells
** them the goal of the game. It also explains some important details about
** the shopping bag, funds, and how time remaining is calculated. The function
** has no parameters and returns nothing.
*******************************************************************************/

void Game::displayInstructions()
{
    cout << "\033[2J\033[1;1H";
    cout << '\n' << string(55, '-') << endl;
    cout << "\nWelcome to Ms. Whiskers' Birthday Bash!" << endl;

    cout << "\nTo prepare for the party, you’ll need to buy supplies."
         << "\nYou’ll be given money and a list of items to buy."
         << "\nTo win the game, you must get back to the house with"
         << "\nall items before the guests arrive. The amounts of"
         << "\ntime and money you start with are determined by the"
         << "\ndifficulty level you choose." << endl;

    cout << '\n' << string(55, '-') << endl;
    cout << "\nNEED TO KNOW" << endl;
    cout << "\nYour shopping bag only holds 8 items. Everything you"
         << "\npick up is put in your bag. The only thing not in"
         << "\nyour bag is the money in your pocket." << endl;

    cout << "\nYou’ll have opportunities to find money as you move"
         << "\naround town. There’s no penalty for running out of"
         << "\nmoney, but without enough money, you won't be able"
         << "\nto buy all the items on your list." << endl;

    cout << "\nEvery time you move to a new space, 10 minutes is"
         << "\nsubtracted from the time remaining. Once you're"
         << "\nin a space, time stands still, so look around as"
         << "\nlong as you want." << endl;

    cout << "\nFrom inside any space, you can go back to the main"
         << "\nmenu to check your location, current funds, time"
         << "\nremaining, items on list, and items in your bag." << endl;

    cout << "\nImportant: You are unable to return to the house"
         << "\nunless you have every item on the list." << endl;
}


/*******************************************************************************
** Description: The offerHelp function give the user two options for help before
** the game starts, by providing either a list of hints or the precise steps to
** win the game. The function has no parameters and returns nothing.
*******************************************************************************/

void Game::offerHelp()
{
    cout << "\n" << string(55, '-') << endl;
    cout << "\nGET HELP" << endl;
    cout << "\nOnce you get started, you’re on your own, but here's"
         << "\nyour chance to get help before the game begins." << endl;

    vector<string> helpOptions = {"Give me some big hints",
                                  "Tell me exactly how to win",
                                  "I don't want any help"};
    Menu helpMenu(helpOptions);
    cout << "\nChoose from the following:" << endl;
    int helpChoice = helpMenu.run();

    if (helpChoice == 1)
    {
        printHints();
    }

    else if (helpChoice == 2)
    {
        printHowToWin();
    }
}


/*******************************************************************************
** Description: The printHints function prints a list of hints to help the user
** win the game. It has no parameters and returns nothing.
*******************************************************************************/

void Game::printHints()
{
    cout << string(55, '-') << endl;
    cout << "\nBIG HINTS" << endl;
    cout << "\nThere’s a puppy hiding behind the large plant.\n"
         << "\nThe bank teller knows where the catnip thief hangs out.\n"
         << "\nTake ID and keys to cash check and open locked spaces.\n"
         << "\nYou can remove extra items (not ID/keys) in post office.\n"
         << "\nWatch cleaning demo to get a coupon for carpet cleaner.\n"
         << "\nGo to post office bulletin board for lost pupppy flyer.\n"
         << "\nYou will lose money if you drop the small plant.\n"
         << "\nDon't take free laser pointer if you have catnip.\n"
         << "\nYou can't do anything in bank with puppy in your bag.\n" << endl;
}


/*******************************************************************************
** Description: The printHowToWin function displays step by step instructions
** on how to win. The instructions work regardless of the difficulty level
** chosen by user. The function has no parameters and returns nothing.
*******************************************************************************/

void Game::printHowToWin()
{
    cout << string(55, '-') << endl;
    cout << "\nHOW TO WIN" << endl;

    cout << "\nStarting in House"
         << "\n\tTake Keys"
         << "\n\tTake ID Card" << endl;

    cout << "\nMove to Cleaning Store"
         << "\n\tWatch demo and take coupon"
         << "\n\tBuy Carpet Cleaner"
         << "\n\tBuy Lint Rollers" << endl;

    cout << "\nMove to Post Office"
         << "\n\tGet mail and take Check"
         << "\n\tGo to bulletin board and take Lost Puppy Flyer" << endl;

    cout << "\nMove to Bank"
         << "\n\tCash Check"
         << "\n\tOpen safe deposit box and take coins" << endl;

    cout << "\nMove to Plant Store"
         << "\n\tBuy large Potted Plant"
         << "\n\tBuy Fresh Catnip" << endl;

    cout << "\nMove to Cat Toy Store"
         << "\n\tBuy Laser Pointer"
         << "\n\tBuy regular Ping Pong Balls" << endl;

    cout << "\nMove to House and you win!\n" << endl;
}


/*******************************************************************************
** Description: The setDifficultyLevel function presents the user with three
** different levels of difficulty to choose from. The level they choose 
** determines the amounts of money and time they start the game with. The 
** function has no parameters and returns nothing.
*******************************************************************************/

void Game::setDifficultyLevel()
{
    cout << string(55, '-') << endl;
    cout << "\nLet's get started! Here's a map of the town.\n" << endl;
    printMap();
    cout << string(55, '-') << endl;
    cout << "\nChoose a difficulty level:" << endl;
    vector<string> levels = {"Easy - 3 hours, $200",
                             "Average - 2 hours, $50",
                             "Challenging - 1 hour, $15"};

    Menu levelsMenu(levels);
    int difficultyLevel = levelsMenu.run();

    if (difficultyLevel == EASY)
    {
        timeRemaining = 180;
        currentFunds = 200;
    }

    else if (difficultyLevel == AVERAGE)
    {
        timeRemaining = 120;
        currentFunds = 50;
    }

    else
    {
        timeRemaining = 60;
        currentFunds = 15;
    }
}


/*******************************************************************************
** Description: The buildSpaceStructure function allocates memory for each of
** the pointers to the six spaces in the game. It also sets the adjacent spaces
** for each one by passing in the spaces to the top, right, bottom, and left.
** The function has no parameters and returns nothing.
*******************************************************************************/

void Game::buildSpaceStructure()
{
    house = new House("House");
    catToyStore = new CatToyStore("Cat Toy Store");
    plantStore = new PlantStore("Plant Store");
    cleaningStore = new CleaningStore("Cleaning Supply Store");
    postOffice = new PostOffice("Post Office");
    bank = new Bank("Bank");

    house->setAdjacent(catToyStore, cleaningStore, nullptr, nullptr);
    catToyStore->setAdjacent(nullptr, plantStore, house, nullptr);
    plantStore->setAdjacent(nullptr, bank, cleaningStore, catToyStore);
    cleaningStore->setAdjacent(plantStore, postOffice, nullptr, house);
    postOffice->setAdjacent(bank, nullptr, nullptr, cleaningStore);
    bank->setAdjacent(nullptr, nullptr, postOffice, plantStore);
}


/*******************************************************************************
** Description: The startGame function displays a menu of options and gets the
** user's choice until they choose to quit or they win or lose the game. The
** options include looking around the space, changing location, printing the
** bag contents, printing the list, or printing the map. If the player has
** won or lost, functions are called to display that information. The function
** has no parameters and returns nothing.
*******************************************************************************/

void Game::startGame()
{
    vector<string> gameMenuOptions = {"Look around space",
                                      "Go somewhere else",
                                      "Print bag contents",
                                      "Print shopping list",
                                      "Print map of town",
                                      "Exit game"};

    gameMenu = new Menu(gameMenuOptions);
    int choice = 0;

    while (choice != 6)
    {
        if (getGameStatus() == PLAYING)
        {
            displayGameStatus(PLAYING);

            cout << "\nWhat would you like to do?" << endl;
            choice = gameMenu->run();

            if (choice == 1)
            {
                currentLocation->lookAround(currentFunds, shoppingBag);
            }

            else if (choice == 2)
            {
                changeLocation();
            }

            else if (choice == 3)
            {
                printBagContents();
            }

            else if (choice == 4)
            {
                printList();
            }

            else if (choice == 5)
            {
                printMap();
            }
        }

        else if (getGameStatus() == WON)
        {
            displayGameStatus(WON);
            return;
        }

        else
        {
            displayGameStatus(LOST);
            return;
        }
    }
}


/*******************************************************************************
** Description: The changeLocation function first prints the map of the town
** and then determines which spaces or adjacent to the current space, and gives
** the player the option to move to one of those spaces. It then updates the
** player's current location and adjusts the time remaining. If the player
** wants to move to the house, it checks if they have all the items on the list.
** If they don't, a message is printed and they aren't allowed to move to the
** house. The function has no parameters and returns nothing.
*******************************************************************************/

void Game::changeLocation()
{
    printMap();
    vector<Space*> adjacentSpaces;
    vector<string> adjacentNames;

    if (currentLocation->getLeft())
    {
        adjacentSpaces.push_back(currentLocation->getLeft());
    }

    if (currentLocation->getTop())
    {
        adjacentSpaces.push_back(currentLocation->getTop());
    }

    if (currentLocation->getRight())
    {
        adjacentSpaces.push_back(currentLocation->getRight());
    }

    if (currentLocation->getBottom())
    {
        adjacentSpaces.push_back(currentLocation->getBottom());
    }

    for (Space* space : adjacentSpaces)
    {
        adjacentNames.push_back(space->getName());
    }

    Menu adjacentMenu(adjacentNames);

    cout << string(55, '-') + '\n' << endl;
    cout << "Where do you want to go?" << endl;
    int adjChoice =  adjacentMenu.run();
    Space* newLocation = (adjacentSpaces[adjChoice - 1]);

    if (newLocation == house && !haveAllItems())
    {
        cout << string(55, '-') << endl;
        cout << "\nSorry, Ms. Whiskers says you can't return home"
             << "\nuntil you have all items on list.\n" << endl;
    }

    else
    {
        currentLocation = (adjacentSpaces[adjChoice - 1]);
        timeRemaining -= 10;
    }
}


/*******************************************************************************
** Description: The printBagContents function prints the number of items in
** in the bag and a list of those items. If the bag is empty, it prints message
** saying that. The function has no parameters and returns nothing.
*******************************************************************************/

void Game::printBagContents()
{
    cout << string(55, '-') + '\n' << endl;
    cout << "BAG CONTENTS (" << shoppingBag.size() << " items):" << endl;

    if (shoppingBag.empty())
    {
        cout << "Your bag is empty" << endl;
    }

    else
    {
        for (string item : shoppingBag)
        {
            cout << item << endl;
        }
    }

    cout << '\n';
}


/*******************************************************************************
** Description: The printList function prints the number of items on the list
** and what those items are. The function has no parameters and returns nothing.
*******************************************************************************/

void Game::printList()
{
    cout << string(55, '-') + '\n' << endl;
    cout << "SHOPPING LIST (" << shoppingList.size() << " items):" << endl;

    for (string item : shoppingList)
    {
        cout << item << endl;
    }

    cout << '\n';
}


/*******************************************************************************
** Description: The printMap function prints a map of the town with the spaces
** labeled. The function has no parameters and returns nothing.
*******************************************************************************/

void Game::printMap()
{
    cout << string(55, '-') << endl;
    cout << "|                 |                 |                 |" << endl;
    cout << "|                 |                 |                 |" << endl;
    cout << "|     Cat Toy     |   Plant Store   |       Bank      |" << endl;
    cout << "|      Store      |                 |                 |" << endl;
    cout << "|                 |                 |                 |" << endl;
    cout << "|                 |                 |                 |" << endl;
    cout << string(55, '-') << endl;
    cout << "|                 |                 |                 |" << endl;
    cout << "|                 |                 |                 |" << endl;
    cout << "|      House      |     Cleaning    |   Post Office   |" << endl;
    cout << "|                 |   Supply Store  |                 |" << endl;
    cout << "|                 |                 |                 |" << endl;
    cout << "|                 |                 |                 |" << endl;
}


/*******************************************************************************
** Description: The getGameStatus function checks to see if the game is won,
** lost, or still playing. If the player is at the house with all list items,
** they win. If they run out of time, they lose. Otherwise, they continue to
** play. The function has no parameters and returns nothing.
*******************************************************************************/

GameStatus Game::getGameStatus()
{
    if (currentLocation == house && haveAllItems())
    {
        return WON;
    }

    else if (timeRemaining == 0)
    {
        return LOST;
    }

    else
    {
        return PLAYING;
    }
}


/*******************************************************************************
** Description: The displayGameStatus function has one parameter, the status
** of the game. If the status is playing, it displays their location, funds,
** and time remaining. If status is won or lost, a message is printed saying 
** that. The function returns nothing.
*******************************************************************************/

void Game::displayGameStatus(GameStatus status)
{
    cout << string(55, '-') + "\n" << endl;

    if (status == PLAYING)
    {
        cout << "Your Location: " << currentLocation->getName() << endl;
        cout << "Current Funds: $" << currentFunds << endl;
        cout << "Time Remaining: " << timeRemaining << " minutes" << endl;
    }

    else if (status == WON)
    {
        cout << "YOU WON" << endl;
        cout << "You're home with all the supplies in time to greet"
             << "\nthe party guests. Ms. Whiskers is very pleased.\n" << endl;
    }

    else
    {
        cout << "YOU LOST" << endl;
        cout << "Your guests have arrived but you're not there."
             << "\nMs. Whiskers is very disappointed.\n" << endl;
    }
}


/*******************************************************************************
** Description: The haveAllItems function checks to see if all the items on
** the shopping list are in the shopping bag. If so, it returns true. If not,
** it returns false. The code for this function is based on this resource:
** https://stackoverflow.com/questions/6906521/how-to-check-whether-a-vector-
** is-a-subset-of-another-in-c
*******************************************************************************/

bool Game::haveAllItems()
{
    for (int i = 0; i < shoppingList.size(); i++)
    {
        bool found = false;

        for (int j = 0; j < shoppingBag.size(); j++)
        {
            if (shoppingList[i] == shoppingBag[j])
            {
                found = true;
                break;
            }
        }

        if (!found)
        {
            return false; 
        }
    }

    return true;
}


/*******************************************************************************
** Description: The destructor function deallocates memory for each of the space
** pointers and main game menu.
*******************************************************************************/

Game::~Game()
{
    delete house;
    delete catToyStore;
    delete plantStore;
    delete cleaningStore;
    delete postOffice;
    delete bank;
    delete gameMenu;
}

#endif
