#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

int main()
{
    string salam = "======================================";
    int len = salam.length();

    for (int i = 0; i < len; ++i)
    {
        cout << salam[i];
        Sleep(1000);
    }
}
