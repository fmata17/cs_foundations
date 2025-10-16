#include <vector>
#include <iostream>
using namespace std;

// You are given an integer array heights where
// heights[i] represents the height of the ith bar.

// You may choose any two bars to form a container.
// Return the maximum amount of water a container can store.
class Solution
{
public:
    // height = [1,7,2,5,4,7,3,6]
    // index  =  0 1 2 3 4 5 6 7

    // optimal solution: O(n)
    // start two pointers at biggest distance possible,
    // update the one with the least height to maximize area in both steps
    int maxArea(vector<int> &heights)
    {
        int maxArea = 0;
        int leftPtr = 0;
        int rightPtr = heights.size() - 1;

        while (leftPtr < rightPtr)
        {
            int height = min(heights[leftPtr], heights[rightPtr]);
            int base = rightPtr - leftPtr;
            maxArea = max(maxArea, (base * height));

            if (heights[leftPtr] < heights[rightPtr])
                ++leftPtr;
            else // if heights[l] > heights[r] or if heights are equal can have the same pointer update
                --rightPtr;
        }
        return maxArea;
    }

    // brute force
    int maxAreaBruteForce(vector<int> &heights)
    {
        int maxArea = 0;
        for (int i = 0; i < heights.size() - 1; ++i)
        {
            int leftVal = heights[i];
            for (int j = i + 1; j < heights.size(); ++j)
            {
                int heightVal = min(leftVal, heights[j]);
                int baseDistance = j - i;
                maxArea = max(maxArea, (heightVal * baseDistance));
            }
        }
        return maxArea;
    }
};

int main()
{
    vector<int> vec({1, 7, 2, 5, 4, 7, 3, 6});

    Solution s;
    int maxArea = s.maxArea(vec);
    cout << "Maximum Area: " << maxArea << endl;

    return 0;
}
