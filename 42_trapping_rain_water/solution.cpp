#include <vector>
#include <iostream>
using namespace std;

// You are given an array of non-negative integers height which represent an elevation map.
// Each value height[i] represents the height of a bar, which has a width of 1.

// Return the maximum area of water that can be trapped between the bars.
class Solution
// height = [0,2,0,3,1,0,1,3,2,1]
// output = 9
{
public:
    int trap(vector<int> &height)
    {
      int area = 0;
      vector<int> max_left(height.size(), 0);
      int cur_max = height[0];
      for (int i = 1; i < height.size(); ++i)
      {
        max_left[i] = cur_max;
        cur_max = max(cur_max, height[i]);
      }
      
      // TODO find max_right and then min of both

      for(int num : max_left)
      {
        cout << num << " ";
      }
      cout << endl;

      return -1;
    }
};


int main () {
  Solution s;
  vector<int> nums{0,2,0,3,1,0,1,3,2,1};
  s.trap(nums);
  return 0;
}
