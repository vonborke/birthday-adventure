/*******************************************************************************
** Program Name: Birthday Adventure Game 
** Authors: Kelly von Borstel
** Date: 3/19/2018
** Description: This is declaration file for plantStore class, which is
** derived from space class. In addition to the member variable and function
** it inherits, it has two addition member variable to keep track of whether
** the puppy was found and whether the plant was dropped. It overrides the 
** virtual function that looks around to include a description and menu options
** specific to this space. It has four additional functions to purchase catnip,
** purchase a small or large plant, and run scenario when puppy is found.
*******************************************************************************/

#ifndef PLANT_STORE_HPP
#define PLANT_STORE_HPP

#include "space.hpp"

class PlantStore : public Space
{
    private:
        bool foundPuppy;
        bool droppedPlant;
        virtual void lookAround(int& funds, vector<string>& bag);
        void buyCatnip(int& funds, vector<string>& bag);
        void buySmallPlant(int& funds, vector<string>& bag);
        void buyLargePlant(int& funds, vector<string>& bag);
        void runPuppyScenario(int& funds, vector<string>& bag);

    public:
        PlantStore(string name);
        virtual ~PlantStore();
};

#endif
