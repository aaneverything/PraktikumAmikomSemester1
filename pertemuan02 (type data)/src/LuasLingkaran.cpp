#include <iostream>
using namespace std;

int main(){
    const float PI = 3.14;
    int jari;
    float hasil;

    cout << "========== Program Mencari Luas Lingkaran ==========\n";
    cout << "Masukan Jari-Jari : ";
    cin >> jari;
    hasil = PI * jari * jari ;
    cout << "Hasil : " << hasil << endl;
    cout << "====================================================\n";

    cin.get();
    return 0;
}