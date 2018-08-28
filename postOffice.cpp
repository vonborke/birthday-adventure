/*******************************************************************************
** Program Name: Birthday Adventure Game 
** Authors: Kelly von Borstel
** Date: 3/19/2018
** Description: This is implemention file for postOffice class, which is derived
** from space class. In addition to the member variable and function it
** inherits, it also has a member variable to keep track of whether the user
** has taken check from their mailbox. It overrides the virtual function that 
** looks around to include a description and menu options specific to this
** space. It has three additional functions that get main from the mailbox, go
** to the bulletin board, and donate an item from their bag.
*******************************************************************************/

#include "postOffice.hpp"


/*******************************************************************************
** Description: The constructor has one parameter, a string for the name of the
** space. In additon to setting name, it sets tookCheck initially to false.
*******************************************************************************/

PostOffice::PostOffice(string name) : Space(name)
{
   tookCheck = false;
}


/*******************************************************************************
** Description: The lookAround function has two parameters, a reference to
** an integer of the user's funds and a reference to a vector of strings of
** the names of items in their shopping bag. After describing the space, the
** function gets the user's choice from a menu of options and calls other
** functions based on their choice. It returns nothing.
*******************************************************************************/

void PostOffice::lookAround(int& funds, vector<string>& bag)
{
    cout << string(55, '-') << endl;
    cout << "\nThe Post Office has a wall of mailboxes in front"
         << "\nof you, a bulletin board on the wall to your left,"
         << "\nand a donation bin next to the door." << endl;

    vector<string> spaceMenuOptions = {"Get mail",
                                       "Approach bulletin board",
                                       "Donate Item",
                                       "Go back to Main Menu"};

    Menu spaceMenu(spaceMenuOptions);
    int choice = 0;
    
    while (choice != 4)
    {
        cout << "\nWhat would you like to do?" << endl;
        choice = spaceMenu.run();

        if (choice == 1)
        {
            getMail(bag);
        }

        else if (choice == 2)
        {
            approachBulletinBoard(funds, bag);
        }

        else if (choice == 3)
        {
            donateItem(bag);
        }
    }
}


/*******************************************************************************
** Description: The getMain function has two parameters, a reference to a vector
** of strings of the names of items in their shopping bag. It checks to make
** sure the user has keys and hasn't already taken the check. If so, the user
** is given the option to take the check. If they decline, it is put back in
** the mailbox. If they don't have keys or have already taken the check, a
** message is printed. The function returns nothing.
*******************************************************************************/

void PostOffice::getMail(vector<string>& bag)
{
    if (haveItem("Keys", bag))
    {
        if (!tookCheck)
        {
            cout << string(55, '-') << endl;

            cout << "\nGood thing you have your Keys. You got a letter and"
                 << "\nit has a Check for $25. Do you want to add the Check"
                 << "\nto your bag?" << endl;

            if (yesNoMenu->run() == 1)
            {
                if (haveSpace(bag))
                {
                    addItem("Check for $25", bag);
                    tookCheck = true;
                }
            }

            else
            {
                cout << string(55, '-') << endl;
                cout << "\nOk, it's been put back in envelope and returned"
                     << "\nto your mailbox." << endl;
            }
        }

        else
        {
            cout << string(55, '-') << endl;
            cout << "\nSorry, your mailbox is empty." << endl;
        }
    }

    else
    {
        cout << string(55, '-') << endl;
        cout << "\nSorry, you need Keys to open mailbox." << endl;
    }
}


/*******************************************************************************
** Description: The approachBulletinBoard function has two parameters, a
** reference to an integer of the user's funds and a reference to a vector of
** strings of the items in the user's bag. A message is printed that there
** are lost puppy flyers. If they have the puppy in their bag, a reward is 
** given. If they don't have puppy, they're asked if they want a flyer added
** to their bag. The function returns nothing.
*******************************************************************************/

void PostOffice::approachBulletinBoard(int& funds, vector<string>& bag)
{
    cout << string(55, '-') << endl;
    cout << "\nAs you approach the bulletin board, you see a stack"
         << "\nof Lost Puppy Flyers on a nearby table." << endl;

    if (haveItem("Puppy", bag))
    {
        cout << "\nYou have the Puppy! You return her and get a reward."
             << "\nThat's $50 added to your pocket." << endl;

        removeItem("Puppy", bag);
        funds += 50;
    }

    else
    {
        if (haveItem("Lost Puppy Flyer", bag))
        {
            cout << "\nYou already have one. Do you want to remove it"
                 << "\nfrom your bag?" << endl;

            if (yesNoMenu->run() == 1)
            {
                removeItem("Lost Puppy Flyer", bag);
                cout << string(55, '-') << endl;
                cout << "\nLost Puppy Flyer was removed from your bag." << endl;
            }

            else
            {
                cout << string(55, '-') << endl;
                cout << "\nOk, Lost Puppy Flyer is still in your bag." << endl;
            }
        }

        else
        {
            cout << "\nDo you want to put a Lost Puppy Flyer in your bag?" << endl;

            if (yesNoMenu->run() == 1)
            {
                if (haveSpace(bag))
                {
                    addItem("Lost Puppy Flyer", bag);
                }
            }

            else
            {
                cout << string(55, '-') << endl;
                cout << "\nOk, no Lost Puppy Flyer for you." << endl;
            }
        
        }
    }
}


/*******************************************************************************
** Description: The donateItem function has one parameter, a reference to a
** vector of strings of the items in the user's shopping bag. They are shown
** a menu of items that can be donated. If they have the items they choose to
** donate, it is removed from their bag. If they don't have the item, a message
** is printed. The function returns nothing.
*******************************************************************************/

void PostOffice::donateItem(vector<string>& bag)
{
    vector<string> eligibleItems = {"Ping Pong Balls", "Fresh Catnip",
        "Carpet Cleaner", "Laser Pointer", "Potted Plant", "Lint Rollers"};

    Menu itemsMenu(eligibleItems);

    cout << string(55, '-') << endl;
    cout << "\nDonations of the following items are accepted."
         << "\nWhat would you like to donate?" << endl;

    int choice = itemsMenu.run();

    if (haveItem(eligibleItems[choice - 1], bag))
    {
        removeItem(eligibleItems[choice - 1], bag);    
        cout << string(55, '-') << endl;
        cout << "\nThanks for donating!" << endl;
    }

    else
    {
        cout << string(55, '-') << endl;
        cout << "\nYou don't have " << eligibleItems[choice - 1] 
             << " to donate." << endl;
    }
}

PostOffice::~PostOffice()
{
}
