// Progaram : toon Generator Nada
#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

int main()
{
    while (true)
    {
        char tone = getch();
        double freq = 0;
        switch (tone)
        {
        case 'c':
            freq = 261.63;
            break;
        case 'd':
            freq = 293.66;
            break;
        case 'e':
            freq = 329.63;
            break;
        case 'f':
            freq = 349.23;
            break;
        case 'g':
            freq = 392.00;
            break;
        case 'a':
            freq = 440.00;
            break;
        case 'b':
            freq = 493.88;
            break;
        }
        Beep(freq, 1500);
    }

    return 0;
}
