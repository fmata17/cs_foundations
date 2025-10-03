#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        vector<int> products(nums.size(), 1); // solution vector
        int prefix = 1;
        int postfix = 1;

        for (int i = 0; i < nums.size(); ++i)
        {
            products[i] = prefix;
            prefix = prefix * nums[i];
        }

        for (int i = nums.size() - 1; i >= 0; --i)
        {
            products[i] = products[i] * postfix;
            postfix = postfix * nums[i];
        }

        return products;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> vec = {1, 3, 5, 10};
    vec = s.productExceptSelf(vec);
    for (int n: vec)
    {
        cout << n << " ";
    }
    cout << endl;
    return 0;
}
