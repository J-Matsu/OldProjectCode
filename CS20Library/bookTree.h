//
// bookTree.h
//
// Joseph Matsushita
// CS20 Assignment 3
// a tree that holds books
//

#ifndef BOOKTREE
#define BOOKTREE

#include <iostream>
#include <fstream>
using namespace std;

struct CUSTOMER;

struct BOOK
{
    char title[100];
    char author[50];
    int idnum;
    CUSTOMER *cust = NULL;
};

struct BOOK_NODE
{
    BOOK book;
    BOOK_NODE *left;
    BOOK_NODE *right;
};

class BOOK_TREE
{
    private:
        BOOK_NODE *root;
        static BOOK_NODE *free;
        void RecursiveClean(BOOK_NODE *);
        BOOK_NODE **AddHelper(BOOK_NODE **, int);
        BOOK_NODE **RemoveHelper(BOOK_NODE **, int);
        BOOK_NODE *BookSearch(BOOK_NODE *, int);
        void PrintCheckedOutHelper(BOOK_NODE *, ostream &);
        void PrintCheckedInHelper(BOOK_NODE *, ostream &);
        void PreOrderPrintHelper(BOOK_NODE *, ostream &);
        void InOrderPrintHelper(BOOK_NODE *, ostream &);
        void PostOrderPrintHelper(BOOK_NODE *, ostream &);
    public:
        BOOK_TREE();
        ~BOOK_TREE();
        void Init();
        void AddBook(BOOK);
        BOOK RemoveBook(int);
        bool CheckOut(CUSTOMER &, int); //returns false if checkout fails
        bool CheckIn(CUSTOMER &, int);
        void PrintCheckedOut(ostream &);
        void PrintCheckedIn(ostream &);
        void PrintPreOrder(ostream &);
        void PrintInOrder(ostream &);
        void PrintPostOrder(ostream &);
        bool IsEmpty();
};

struct CUSTOMER
{
    char name[40];
    char phone[20];
    BOOK_TREE books;
};

#endif // BOOKTREE
