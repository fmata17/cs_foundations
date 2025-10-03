#include <string>
#include <iostream>
using namespace std;

class Solution
{
public:
    bool isPalindrome(string s)
    {
        for (int i = 0; i < (s.size() / 2); ++i)
        {
            int current = static_cast<int>(s[i]);
            char test = static_cast<char>(current - 32);
            cout << test << ", ";
            int j = s.size() - 1 - i;
            if (s[i] != s[j])
            {
                return false;
            };
        }
        cout << endl;
        return true;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    cout << (s.isPalindrome("abccba") ? "true" : "false") << endl;
    return 0;
}
