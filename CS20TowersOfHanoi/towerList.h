//
// towerList.h
//
// Joseph Matsushita
// CSCI 20 Assignment 2
// a list that holds the moves to get to a position
//

#ifndef TOWERLIST
#define TOWERLIST

struct MOVE
{
    char from, to;
    int disk;
};

struct LIST_MOVE
{
    MOVE mov;
    LIST_MOVE *next;
};

class LIST
{
    private:
        LIST_MOVE *head;
        static LIST_MOVE *free; //free stack
        LIST_MOVE *itr;
    public:
        LIST();
        LIST(LIST &);
        ~LIST();
        void Init();
        void Insert(MOVE); //insertions only done at tail
        //moves can only be added to the list, so no need for a remove function
        MOVE Iterate();
        void operator =(const LIST &);
};

#endif // TOWERLIST
