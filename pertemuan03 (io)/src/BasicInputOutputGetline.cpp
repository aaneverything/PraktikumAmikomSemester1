// Basic Input Output
// Demo Mengggunakan Getline()
#include <iostream>
#include <string>
#include <windows.h>

using namespace std;
int main()
{
    string nama;
    cout << "Siapa Nama Pacarmu?\n";
    cout << "Jawab: ";
    getline(cin, nama);

    string salam = "Selamat Pagi " + nama + " sayangkuuu";
    int len = salam.length();

    for (int i = 0; i < len; ++i)
    {
        cout << salam[i];
        Sleep(100);
    }

    cin.get();
    return 0;
}
