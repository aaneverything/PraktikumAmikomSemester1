#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <sstream>
#include "cursorx.h"
#include <ctime>

using namespace std;

// Prototype
void ulang(string menu, string atr);
void catatan();
void rekap();
void tambahPengeluaran();
void tambahPemasukan();
void savePengeluaran(string nama, string kategori, string harga, string date);
void savePemasukan(string nominal, string kategori, string date);
void detailPemasukan();
void detailPengeluaran();
void fistLogin();
int totalPemasukan();
int totalPengeluaran();
string date();

// Vector Data Disimpan
struct DataPengeluaran
{
    string nama;
    string kategori;
    string harga;
    string date;
};
struct DataPemasukan
{
    string nominal;
    string kategori;
    string date;
};
vector<DataPengeluaran> dataOut;
vector<DataPemasukan> dataIn;

// Fungsi Utama
int main()
{
    fistLogin();
    int input;
    cout << "|   [1]. Rekap              |" << endl;
    cout << "|   [2]. Tambah Catatan     |" << endl;
    cout << "|   [3]. Keluar Program     |" << endl;
    cout << "|                           |" << endl;
    cout << "|   Pilih :                 |\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
    cin >> input;
    switch (input)
    {
    case 1:
        rekap();
        break;
    case 2:
        catatan();
        break;
    case 3:
        break;

    default:
        cout << "Menu tidak ada";
    }
    return 0;
}

// Fungsi Tambah Catatan
void catatan()
{
    system("cls");
    int input;
    cout << "[1]. Pemasukan" << endl;
    cout << "[2]. Pengeluaran" << endl;
    cout << "[3]. Kembali ke menu" << endl;
    cout << "[4]. Keluar Program" << endl;
    cout << "Pilih : ";
    cin >> input;
    switch (input)
    {
    case 1:
        tambahPemasukan();
        break;
    case 2:
        tambahPengeluaran();
        break;
    case 3:
        main();
        break;
    case 4:
        break;
    default:
        break;
    }
}

// Fungsi Menamapilkan Total Pemasukan
int totalPemasukan()
{
    int nominal = 0;
    for (auto in : dataIn)
    {

        nominal = stoi(in.nominal);
        nominal = +nominal;
    }
    return nominal;
}

// Fungsi Menmapilkan Total Pengeluaran
int totalPengeluaran()
{
    int nominal = 0;
    for (auto in : dataOut)
    {

        nominal = stoi(in.harga);
        nominal = +nominal;
    }
    return nominal;
}

// Fungsi Rekap
void rekap()
{
    system("cls");

    cout << "------------------------------------------------------------------\n";
    cout << setw(20) << "Total Pemasukan : " << totalPemasukan()
         << setw(15) << " | " << setw(20) << "Total Pengeluaran : " << totalPengeluaran();
    cout << "\n------------------------------------------------------------------\n";
    cout << "[1]. Rincian Pemasukan" << endl;
    cout << "[2]. Rincian Pengeluaran" << endl;
    cout << "[3]. Kembali" << endl;

    cout << "Pilih : ";
    int input;
    cin >> input;
    if (input == 1)
    {
        detailPemasukan();
    }
    if (input == 2)
    {
        detailPengeluaran();
    }
    if (input == 3)
    {
        main();
    }
}

// Fungsi Menampilkan Detail Total Pemasukan
void detailPemasukan()
{
    system("cls");
    cout << "------------------------------------------------------\n";
    cout << setw(20) << "Total Pemasukan : " << totalPemasukan();
    cout << "\n------------------------------------------------------\n";
    for (auto in : dataIn)
    {
        cout << setw(14) << in.nominal;
        cout << setw(25) << in.kategori;
        cout << setw(30) << in.date;

        cout << endl;
    }
    ulang("main", "Kembali ke menu? (y/n): ");
}

// Fungsi Menampilakan Detail Total Pengeluaran
void detailPengeluaran()
{
    system("cls");
    cout << "------------------------------------------------------\n";
    cout << setw(20) << "Total Pengeluaran : " << totalPengeluaran();
    cout << "\n------------------------------------------------------\n";
    for (auto out : dataOut)
    {
        cout << setw(14) << out.nama;
        cout << setw(25) << out.kategori;
        cout << setw(31) << out.harga;
        cout << setw(36) << out.date;
        cout << endl;
    }
    ulang("main", "Kembali ke menu? (y/n): ");
}

// Fungsi Tambah Pengeluaran
void tambahPengeluaran()
{
    system("cls");
    cout << "Nama: ";
    string nama;
    cin >> nama;
    cout << "Kategori: " << endl;
    cout << "[1]. Makanan" << endl;
    cout << "[2]. Pakaian" << endl;
    cout << "Pilih : ";
    string kategori;
    cin >> kategori;
    if (kategori == "1")
    {
        kategori = "Makanan";
    }
    if (kategori == "2")
    {
        kategori = "Pakaian";
    }
    cout << "Harga : ";
    string harga;
    cin >> harga;
    savePengeluaran(nama, kategori, harga, date());
}

// Fungsi Tambah Pemasukan
void tambahPemasukan()
{
    system("cls");
    cout << "Nominal: ";
    string nominal;
    cin >> nominal;
    cout << "Sumber Dana: " << endl;
    cout << "[1]. Pekerjaan" << endl;
    cout << "[2]. Investasi" << endl;
    cout << "Pilih : ";
    string kategori;
    cin >> kategori;
    if (kategori == "1")
    {
        kategori = "Pekerjaan";
    }
    if (kategori == "2")
    {
        kategori = "Investasi";
    }
    savePemasukan(nominal, kategori, date());
}

// Fungsi Save Pengeluaran
// Arg  :   - string nama -> nama pengeluaran
//          - string kategori -> kategori pengeluaran
//          - string harga -> nominal pengeluaran
//          - string date -> tanggal waktu save pengeluaran
void savePengeluaran(string nama, string kategori, string harga, string date)
{
    // vector<DataPengeluaran> dataOut;
    dataOut.push_back({nama, kategori, harga, date});
    ulang("pengeluaran", "Ulang?(y/n) : ");
}

// Fungsi Save Pemasukan
void savePemasukan(string nominal, string kategori, string date)
{
    // vector<DataPemasukan> dataIn;
    dataIn.push_back({nominal, kategori, date});
    ulang("pemasukan", "Ulang?(y/n) : ");
}

// Fungsi Untuk Mengecek Apakah User Ingin Mengulangi
void ulang(string menu, string str)
{
    cout << str;
    char ulang;
    cin >> ulang;
    if (ulang == 'y')
    {
        if (menu == "pengeluaran")
        {
            tambahPengeluaran();
        }
        if (menu == "pemasukan")
        {
            tambahPemasukan();
        }
        if (menu == "main")
        {
            main();
        }
    }
    if (ulang != 'y' | ulang != 'n' | ulang == 'n')
    {
        if (menu == "pengeluaran" | menu == "pemasukan")
        {
            main();
        }
        if (menu == "main")
        {
            return;
        }
    }
}

// Fungsi Untuk Mengecek User Apakah Pertama Kali Login
bool first = true;
void fistLogin()
{
    if (first == true)
    {
        system("cls");
        cout << "|      Selamat Datang       |" << endl;
        cout << "|                           |" << endl;
        first = false;
    }
    else
    {
        system("cls");
        cout << "Silahkan Pilih Menu Yang Tersedia" << endl;
        cout << "|                           |" << endl;
    }
}

string date()
{
    time_t ttime = time(0);
    tm *local_time = localtime(&ttime);
    string date = to_string(local_time->tm_hour) + ":" + to_string(local_time->tm_min) + " " + to_string(local_time->tm_mday) + "-" + to_string(1 + local_time->tm_mon) + "-" + to_string(1900 + local_time->tm_year);
    return date;
}