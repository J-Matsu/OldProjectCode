//
// towerStack.cpp
//
// Joseph Matsushita
// CSCI 20 Assignment 2
// a stack for a tower peg
//

#include "towerStack.h"
#include <iostream>
using namespace std;

DISK * STACK::free = NULL;

void STACK::RecursiveCopy(STACK &t, STACK &s)
{
    short i;
    i = s.Iterate();
    if(i == 0)
    {
        return;
    }
    RecursiveCopy(t, s);
    t.Push(i);
    return;
}

STACK::STACK()
{
    top = NULL;
    itr = NULL;
}

STACK::STACK(short e)
{
    DISK *p = new DISK;
    p->num = e;
    p->next = NULL;
    top = p;
    itr = top;
}

STACK::STACK(STACK &s)
{
    top = NULL;
    RecursiveCopy(*this, s);
    itr = top;
}

STACK::~STACK()
{
    DISK *p;
    while(top)
    {
        p = top;
        top = top->next;
        delete p;
    }
}

void STACK::Init()
{
    DISK *p = NULL;
    while(top)
    {
        p = top;
        top = top->next;
        p->next = free;
        free = p;
    }
    itr = NULL;
    return;
}

void STACK::Push(short e)
{
    DISK *p;
    if(free == NULL)
    {
        p = new DISK;
    }
    else
    {
        p = free;
        free = free->next;
    }
    p->num = e;
    p->next = top;
    top = p;
    itr = top;
    return;
}

short STACK::Pop()
{
    if(top == NULL)
    {
        return 0;
    }
    DISK *p = top;
    short i = p->num;
    top = p->next;
    itr = top;
    p->next = free;
    free = p;
    return i;
}

short STACK::Peek()
{
    if(top == NULL)
    {
        return 999;
    }
    return top->num;
}

bool STACK::IsEmpty()
{
    return top == NULL;
}

short STACK::Iterate()
{
    if(itr == NULL)
    {
        itr = top;
        return 0;
    }
    short i = itr->num;
    itr = itr->next;
    return i;
}

void STACK::operator =(const STACK &s)
{
    if(this == &s)
    {
        return;
    }
    (*this).Init();
    RecursiveCopy(*this, const_cast<STACK &> (s));
    itr = top;
    return;
}
