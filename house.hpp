/*******************************************************************************
** Program Name: Birthday Adventure Game 
** Authors: Kelly von Borstel
** Date: 3/19/2018
** Description: This is declaration file for house class, which is derived
** from space class. In addition to the member variable and function it
** inherits, it also has a member variable to keep track of whether the user
** has said goodbye to Ms. Whiskers. It overrides the virtual function that 
** looks around to include a description and menu options specific to this
** space. It has two additional function, one to take an item from the space,
** and the other to say goodbye to Ms. Whiskers.
*******************************************************************************/

#ifndef HOUSE_HPP
#define HOUSE_HPP

#include "space.hpp"

class House : public Space
{
    private:
        bool saidGoodbye;
        virtual void lookAround(int& funds, vector<string>& bag);
        void takeItem(string item, vector<string>& bag);
        void sayGoodbye();

    public:
        House(string name);
        virtual ~House();
};

#endif
