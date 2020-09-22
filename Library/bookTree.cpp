//
// bookTree.cpp
//
// Joseph Matsushita
// CS20 Assignment 3
// a tree that hold books
//

#include "bookTree.h"
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

BOOK_NODE *BOOK_TREE::free = NULL;

void BOOK_TREE::RecursiveClean(BOOK_NODE *b)
{
    if(b == NULL)
    {
        return;
    }
    if(b->left)
    {
        RecursiveClean(b->left);
    }
    if(b->right)
    {
        RecursiveClean(b->right);
    }
    delete b;
    return;
}

BOOK_NODE **BOOK_TREE::AddHelper(BOOK_NODE **b, int id)
{
    if(*b == NULL)
    {
        return b;
    }
    else if(((*b)->book).idnum > id)
    {
        return AddHelper(&((*b)->left), id);
    }
    else if(((*b)->book).idnum < id)
    {
        return AddHelper(&((*b)->right), id);
    }
    else
    {
        return NULL;
    }
}

BOOK_NODE **BOOK_TREE::RemoveHelper(BOOK_NODE **b, int id)
{
    if(*b == NULL)
    {
        return NULL;
    }
    else if(((*b)->book).idnum == id)
    {
        return b;
    }
    else if(((*b)->book).idnum > id)
    {
        return RemoveHelper(&((*b)->left), id);
    }
    else
    {
        return RemoveHelper(&((*b)->right), id);
    }
}

BOOK_NODE *BOOK_TREE::BookSearch(BOOK_NODE *b, int id)
{
    if(b == NULL)
    {
        return NULL;
    }
    else if((b->book).idnum == id)
    {
        return b;
    }
    else if((b->book).idnum > id)
    {
        return BookSearch(b->left, id);
    }
    else
    {
        return BookSearch(b->right, id);
    }
}

void BOOK_TREE::PrintCheckedOutHelper(BOOK_NODE *b, ostream &o)
{
    if(b == NULL)
    {
        return;
    }
    if(b->left)
    {
        PrintCheckedOutHelper(b->left, o);
    }
    if((b->book).cust != NULL)
    {
        o << (b->book).title << ", by " << (b->book).author << ", ID: #"
          << (b->book).idnum << ", checked out by "
          << ((b->book).cust)->name << "\n" << flush;
    }
    if(b->right)
    {
        PrintCheckedOutHelper(b->right, o);
    }
    return;
}

void BOOK_TREE::PrintCheckedInHelper(BOOK_NODE *b, ostream &o)
{
    if(b == NULL)
    {
        return;
    }
    if(b->left)
    {
        PrintCheckedInHelper(b->left, o);
    }
    if((b->book).cust == NULL)
    {
        o << (b->book).title << ", by " << (b->book).author << ", ID: #"
          << (b->book).idnum << "\n" << flush;
    }
    if(b->right)
    {
        PrintCheckedInHelper(b->right, o);
    }
    return;
}

void BOOK_TREE::PreOrderPrintHelper(BOOK_NODE *b, ostream &o)
{
    if(b == NULL)
    {
        return;
    }
    o << (b->book).title << ", by " << (b->book).author << ", ID: #"
      << (b->book).idnum << flush;
    if((b->book).cust != NULL)
    {
        o << "*";
    }
    o << "\n";
    if(b->left)
    {
        PreOrderPrintHelper(b->left, o);
    }
    if(b->right)
    {
        PreOrderPrintHelper(b->right, o);
    }
}

void BOOK_TREE::InOrderPrintHelper(BOOK_NODE *b, ostream &o)
{
    if(b == NULL)
    {
        return;
    }
    if(b->left)
    {
        InOrderPrintHelper(b->left, o);
    }
    o << (b->book).title << ", by " << (b->book).author << ", ID: #"
      << (b->book).idnum << flush;
    if((b->book).cust != NULL)
    {
        o << "*";
    }
    o << "\n";
    if(b->right)
    {
        InOrderPrintHelper(b->right, o);
    }
    return;
}

void BOOK_TREE::PostOrderPrintHelper(BOOK_NODE *b, ostream &o)
{
    if(b == NULL)
    {
        return;
    }
    if(b->left)
    {
        PostOrderPrintHelper(b->left, o);
    }
    if(b->right)
    {
        PostOrderPrintHelper(b->right, o);
    }
    o << (b->book).title << ", by " << (b->book).author << ", ID: #"
      << (b->book).idnum << flush;
    if((b->book).cust != NULL)
    {
        o << "*";
    }
    o << "\n";
    return;
}

BOOK_TREE::BOOK_TREE()
{
    root = NULL;
}

BOOK_TREE::~BOOK_TREE()
{
    RecursiveClean(root);
}

void BOOK_TREE::Init()
{
    RecursiveClean(root);
    root = NULL;
}

void BOOK_TREE::AddBook(BOOK book)
{
    BOOK_NODE **b = AddHelper(&root, book.idnum);
    if(b == NULL)
    {
        return;
    }
    if(free != NULL)
    {
        *b = free;
        free = free->left;
    }
    else
    {
        *b = new BOOK_NODE;
    }
    (*b)->book = book;
    (*b)->left = (*b)->right = NULL;
    return;
}

BOOK BOOK_TREE::RemoveBook(int id)
{
    BOOK_NODE **b = RemoveHelper(&root, id), **c = NULL, *d = NULL;
    if(b == NULL || ((*b)->book).cust != NULL)
    {
        BOOK none; //creating a nonexistent book to return
        strcpy(none.title, " ");
        strcpy(none.author, " ");
        none.idnum = 0;
        return none;
    }
    BOOK book = (*b)->book;
    if(((*b)->left == NULL) && ((*b)->right == NULL))
    {
        (*b)->left = free;
        free = *b;
        *b = NULL;
    }
    else if((*b)->right == NULL)
    {
        d = *b;
        *b = (*b)->left;
        d->left = free;
        d->right = NULL;
        free = d;
        d = NULL;
    }
    else if((*b)->left == NULL)
    {
        d = *b;
        *b = (*b)->right;
        d->left = free;
        d->right = NULL;
        free = d;
        d = NULL;
    }
    else
    {
        c = &((*b)->left);
        while((*c)->right)
        {
            c = &((*c)->right);
        }
        d = (*c);
        *c = (*c)->left;
        d->left = (*b)->left;
        d->right = (*b)->right;
        (*b)->left = free;
        (*b)->right = NULL;
        free = *b;
        *b = d;
    }
    return book;
}

bool BOOK_TREE::CheckOut(CUSTOMER &c, int id)
{
    BOOK_NODE *b = BookSearch(root, id);
    if(b == NULL || (b->book).cust != NULL)
    {
        return false;
    }
    c.books.AddBook(b->book);
    (b->book).cust = &c;
    return true;
}

bool BOOK_TREE::CheckIn(CUSTOMER &c, int id)
{
    BOOK_NODE *b = BookSearch(root, id);
    if(b == NULL || (b->book).cust != &c)
    {
        return false;
    }
    c.books.RemoveBook(id);
    (b->book).cust = NULL;
    return true;
}

void BOOK_TREE::PrintCheckedOut(ostream &o)
{
    PrintCheckedOutHelper(root, o);
    return;
}

void BOOK_TREE::PrintCheckedIn(ostream &o)
{
    PrintCheckedInHelper(root, o);
    return;
}

void BOOK_TREE::PrintPreOrder(ostream &o)
{
    PreOrderPrintHelper(root, o);
    return;
}

void BOOK_TREE::PrintInOrder(ostream &o)
{
    InOrderPrintHelper(root, o);
    return;
}

void BOOK_TREE::PrintPostOrder(ostream &o)
{
    PostOrderPrintHelper(root, o);
    return;
}

bool BOOK_TREE::IsEmpty()
{
    return root == NULL;
}


