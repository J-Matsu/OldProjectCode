//
// custList.h
//
// Joseph Matsushita
// CS20 Assignment 3
// a list of customers for a library
//

#ifndef CUSTOMERLIST
#define CUSTOMERLIST

#include "bookTree.h"
#include <fstream>

struct CUST_EL
{
    CUSTOMER cust;
    CUST_EL *next;
};

class CUST_LIST
{
    private:
        CUST_EL *head;
    public:
        CUST_LIST();
        ~CUST_LIST();
        void AddCustomer(CUSTOMER);
        CUSTOMER *GetCustomer(char []);
        void PrintCustomersAndBooks(ostream &);
};

#endif // CUSTOMERLIST
