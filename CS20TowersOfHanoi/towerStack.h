//
// towerStack.h
//
// Joseph Matsushita
// CSCI 20 Assignment 2
// a stack for a tower peg
//

#ifndef TOWERSTACK
#define TOWERSTACK
using namespace std;

struct DISK
{
    short num;
    DISK *next;
};

class STACK
{
    private:
        DISK *top;
        static DISK *free; //free stack
        DISK *itr;
        void RecursiveCopy(STACK &, STACK &); //otherwise stack would be reversed on copy
    public:
        STACK();
        STACK(short);
        STACK(STACK &);
        ~STACK();
        void Init();
        void Push(short);
        short Pop();
        short Peek();
        bool IsEmpty();
        short Iterate(); //push and pop reset the iterator
        void operator =(const STACK &);
};

#endif // TOWERSTACK
