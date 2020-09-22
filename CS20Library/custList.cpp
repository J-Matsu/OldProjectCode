//
// custList.cpp
//
// Joseph Matsushita
// CS20 Assignment 3
// a list of customers for a library
//

#include "custList.h"
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

CUST_LIST::CUST_LIST()
{
    head = NULL;
}

CUST_LIST::~CUST_LIST()
{
    CUST_EL *c = NULL;
    while(head)
    {
        c = head;
        head = head->next;
        delete c;
    }
}

void CUST_LIST::AddCustomer(CUSTOMER cust)
{
    CUST_EL *c = new CUST_EL;
    c->cust = cust;
    c->next = NULL;
    CUST_EL *p = head;
    while(p && p->next)
    {
        p = p->next;
    }
    if(!p)
    {
        head = c;
    }
    else
    {
        p->next = c;
    }
    return;
}

CUSTOMER *CUST_LIST::GetCustomer(char name[])
{
    CUST_EL *c = head;
    if(!c)
    {
        return NULL;
    }
    while(strcmp((c->cust).name, name) != 0)
    {
        c = c->next;
        if(!c)
        {
            return NULL;
        }
    }
    return &(c->cust);
}

void CUST_LIST::PrintCustomersAndBooks(ostream &o)
{
    CUST_EL *c = head;
    while(c)
    {
        o << "Customer: " << (c->cust).name << "\nPhone Number: "
          << (c->cust).phone << "\n" << flush;
        (c->cust).books.PrintInOrder(o);
        o << '\n';
        c = c->next;
    }
}
