#include <iostream>
using namespace std;

int main()
{
    for (bool i = true; i; i = true)
    {
        int nilai;
        cout << "Masukkan nilai: ";
        cin >> nilai;
        if (nilai >= 86 && nilai <= 100)
        {
            cout << "Nilai A" << endl;
            cout << "lakukan perulangan lagi? (y/n) ";
            char ulang;
            cin >> ulang;
            if (ulang == 'y')
            {
                continue;
            }
            else
            {
                break;
            }
        }
        else if (nilai >= 66 && nilai <= 85)
        {
            cout << "Nilai B" << endl;
            cout << "lakukan perulangan lagi? (y/n) ";
            char ulang;
            cin >> ulang;
            if (ulang == 'y')
            {
                continue;
            }
            else
            {
                break;
            }
        }
        else if (nilai >= 46 && nilai <= 65)
        {
            cout << "Nilai C" << endl;
            cout << "lakukan perulangan lagi? (y/n) ";
            char ulang;
            cin >> ulang;
            if (ulang == 'y')
            {
                continue;
            }
            else
            {
                break;
            }
        }
        else if (nilai >= 1 && nilai <= 45)
        {
            cout << "Nilai D" << endl;
            cout << "lakukan perulangan lagi? (y/n) ";
            char ulang;
            cin >> ulang;
            if (ulang == 'y')
            {
                continue;
            }
            else
            {
                break;
            }
        }
        else if (nilai == 0)
        {
            cout << "Nilai E" << endl;
            cout << "lakukan perulangan lagi? (y/n) ";
            char ulang;
            cin >> ulang;
            if (ulang == 'y')
            {
                continue;
            }
            else
            {
                break;
            }
        }
        else
        {
            cout << "Nilai tidak valid" << endl;
            cout << "lakukan perulangan lagi? (y/n) ";
            char ulang;
            cin >> ulang;
            if (ulang == 'y')
            {
                continue;
            }
            else
            {
                break;
            }
        }
    }

    return 0;
}