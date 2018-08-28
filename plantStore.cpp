/*******************************************************************************
** Program Name: Birthday Adventure Game 
** Authors: Kelly von Borstel
** Date: 3/19/2018
** Description: This is implementation file for plantStore class, which is
** derived from space class. In addition to the member variable and function
** it inherits, it has two addition member variable to keep track of whether
** the puppy was found and whether the plant was dropped. It overrides the 
** virtual function that looks around to include a description and menu options
** specific to this space. It has four additional functions to purchase catnip,
** purchase a small or large plant, and run scenario when puppy is found.
*******************************************************************************/

#include "plantStore.hpp"

PlantStore::PlantStore(string name) : Space(name)
{
    foundPuppy = false;
    droppedPlant = false;
}


/*******************************************************************************
** Description: The lookAround function has two parameters, a reference to
** an integer of the user's funds and a reference to a vector of strings of
** the names of items in their shopping bag. After describing the space, the
** function gets the user's choice from a menu of options and calls other
** functions based on their choice. It returns nothing.
*******************************************************************************/

void PlantStore::lookAround(int& funds, vector<string>& bag)
{
    cout << string(55, '-') << endl;
    cout << "\nThe Plant Store has bags of Fresh Catnip on a"
         << "\nshelf to your left and Potted Plants in a sunny"
         << "\narea towards the back." << endl;

    vector<string> spaceMenuOptions = {"Buy Fresh Catnip - $10",
                                       "Buy small Potted Plant - $15",
                                       "Buy large Potted Plant - $30",
                                       "Go back to Main Menu"};

    Menu spaceMenu(spaceMenuOptions);
    int choice = 0;
    
    while (choice != 4)
    {
        cout << "\nWhat would you like to do?" << endl;
        choice = spaceMenu.run();

        if (choice == 1)
        {
            buyCatnip(funds, bag);
        }

        else if (choice == 2)
        {
            buySmallPlant(funds, bag);
        }

        else if (choice == 3)
        {
            buyLargePlant(funds, bag);
        }
    }
}


/*******************************************************************************
** Description: The buyCatnip function has two parameters, a reference 
** to an integers of the user's funds and a reference to a vector of strings
** of the names of items in their shopping bag. It checks if there is space
** in their bag and enough funds to purchase the item. If so, it then checks
** if they already have the item or don't want another. If neither is the case,
** the items is added to bag. The function returns nothing.
*******************************************************************************/

void PlantStore::buyCatnip(int& funds, vector<string>& bag)
{
    if (haveSpace(bag) && haveFunds(10, funds))
    {
        if (haveItem("Fresh Catnip", bag) && !wantAnother("Fresh Catnip"))
        {
            cout << string(55, '-') << endl;
            cout << "\nNothing was added to your bag." << endl;
            return;
        }

        addItem("Fresh Catnip", bag, 10, funds);
    }
}


/*******************************************************************************
** Description: The buySmallPlant function has two parameters, a reference 
** to an integers of the user's funds and a reference to a vector of strings
** of the names of items in their shopping bag. It checks if there is space
** in their bag and enough funds to purchase the item. If so, it then checks
** if they already have the item or don't want another. If this is the user's
** first time to purchase a small plant, a message is printed that the plant
** was dropped and broken. If it isn't their first time, a message is printed 
** that there are no more small plants. The function returns nothing.
*******************************************************************************/

void PlantStore::buySmallPlant(int& funds, vector<string>& bag)
{
    if (haveSpace(bag) && haveFunds(15, funds))
    {
        if (haveItem("Potted Plant", bag) && !wantAnother("Potted Plant"))
        {
            cout << string(55, '-') << endl;
            cout << "\nNothing was added to your bag." << endl;
            return;
        }

        if (droppedPlant)
        {
            cout << string(55, '-') << endl;
            cout << "\nSorry, there are no more small plants." << endl;
        }

        else
        {
            cout << string(55, '-') << endl;
            cout << "\nOh no! You dropped the plant as you tried to put "
                 << "\nit in your bag. The pot is broken and there's dirt "
                 << "\neverywhere. The store rules are 'you break it, you "
                 << "\nbuy it'. Now you're out $15 for nothing." << endl;

            droppedPlant = true;
            funds -= 15;
        }
    }
}


/*******************************************************************************
** Description: The buyLargePlant function has two parameters, a reference 
** to an integers of the user's funds and a reference to a vector of strings
** of the names of items in their shopping bag. It checks if there is space
** in their bag and enough funds to purchase the item. If so, it then checks
** if they already have the item or don't want another. If neither is the case,
** the items is added to bag. Additionally, if the puppy has not been found
** before, the puppy scenario is run. The function returns nothing.
*******************************************************************************/

void PlantStore::buyLargePlant(int& funds, vector<string>& bag)
{
    if (haveSpace(bag) && haveFunds(30, funds))
    {
        if (haveItem("Potted Plant", bag) && !wantAnother("Potted Plant"))
        {
            cout << string(55, '-') << endl;
            cout << "\nNothing was added to your bag." << endl;
            return;
        }

        addItem("Potted Plant", bag, 30, funds);

        if (!foundPuppy)
        {
            runPuppyScenario(funds, bag);
        }
    }
}


/*******************************************************************************
** Description: The runPuppyScenario function has two parameters, a reference 
** to an integers of the user's funds and a reference to a vector of strings
** of the names of items in their shopping bag. It prints a message that puppy
** is found. If they have lost puppy flyer, they get reward and flyer is 
** removed from bag. If they don't, they are asked if thye want one. If they
** have space in bag, the puppy is add. The function returns nothing.
*******************************************************************************/

void PlantStore::runPuppyScenario(int& funds, vector<string>& bag)
{
    cout << "\nWhen you take the plant, you see a small puppy that "
         << "\nhad been hiding." << endl;
    foundPuppy = true;

    if (haveItem("Lost Puppy Flyer", bag))
    {
        cout << "\nThis must be the lost puppy! You remove the Lost"
             << "\nPuppy Flyer from your bag and collect reward!"
             << "\nThat's $50 added to your pocket." << endl;

        funds += 50;
        removeItem("Lost Puppy Flyer", bag);
    }

    else
    {
        cout << "\nDo you want to put Puppy in your bag?" << endl;
        int choice = yesNoMenu->run();

        if (choice == 1)
        {
            if (haveSpace(bag))
            {
                addItem("Puppy", bag);
            }
        }

        else
        {
            cout << string(55, '-') << endl;
            cout << "\nOk, no Puppy for you." << endl;
        }
    }
}

PlantStore::~PlantStore()
{
}
