#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_set>
#include <cassert>
#include <stack>
#include <limits>
#include <deque>
#include <unordered_set>
#include <unordered_map>
#include <sstream>
#include <iterator>
#include <set>
#include <cmath>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
 public:
  void RunTest()
  {
  }

  int maxProduct(vector<int>& nums) {
    int nums_size = nums.size();
    if (nums_size == 0)
    {
      return 0;
    }
    int max = nums[0];
    int min = nums[0];
    int result = nums[0];
    for (int i = 1; i < nums_size; ++i)
    {
      if (nums[i] < 0)
      {
        std::swap(max, min);
      }
      max = std::max(nums[i], max * nums[i]);
      min = std::min(nums[i], min * nums[i]);

      result = std::max(result, max);
    }

    return result;
  }

  template<class T>
  void Show(vector<T> &result)
  {
    for (size_t i = 0; i < result.size(); ++i)
    {
      cout << result[i] << ", ";
    }
    cout << endl;
  }

  template<class T>
  void Show(vector<vector<T>> &result)
  {
    for (size_t i = 0; i < result.size(); ++i)
    {
      for (size_t j = 0; j < result[i].size(); ++j)
      {
        cout << result[i][j] << ", ";
      }
      cout << endl;
    }
  }
};

int main()
{
  Solution *solution = new Solution();
  solution->RunTest();

  return 0;
}
