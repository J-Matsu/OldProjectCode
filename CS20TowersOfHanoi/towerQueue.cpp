//
// towerQueue.h
//
// Joseph Matsushita
// CSCI 20 Assignment 2
// a queue of positions to evaluate
//

#include "towerQueue.h"
#include <iostream>
using namespace std;

QUEUE::QUEUE()
{
    head = NULL;
    tail = NULL;
}

QUEUE::~QUEUE()
{
    POSITION_QUEUE *q = NULL;
    while(head)
    {
        q = head;
        head = head->next;
        delete q;
    }
}

void QUEUE::Init()
{
    POSITION_QUEUE *q = NULL;
    while(head)
    {
        q = head;
        head = head->next;
        delete q;
    }
}

void QUEUE::Enqueue(POSITION e)
{
    POSITION_QUEUE *q = new POSITION_QUEUE;
    q->p = e;
    q->next = NULL;
    if(tail)
    {
        tail->next = q;
        tail = q;
    }
    else
    {
        head = tail = q;
    }
    e.Free(); //for some reason it crsahes without this :(
    return;
}

POSITION QUEUE::Dequeue()
{
    POSITION p;
    if(head == NULL)
    {
        return p;
    }
    POSITION_QUEUE *q = head;
    head = head->next;
    if(!head)
    {
        tail = NULL;
    }
    p = q->p;
    delete q;
    return p;
}

bool QUEUE::IsEmpty()
{
    return (head == NULL);
}
