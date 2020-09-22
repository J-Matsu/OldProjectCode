//
// directory.cpp
//
// Joseph Matsushita
// Final Assignment
// creates and runs a directory file system
//

#include "system.h"
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main(int argc, char *argv[])
{
    SYSTEM s;
    char command[200];
    if(argc != 3)
    {
        cout << "Error: no input or output file." << endl;
        return -1;
    }
    ifstream fin;
    ofstream fout;
    fin.open(argv[1]);
    fout.open(argv[2]);
    if(!fin || !fout)
    {
        cout << "Error: could not open input or output file." << endl;
    }
    while(!fin.eof())
    {
        fin.getline(command, 200);
        fout << "* " << command << endl;
        s.ParseCommand(command, fout);
    }
    return 0;
}
