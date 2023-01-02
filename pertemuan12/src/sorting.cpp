#include <iostream>

using namespace std;

int min(int arr[], int first, int last);
void swap(int &a, int &b);

void bub_sort(int arr[], int first, int last);
void sel_sort(int arr[], int first, int last);
void ins_sort(int arr[], int first, int last);

int main()
{
    const int SIZE = 8;
    int data[SIZE] = {
        32,
        43,
        75,
        21,
        64,
        76,
        96,
        12};

    // bub_sort(data, 0, SIZE);
    // sel_sort(data, 0, SIZE);
    ins_sort(data, 0, SIZE);
    for (int d : data)
    {
        cout << d << ' ';
    }
    return 0;
}

void swap(int &a, int &b)
{
    int c = a;
    a = b;
    b = c;
}

void bub_sort(int arr[], int first, int last)
{
    for (int i = first; i < last - 1; ++i)
    {
        for (int j = first; j < last - i - 1; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int min(int arr[], int first, int last)
{
    int idx_min = first;
    for (int i = first + 1; i < last; ++i)
    {
        if (arr[i] < arr[idx_min])
        {
            idx_min = i;
        }
    }
    return idx_min;
}

void sel_sort(int arr[], int first, int last)
{
    for (int i = first; i < last; ++i)
    {
        int idx_min = min(arr, i, last);
        swap(arr[idx_min], arr[i]);
    }
}

void ins_sort(int arr[], int first, int last)
{
    for (int i = first + 1; i < last; ++i)
    {
        int sel_val = arr[i];
        int ins_idx = i - 1;
        while (ins_idx >= first && sel_val < arr[ins_idx])
        {
            arr[ins_idx + 1] = arr[ins_idx];
            --ins_idx;
        }
        arr[ins_idx + 1] = sel_val;
    }
}