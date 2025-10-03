#include <vector>
#include <unordered_set>
#include <iostream>
using namespace std;

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        int res = 0;
        unordered_set<int> store(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i)
        {
            if (store.count(nums[i] - 1) == 0)
            {
                int streak = 0;
                while (store.count(nums[i] + streak) != 0)
                {
                    ++streak;
                }
                res = max(res, streak);
            }
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> list = {100, 3, 4, -5, 5, 99, 99, 99, -4, -3, -2, -1, 6, 7, 8};
    cout << s.longestConsecutive(list) << endl;
    return 0;
}
