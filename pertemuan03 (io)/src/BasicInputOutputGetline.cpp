// Basic Input Output
// Demo Mengggunakan Getline()
#include <iostream>
#include <string>

using namespace std;
int main()
{
    string nama;
    cout << "Siapa Nama Pacarmu?\n";
    cout << "Jawab: ";
    getline(cin, nama);

    cout << "Selama pagi "<< nama << " sayangkuuu";
    cin.get();
    return 0;
}
