#include <iostream>
using namespace std;

// linear search

template <class Type>
int seqSearch(const Type arr[], const int size, const Type target)
{
    for (int i = 0; i < size; ++i)
    {
        if (arr[i] == target)
        {
            return i;
        }
    }
    return -1;
}

template <class Type>
int seqSearch(const vector<Type> &arr, const Type target)
{
    for (int i = 0; i < arr.size(); ++i)
    {
        if (arr[i] == target)
        {
            return i;
        }
    }
    return -1;
}

template <class Type>
int seqSearchFancyForLoop(const vector<Type> &arr, const Type target)
{
    int index = 0;
    for (Type i : arr) // TODO undestand difference & improvement of 'for (const auto& i : arr)'
    {
        if (i == target)
        {
            return index;
        }
        ++index;
    }
    return -1;
}

template <class Type>
int seqSearchRecursion(const Type arr[], const int size, const Type target) // TODO clean with tail recursion
{
    if (size < 1)
    {
        return -1;
    }
    if (arr[size - 1] == target)
    {
        return size - 1;
    }
    return seqSearchRecursion(arr, size - 1, target);
}

int main()
{
    float arr[6] = {0, 1, 2, 3, 4, 5};
    vector<int> vecArr({6, 7, 8, 9, 10, 11});

    cout << seqSearch(arr, 6, float(5)) << endl;
    cout << seqSearch(vecArr, 11) << endl;
    cout << seqSearchFancyForLoop(vecArr, 11) << endl;
    cout << seqSearchRecursion(arr, 6, float(5)) << endl;

    return 0;
}
