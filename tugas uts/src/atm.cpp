#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

int main()
{
    string code = "1111";
    string userinput;
    int repeat = 0;
    int balance = 0;
    int inputmenu;
    int inputbalance;
    int withdrawbalance = 0;

    while (true)
    {
        cout << "Insert Pin : ";
        cin >> userinput;
        if (userinput == code)
        {
            system("cls");
            cout << "Correct Passcode";
            Sleep(1000);
            system("cls");

            while (true)
            {
                cout << "\n====== Welcome ======\n";
                cout << "1. Check balance\n";
                cout << "2. Add Balance\n";
                cout << "3. Withdraw Balance\n";
                cout << "4. Exit Program\n";

                cout << "=====================\n";
                cout << "Input Menu : ";
                cin >> inputmenu;
                switch (inputmenu)
                {
                case 1:
                    system("cls");
                    Sleep(500);
                    cout << "\nBalance : Rp.";
                    cout << balance << endl;
                    break;
                case 2:
                    system("cls");
                    cout << "Input Balance : ";
                    cin >> inputbalance;
                    balance += inputbalance;
                    Sleep(500);
                    system("cls");
                    cout << "Saved successfully!" << endl;
                    cout << "Total Balance : ";
                    cout << balance << endl;
                    Sleep(1000);
                    system("cls");
                    break;
                case 3:
                    if (balance == 0)
                    {
                        system("cls");
                        cout << "Balance is not sufficient" << endl;
                        Sleep(500);
                    }
                    else
                    {
                        system("cls");
                        cout << "Withdrawal Amount : ";
                        cin >> withdrawbalance;
                        if (withdrawbalance > balance)
                        {
                            system("cls");
                            cout << "Balance is not sufficient" << endl;
                            Sleep(500);
                        }
                        else
                        {
                            balance -= withdrawbalance;
                            withdrawbalance = 0;
                            Sleep(500);
                            system("cls");
                            cout << "Withdraw successfully!" << endl;
                            cout << "\nTotal Balance : ";
                            cout << balance << endl;
                        }
                    }
                    break;
                case 4:
                    return 0;
                default:
                    break;
                }
            }
        }
        else if (repeat == 5)
        {
            system("cls");
            cout << "Blocked!" << endl;
            break;
        }
        else
        {
            system("cls");
            cout << "Passcode wrong, try again!" << endl;
            repeat++;
            Sleep(1000);
            system("cls");
        }
    }
    return 0;
}