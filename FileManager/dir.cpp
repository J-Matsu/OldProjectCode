//
// dir.cpp
//
// Joseph Matsushita
// Final Assignment
// source for the directory class
//

#include "dir.h"
#include <iostream>
#include <cstring>
using namespace std;

DIR::DIR()
{
    file = false;
    name = "";
    parent = this;
}

DIR::DIR(bool f, char *n, DIR *p)
{
    if(f)
    {
        file = true;
    }
    else
    {
        file = false;
    }
    name = new char[strlen(n) + 1];
    strcpy(name, n);
    if(p == NULL)
    {
        parent = this; //if root
    }
    else
    {
        parent = p;
    }
}

DIR::~DIR()
{
    delete name;
    DIR *d = l.Iterator();
    while(d)
    {
        delete d;
        d = l.Iterator();
    }
    l.Init();
}

void DIR::Init()
{
    DIR *d = l.Iterator();
    while(d)
    {
        delete d;
        d = l.Iterator();
    }
    l.Init();
}

void DIR::ListFiles(ostream &out)
{
    DIR *d = l.Iterator();
    while(d)
    {
        out << d->name;
        if (!d->file)
        {
            out << "/";
        }
        out << endl;
        d = l.Iterator();
    }
    return;
}

void DIR::ListFilesRecursive(ostream &out)
{
    int tab = 0;
    ListFilesRecursiveHelper(out, tab);
    return;
}

void DIR::ListFilesRecursiveHelper(ostream &out, int tab)
{
    DIR *d = l.Iterator();
    while(d)
    {
        for(int i = 0; i < tab; i++)
        {
            out << '\t';
        }
        out << d->name;
        if (!d->file)
        {
            out << "/" << endl;
            d->ListFilesRecursiveHelper(out, tab + 1);
        }
        else
        {
            out << endl;
        }
        d = l.Iterator();
    }
    return;
}

DIR *DIR::SearchFiles(char *c)
{
    DIR *d = l.Iterator();
    DIR *g = NULL;
    //need to cycle through entire list to reset iterator
    while(d)
    {
        if(strcmp(d->name, c) == 0)
        {
            g = d;
        }
        d = l.Iterator();
    }
    return g;
}

void DIR::AddDirectory(DIR *d)
{
    l.AddDirectory(d, d->name);
    return;
}

DIR *DIR::RemoveDirectory(char *c)
{
    DIR *d = l.RemoveDirectory(c);
    return d;
}

DIR *DIR::GetParent()
{
    return parent;
}

char *DIR::GetName()
{
    return name;
}

bool DIR::IsFile()
{
    return file;
}

bool DIR::IsEmpty()
{
    return l.IsEmpty();
}
