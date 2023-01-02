#include <iostream>
#include <algorithm>

using namespace std;

int bin_search(int arr[], int first, int last, int key);
int main()
{
    const int SIZE = 10;
    int data[SIZE] = {12, 23, 32, 34, 56, 65, 78, 85, 89, 90};
    int key = 100;
    int found = bin_search(data, 0, SIZE, key);
    if (found != SIZE)
    {
        cout << "Data ditemukan" << endl;
    }
    else
    {
        cout << "Data tidak ditemukan" << endl;
    }

    return 0;
}

int bin_search(int arr[], int first, int last, int key)
{
    int l = first;
    int r = last;

    while (r - l > 1)
    {
        int m = l + (r - l) / 2;
        if (key == arr[m])
        {
            return m;
        }
        if (key < arr[m])
        {
            r = m;
        }
        else
        {
            l = m;
        }
    }
    return last;
}
