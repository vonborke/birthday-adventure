/*******************************************************************************
** Program Name: Birthday Adventure Game 
** Authors: Kelly von Borstel
** Date: 3/19/2018
** Description: This is declaration file for postOffice class, which is derived
** from space class. In addition to the member variable and function it
** inherits, it also has a member variable to keep track of whether the user
** has taken check from their mailbox. It overrides the virtual function that 
** looks around to include a description and menu options specific to this
** space. It has three additional functions that get main from the mailbox, go
** to the bulletin board, and donate an item from their bag.
*******************************************************************************/

#ifndef POST_OFFICE_HPP
#define POST_OFFICE_HPP

#include "space.hpp"

class PostOffice : public Space
{
    private:
        bool tookCheck;
        virtual void lookAround(int& funds, vector<string>& bag);
        void getMail(vector<string>& bag);
        void approachBulletinBoard(int& funds, vector<string>& bag);
        void donateItem(vector<string>& bag);

    public:
        PostOffice(string name);
        virtual ~PostOffice();
};

#endif
