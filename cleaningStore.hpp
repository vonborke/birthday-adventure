/*******************************************************************************
** Program Name: Birthday Adventure Game
** Authors: Kelly von Borstel
** Date: 3/19/2018
** Description: This is declaration file for cleaningStore class, which is
** derived from space class. In addition to the member variable and function
** it inherits, it has three additional functions to purchase lint rollers, 
** purchase carpet cleaner, and watch a carpet cleaning demonstration. It
** overrides the virtual function that looks around to include a description 
** and menu options specific to this space.
*******************************************************************************/

#ifndef CLEANING_STORE_HPP
#define CLEANING_STORE_HPP

#include "space.hpp"

class CleaningStore: public Space
{
    private: 
        virtual void lookAround(int& funds, vector<string>& bag);
        void buyLintRollers(int& funds, vector<string>& bag);
        void buyCarpetCleaner(int& funds, vector<string>& bag);
        void watchDemo(vector<string>& bag);

    public:
        CleaningStore(string name);
        virtual ~CleaningStore();
};

#endif
