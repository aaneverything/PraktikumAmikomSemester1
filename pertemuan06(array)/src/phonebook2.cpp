#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

// membuat struktur data untuk PhoneBook
struct PhoneBook
{
    string phone;
    string name;
    string address;
};

int main()
{
    vector<PhoneBook> pb;

    // struktur menu:
    string menu;

    while (true)
    {

        system("cls");
        cout << "Phonebook\n";
        cout << "[1] Insert\n";
        cout << "[2] Show\n";
        cout << "[3] FInd\n";
        cout << "[4] Exit\n";
        cout << "Select: ";
        getline(cin, menu);
        switch (menu[0])
        {
        case '1':
            // input:
            while (true)
            {

                string ip, in, ia;
                system("cls");

                cout << "Phone: ";
                getline(cin, ip);
                // jika nomor telp. kosong, input selesai
                if (ip == "")
                    break;

                cout << "Name : ";
                getline(cin, in);
                cout << "Addr.: ";
                getline(cin, ia);

                // simpan ke vector:
                pb.push_back({ip, in, ia});
            }
            break;
        case '2':
            // show:
            system("cls");
            cout << "----------------------------------------------------------------------\n";
            cout << setw(14) << "PHONE NUM" << setw(25) << "NAME" << setw(31) << "ADRRESS";
            cout << "\n----------------------------------------------------------------------\n";

            // for each 'p' dalam 'pb'
            // note: pb adalah vector (jumlahnya banyak)
            for (auto p : pb)
            {
                cout << setw(14) << p.phone;
                cout << setw(25) << p.name;
                cout << setw(31) << p.address;
                cout << endl;
            }
            cout << "----------------------------------------------------------------------\n";
            system("pause");
            break;
        case '3':
        {
            string nsearch;
            int idx_found = pb.size();
            system("cls");
            cout << "Search \n";
            cout << "Enter Name: ";
            getline(cin, nsearch);
            for (int i = 0; i < pb.size(); i++)
            {
                if (nsearch == pb[i].name)
                {
                    idx_found = i;
                    break;
                }
            }
            if (idx_found == pb.size())
            {
                cout << "Not Found\n\n";
            }
            else
            {
                cout << "Phone :" << pb[idx_found].phone << endl;
                cout << "Name :" << pb[idx_found].name << endl;
                cout << "Address :" << pb[idx_found].address << endl;
            }
            cout << "Result: \n";
            system("pause");
            break;
        }

        case '4':
            return 0;
        }
    }

    return 0;
}