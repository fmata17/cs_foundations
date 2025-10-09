#include <cstddef>
#include <iostream>
using namespace std;

// template <typename Type, size_t N>
// // Here, 'size_t N' is a compile-time constant automatically deduced from the array's length.
// // Unlike passing 'int size' manually, this lets the compiler know the array size at compile time
// // and prevents pointer decay — so 'arr' remains a full reference to the array, not just a pointer.
// // '(&arr)[N]' passes the whole array by reference (no copy, same memory cost as a pointer),
// // but keeps compile-time size info and type safety — unlike 'Type* arr', which loses size.
// int binarySearch(const Type (&arr)[N], const Type target)
// {
//     int mid = N / 2;
//     // base case
//     if (arr[mid] == target)
//     {
//         return mid;
//     }
//     else if (arr[mid] < target)
//     {
//         // binary_search();
//     }
//     else if (arr[mid] > target)
//     {
//     }
// }

// this method loses the context on the mid index every iteration so the final index is with respect to that iteration
template <typename Type>
int binarySearch(const Type arr[], int size, const Type target)
{
    int mid = size / 2;
    // base case
    if (size == 0)
    {
        return -1;
    }
    else if (arr[mid] == target)
    {
        return mid;
    }
    else if (arr[mid] < target)
    {
        cout << '<' << endl;
        return binarySearch(arr + (mid + 1), size - mid, target);
    }
    else if (arr[mid] > target)
    {
        cout << '>' << endl;
        return binarySearch(arr, mid, target);
    }
    return -1;
}

// works since it keeps context of original index on each recursion call
template <typename Type>
int binarySearchClassExample(const Type arr[], const int start, const int end, const Type target)
{
    int size = end - start;
    int pivot = start + (size / 2);

    if (size == 0)
    {
        return -1;
    }
    else if (arr[pivot] == target)
    {
        return pivot;
    }
    else if (arr[pivot] < target)
    {
        return binarySearchClassExample(arr, pivot + 1, end + 1, target);
    }
    else if (arr[pivot] > target)
    {
        return binarySearchClassExample(arr, start, pivot, target);
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    int array[] = {0, 1, 2, 3, 4, 5};
    cout << binarySearchClassExample(array, 0, 5, 5) << endl;
    return 0;
}
