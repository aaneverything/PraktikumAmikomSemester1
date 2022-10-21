#include <iostream>
using namespace std;

int main()
{

    int a, b, c;
    cout << "Masukan 3 angka :";
    cin >> a >> b >> c;

    int max = a;
    if(b > max)
        max = b;
    
    if(c > max)
        max = c;
    

    cout << "Nilai Terbesar :" << max;
    return 0;
}