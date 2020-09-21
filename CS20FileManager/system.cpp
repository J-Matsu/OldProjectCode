//
// system.cpp
//
// Joseph Matsushita
// Final Assignment
// directory system class interface source
//

#include "system.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <exception>

SYSTEM::SYSTEM()
{
    DIR *d = new DIR(false, "/", NULL); //create root
    root = d;
    cwd = d;
}

SYSTEM::~SYSTEM()
{
    delete root;
}

void SYSTEM::MakeDirectory(char *c, ostream &out)
{
    char ch;
    int len = strlen(c);
    for(int i = 0; i < len; i++)
    {
        ch = c[i];
        if(ch == '/')
        {
            out << "Error: \"" << c
                << "\" has a '/' in the name." << endl;
        }
    }
    DIR *d = cwd->SearchFiles(c);
    if(d != NULL)
    {
        out << "Error: \"" << c
            << "\" already exists in current directory." << endl;
        return;
    }
    d = new DIR(false, c, cwd);
    cwd->AddDirectory(d);
    return;
}

void SYSTEM::RemoveDirectory(char *c, ostream &out)
{
    DIR *d = cwd->SearchFiles(c);
    if(d == NULL)
    {
        out << "Error: \"" << c
            << "\" does not exist in current directory." << endl;
        return;
    }
    if(d->IsFile())
    {
        out << "Error: \"" << c
            << "\" is a file." << endl;
        return;
    }
    d = cwd->RemoveDirectory(c);
    delete d;
    return;
}

void SYSTEM::ChangeDirectory(char *c, ostream &out)
{
    char *t = new char[strlen(c) + 1];
    strcpy(t, c);
    DIR *cur = cwd;
    DIR *d;
    if(c[0] == '/') //if first character is '/', go to root
    {
        cur = root;
    }
    char *s = strtok(t, "/");
    while(s)
    {
        if(strcmp(s, ".") == 0)
        {
            d = cur;
        }
        else if(strcmp(s, "..") == 0)
        {
            d = cur->GetParent();
        }
        else
        {
            d = cur->SearchFiles(s);
            if(d == NULL)
            {
                out << "Error: \"" << s
                    << "\" in path \"" << c << "\" does not exist." << endl;
                return;
            }
            if(d->IsFile())
            {
                out << "Error: \"" << s
                    << "\" in path \"" << c << "\" is a file." << endl;
                return;
            }
        }
        cur = d;
        s = strtok(NULL, "/");
    }
    cwd = cur;
    out << "Changed directory to ";
    PrintWorkingDirectory(out);
    delete t;
    return;
}

void SYSTEM::ListFiles(ostream &out)
{
    cwd->ListFiles(out);
    return;
}

void SYSTEM::ListFilesRecursive(ostream &out)
{
    cwd->ListFilesRecursive(out);
    return;
}

void SYSTEM::MakeFile(char *c, ostream &out)
{
    char ch;
    int len = strlen(c);
    for(int i = 0; i < len; i++)
    {
        ch = c[i];
        if(ch == '/')
        {
            out << "Error: \"" << c
                << "\" has a '/' in the name." << endl;
        }
    }
    DIR *d = cwd->SearchFiles(c);
    if(d != NULL)
    {
        out << "Error: \"" << c
            << "\" already exists in current directory." << endl;
        return;
    }
    d = new DIR(true, c, cwd);
    cwd->AddDirectory(d);
    return;
}

void SYSTEM::RemoveFile(char *c, ostream &out)
{
    DIR *d = cwd->SearchFiles(c);
    if(d == NULL)
    {
        out << "Error: \"" << c
            << "\" does not exist in current directory." << endl;
        return;
    }
    if(!d->IsFile())
    {
        out << "Error: \"" << c
            << "\" is a directory." << endl;
        return;
    }
    d = cwd->RemoveDirectory(c);
    delete d;
    return;
}

void SYSTEM::PrintWorkingDirectory(ostream &out)
{
    PrintWorkingDirectoryHelper(cwd, out);
    out << endl;
    return;
}

void SYSTEM::PrintWorkingDirectoryHelper(DIR *d, ostream &out)
{
    if(d == root)
    {
        out << '/';
        return;
    }
    PrintWorkingDirectoryHelper(d->GetParent(), out);
    out << d->GetName() << '/';
    return;
}

void SYSTEM::ParseCommand(char *c, ostream &out)
{
    char t[200];
    strcpy(t, c);
    char *s = strtok(t, " ");
    if(strcmp(s, "Q") == 0)
    {
        ChangeDirectory("/", out);
        PrintWorkingDirectory(out);
        ListFilesRecursive(out);
    }
    else if(strcmp(s, "mkdir") == 0)
    {
        s = strtok(NULL, " ");
        MakeDirectory(s, out);
    }
    else if(strcmp(s, "rmdir") == 0)
    {
        s = strtok(NULL, " ");
        RemoveDirectory(s, out);
    }
    else if(strcmp(s, "chdir") == 0)
    {
        s = strtok(NULL, " ");
        ChangeDirectory(s, out);
    }
    else if(strcmp(s, "ls") == 0)
    {
        ListFiles(out);
    }
    else if(strcmp(s, "lsr") == 0)
    {
        ListFilesRecursive(out);
    }
    else if(strcmp(s, "mkfile") == 0)
    {
        s = strtok(NULL, " ");
        MakeFile(s, out);
    }
    else if(strcmp(s, "rmfile") == 0)
    {
        s = strtok(NULL, " ");
        RemoveFile(s, out);
    }
    else if(strcmp(s, "pwd") == 0)
    {
        PrintWorkingDirectory(out);
    }
    else
    {
        out << "Invalid command." << endl;
    }
    return;
}
