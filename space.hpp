/*******************************************************************************
** Program Name: Birthday Adventure Game
** Authors: Kelly von Borstel
** Date: 3/19/2018
** Description: This is declaration file for abstract space class. It's base
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

#ifndef SPACE_HPP
#define SPACE_HPP

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using std::cout;
using std::endl;
using std::string;
using std::vector;

#include "menu.hpp"

class Space
{
    protected:
        string name;
        Space* top;
        Space* right;
        Space* bottom;
        Space* left;
        Menu* yesNoMenu;

    public:
        Space(string name);
        void setName(string name);
        string getName();
        void setAdjacent(Space* top, Space* right, Space* bottom, Space* left);
        Space* getTop();
        Space* getRight();
        Space* getBottom();
        Space* getLeft();
        virtual void lookAround(int& funds, vector<string>& bag) = 0;
        bool haveSpace(vector<string> bag);
        bool haveFunds(int cost, int funds);
        bool haveItem(string item, vector<string>& bag);
        bool wantAnother(string item);
        int getItemPosition(string item, vector<string>& bag);
        void addItem(string item, vector<string>& bag);
        void addItem(string item, vector<string>& bag, int cost, int& funds);
        void removeItem(string item, vector<string>& bag);
        void createYesNoMenu();
        virtual ~Space();
};

#endif
