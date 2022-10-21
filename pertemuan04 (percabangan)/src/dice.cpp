#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main()
{

    for (bool i = true; i; i = true)
    {
        srand(time(NULL));
        int diceNumber = rand() % 6 + 1;
        int guestNumber;

        cout << "Tebak Dadu Yang Muncul\n";
        cout << "Masukan Nilai Dadu: ";
        cin >> guestNumber;

        if (diceNumber == guestNumber)
        {
            cout << "Wah anda peramal yaaa, Jawabanya" << diceNumber << endl
                 << endl;
        }
        else
        {
            cout << "Salah Jawabanya tuh " << diceNumber << endl
                 << endl;
        }
    }

    return 0;
}
