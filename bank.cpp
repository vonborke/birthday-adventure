/*******************************************************************************
** Program Name: Birthday Adventure Game
** Authors: Kelly von Borstel
** Date: 3/19/2018
** Description: This is implemenation file for bank class, which is derived
** from space class. In addition to the member variable and function it
** inherits, it also has a member variable to keep track of whether the user
** has taken the coins from safe deposit box. It overrides the virtual function
** that looks around to include a description and menu options specific to this
** space. It has three additional functions that cash a check, open the safe
** deposit box, and ask the bank teller a question.
*******************************************************************************/

#include "bank.hpp"


/*******************************************************************************
** Description: The constructor has one parameter, a string for the name of the
** space. In additon to setting name, it sets tookCoins initially to false.
*******************************************************************************/

Bank::Bank(string name) : Space(name)
{
    tookCoins = false;
}


/*******************************************************************************
** Description: The lookAround function has two parameters, a reference to
** an integer of the user's funds and a reference to a vector of strings of
** the names of items in their shopping bag. After describing the space, the
** function gets the user's choice from a menu of options and calls other
** functions based on their choice. It returns nothing. If the user has a
** puppy in their bag, a message is printed that they can't look around. The
** function returns nothing.
*******************************************************************************/

void Bank::lookAround(int& funds, vector<string>& bag)
{
    cout << string(55, '-') << endl;
    cout << "\nThe bank is small with only a single teller working."
         << "\nYou're standing next to a room of safe deposit boxes." << endl;

    vector<string> spaceMenuOptions = {"Cash Check",
                                       "Open safe deposit box",
                                       "Ask bank teller question",
                                       "Go back to Main Menu"};

    Menu spaceMenu(spaceMenuOptions);
    int choice = 0;

    if (haveItem("Puppy", bag))
    {
        cout << "\nSorry, you can't do anything inside the bank with "
             << "\na Puppy in your bag. No animals allowed!\n" << endl;
        choice = 3;
    }

    else
    {
        while (choice != 4)
        {
            cout << "\nWhat would you like to do?" << endl;
            choice = spaceMenu.run();

            if (choice == 1)
            {
                cashCheck(funds, bag);
            }

            else if (choice == 2)
            {
                openSafeDepositBox(funds, bag);
            }

            else if (choice == 3)
            {
                askTeller();
            }
        }
    }
}


/*******************************************************************************
** Description: The cashCheck function has two parameters, a reference to an
** integer of the user's funds and a reference to a vector of strings of the
** names of items in their shopping bag. It calls a function to determine if
** they have a check and their ID card in the bag. If both are true, the check
** is cashed and their funds increase. If not, a message telling them what
** they need is displayed. The function returns nothing.
*******************************************************************************/

void Bank::cashCheck(int& funds, vector<string>& bag)
{
    if (haveItem("Check for $25", bag))
    {
        if (haveItem("ID Card", bag))
        {
            removeItem("Check for $25", bag);
            funds += 25;
            cout << string(55, '-') << endl;
            cout << "\nGood thing you have your ID Card. Check is"
                 << "\ncashed and $25 is added to your pocket." << endl;
        }

        else
        {
            cout << string(55, '-') << endl;
            cout << "\nSorry, you need an ID Card to cash Check." << endl;
        }
    }

    else
    {
        cout << string(55, '-') << endl;
        cout << "\nSorry, you don't have a Check to cash." << endl;
    }
}


/*******************************************************************************
** Description: The openSafeDepositBox function has two parameters, a reference
** to an integer of the user's funds and a vector of strings of the names of
** items in their shopping bag. If they have their keys and they haven't taken
** the coins already, the user if given the option to take the coins. If the
** decline, a message is printed that they can get them later. If they don't 
** have keys or the box is empty, a message is printed.
*******************************************************************************/

void Bank::openSafeDepositBox(int& funds, vector<string> bag)
{
    if (haveItem("Keys", bag))
    {
        if (!tookCoins)
        {
            cout << string(55, '-') << endl;
            cout << "\nGood thing you have your Keys with you. Inside your"
                 << "\nsafe deposit box are ten 50-cent pieces. Do you want" 
                 << "\nto put the coins in your pocket?" << endl;

            if (yesNoMenu->run() == 1)
            {
                cout << string(55, '-') << endl;
                cout << "\nFive dollars is added to your pocket." << endl;
                funds += 5; 
                tookCoins = true;
            }

            else
            {
                cout << string(55, '-') << endl;
                cout << "\nOk, the coins are back in the safe deposit box"
                     << "\nin case you want to get them later." << endl;
            }
        }

        else
        {
            cout << string(55, '-') << endl;
            cout << "\nSorry, your safe deposit box is empty." << endl;
        }
    }

    else
    {
        cout << string(55, '-') << endl;
        cout << "\nSorry, you need Keys to open safe deposit box." << endl;
    }
}


/*******************************************************************************
** Description: The askTeller function prints a question and answer about the
** catnip thief running around town.
*******************************************************************************/

void Bank::askTeller()
{
    cout << string(55, '-') << endl;
    cout << "\nYou ask teller if he knows anything about the catnip"
         << "\nthief. He replies, \"I haven't seen the thief in here,"
         << "\nbut be careful if you go to the Cat Toy Store.\"" << endl;
}

Bank::~Bank()
{
}
