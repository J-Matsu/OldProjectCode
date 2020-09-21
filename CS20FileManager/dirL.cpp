//
// dirL.cpp
//
// Joseph Matsushita
// Final Assignment
// source for the directory list class
//

#include "dirL.h"
#include <iostream>
#include <cstring>
using namespace std;

DIR_CON *DIR_LIST::free = NULL;

DIR_LIST::DIR_LIST()
{
    head = NULL;
    curr = 0;
}

DIR_LIST::DIR_LIST(DIR *d, char *name)
{
    head = new DIR_CON;
    head->d = d;
    head->next = NULL;
    head->n = name;
    curr = NULL;
}

DIR_LIST::~DIR_LIST()
{
    DIR_CON *c;
    while(head)
    {
        c = head;
        head = head->next;
        delete c;
    }
}

void DIR_LIST::Init()
{
    DIR_CON *c;
    while(head)
    {
        c = head;
        head = head->next;
        delete c;
    }
    curr = NULL;
    return;
}

void DIR_LIST::AddDirectory(DIR *dir, char *c)
{
    DIR_CON *e = NULL;
    if(free != NULL)
    {
        e = free;
        free = free->next;
    }
    else
    {
        e = new DIR_CON;
    }
    e->d = dir;
    e->n = c;
    DIR_CON *p = head, *q = NULL;
    while(p && strcmp(p->n, c) < 0)
    {
        q = p;
        p = p->next;
    }
    if(!q)
    {
        e->next = head;
        head = e;
    }
    else
    {
        e->next = p;
        q->next = e;
    }
    curr = head; //reset iterator
    return;
}

DIR *DIR_LIST::RemoveDirectory(char *c)
{
    DIR *d;
    DIR_CON *p = head, *q = NULL;
    while(p && strcmp(p->n, c) != 0)
    {
        q = p;
        p = p->next;
    }
    if(!p)
    {
        return NULL;
    }
    if(!q)
    {
        head = p->next;
    }
    else
    {
        q->next = p->next;
    }
    d = p->d;
    p->d = NULL;
    p->next = free;
    free = p;
    curr = head; //reset iterator
    return d;
}

DIR *DIR_LIST::Iterator()
{
    if(!curr)
    {
        curr = head;
        return NULL;
    }
    DIR *d = curr->d;
    curr = curr->next;
    return d;
}

bool DIR_LIST::IsEmpty()
{
    return(head == NULL);
}
