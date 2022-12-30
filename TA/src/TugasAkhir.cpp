#include "menu.cpp"
#include "xycolor.h"

void all();
void firstLogin();
void incomeDetail();
void spendDetail();
void addSpend();
void addIncome();
void loadingAnimation(int panjang, int x, int y, int fc, int bc);
void searchKategori(string str);
void ulang(string menu, string atr);
void saveSpend(string nama, string kategori, string harga, string date);
void saveIncome(string nominal, string kategori, string date);
void textSuccess(int x, int y, int string);
void ulangBaru(int x, int y, string str, int color);
void loadData();

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
        all();
        break;
    case 1:
        addIncome();
        break;
    case 2:
        addSpend();
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
void all()
{
    system("cls");

    xyColor(21, 10, 0, 10);
    cout << "Income: " << totalNominal("pemasukan") << " | Spending: " << totalNominal("pengeluaran") << endl;

    Menu menu;
    int input;
    menu.set_xy(21, 12);
    menu.set_color(menu.GREEN);
    input = menu.Gmenu("Income Details", "Spend Details", "Back");
    switch (input)
    {
    case 0:
        incomeDetail();
        break;
    case 1:
        spendDetail();
        break;
    case 2:
        main();
    }
}

// Fungsi Menampilkan Detail Total Pemasukan
void incomeDetail()
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
void spendDetail()
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
void addIncome()
{
    system("cls");
    string nominal, kategori;
    int inputKategori;

    xyColor(21, 11, 0, 14);
    cout << " Nominal " << endl;

    xyColor(21, 13, 14, 0);
    cin >> nominal;

    xyColor(35, 11, 0, 14);
    cout << " Pilih Kategori " << endl;

    Menu menu;
    menu.clear_screen(false);
    menu.set_xy(35, 13);
    menu.set_color(menu.YELLOW);
    inputKategori = menu.Gmenu("Pekerjaan", "Investasi", "Nyolong");
    switch (inputKategori)
    {
    case 0:
        kategori = "Pekerjaan";
        saveIncome(nominal, kategori, date());
        loadingAnimation(30, 21, 17, 14, 14);
        textSuccess(57, 11, 14);
        ulangBaru(57, 13, "addIncome", 14);
        break;
    case 1:
        kategori = "Investasi";
        saveIncome(nominal, kategori, date());
        loadingAnimation(30, 21, 17, 14, 14);
        textSuccess(57, 11, 14);
        ulangBaru(57, 13, "addIncome", 14);
        break;
    case 2:
        kategori = "Nyolong";
        saveIncome(nominal, kategori, date());
        loadingAnimation(30, 21, 17, 14, 14);
        textSuccess(57, 11, 14);
        ulangBaru(57, 13, "addIncome", 14);
        break;
    }
}

// Fungsi Tambah Pengeluaran
void addSpend()
{
    system("cls");
    string nama, kategori, harga;
    int inputKategori;

    xyColor(21, 11, 0, 10);
    cout << " Nama " << endl;

    xyColor(21, 13, 10, 0);
    cin.ignore();
    getline(cin, nama);

    xyColor(35, 11, 0, 10);
    cout << " Pilih Kategori " << endl;

    Menu menu;
    menu.clear_screen(false);
    menu.set_xy(35, 13);
    menu.set_color(menu.GREEN);

    inputKategori = menu.Gmenu("Makanan", "Pakaian", "Lainnya");

    switch (inputKategori)
    {
    case 0:
        kategori = "Makanan";
        xyColor(60, 11, 0, 10);
        cout << " Harga " << endl;

        xyColor(60, 13, 10, 0);
        getline(cin, harga);

        saveSpend(nama, kategori, harga, date());
        loadingAnimation(45, 21, 17, 10, 10);
        textSuccess(75, 11, 10);
        ulangBaru(75, 13, "addSpend", 10);
        break;
    case 1:
        kategori = "Pakaian";
        xyColor(60, 11, 0, 10);
        cout << " Harga " << endl;

        xyColor(60, 13, 10, 0);
        getline(cin, harga);

        saveSpend(nama, kategori, harga, date());
        loadingAnimation(45, 21, 17, 10, 10);
        textSuccess(75, 11, 10);
        ulangBaru(75, 13, "addSpend", 10);
        break;
    case 2:
        kategori = "Lainnya";
        xyColor(60, 11, 0, 10);
        cout << " Harga " << endl;

        xyColor(60, 13, 10, 0);
        getline(cin, harga);

        saveSpend(nama, kategori, harga, date());
        loadingAnimation(45, 21, 17, 10, 10);
        textSuccess(75, 11, 10);
        ulangBaru(75, 13, "addSpend", 10);
        break;
    }
}

// Fungsi Save Pemasukan
// Arg  :   - string nominal -> jumlah jumlah nominal pemasukan
//          - string kategori -> kategori pemasukan
//          - string date -> tanggal waktu save pemasukan
void saveIncome(string nominal, string kategori, string date)
{
    // Push data ke vector
    // string nominal, kategori, tanggal;
    DataPemasukan temp;
    temp.nominal = nominal;
    temp.kategori = kategori;
    temp.date = date;
    dataIn.push_back(temp);
    //
    // dataIn.push_back({nominal, kategori, date});
    std::ofstream out("data.txt");
    for (auto in : dataIn)
    {
        out << in.nominal << ' ';
        out << in.kategori << ' ';
        out << in.date << ' ';
        out << '\n';
    }
    out.close();
}

// Fungsi Save Pengeluaran
// Arg  :   - string nama -> nama pengeluaran
//          - string kategori -> kategori pengeluaran
//          - string harga -> nominal pengeluaran
//          - string date -> tanggal waktu save pengeluaran
void saveSpend(string nama, string kategori, string harga, string date)
{
    // Push data ke vector
    dataOut.push_back({nama, kategori, harga, date});
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
            addSpend();
        }
        if (menu == "pemasukan")
        {
            addIncome();
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
void firstLogin()
{
    Menu menu;
    if (first == true)
    {
        system("cls");
        xyColor(21, 10, 0, 12);
        cout << "Welcome to Catat.in" << endl;
        xyColor(21, 17, 0, 12);
        cout << "Use the arrow keys to move through the menus." << endl;
        first = false;
        loadData();
    }
    else
    {
        system("cls");
        xyColor(21, 10, 0, 12);
        cout << "Welcome to Catat.in" << endl;
        xyColor(21, 17, 0, 12);
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
    string date = to_string(local_time->tm_hour) + ":" + to_string(local_time->tm_min) + "-" + to_string(local_time->tm_mday) + "-" + to_string(1 + local_time->tm_mon) + "-" + to_string(1900 + local_time->tm_year);
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

void loadingAnimation(int panjang, int x, int y, int fc, int bc)
{
    char a = 177, b = 219;
    // xyColor(21, 17, 10, 10);
    xyColor(x, y, fc, bc);
    for (int i = 0; i <= panjang; i++)
    {
        cout << b;
        for (int j = 0; j <= 2e7; j++)
            ;
    }
}

// Fungsi untuk mmenampilkan keterangan sukses
// Arg : int x -> posisi x
//       int y -> posisi y
//       int color -> untuk merubah warna text (12 = red; 10 = green; 11 = turquoise; 14 = yellow; 13 = purle)
void textSuccess(int x, int y, int color)
{
    xyColor(x, y, 0, color);
    cout << " Sukses disimpan " << endl;
}

// Fungsi untuk menapilkan piliha ulang
// Arg : int x -> posisi x
//       int y -> posisi y
//       string str -> untuk pindah kemenu mana apa bila user konfirmasi ulang (addIncome/addSpend)
//       int color -> untuk merubah warna text (12 = red; 10 = green; 11 = turquoise; 14 = yellow; 13 = purle)
void ulangBaru(int x, int y, string str, int color)
{
    int input;
    Menu menu;
    menu.clear_screen(false);
    menu.set_xy(x, y);
    menu.set_color(menu.GREEN);
    if (color == 12)
        menu.set_color(menu.RED);
    if (color == 10)
        menu.set_color(menu.GREEN);
    if (color == 11)
        menu.set_color(menu.TURQUOISE);
    if (color == 14)
        menu.set_color(menu.YELLOW);
    if (color == 13)
        menu.set_color(menu.PURPLE);
    input = menu.Gmenu("Ulang", "Kembali");
    switch (input)
    {
    case 0:
        if (str == "addIncome")
        {
            addIncome();
            break;
        }
        if (str == "addSpend")
        {
            addSpend();
            break;
        }

    case 1:
        main();
        break;
    }
}

void loadData()
{
    ifstream file("data.txt");
    string nominal, kategori, tanggal;
    while (file >> nominal >> kategori >> tanggal)
    {
        DataPemasukan temp;
        temp.nominal = nominal;
        temp.kategori = kategori;
        temp.date = tanggal;
        dataIn.push_back(temp);
    }
    file.close();
}