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
#include <queue>

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

class Node {
 public:
  int val;
  vector<Node*> neighbors;

  Node() {
    val = 0;
    neighbors = vector<Node*>();
  }

  Node(int _val) {
    val = _val;
    neighbors = vector<Node*>();
  }

  Node(int _val, vector<Node*> _neighbors) {
    val = _val;
    neighbors = _neighbors;
  }
};

// class Node {
// public:
//     int val;
//     Node* left;
//     Node* right;

//     Node() {}

//     Node(int _val) {
//         val = _val;
//         left = NULL;
//         right = NULL;
//     }

//     Node(int _val, Node* _left, Node* _right) {
//         val = _val;
//         left = _left;
//         right = _right;
//     }
// };

class Solution {
 public:
  void RunTest()
  {
    vector<int> arr = {1,2,3};
    vector<int> result = getLeastNumbers(arr, 2);
    Show(result);
  }

  vector<int> getLeastNumbers(vector<int>& arr, int k) {
    if (k <= 0)
    {
      return {};
    }
    std::priority_queue<int, vector<int>, less<int>> pq;
    for (int i = 0; i < arr.size(); ++i)
    {
      if (pq.size() < k)
      {
        pq.push(arr[i]);
      }
      else
      {
        if (pq.top() > arr[i])
        {
          pq.pop();
          pq.push(arr[i]);
        }
      }
    }

    vector<int> result;
    while (!pq.empty())
    {
      result.push_back(pq.top());
      pq.pop();
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
  delete solution;
  return 0;
}
