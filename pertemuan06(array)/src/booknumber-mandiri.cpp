#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

int main()
{
    cout << "====== Selamat datang di Book Number ======\n";

    // membuat variable untuk array dan panjang array
    /* struktur array yang diinginkan
    [
        ["nama", "nomer", "alamat"],
        ["nama", "nomer", "alamat"],
        ["nama", "nomer", "alamat"]
     ] */

    const int jumlahData = 10;
    string dataKontak[jumlahData][3];

    string nama, nomer, alamat;

    int i = 0;

    while (true)
    {
        int input;
        cout << "\nSilahkan Pilih Menu" << endl;
        cout << "1. Tambah Nomer" << endl;
        cout << "2. Edit Nomer" << endl;
        cout << "3. Cari Nomer" << endl;
        cout << "4. Liat Daftar Nomer\n\n";
        cout << "Pilih Menu : ";
        cin >> input;
        {
            switch (input)
            {
            case 1:
                system("cls");
                cout << "Masukan nama : ";
                cin >> nama;
                cout << "Masukan nomer : ";
                cin >> nomer;
                cout << "Masukan alamat : ";
                cin >> alamat;
                dataKontak[i][0] = nama;
                dataKontak[i][1] = nomer;
                dataKontak[i][2] = alamat;
                if (dataKontak[i][0] == nama && dataKontak[i][1] == nomer && dataKontak[i][2] == alamat)
                {
                    system("cls");
                    cout << "Data berhasil disimpan!\n";
                    Sleep(1500);
                    i += 1;
                    system("cls");
                }
                else
                {
                    system("cls");
                    cout << "Data gagal disimpan!";
                    Sleep(1500);
                }
                break;
            case 2:
                cout << " anda memilih menu edit nomer";
                break;
            case 3:
                cout << " anda memilih menu cari nomear";
                break;
            case 4:
                system("cls");

                for (int i = 0; i < jumlahData; i++)
                {
                    cout << "=============================\n";
                    cout << "Nama : " << dataKontak[i][0] << endl;
                    cout << "Nomer : " << dataKontak[i][1] << endl;
                    cout << "Alamat : " << dataKontak[i][2] << endl;
                    cout << "=============================\n";
                }
                break;
            default:
                break;
            }
        }
    }
    return 0;
}