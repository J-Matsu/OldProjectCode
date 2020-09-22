//
// towerPosition.h
//
// Joseph Matsushita
// CSCI 20 Assignment 2
// a possible position of towers
//

#ifndef TOWERPOSITION
#define TOWERPOSITION

#include "towerStack.h"
#include "towerList.h"
#include <fstream>

class POSITION
{
    private:
        STACK a, b, c;
        LIST l;
        bool diskOne; //if true, only move disk one
    public:
        POSITION(); //defaults to 3 disks on A
        POSITION(short); //create a new position with the amount of disks on A
        POSITION(POSITION &);
        ~POSITION();
        void Free(); //frees all carriers on stacks and list to free stacks
        bool CheckMove(char, char);
        short CheckDisk(char); //checks top disk of entered stack
        bool IsDiskOne();
        void ToggleDiskOne();
        short MoveDisk(char, char); //returns number of disk moved
        void AddMoveToList(MOVE);
        bool IsSolved();
        void operator =(const POSITION &);
        friend ostream &operator <<(ostream &, POSITION &); //prints move list
        //friend bool operator ==(POSITION &, POSITION &);
};

#endif // TOWERPOSITION
