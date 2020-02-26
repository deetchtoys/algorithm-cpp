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
#include <bitset>

using namespace std;

class Solution {
 public:
  struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

  void RunTest()
  {
    TreeNode *input;
    bool result;

    input = new TreeNode(2);
    input->left = new TreeNode(1);
    input->right = new TreeNode(3);

    result = isValidBST(input);
    cout << "result: " << result << endl;
    assert(result == true);
  }

  bool isValidBST(TreeNode* root) {
    if (!root)
    {
      return true;
    }

    stack<TreeNode *> s;
    TreeNode *prevNode = nullptr;
    while (root || !s.empty())
    {
      while (root)
      {
        s.push(root);
        root = root->left;
      }

      root = s.top();
      s.pop();
      if (prevNode && prevNode->val >= root->val)
      {
        return false;
      }
      prevNode = root;
      root = root->right;
    }

    return true;
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
