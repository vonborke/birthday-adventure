/*******************************************************************************
** Program Name: Birthday Adventure Game
** Authors: Kelly von Borstel
** Date: 3/19/2018
** Description: This is declaration file for catToyStore class, which is
** derived from space class. In addition to the member variable and function
** it inherits, it has one addition member variable to keep track of whether
** they've had catnip stolen. It overrides the virtual function that looks 
** around to include a description and menu options specific to this space. 
** It has four additional functions to purchase laser pointer, purchase regular
** or extra bouncy ping pong balls, and run scenario when they buy ping pong
** balls, get free laser pointer and catnip is stolen.
*******************************************************************************/

#ifndef CAT_TOY_STORE_HPP
#define CAT_TOY_STORE_HPP

#include "space.hpp"

class CatToyStore : public Space
{
    private:
        bool lostCatnip;
        virtual void lookAround(int& funds, vector<string>& bag);
        void buyLaserPointer(int& funds, vector<string>& bag);
        void buyRegularPingPongBalls(int& funds, vector<string>& bag);
        void buyBouncyPingPongBalls(int& funds, vector<string>& bag);
        void runFreeLaserPointer(int& funds, vector<string>& bag);

    public:
        CatToyStore(string name);
        virtual ~CatToyStore();
};

#endif
