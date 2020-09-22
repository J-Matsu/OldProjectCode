//
// towerMain.cpp
//
// Joseph Matsushita
// CSCI 20 Assignment 2
// solves the Towers of Hanoi puzzle
//

#include "towerPosition.h"
#include "towerQueue.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

POSITION SolveTowers(int);
void CreatePosition(char, char, POSITION &, POSITION &);

int main(int argc, char *argv[])
{
    if(argc != 3)
    {
        cout << "Error: enter the number of disks and the output file."
             << endl << flush;
        return -1;
    }
    POSITION solved;
    int disks = atoi(argv[1]);
    ofstream fout;
    fout.open(argv[2]);
    if(!fout)
    {
        cout << "Error: could not open output file." << endl << flush;
        return -2;
    }
    solved = SolveTowers(disks);
    fout << solved;
    return 0;
}

POSITION SolveTowers(int disks)
{
    POSITION p(disks);
    QUEUE q;
    POSITION newPosition;
    q.Enqueue(p);
    while(!q.IsEmpty())
    {
        p = q.Dequeue();
        if(p.CheckMove('A', 'B'))
        {
            if((p.IsDiskOne() && (p.CheckDisk('A') == 1)) ||
              (!p.IsDiskOne() && !(p.CheckDisk('A') == 1)))
            {
                CreatePosition('A', 'B', p, newPosition);
                if(newPosition.IsSolved())
                {
                    return newPosition;
                }
                newPosition.ToggleDiskOne();
                q.Enqueue(newPosition);
            }
        }
        if(p.CheckMove('A', 'C'))
        {
            if((p.IsDiskOne() && (p.CheckDisk('A') == 1)) ||
              (!p.IsDiskOne() && !(p.CheckDisk('A') == 1)))
            {
                CreatePosition('A', 'C', p, newPosition);
                if(newPosition.IsSolved())
                {
                    return newPosition;
                }
                newPosition.ToggleDiskOne();
                q.Enqueue(newPosition);
            }
        }
        if(p.CheckMove('B', 'A'))
        {
            if((p.IsDiskOne() && (p.CheckDisk('B') == 1)) ||
              (!p.IsDiskOne() && !(p.CheckDisk('B') == 1)))
            {
                CreatePosition('B', 'A', p, newPosition);
                if(newPosition.IsSolved())
                {
                    return newPosition;
                }
                newPosition.ToggleDiskOne();
                q.Enqueue(newPosition);
            }
        }
        if(p.CheckMove('B', 'C'))
        {
            if((p.IsDiskOne() && (p.CheckDisk('B') == 1)) ||
              (!p.IsDiskOne() && !(p.CheckDisk('B') == 1)))
            {
                CreatePosition('B', 'C', p, newPosition);
                if(newPosition.IsSolved())
                {
                    return newPosition;
                }
                newPosition.ToggleDiskOne();
                q.Enqueue(newPosition);
            }
        }
        if(p.CheckMove('C', 'A'))
        {
            if((p.IsDiskOne() && (p.CheckDisk('C') == 1)) ||
              (!p.IsDiskOne() && !(p.CheckDisk('C') == 1)))
            {
                CreatePosition('C', 'A', p, newPosition);
                if(newPosition.IsSolved())
                {
                    return newPosition;
                }
                newPosition.ToggleDiskOne();
                q.Enqueue(newPosition);
            }
        }
        if(p.CheckMove('C', 'B'))
        {
            if((p.IsDiskOne() && (p.CheckDisk('C') == 1)) ||
              (!p.IsDiskOne() && !(p.CheckDisk('C') == 1)))
            {
                CreatePosition('C', 'B', p, newPosition);
                if(newPosition.IsSolved())
                {
                    return newPosition;
                }
                newPosition.ToggleDiskOne();
                q.Enqueue(newPosition);
            }
        }
        p.Free();
    }
    cout << "Solution not found." << endl << flush; //just in case
    POSITION d;
    return d;
}

void CreatePosition(char a, char b, POSITION &p, POSITION &n)
{
    n = p;
    int diskNum = n.MoveDisk(a, b);
    MOVE m;
    m.disk = diskNum;
    m.from = a;
    m.to = b;
    n.AddMoveToList(m);
    return;
}
