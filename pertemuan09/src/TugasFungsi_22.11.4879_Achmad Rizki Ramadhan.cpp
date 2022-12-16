#include <iostream>
#include <string>

using namespace std;

// prototype
float luaslingkaran(float n);
float luassegitiga(float o, float p);

int main()
{
    cout << "Luas Lingkaran : " << luaslingkaran(5) << endl;
    cout << "Luas Segitiga: " << luassegitiga(5, 3) << endl;
    return 0;
}

// fungsi untuk menghitung luas lingkaran
// type : non void(float);
// arg  :  float n = jari jari
float luaslingkaran(float n)
{
    float hasil = 3.14 * n * n;
    return hasil;
}

// fungsi untuk menghitung luas lingkaran
// type : non void(float);
// arg  :   float a = alas segitiga
//          float t = tinggi segitiga
float luassegitiga(float a, float t)
{
    float hasil = 0.5 * a * t;
    return hasil;
}