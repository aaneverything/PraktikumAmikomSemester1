#include <iostream>
#include <algorithm>

using namespace std;

int seq_search(int arr[], int first, int last, int key);
int main()
{
    const int SIZE = 10;
    int data[SIZE] = {12, 23, 92, 45, 56, 32, 45, 75, 32, 54};
    int key = 12;
    int found = seq_search(data, 0, SIZE, key);
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

int seq_search(int arr[], int first, int last, int key)
{
    int it = first;
    while (it != last)
    {
        if (key == arr[it])
        {
            break;
        }
        it++;
    }
    return it;
}