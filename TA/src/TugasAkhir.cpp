#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

// Prototype
void ulang(string menu, string atr);
void catatan();
void rekap();
void tambahPengeluaran();
void tambahPemasukan();
void savePengeluaran(string nama, string kategori, string harga);
void savePemasukan(string nominal, string kategori);
void detailPemasukan();
void detailPengeluaran();

bool first = true;
void fistLogin();

struct DataPengeluaran
{
    string nama;
    string kategori;
    string harga;
};

struct DataPemasukan
{
    string nominal;
    string kategori;
};

vector<DataPengeluaran> dataOut;
vector<DataPemasukan> dataIn;

// Fungsi Utama
int main()
{
    fistLogin();
    int input;
    cout << "[1]. Rekap" << endl;
    cout << "[2]. Tambah Catatan" << endl;
    cout << "[3]. Keluar Program" << endl;
    cout << "Pilih : ";
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

// Fungsi Rekap
void rekap()
{
    system("cls");
    cout << "------------------------------------------------------------------\n";
    cout << setw(20) << "Total Pemasukan : " << setw(15) << " | " << setw(20) << "Total Pengeluaran : ";
    cout << "\n------------------------------------------------------------------\n";
    cout << "[1]. Detail Pemasukan" << endl;
    cout << "[2]. Detail Pengeluaran" << endl;
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
}

// Fungsi Menampilkan Detail Total Pemasukan
void detailPemasukan()
{
    system("cls");
    cout << "------------------------------------------------------\n";
    cout << setw(20) << "Total Pemasukan : ";
    cout << "\n------------------------------------------------------\n";
    for (auto in : dataIn)
    {
        cout << setw(14) << in.nominal;
        cout << setw(25) << in.kategori;
        cout << endl;
    }
    ulang("main", "Kembali ke menu? (y/n): ");
}

// Fungsi Menampilakan Detail Total Pengeluaran
void detailPengeluaran()
{
    for (auto out : dataOut)
    {
        cout << setw(14) << out.nama;
        cout << setw(25) << out.kategori;
        cout << setw(31) << out.harga;
        cout << endl;
    }
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
    cout << "Harga : ";
    string harga;
    cin >> harga;
    savePengeluaran(nama, kategori, harga);
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
    savePemasukan(nominal, kategori);
}

// Fungsi Save Pengeluaran
void savePengeluaran(string nama, string kategori, string harga)
{
    // vector<DataPengeluaran> dataOut;
    dataOut.push_back({nama, kategori, harga});
    ulang("pengeluaran", "Ulang?(y/n) : ");
}

// Fungsi Save Pemasukan
void savePemasukan(string nominal, string kategori)
{
    // vector<DataPemasukan> dataIn;
    dataIn.push_back({nominal, kategori});
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
void fistLogin()
{
    if (first == true)
    {
        system("cls");
        cout << "Selamat Datang" << endl;
        first = false;
    }
    else
    {
        system("cls");
        cout << "Silahkan Pilih Menu Yang Tersedia" << endl;
    }
}