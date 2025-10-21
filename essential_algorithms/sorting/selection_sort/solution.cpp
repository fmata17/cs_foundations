#include <iostream>
#include <cstdlib>
using namespace std;

void mySwap(int *i, int *j)
// swap two elements in an int array
// own, simplified version of std::swap
{
    int temp = *i;
    *i = *j;
    *j = temp;
}

void selectionSort(int arr[], int size) // O(n^2)
// repeatedly finds the smallest element and moves it to the front.
{
    for (int i = 0; i < size; ++i) // for each element in the array
    {
        int currMin = arr[i];
        int currMinIndex = i;

        for (int j = i + 1; j < size; ++j) // find the current minimum, unordered element
        {
            if (arr[j] < currMin)
            {
                currMin = arr[j];
                currMinIndex = j;
            }
        }

        mySwap(&arr[i], &arr[currMinIndex]); // and insert to the sorted left side
    }
}
int main()
{
    srand(12345); // fixed seed for reproducibility
    int size = 10;
    int *arr = new int[size];

    for (int i = 0; i < size; ++i)
    {
        int val = rand() % 100;
        arr[i] = val;
    }

    for (int i = 0; i < size; ++i){
        cout << arr[i] << " ";
    }
    cout << endl;

    selectionSort(arr, size);

    for (int i = 0; i < size; ++i){
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;
    return 0;
}
