//
// library.cpp
//
// 4/5/2015
// Joseph Matsushita
// Assignment 3
// a simulation of a library
//

#include "bookTree.h"
#include "custList.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
using namespace std;

int main(int argc, char *argv[])
{
    if(argc != 3)
    {
        cout << "Error: enter an input and output file!\n" << flush;
        return -1;
    }
    char choice = 'Z';
    char input[200];
    int idnumber;
    bool result, flag = true; //flag is for case Z, if case Q was not done
    BOOK b;
    CUSTOMER c;
    CUSTOMER *p = NULL;
    BOOK_TREE library;
    CUST_LIST customers;
    ifstream fin;
    ofstream fout;
    fin.open(argv[1]);
    fout.open(argv[2]);
    if(!fin || !fout)
    {
        cout << "Error: could not open input or output file\n" << flush;
        return -2;
    }
    fin.getline(input, 100, '\n');
    while(true)
    {
        choice = *(strtok(input, "\t"));
        switch(choice)
        {
            case('A'):
            {
                strcpy(b.title, strtok(NULL, "\t"));
                strcpy(b.author, strtok(NULL, "\t"));
                b.idnum = atoi(strtok(NULL, "\t"));
                library.AddBook(b);
                fout << "Added book \"" << b.title << "\" to the library.\n"
                     << flush;
                flag = true;
                break;
            }
            case('B'):
            {
                strcpy(c.name, strtok(NULL, "\t"));
                strcpy(c.phone, strtok(NULL, "\t"));
                customers.AddCustomer(c);
                fout << "Added customer \"" << c.name << "\" to the list.\n"
                     << flush;
                flag = true;
                break;
            }
            case('C'):
            {
                idnumber = atoi(strtok(NULL, "\t"));
                p = customers.GetCustomer(strtok(NULL, "\t"));
                if(!p)
                {
                    fout << "Error: Invalid Customer.\n" << flush;
                    break;
                }
                result = library.CheckOut(*p, idnumber);
                if(result)
                {
                    fout << "Book #" << idnumber << " checked out by "
                         << p->name << "\n" << flush;
                }
                else
                {
                    fout << "Error: could not check out book.\n" << flush;
                }
                flag = true;
                break;
            }
            case('D'):
            {
                idnumber = atoi(strtok(NULL, "\t"));
                b = library.RemoveBook(idnumber);
                if((b.idnum) == 0)
                {
                    fout << "Could not remove book #" << idnumber
                         << " from library.\n" << flush;
                }
                else
                {
                    fout << "Removed \"" << b.title << "\" (#" << b.idnum
                         << ") from the library.\n" << flush;
                }
                flag = true;
                break;
            }
            case('I'):
            {
                idnumber = atoi(strtok(NULL, "\t"));
                p = customers.GetCustomer(strtok(NULL, "\t"));
                if(!p)
                {
                    fout << "Error: Invalid Customer.\n" << flush;
                    break;
                }
                result = library.CheckIn(*p, idnumber);
                if(result)
                {
                    fout << "Book #" << idnumber << " checked in by "
                         << p->name << "\n" << flush;
                }
                else
                {
                    fout << "Error: could not check in book.\n" << flush;
                }
                flag = true;
                break;
            }
            case('N'):
            {
                fout << "\nBooks Checked In\n"
                     << "--------------------\n" << flush;
                library.PrintCheckedIn(fout);
                fout << "--------------------\n" << flush;
                flag = true;
                break;
            }
            case('O'):
            {
                fout << "\nBooks Checked Out\n"
                     << "--------------------\n" << flush;
                library.PrintCheckedOut(fout);
                fout << "--------------------\n" << flush;
                flag = true;
                break;
            }
            case('P'):
            {
                fout << "\nCustomer List\n"
                     << "--------------------\n" << flush;
                customers.PrintCustomersAndBooks(fout);
                fout << "--------------------\n" << flush;
                flag = true;
                break;
            }
            case('Q'):
            {
                fout << "\nBooks In Library (InOrder)\n"
                     << "--------------------\n" << flush;
                library.PrintInOrder(fout);
                fout << "--------------------\n" << flush;
                flag = false;
                break;
            }
            case('R'):
            {
                fout << "\nBooks In Library (PreOrder)\n"
                     << "--------------------\n" << flush;
                library.PrintPreOrder(fout);
                fout << "--------------------\n" << flush;
                flag = true;
                break;
            }
            case('S'):
            {
                fout << "\nBooks In Library (PostOrder)\n"
                     << "--------------------\n" << flush;
                library.PrintPostOrder(fout);
                fout << "--------------------\n" << flush;
                flag = true;
                break;
            }
            case('Z'):
            default:
            {
                if(flag)
                {
                    fout << "\nBooks In Library (InOrder)\n"
                     << "--------------------\n" << flush;
                    library.PrintInOrder(fout);
                    fout << "--------------------\n" << flush;
                }
                fout << "Quitting Program...\n" << flush;
                fin.close();
                fout.close();
                return 0;
            }
        }
        fin.getline(input, 100, '\n');
    }
}
