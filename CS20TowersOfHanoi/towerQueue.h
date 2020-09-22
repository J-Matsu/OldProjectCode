//
// towerQueue.h
//
// Joseph Matsushita
// CSCI 20 Assignment 2
// a queue of positions to evaluate
//

#ifndef TOWERQUEUE
#define TOWERQUEUE

#include "towerPosition.h"

struct POSITION_QUEUE
{
    POSITION p;
    POSITION_QUEUE *next;
};
class QUEUE
{
    private:
        POSITION_QUEUE *head;
        POSITION_QUEUE *tail;
    public:
        QUEUE();
        ~QUEUE();
        void Init();
        void Enqueue(POSITION);
        POSITION Dequeue();
        bool IsEmpty();
};

#endif // TOWERQUEUE
