//
// towerPosition.h
//
// Joseph Matsushita
// CSCI 20 Assignment 2
// a possible position of towers
//

#include "towerPosition.h"
#include <iostream>
#include <fstream>
using namespace std;

POSITION::POSITION()
{
    a.Push(3); //3 disks for default
    a.Push(2);
    a.Push(1);
    diskOne = true;
}

POSITION::POSITION(short e)
{
    for( ; e > 0; e--)
    {
        a.Push(e);
    }
    diskOne = true;
}

POSITION::POSITION(POSITION &p)
{
    a = p.a;
    b = p.b;
    c = p.c;
    l = p.l;
    diskOne = p.diskOne;
}

POSITION::~POSITION()
{
    a.Init(); //Init frees memory from stack onto free
    b.Init();
    c.Init();
    l.Init();
}

void POSITION::Free() //puts memory of position's stacks and list on free ones
{
    a.Init(); //Init frees memory from stack onto free
    b.Init();
    c.Init();
    l.Init();
    return;
}

bool POSITION::CheckMove(char from, char to)
{
    if(from == 'A')
    {
        if(to == 'B')
        {
            return (a.Peek() < b.Peek());
        }
        else if(to == 'C')
        {
            return (a.Peek() < c.Peek());
        }
    }
    else if(from == 'B')
    {
        if(to == 'A')
        {
            return (b.Peek() < a.Peek());
        }
        else if(to == 'C')
        {
            return (b.Peek() < c.Peek());
        }
    }
    else if(from == 'C')
    {
        if(to == 'A')
        {
            return (c.Peek() < a.Peek());
        }
        else if(to == 'B')
        {
            return (c.Peek() < b.Peek());
        }
    }
    return false;
}

short POSITION::CheckDisk(char d)
{
    if(d == 'A')
    {
        return a.Peek();
    }
    if(d == 'B')
    {
        return b.Peek();
    }
    if(d == 'C')
    {
        return c.Peek();
    }
    return 0;
}

bool POSITION::IsDiskOne()
{
    return diskOne;
}

void POSITION::ToggleDiskOne()
{
    if(diskOne)
    {
        diskOne = false;
    }
    else
    {
        diskOne = true;
    }
    return;
}

short POSITION::MoveDisk(char from, char to)
{
    if(from == 'A')
    {
        if(to == 'B')
        {
            b.Push(a.Pop());
            return b.Peek();
        }
        else if(to == 'C')
        {
            c.Push(a.Pop());
            return c.Peek();
        }
    }
    else if(from == 'B')
    {
        if(to == 'A')
        {
            a.Push(b.Pop());
            return a.Peek();
        }
        else if(to == 'C')
        {
            c.Push(b.Pop());
            return c.Peek();
        }
    }
    else if(from == 'C')
    {
        if(to == 'A')
        {
            a.Push(c.Pop());
            return a.Peek();
        }
        else if(to == 'B')
        {
            b.Push(c.Pop());
            return b.Peek();
        }
    }
    return 0; //invalid disk
}

void POSITION::AddMoveToList(MOVE m)
{
    l.Insert(m);
    return;
}

bool POSITION::IsSolved()
{
    return (a.IsEmpty() && c.IsEmpty());
}

void POSITION::operator =(const POSITION &p)
{
    a = p.a;
    b = p.b;
    c = p.c;
    l = p.l;
    diskOne = p.diskOne;
    return;
}

ostream &operator <<(ostream &o, POSITION &p)
{
    MOVE m;
    m = (p.l).Iterate();
    while(m.disk)
    {
        o << "Move disk " << m.disk << " from " << m.from << " to " << m.to
          << '\n' << flush;
          m = (p.l).Iterate();
    }
    return o;
}
