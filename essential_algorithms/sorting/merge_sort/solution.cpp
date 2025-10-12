/*
Split phase:
<8, 4, 2, 7, 1, 0>
→ <8, 4, 2> <7, 1, 0>
→ <8> <4, 2> <7> <1, 0>
→ <8> <4> <2> <7> <1> <0>

Merge phase:
→ <4, 8> <2> <1, 7> <0>
→ <2, 4, 8> <0, 1, 7>
→ <0, 1, 2, 4, 7, 8>
*/

template <typename Type>
void mergeSort(Type arr[], int size)
{
    
}