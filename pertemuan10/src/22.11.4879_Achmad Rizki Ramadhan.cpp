#include <iostream>
using namespace std;

// prototype
void dec2bin(int n);

int main()
{
    dec2bin(12);
    return 0;
}

// fungsi desimal ke biner
// merubah bilangan desimal ke biner
// type : void
// arg  : int n = nilai desimal yang ingin diubah
void dec2bin(int n)
{
    if (n <= 1)
    {
        cout << n;
        return;
    }
    dec2bin(n >> 1);
    cout << n % 2;
}