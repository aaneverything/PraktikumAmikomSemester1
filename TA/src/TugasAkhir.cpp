#include "menu.cpp"
#include "cursorx.h"

void ulang(string menu, string atr);
void rekap();
void firstLogin();
void detailPemasukan();
void detailPengeluaran();
void tambahPengeluaran();
void tambahPemasukan();
void savePengeluaran(string nama, string kategori, string harga, string date);
void savePemasukan(string nominal, string kategori, string date);
void searchKategori(string str);
int totalNominal(string total);
string randomQuote();
string date();

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
    Menu menu;
    firstLogin();
    int input;
    menu.set_xy(21, 12);
    menu.set_color(menu.RED);
    input = menu.Gmenu("View all records", "Add entry records", "Add expense records", "Exit");
    switch (input)
    {
    case 0:
        rekap();
        break;
    case 1:
        tambahPemasukan();
        break;
    case 2:
        tambahPengeluaran();
    case 3:
        return 0;
    }
    return 0;
}

// Fungsi Menamapilkan Total nominal
// Arg  : string total -> string total yang ingin ditampilkan (pemasukan/pengeluaran)
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

// Fungsi untuk melihat semua catatan
void rekap()
{
    system("cls");
    set_color(0, 0);

    Menu menu;
    int input;
    set_xy(21, 10);
    set_color(0, 10);
    cout << "Income: " << totalNominal("pemasukan") << " | Spending: " << totalNominal("pengeluaran") << endl;
    menu.set_xy(21, 12);
    menu.set_color(menu.GREEN);
    input = menu.Gmenu("Income Details", "Spend Details", "Back");
    switch (input)
    {
    case 0:
        detailPemasukan();
        break;
    case 1:
        detailPengeluaran();
        break;
    case 2:
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
    set_color(0, 12);
    string nominal, kategori;
    int inputKategori;

    set_xy(21, 11);
    set_color(0, 10);
    cout << " Nominal " << endl;
    set_xy(21, 13);
    set_color(10, 0);

    cin.ignore();
    getline(cin, nominal);

    set_color(0, 10);
    set_xy(35, 11);
    cout << " Pilih Kategori " << endl;
    Menu menu;
    menu.clear_screen(false);
    menu.set_xy(35, 13);
    menu.set_color(menu.GREEN);
    inputKategori = menu.Gmenu("Pekerjaan", "Investasi", "Nyolong");
    switch (inputKategori)
    {
    case 0:
        kategori = "Pekerjaan";
        savePemasukan(nominal, kategori, date());
        break;
    case 1:
        kategori = "Investasi";
        savePemasukan(nominal, kategori, date());
        break;
    case 2:
        kategori = "Nyolong";
        savePemasukan(nominal, kategori, date());
        break;
    }
}

// Fungsi Tambah Pengeluaran
void tambahPengeluaran()
{
    system("cls");
    string nama, kategori, harga;
    cout << "Nama : ";
    cin.ignore();

    getline(cin, nama);
    cout << "Kategori: " << endl;
    cout << "[1]. Makanan" << endl;
    cout << "[2]. Pakaian" << endl;
    cout << "[3]. Lainnya" << endl;
    cout << "Pilih : ";
    getline(cin, kategori);
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
    getline(cin, harga);
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
    char a = 177, b = 219;
    set_xy(21, 17);
    set_color(10, 10);
    for (int i = 0; i <= 30; i++)
    {
        cout << b;
        for (int j = 0; j <= 2e7; j++)
            ;
    }
    set_xy(57, 11);
    set_color(0, 10);
    cout << " Sukses disimpan " << endl;
    // set_xy(57, 15);

    int input;
    Menu menu;
    menu.clear_screen(false);
    menu.set_xy(57, 13);
    menu.set_color(menu.GREEN);
    input = menu.Gmenu("Ulang", "Kembali");
    switch (input)
    {
    case 0:
        /* code */
        tambahPemasukan();
        // getch();
        break;

    case 1:
        main();
        // getch();
        break;
    }
    // set_color(0, 0);
    // ulang("pemasukan", "Ulang? (y/n) : ");
    // getch();
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
    return;
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
    set_color(0, 0);
}

// Fungsi Untuk Mengecek User Apakah Pertama Kali Login
bool first = true;
void firstLogin()
{
    Menu menu;
    if (first == true)
    {
        system("cls");
        set_xy(21, 10);
        set_color(0, 12);
        cout << "Welcome to Catat.in" << endl;
        set_xy(21, 17);
        cout << "Use the arrow keys to move through the menus." << endl;
        first = false;
    }
    else
    {
        system("cls");
        set_xy(21, 10);
        set_color(0, 12);
        cout << "Welcome to Catat.in" << endl;
        set_xy(21, 17);
        cout << randomQuote() << endl;
    }
}

string randomQuote()
{
    srand(time(NULL));
    string text[4] = {
        "Tidak menghabiskan uang adalah cara terbaik untuk menabung",
        "Jika kamu ingin kaya, pikirkanlah menabung dan menghasilkan",
        "Jangan pernah menghabiskan uang Anda sebelum Anda memilikinya",
        "Dalam berhemat, kamu akan belajar untuk memprioritaskan hal yang lebih penting"};
    int idx = rand() % 4;
    return text[idx];
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