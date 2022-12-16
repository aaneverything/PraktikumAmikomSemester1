// Fungsi lanjut
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

// Prototype
int countWord(string str);
void swap(char &a, char &b);
string encrypt(string str);

int main()
{
    string word = "yo ndak tau kok tanya saya";
    cout << word << ": " << countWord(word) << endl;
    char a = 'X';
    char b = 'Y';
    cout << "a." << a << " | b." << b << endl;
    swap(a, b);
    cout << "a." << a << " | b." << b << endl
         << endl;
    string myName;
    cout << "Nama: ";
    getline(cin, myName);
    string encryptName = encrypt(myName);
    cout << "Nama Acak: " << encryptName << endl;
    return 0;
}

// Fungsi countWord
// Menghitung jumlah kata dalam kalimat
// type: int    - Jumlah Kata
// Arg: str     - Input Kalimat
int countWord(string str)
{
    int count = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == ' ')
        {
            count++;
        }
    }
    return count + 1;
}

// Fungsi Swap
// Menukar 2 nilai a dan b
// Type : Void
// Arg : char a - nilai 1
//       char b - nilai 2
void swap(char &a, char &b)
{
    char c = a;
    a = b;
    b = c;
}

// Fungsi encrypt
// Mengacak susunan huruf dari sebuah string
// Tipe :   string  - string dengan huruf yang sudah teracak
// Arg  :   string str  - string input
string encrypt(string str)
{
    int lenght = str.length();
    string encrypted = str;
    srand(time(NULL));

    for (int i = 0; i < lenght / 2; i++)
    {
        int idx1 = rand() % lenght;
        int idx2 = rand() % lenght;
        swap(encrypted[idx1], encrypted[idx2]);
    }
    return encrypted;
}