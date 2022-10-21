#include <iostream>
using namespace std;

int main()
{

    int number;
    cout << "Konversi Angka\n";

    cout << "Masukan NIlai : ";
    cin >> number;

    if (number >= 86 && number <= 100)
    {
        cout << "NIlai A";
    }
    else if (number >= 85 && number <= 66)
    {
        cout << "NIlai B";
    }
    else if (number >= 65 && number <= 46)
    {
        cout << "NIlai C";
    }
    else if (number >= 1 && number <= 45)
    {
        cout << "Nilai D";
    }
    else if (number == 0)
    {
        cout << "Nilai E";
    }
    else
    {
        cout << "Nilai Tidak Valid";
    }
    return 0;
}