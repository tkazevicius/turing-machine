#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <thread>
#include <mutex>
#include "Windows.h"
using namespace std;
struct Tiuringas
{
    string busena;
    char esamassim;
    char naujassim;
    char krypt;
    string naujabus;
};
void Darbas(Tiuringas T[]);
int main()
{
    Tiuringas T[5000];
    Darbas(T);
    return 0;
}
void Darbas(Tiuringas T[])
{
    cout << "Koki faila norite paleisti? ";
bruh:
    int galvute, veiksmai = 0;
    string file, juosta, bus;
    cin >> file;
    ifstream openfile;
    openfile.open(file.c_str());
    getline(openfile, juosta);
    openfile >> galvute;
    while (!openfile.eof())
    {
        openfile >> T[veiksmai].busena;
        openfile >> T[veiksmai].esamassim;
        openfile >> T[veiksmai].naujassim;
        openfile >> T[veiksmai].krypt;
        openfile >> T[veiksmai].naujabus;
        veiksmai++;
    }
    openfile.close();
    bus = '0';
    bool run = true;
    
loop:
    while (run)
    {
        if (galvute < 0 || galvute > juosta.length()) break;
        for (int i = 0; i < veiksmai; i++)
        {
            if (T[i].busena == bus)
            {
                if (T[i].esamassim == juosta[galvute])
                {
                    juosta[galvute] = T[i].naujassim;
                    if (T[i].krypt == 'R')
                    {
                        galvute++;
                    }
                    if (T[i].krypt == 'L')
                    {
                        galvute--;
                    }
                    bus = T[i].naujabus;
                }
            }
            if (bus == "H" || bus == "X" || GetAsyncKeyState(VK_LSHIFT))
            {
                run = false;
                goto loop;
            }
            cout << "\r" << juosta;
        }
    }
}