/*******************************************************************************
** Program Name: Birthday Adventure Game
** Authors: Kelly von Borstel
** Date: 3/19/2018
** Description: This is declaration file for bank class, which is derived
** from space class. In addition to the member variable and function it
** inherits, it also has a member variable to keep track of whether the user
** has taken the coins from safe deposit box. It overrides the virtual function
** that looks around to include a description and menu options specific to this
** space. It has three additional functions that cash a check, open the safe
** deposit box, and ask the bank teller a question.
*******************************************************************************/

#ifndef BANK_HPP
#define BANK_HPP

#include "space.hpp"

class Bank : public Space
{
    private:
        bool tookCoins;
        virtual void lookAround(int& funds, vector<string>& bag);
        void cashCheck(int& funds, vector<string>& bag);
        void openSafeDepositBox(int& funds, vector<string> bag);
        void askTeller();

    public:
        Bank(string name);
        virtual ~Bank();
};

#endif
