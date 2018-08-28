/*******************************************************************************
** Program Name: Birthday Adventure Game
** Authors: Kelly von Borstel
** Date: 3/19/2018
** Description: This is implementation file for cleaningStore class, which is
** derived from space class. In addition to the member variable and function
** it inherits, it has three additional functions to purchase lint rollers, 
** purchase carpet cleaner, and watch a carpet cleaning demonstration. It
** overrides the virtual function that looks around to include a description 
** and menu options specific to this space.
*******************************************************************************/

#include "cleaningStore.hpp"

CleaningStore::CleaningStore(string name) : Space(name)
{
}


/*******************************************************************************
** Description: The lookAround function has two parameters, a reference to
** an integer of the user's funds and a reference to a vector of strings of
** the names of items in their shopping bag. After describing the space, the
** function gets the user's choice from a menu of options and calls other
** functions based on their choice. It returns nothing.
*******************************************************************************/

void CleaningStore::lookAround(int& funds, vector<string>& bag)
{
    cout << string(55, '-') << endl;
    cout << "\nThe Cleaning Store has packages of Lint Rollers in the"
         << "\nfirst aisle and Carpet Cleaner in the next, where they"
         << "\nseem to be doing some sort of demonstration." << endl;

    vector<string> spaceMenuOptions = {"Buy Lint Rollers - $10",
                                       "Buy Carpet Cleaner - $10",
                                       "Watch carpet cleaning demo",
                                       "Go back to Main Menu"};

    Menu spaceMenu(spaceMenuOptions);
    int choice = 0;
    
    while (choice != 4)
    {
        cout << "\nWhat would you like to do?" << endl;
        choice = spaceMenu.run();

        if (choice == 1)
        {
            buyLintRollers(funds, bag);
        }

        else if (choice == 2)
        {
            buyCarpetCleaner(funds, bag);
        }

        else if (choice == 3)
        {
            watchDemo(bag);
        }
    }
}


/*******************************************************************************
** Description: The buyLintRollers function has two parameters, a reference 
** to an integers of the user's funds and a reference to a vector of strings
** of the names of items in their shopping bag. It checks if there is space
** in their bag and enough funds to purchase the item. If so, it then checks
** if they already have the item or don't want another. If neither is the case,
** the items is added to bag. The function returns nothing.
*******************************************************************************/

void CleaningStore::buyLintRollers(int& funds, vector<string>& bag)
{
    if (haveSpace(bag) && haveFunds(10, funds))
    {
        if (haveItem("Lint Rollers", bag) && !wantAnother("Lint Rollers"))
        {
            cout << string(55, '-') << endl;
            cout << "\nNothing was added to your bag." << endl;
            return;
        }

        addItem("Lint Rollers", bag, 10, funds);
    }
}


/*******************************************************************************
** Description: The buyCarpetCleaner function has two parameters, a reference 
** to an integers of the user's funds and a reference to a vector of strings
** of the names of items in their shopping bag. It checks if there is space
** in their bag and enough funds to purchase the item. If so, it then checks
** if they already have the item or don't want another. If neither is the case,
** the items is added to bag. If they have a coupon in their bag, the coupon
** is applied and removed from bag. The function returns nothing.
*******************************************************************************/

void CleaningStore::buyCarpetCleaner(int& funds, vector<string>& bag)
{
    if (haveItem("Coupon for Carpet Cleaner", bag))
    {
        if (haveFunds(5, funds))
        {
            if (haveItem("Carpet Cleaner", bag) && !wantAnother("Carpet Cleaner"))
            {
                cout << string(55, '-') << endl;
                cout << "\nNothing was added to your bag." << endl;
                return;
            }

            removeItem("Coupon for Carpet Cleaner", bag);
            addItem("Carpet Cleaner", bag, 5, funds);
            cout << "\nYou saved $5 by using coupon!" << endl;
        }
    }

    else
    {
        if (haveFunds(10, funds))
        {
            if (haveItem("Carpet Cleaner", bag) && !wantAnother("Carpet Cleaner"))
            {
                cout << string(55, '-') << endl;
                cout << "\nNothing was added to your bag." << endl;
                return;
            }

            addItem("Carpet Cleaner", bag, 10, funds);
        }
    }
}


/*******************************************************************************
** Description: The watchDemo function has one parameter, a reference to a
** vector of strings of the items in the user's shopping bag. A message is
** printed and the user is asked if they want a coupon. If yes, the coupon is
** added to their bag. The function returns nothing.
*******************************************************************************/

void CleaningStore::watchDemo(vector<string>& bag)
{
    cout << string(55, '-') << endl;
    cout << "\nYou watch a demonstration of someone cleaning a rug."
         << "\nThey are handing out $5 off coupons for Carpet Cleaner." << endl;

    cout << "\nDo you want a coupon added to your bag?" << endl;

    if (yesNoMenu->run() == 1)
    {
        if (haveSpace(bag))
        {
            if (haveItem("Coupon for Carpet Cleaner", bag) 
                    && !wantAnother("Coupon for Carpet Cleaner"))
            {
                cout << string(55, '-') << endl;
                cout << "\nNothing was added to your bag." << endl;
                return;
            }

            addItem("Coupon for Carpet Cleaner", bag);
        }
    }

    else
    {
        cout << string(55, '-') << endl;
        cout << "\nOk, no coupon for you. Thanks for watching demo." << endl;
    }
}

CleaningStore::~CleaningStore()
{
}
