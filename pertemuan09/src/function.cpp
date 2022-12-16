// Demo Fungsi
#include <iostream>
#include <string>

using namespace std;

// prototype
void pyramid(int h, char c);
int factorial(int n);

int main()
{
    pyramid(10, 'a');
    cout << factorial(4) << endl;
    return 0;
}

// fungsi pyramid
// menggambar pyramid dengan karakter tertentu
// type : void
// arg ilkan : int h = tinggi pyramid
//      : char c = karekter yang ditampilkan
void pyramid(int h, char c)
{
    for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << c;
        }
        cout << endl;
    }
}

// fungsi faktorial
// menampilkan faktorial dari arg n
// type  : non void
// arg   : int n

int factorial(int n)
{
    int hasil = 1;
    for (int i = 1; i <= n; i++)
    {
        hasil = hasil * i;
    }
    return hasil;
}