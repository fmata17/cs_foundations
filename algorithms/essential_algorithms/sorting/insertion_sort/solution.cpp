#include <iostream>
using namespace std;
/*
  s  u  u  u  u
< 8, 4, 2, 7, 1 >

  s  s  u  u  u
< 4, 8, 2, 7, 1 >

  s  s  s  u  u
< 2, 4, 8, 7, 1 >

  s  s  s  s  u
< 2, 4, 7, 8, 1 >

  s  s  s  s  s
< 1, 2, 4, 7, 8 >

assume a single element is sorted, append to the sorted side by switching the compared element with
its neighbor until its in the right place
*/

void insertionSort(int unsortedList[], int size)
{
    int j = 0;    // use j to not mess with the i loop counter
    int temp = 0; // use to make comparison switches
    for (int i = 1; i < size; ++i)
    {
        j = i;
        while (j > 0 && unsortedList[j] < unsortedList[j - 1]) // shortcircuit to avoid index underflow
        {
            temp = unsortedList[j - 1];
            unsortedList[j - 1] = unsortedList[j];
            unsortedList[j] = temp;
            --j;
        }
    }
}

int main(int argc, char const *argv[])
{
    int arr[] = {4, 1, 3, 0, 9};
    insertionSort(arr, 5);
    for (int i : arr)
    {
        cout << i << ' ';
    }
    cout << endl;
    return 0;
}
