//
// system.h
//
// Joseph Matsushita
// Final Assignment
// directory system class interface
//

#include "dir.h"
#ifndef SYSTEM_H
#define SYSTEM_H

class SYSTEM
{
private:
    DIR *root;
    DIR *cwd;
    void PrintWorkingDirectoryHelper(DIR *, ostream &);
public:
    SYSTEM();
    ~SYSTEM();
    void MakeDirectory(char *, ostream &);
    void RemoveDirectory(char *, ostream &);
    void ChangeDirectory(char *, ostream &);
    void ListFiles(ostream &);
    void ListFilesRecursive(ostream &);
    void MakeFile(char *, ostream &);
    void RemoveFile(char *, ostream &);
    void PrintWorkingDirectory(ostream &);
    void ParseCommand(char *, ostream &);
};
#endif //SYSTEM_H
