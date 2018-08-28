/*******************************************************************************
** Program Name: Birthday Adventure Game
** Authors: Kelly von Borstel
** Date: 3/19/2018
** Description: This is implemenation file for abstract space class. It's base
** class for bank, postOffice, plantStore, cleaningStore, catToyStore, and house
** classes. The space class has member variables for the name of the space,
** space pointers for the spaces to the top, rightt, bottom, and left, and a
** menu for yes/no decisions within the space. There are member functions to
** set and get the name, set and get the adjacent spaces, and look around the
** space. The lookAround function is pure virtual function because each derived
** space has different actions available when the user looks around. There are
** also functions within the space class to check if the user's shopping bag is
** full, it they have enough money for a purchase, have the item already in
** their bag, confirm that they want an item they already have, find/add/remove
** and item, and to create a menu for yes/no decisions within the space.
*******************************************************************************/

#include "space.hpp"


/*******************************************************************************
** Description: The construction function has one parameter, a string of the
** name of the space. It sets the name and each of the directions to null. It
** also creates a menu for yes/no decisions within the space.
*******************************************************************************/

Space::Space(string name)
{
    setName(name);
    this->top = nullptr;
    this->right = nullptr;
    this->bottom = nullptr;
    this->left = nullptr;
    createYesNoMenu();
}


/*******************************************************************************
** Description: The setName function has one parameter, a string of the name
** of the space. It returns nothing. The getName function returns a string of
** the name of the space.
*******************************************************************************/

void Space::setName(string name)
{
    this->name = name;
}

string Space::getName()
{
    return name;
}


/*******************************************************************************
** Description: The setAdjacent function has four parameters, space pointers
** for the top, right, bottom, and left spaces. If there is no space to a
** particular direction, null will be passed in. The function returns nothing.
** The get functions for each of the directions returns a pointer to the space
** in that direction.
*******************************************************************************/

void Space::setAdjacent(Space* top, Space* right, Space* bottom, Space* left)
{
    this->top = top;
    this->right = right;
    this->bottom = bottom;
    this->left = left;
}

Space* Space::getTop()
{
    return top;
}

Space* Space::getRight()
{
    return right;
}

Space* Space::getBottom()
{
    return bottom;
}

Space* Space::getLeft()
{
    return left;
}


/*******************************************************************************
** Description: The haveSpace function has one parameter, the user's shopping
** bag. The purpose of the function is to check if there's room in the bag to
** add another item. If there is, it returns true. If not, it returns false.
*******************************************************************************/

bool Space::haveSpace(vector<string> bag)
{
    if (bag.size() == 8)
    {
        cout << string(55, '-') << endl;
        cout << "\nSorry, you don't have enough space in your bag." << endl;
        return false;
    }

    return true;
}


/*******************************************************************************
** Description: The haveFunds function has two parameters, an integers for the
** cost of the item and the user's funds. The purpose of the function is to
** check if there are enough funds to purchase the item. If there are, the
** function returns true. If not, it returns false.
*******************************************************************************/

bool Space::haveFunds(int cost, int funds)
{
    if (funds < cost)
    {
        cout << string(55, '-') << endl;
        cout << "\nSorry, you don't have enough money." << endl;
        return false;
    }

    return true;
}


/*******************************************************************************
** Description: The haveItem function has two parameters, a string of the name
** of the item, and a reference to the user's shopping bag. If the item is
** found in the bag, the function returns true. If not, it returns false.
*******************************************************************************/

bool Space::haveItem(string item, vector<string>& bag)
{
    int position = find(bag.begin(), bag.end(), item) - bag.begin();
    return position != bag.size();   
}


/*******************************************************************************
** Description: The wantAnother function has one parameter, a string of the 
** name of the item. The purpose of the function is to check if the user wants
** to add to their bag an item that they already have. If they do, the function
** returns true. If not, it returns false.
*******************************************************************************/

bool Space::wantAnother(string item)
{
    cout << string(55, '-') << endl;
    cout << "\nYou already have " << item << " in your bag." << endl;
    cout << "Do you want to get another?" << endl;
    int getAnother = yesNoMenu->run();
    return getAnother == 1;
}


/*******************************************************************************
** Description: The getItemPosition function has two parameters, a string of
** the name of the items and a reference to the user's shopping bag. If the
** item is in the shopping bag, it returns the index of the item. If not, it
** prints message that the items is not in the bag and returns -1.
*******************************************************************************/

int Space::getItemPosition(string item, vector<string>& bag)
{
    if (haveItem(item, bag))
    {
        return find(bag.begin(), bag.end(), item) - bag.begin();
    }

    cout << string(55, '-') << endl;
    cout << "\nThere is no " << item << " in the bag." << endl;
    return -1;
}


/*******************************************************************************
** Description: The addItem function has two parameters, a string of the name
** of the item and a reference to the user's shopping bag. The item is added to
** the bag and a message is printed. The function returns nothing.
*******************************************************************************/

void Space::addItem(string item, vector<string>& bag)
{
    bag.push_back(item);
    cout << string(55, '-') << endl;
    cout << "\nAdded to your bag: " << item << endl;
}


/*******************************************************************************
** Description: The addItem function with four parameters overloads the previous
** version to also accept as arguments the cost of the item and a reference
** to the user's funds. The items is added to the bag, the cost subtracted from
** the funds, and a message is printed. The function returns nothing.
*******************************************************************************/

void Space::addItem(string item, vector<string>& bag, int cost, int& funds)
{
    bag.push_back(item);
    funds -= cost;
    cout << string(55, '-') << endl;
    cout << "\nAdded to your bag: " << item << endl;
}


/*******************************************************************************
** Description: The removeItem function has two parameters, a string for the
** item to be removes, and a reference to the shopping bag. If the item is 
** found, it is removed. The function returns nothing.
*******************************************************************************/

void Space::removeItem(string item, vector<string>& bag)
{
    int position = find(bag.begin(), bag.end(), item) - bag.begin();
    bag.erase(bag.begin() + position);
}


/*******************************************************************************
** Description: The createYesNoMenu function creates a menu used for yes/no
** decisions within the space. It has no parameters and returns nothing.
*******************************************************************************/

void Space::createYesNoMenu()
{
    vector<string> menuOptions = {"Yes", "No"};
    yesNoMenu = new Menu(menuOptions);
}


/*******************************************************************************
** Description: The destructor function deallocates memory for the yesNoMenu.
*******************************************************************************/

Space::~Space()
{
    delete yesNoMenu;
}
