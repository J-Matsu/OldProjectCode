//
// dirL.h
//
// Joseph Matsushita
// Final Assignment
// header for the directory list class
//

#ifndef DIRLIST
#define DIRLIST

class DIR;

struct DIR_CON
{
    DIR *d;
    char *n; //for sorting by name
    DIR_CON *next;
};

class DIR_LIST
{
private:
    DIR_CON *head;
    static DIR_CON *free;
    DIR_CON *curr;
public:
    DIR_LIST();
    DIR_LIST(DIR *, char *);
    ~DIR_LIST();
    void Init();
    void AddDirectory(DIR *, char *);
    DIR *RemoveDirectory(char *);
    DIR *Iterator();
    bool IsEmpty();
};
#endif //DIRLIST
