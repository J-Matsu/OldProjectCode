//
// dir.h
//
// Joseph Matsushita
// Final Assignment
// header for the directory class
//

#include "dirL.h"
#ifndef DIR_H
#define DIR_H
#include <iostream>
using namespace std;

class DIR
{
private:
    bool file;
    DIR_LIST l;
    char *name;
    DIR *parent;
    void ListFilesRecursiveHelper(ostream &, int);
public:
    DIR();
    DIR(bool, char *, DIR *);
    ~DIR();
    void Init();
    void ListFiles(ostream &);
    void ListFilesRecursive(ostream &);
    DIR *SearchFiles(char *);
    void AddDirectory(DIR *);
    DIR *RemoveDirectory(char *);
    DIR *GetParent();
    char *GetName();
    bool IsFile();
    bool IsEmpty();
};
#endif //DIR_H
