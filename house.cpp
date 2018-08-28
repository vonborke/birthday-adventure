/*******************************************************************************
** Program Name: Birthday Adventure Game 
** Authors: Kelly von Borstel
** Date: 3/19/2018
** Description: This is implemenation file for house class, which is derived
** from space class. In addition to the member variable and function it
** inherits, it also has a member variable to keep track of whether the user
** has said goodbye to Ms. Whiskers. It overrides the virtual function that 
** looks around to include a description and menu options specific to this
** space. It has two additional function, one to take an item from the space,
** and the other to say goodbye to Ms. Whiskers.
*******************************************************************************/

#include "house.hpp"


/*******************************************************************************
** Description: The constructor has one parameter, a string for the name of the
** space. In additon to setting name, it sets saidGoodbye initially to false.
*******************************************************************************/

House::House(string name) : Space(name)
{
    saidGoodbye = false;
}


/*******************************************************************************
** Description: The lookAround function has two parameters, a reference to
** an integer of the user's funds and a reference to a vector of strings of
** the names of items in their shopping bag. After describing the space, the
** function gets the user's choice from a menu of options and calls other
** functions based on their choice. It returns nothing.
*******************************************************************************/

void House::lookAround(int& funds, vector<string>& bag)
{
    cout << string(55, '-') << endl;
    cout << "\nIn your house, there is a small table by the door"
         << "\nwith a set of Keys and your ID Card. Ms. Whiskers"
         << "\nis watching you from her favorite chair." << endl;

    vector<string> spaceMenuOptions = {"Take Keys",
                                       "Take ID Card",
                                       "Say goodbye to Ms. Whiskers",
                                       "Go back to Main Menu"};

    Menu spaceMenu(spaceMenuOptions);
    int choice = 0;
    
    while (choice != 4)
    {
        cout << "\nWhat would you like to do?" << endl;
        choice = spaceMenu.run();

        if (choice == 1)
        {
            takeItem("Keys", bag);
        }

        else if (choice == 2)
        {
            takeItem("ID Card", bag);
        }

        else if (choice == 3)
        {
            sayGoodbye();
        }
    }
}


/*******************************************************************************
** Description: The takeItem function has two parameters, a string of the name
** of the item and a reference to a vector os strings of the names of the items
** in the user's bag. It checks if they have space for the items and checks
** that they don't already have the item, and then adds the item to bag. If
** they already have it, a message is printed. The function returns nothing.
*******************************************************************************/

void House::takeItem(string item, vector<string>& bag)
{
    if (haveSpace(bag) && !haveItem(item, bag))
    {
        addItem(item, bag);
    }

    else
    {
        cout << string(55, '-') << endl;
        cout << "\nYou already have " << item << " in your bag." << endl;
    }
}


/*******************************************************************************
** Description: The sayGoodbye function prints a response from Ms. Whiskers
** based on whether you have said goodbye already or not, then sets saidGoodbye
** to true. It has no parameters and returns nothing.
*******************************************************************************/

void House::sayGoodbye()
{
    cout << string(55, '-') << endl;

    if (saidGoodbye)
    {
        cout << "\nMs. Whiskers repeats, "; 
    }

    else
    {
        cout << "\nMs. Whiskers says, ";
    }

    cout << "\"Hurry home, but don't return until"
         << "\nyou have everything on the list. I won't let you"
         << "\nback in the house unless you have all the supplies"
         << "\nfor my birthday party!\"" << endl;

    saidGoodbye = true;
}

House::~House()
{
}
