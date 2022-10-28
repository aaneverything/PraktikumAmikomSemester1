#include <iostream>
using namespace std;

int main()
{
    int banyakNomer = 100;
    for (int i = 1; i < banyakNomer; ++i)
    {
        if (i % 2 == 0)
        {
            cout << i << " Ini Nomer Genap\n";
        }
    }
    return 0;
}
