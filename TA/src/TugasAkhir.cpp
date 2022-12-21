#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <sstream>
#include "cursorx.h"
#include <ctime>

using namespace std;

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
string date();
int totalNominal(string total);
void searchKategori(string str);

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
    set_color(15, 6);

    fistLogin();
    int input;
    set_color(15, 13);
    set_xy(40, 10);
    cout << "       |   [1]. Rekap              |       " << endl;
    set_xy(40, 11);
    cout << "       |   [2]. Tambah Catatan     |       " << endl;
    set_xy(40, 12);
    cout << "       |   [3]. Keluar Program     |       " << endl;
    set_xy(40, 13);
    cout << "       |                           |       " << endl;
    set_xy(40, 14);
    cout << "       |   Pilih :                 |       " << endl;
    set_xy(40, 15);
    cout << "                                           ";
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

// Fungsi Menamapilkan Total nominal
// Arg  : string total -> total yan ingin ditampilkan (pemasukan/pengeluaran)
int totalNominal(string total)
{
    if (total == "pemasukan")
    {
        int nominal = 0;
        for (auto in : dataIn)
        {

            int harga = stoi(in.nominal);
            nominal += harga;
        }
        return nominal;
    }
    else if (total == "pengeluaran")
    {
        int nominal = 0;
        for (auto out : dataOut)
        {
            int harga = stoi(out.harga);
            nominal += harga;
        }
        return nominal;
    }
    return 0;
}

// Fungsi Rekap
void rekap()
{
    system("cls");

    cout << "------------------------------------------------------------------\n";
    cout << setw(20) << "Total Pemasukan : " << totalNominal("pemasukan") << setw(15) << " | " << setw(20) << "Total Pengeluaran : " << totalNominal("pengeluaran");
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
    cout << setw(20) << "Total Pemasukan : " << totalNominal("pemasukan");
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
    cout << setw(20) << "Total Pengeluaran : " << totalNominal("pengeluaran");
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

// Fungsi Tambah Pengeluaran
void tambahPengeluaran()
{
    system("cls");
    cout << "Nama    : ";
    string nama;
    cin >> nama;
    cout << "Kategori: " << endl;
    cout << "[1]. Makanan" << endl;
    cout << "[2]. Pakaian" << endl;
    cout << "[3]. Lainnya" << endl;
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
    if (kategori == "3")
    {
        kategori = "Lain-Lain";
    }
    cout << "Harga : ";
    string harga;
    cin >> harga;
    savePengeluaran(nama, kategori, harga, date());
}

// Fungsi Save Pemasukan
// Arg  :   - string nominal -> jumlah jumlah nominal pemasukan
//          - string kategori -> kategori pemasukan
//          - string date -> tanggal waktu save pemasukan
void savePemasukan(string nominal, string kategori, string date)
{
    // Push data ke vector
    dataIn.push_back({nominal, kategori, date});
    Sleep(3000);
    cout << "sukses disimpan";
    ulang("pemasukan", "Ulang?(y/n) : ");
}

// Fungsi Save Pengeluaran
// Arg  :   - string nama -> nama pengeluaran
//          - string kategori -> kategori pengeluaran
//          - string harga -> nominal pengeluaran
//          - string date -> tanggal waktu save pengeluaran
void savePengeluaran(string nama, string kategori, string harga, string date)
{
    // Push data ke vector
    dataOut.push_back({nama, kategori, harga, date});
    ulang("pengeluaran", "Ulang?(y/n) : ");
}

// Fungsi Untuk Mengecek Apakah User Ingin Mengulangi
// Arg  : string menu -> untuk ulang ke fungsi pengeluaran/pemasukan/menu
//      : string str -> kalimat yang ingin ditampilkan
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
        set_color(15, 13);
        set_xy(40, 7);
        cout << "                                           " << endl;
        set_xy(40, 8);
        cout << "       |      Selamat Datang       |       " << endl;
        set_xy(40, 9);
        cout << "       |                           |       " << endl;
        first = false;
    }
    else
    {
        system("cls");
        set_color(15, 13);
        set_xy(40, 7);
        cout << "                                           " << endl;
        set_xy(40, 8);
        cout << "     Silahkan Pilih Menu Yang Tersedia     " << endl;
        set_xy(40, 9);
        cout << "       |                           |      " << endl;
    }
}

string date()
{
    time_t ttime = time(0);
    tm *local_time = localtime(&ttime);
    string date = to_string(local_time->tm_hour) + ":" + to_string(local_time->tm_min) + " " + to_string(local_time->tm_mday) + "-" + to_string(1 + local_time->tm_mon) + "-" + to_string(1900 + local_time->tm_year);
    return date;
}

// Fungsi untuk mencari data berdasarkan kategori
// Arg  : string str -> data yang ingin dicari "Pemasukan | Pengeluaran"
void searchKategori(string str)
{
    cout << "Input Kategori : ";
    string kategori;
    cin >> kategori;
    if (str == "Pemasukan")
    {
        for (int i = 0; i < dataIn.size(); i++)
        {
            if (kategori == dataIn[i].kategori)
            {
                cout << dataIn[i].kategori << endl;
                cout << dataIn[i].nominal << endl;
                cout << dataIn[i].date << endl;
            }
        }
    }
    if (str == "Pengeluaran")
    {
        for (int i = 0; i < dataOut.size(); i++)
        {
            if (kategori == dataIn[i].kategori)
            {
                cout << dataOut[i].nama << endl;
                cout << dataOut[i].harga << endl;
                cout << dataOut[i].kategori << endl;
                cout << dataOut[i].date << endl;
            }
        }
    }
}