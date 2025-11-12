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

void quickSort(int arr[], int left, int right) // best -> O(nlogn)    worst -> O(n^2)
// pick a random pivot, partition the array so smaller elements go left
// and larger go right, then recursively sorts both sides.
{
    // base case
    if (left >= right)
        return;

    int pivotIndex = left + (rand() % (right + 1 - left));
    int pivot = arr[pivotIndex];

    // temporarily move pivot to end to keep it out of the way while comparing other elements
    mySwap(&arr[pivotIndex], &arr[right]);

    int i = left; // index for next sorted element

    // partition by smaller and greater than pivot using i as the delimeter index
    for (int j = left; j < right; ++j)
    {
        if (arr[j] <= pivot)
        {
            // insert to the left sublist (less than pivot)
            mySwap(&arr[i], &arr[j]);
            ++i;
        }
    }
    // insert pivot in correct position
    mySwap(&arr[i], &arr[right]);

    int partitionIndex = i;

    // recursion
    quickSort(arr, left, partitionIndex - 1);
    quickSort(arr, partitionIndex + 1, right);
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

    for (int i = 0; i < size; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    quickSort(arr, 0, size - 1);

    for (int i = 0; i < size; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;
    return 0;
}
