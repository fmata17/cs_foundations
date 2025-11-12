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
  int trap(vector<int> &height) // two pointer solution - memory O(n) and space O(1)
  {
    int area = 0;

    return area;
  }

  int trapV1(vector<int> &height) // memory and space are O(n)
  {
    int area = 0;

    // find the max left column for each num
    vector<int> max_left(height.size(), 0);
    int cur_max = height[0];
    for (int i = 1; i < height.size(); ++i)
    {
      max_left[i] = cur_max;
      cur_max = max(cur_max, height[i]);
    }

    // find the max right column for each num
    vector<int> max_right(height.size(), 0);
    cur_max = height[height.size() - 1];
    for (int i = height.size() - 2; i >= 0; --i)
    {
      max_right[i] = cur_max;
      cur_max = max(cur_max, height[i]);
    }

    // find the min column (left or right) for each num
    vector<int> min_lef_right(height.size(), 0);
    for(int i = 0; i < height.size(); ++i)
    {
      min_lef_right[i] = min(max_left[i], max_right[i]);
    }

    // compute area for each column ( max_possible_area_height - curr_col_height )
    for (int i = 0; i < height.size(); ++i) {
      area = area + max(0, (min_lef_right[i] - height[i]));
    }

    return area;
  }
};


int main () {
  Solution s;
  vector<int> nums{0,2,0,3,1,0,1,3,2,1};
  cout << s.trapV1(nums) << endl;
  return 0;
}
