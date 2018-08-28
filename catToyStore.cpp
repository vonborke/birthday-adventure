/*******************************************************************************
** Program Name: Birthday Adventure Game
** Authors: Kelly von Borstel
** Date: 3/19/2018
** Description: This is implementation file for catToyStore class, which is
** derived from space class. In addition to the member variable and function
** it inherits, it has one addition member variable to keep track of whether
** they've had catnip stolen. It overrides the virtual function that looks 
** around to include a description and menu options specific to this space. 
** It has four additional functions to purchase laser pointer, purchase regular
** or extra bouncy ping pong balls, and run scenario when they buy ping pong
** balls, get free laser pointer and catnip is stolen.
*******************************************************************************/

#include "catToyStore.hpp"

CatToyStore::CatToyStore(string name) : Space(name)
{
    lostCatnip = false;
}


/*******************************************************************************
** Description: The lookAround function has two parameters, a reference to
** an integer of the user's funds and a reference to a vector of strings of
** the names of items in their shopping bag. After describing the space, the
** function gets the user's choice from a menu of options and calls other
** functions based on their choice. It returns nothing.
*******************************************************************************/

void CatToyStore::lookAround(int& funds, vector<string>& bag)
{
    cout << string(55, '-') << endl;
    cout << "\nThe Cat Toy Store has a display of Laser Pointers"
         << "\nby the register and an assortment of Ping Pong"
         << "\nBalls on a nearby shelf." << endl;

    vector<string> spaceMenuOptions = {"Buy Laser Pointer - $10",
                                       "Buy regular Ping Pong Balls - $10",
                                       "Buy extra bouncy Ping Pong Balls - $15",
                                       "Go back to Main Menu"};

    Menu spaceMenu(spaceMenuOptions);
    int choice = 0;
    
    while (choice != 4)
    {
        cout << "\nWhat would you like to do?" << endl;
        choice = spaceMenu.run();

        if (choice == 1)
        {
            buyLaserPointer(funds, bag);
        }

        else if (choice == 2)
        {
            buyRegularPingPongBalls(funds, bag);
        }

        else if (choice == 3)
        {
            buyBouncyPingPongBalls(funds, bag);
        }
    }
}


/*******************************************************************************
** Description: The buyLaserPointer function has two parameters, a reference 
** to an integers of the user's funds and a reference to a vector of strings
** of the names of items in their shopping bag. It checks if there is space
** in their bag and enough funds to purchase the item. If so, it then checks
** if they already have the item or don't want another. If neither is the case,
** the items is added to bag. The function returns nothing.
*******************************************************************************/

void CatToyStore::buyLaserPointer(int& funds, vector<string>& bag)
{
    if (haveSpace(bag) && haveFunds(10, funds))
    {
        if (haveItem("Laser Pointer", bag) && !wantAnother("Laser Pointer"))
        {
            cout << string(55, '-') << endl;
            cout << "\nNothing was added to your bag." << endl;
            return;
        }

        addItem("Laser Pointer", bag, 10, funds);
    }
}


/*******************************************************************************
** Description: The buyRegularPingPongBalls function has two parameters, a
** reference to an integer of user's funds and a reference to vector of strings
** of the names of items in their shopping bag. It checks if there is space
** in their bag and enough funds to purchase the item. If so, it then checks
** if they already have the item or don't want another. If neither is the case,
** the items is added to bag. The function returns nothing.
*******************************************************************************/

void CatToyStore::buyRegularPingPongBalls(int& funds, vector<string>& bag)
{
    if (haveSpace(bag) && haveFunds(10, funds))
    {
        if (haveItem("Ping Pong Balls", bag) && !wantAnother("Ping Pong Balls"))
        {
            cout << string(55, '-') << endl;
            cout << "\nNothing was added to your bag." << endl;
            return;
        }

        addItem("Ping Pong Balls", bag, 10, funds);
    }
}


/*******************************************************************************
** Description: The buyBouncyPingPongBalls function has two parameters, a 
** reference to an integer of user's funds and a reference to vector of strings
** of the names of items in their shopping bag. It checks if there is space
** in their bag and enough funds to purchase the item. If so, it then checks
** if they already have the item or don't want another. If neither is the case,
** the items is added to bag and the free laser pointer scenario is run. The
** function returns nothing.
*******************************************************************************/

void CatToyStore::buyBouncyPingPongBalls(int& funds, vector<string>& bag)
{
    if (haveSpace(bag) && haveFunds(15, funds))
    {
        if (haveItem("Ping Pong Balls", bag) && !wantAnother("Ping Pong Balls"))
        {
            cout << string(55, '-') << endl;
            cout << "\nNothing was added to your bag." << endl;
            return;
        }

        addItem("Ping Pong Balls", bag, 15, funds);

        runFreeLaserPointer(funds, bag);
    }
}


/*******************************************************************************
** Description: The runFreeLaserPointer function has two parameters, a 
** reference to an integer of user's funds and a reference to vector of strings
** of the names of items in their shopping bag. It prints a message that they
** get a free laser pointer with purchase and asks if they want it. If they
** do, and they have catnip in their bag, the catnip is stolen. If they don't
** have catnip, the bag is checked to make sure there's space and the laser
** pointer is added. The function returns nothing.
*******************************************************************************/

void CatToyStore::runFreeLaserPointer(int& funds, vector<string>& bag)
{
    cout << "\nSpecial Today: Buy a bag of extra bouncy Ping" << endl
         << "Pong Balls and get a free Laser Pointer!" << endl;

        cout << "\nDo you want a free Laser Pointer?" << endl;

        if (yesNoMenu->run() == 1)
        {
            {
                while (haveItem("Fresh Catnip", bag))
                {
                    removeItem("Fresh Catnip", bag);
                    lostCatnip = true;
                }

                if (haveSpace(bag))
                {
                    addItem("Laser Pointer", bag);

                    if (lostCatnip)
                    {
                        cout << "\nAs you place the free Laser Pointer in your "
                             << "\nbag, you notice your Fresh Catnip is gone. "
                             << "\nYou've been robbed!" << endl;

                        // reset lostCatnip to false so it doesn't print message
                        // a second time if catnip was taken once already
                        lostCatnip = false;
                    }
                }
            }
        }

        else
        {
            cout << string(55, '-') << endl;
            cout << "\nOk, no free Laser Pointer for you." << endl;
        }
}

CatToyStore::~CatToyStore()
{
}
