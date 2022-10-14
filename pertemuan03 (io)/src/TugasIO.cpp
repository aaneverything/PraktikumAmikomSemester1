#include <iostream>
using namespace std;

// int main()
// {
//     float data;
//     cout << "Program Merubah Suhu Celcius ke Reamur dan Farenhet\n";
//     cout << "Masukan Suhu Celcius : C\b\b";

//     cin >> data;
//     float hasilkelvin = data + 273.15;
//     double hasilreamur = data * 4 / 5;
//     float hasilfarenheat = (9 / 5) * data + 32;

//     cout << "====================\n";
//     cout << "Hasil Kelvin : " << hasilkelvin << endl;
//     cout << "Hasil Remaur : " << hasilreamur << endl;
//     cout << "Hasil Farenheat : " << hasilfarenheat << endl;
//     cout << "====================";

//     cin.get();
//     return 0;
// }

int main()
{

    int menu;
    int data;
    double hasilreamur;
    double hasilfarenheat;
    double hasilkelvin;

    cout << "Program Mengubah suhu\n";
    cout << "1. Celcius ke Reamur\n2. Celcius ke Farenheat\n3. Celcius ke Kelvin\n";
    cout << "Pilih Menu : ";
    cin >> menu;
    if (menu > 3)
    {
        cout << "ga ada menunya";
        cin.get();
    }
    else
    {
        switch (menu)
        {
        case 1:
            cout << "Data : ";
            cin >> data;
            hasilreamur = data * 4 / 5;
            cout << "Hasil Remaur : " << hasilreamur << endl;
            cin.get();

            break;
        case 2:
            cout << "Data : ";
            cin >> data;
            hasilfarenheat = (9 / 5) * data + 32;
            cout << "Hasil Farenheat : " << hasilfarenheat << endl;
            cin.get();
            break;
        case 3:
            cout << "Data : ";
            cin >> data;
            hasilreamur = data * 4 / 5;
            cout << "Hasil Kelvin : " << hasilkelvin << endl;
            cin.get();

            break;
        }
    }

    cin.get();
    return 0;
}
