// Program IO Basic
#include <iostream>
#include <cmath>

using namespace std;
int main(){
    double a,b;
    
    cout << "Menghitung Sisi Miring Segitiga\n";
    cout << "Input A :";
    cin >> a ;

    cout << "Input B :";
    cin >> b;

    double c = hypot(a,b);
    cout << "Sisi Miring = " << c ;

    cin.get();
    return 0;
}