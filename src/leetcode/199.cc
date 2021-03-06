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

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
 public:
  void RunTest()
  {
  }

  vector<int> rightSideView(TreeNode* root)
  {
    vector<int> result;
    if (!root)
    {
      return result;
    }
    deque<TreeNode *> dq;
    dq.push_back(root);
    while (!dq.empty())
    {
      int dq_size = dq.size();
      result.push_back(dq[dq_size-1]->val);
      while (dq_size >= 1)
      {
        TreeNode *node = dq.front();
        dq.pop_front();
        if (node->left)
        {
          dq.push_back(node->left);
        }
        if (node->right)
        {
          dq.push_back(node->right);
        }
        --dq_size;
      }
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
