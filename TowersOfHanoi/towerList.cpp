//
// towerList.cpp
//
// Joseph Matsushita
// CSCI 20 Assignment 2
// a list that holds the moves to get to a position
//

#include "towerList.h"
#include <iostream>
using namespace std;

LIST_MOVE * LIST::free = NULL;

LIST::LIST()
{
    head = NULL;
    itr = NULL;
}

LIST::LIST(LIST &l)
{
    MOVE m;
    m = l.Iterate();
    while(m.disk != 0)
    {
        Insert(m);
        m = l.Iterate();
    }
    itr = head;
}

LIST::~LIST()
{
    LIST_MOVE *p;
    while(head)
    {
        p = head;
        head = head->next;
        delete p;
    }
}

void LIST::Init()
{
    LIST_MOVE *p;
    while(head)
    {
        p = head;
        head = head->next;
        p->next = free;
        free = p;
    }
    head = NULL;
    itr = NULL;
    return;
}

void LIST::Insert(MOVE m)
{
    LIST_MOVE *e;
    if(free == NULL)
    {
        e = new LIST_MOVE;
    }
    else
    {
        e = free;
        free = free->next;
    }
    LIST_MOVE *p = head, *q = NULL;
    e->mov = m;
    e->next = NULL;
    while(p)
    {
        q = p;
        p = p->next;
    }
    if(!q)
    {
        head = e;
    }
    else
    {
        q->next = e;
    }
    if(!itr)
    {
        itr = head;
    }
    return;
}

MOVE LIST::Iterate()
{
    MOVE m;
    if(itr == NULL)
    {
        itr = head;
        m.from = m.to = 'D';
        m.disk = 0;
    }
    else
    {
        m = itr->mov;
        itr = itr->next;
    }
    return m;
}

void LIST::operator =(const LIST &l)
{
    if(this == &l)
    {
        return;
    }
    this->Init();
    MOVE m;
    m = (const_cast<LIST &> (l)).Iterate();
    while(m.disk != 0)
    {
        Insert(m);
        m = (const_cast<LIST &> (l)).Iterate();
    }
    itr = head;
    return;
}
