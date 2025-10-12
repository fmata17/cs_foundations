#include <string>
#include <cctype>
#include <iostream>
using namespace std;

class Solution
{
public:
    bool isAlphaNumeric(int c) // to avoid using <cctype> isalnum()
    {
        // can use char literals or ascii integer representation
        return (('0' <= c && c <= '9') || (65 <= c && c <= 90) || ('a' <= c && c <= 'z'));
    }

    int toLowerCase(int c)
    {
        if ('A' <= c && c <= 'Z')
            return c + 32;
        else
            return c; // if c is not a letter it just returns the unchanges value
    }

    bool isPalindrome(string s)
    {
        int l = 0;
        int r = s.size() - 1;

        while (l < r)
        {
            while (l < r && !isAlphaNumeric(s[l]))
            {
                ++l;
            }
            while (l < r && !isAlphaNumeric(s[r]))
            {
                --r;
            }
            if (toLowerCase(s[l]) != toLowerCase(s[r]))
            {
                return 0;
            }
            ++l;
            --r;
        }
        return 1;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    cout << (s.isPalindrome("Was it a car or a cat I saw?") ? "true" : "false") << endl;
    return 0;
}
