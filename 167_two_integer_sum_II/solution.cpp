#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        for (int i = 0; i < numbers.size() - 1; ++i)
        {
            int j = i + 1;
            while (j < numbers.size())
            {
                if (numbers[i] + numbers[j] == target)
                    return {i + 1, j + 1};
                ++j;
            }
        }
        return {-1};
    }
};

int main()
{
    vector<int> v = {1, 3, 5, 6};
    Solution s;
    vector<int> res = s.twoSum(v, 6);
    for (int i : res)
    {
        cout << i;
    }
    cout << endl;
    return 0;
}
