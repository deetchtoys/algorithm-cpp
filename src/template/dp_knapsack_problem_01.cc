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
#include <list>

using namespace std;


class Solution {
 public:
  void RunTest()
  {
    cout << "==================bruteforce======================" << endl;
    int result = KnapsackProblem01Recur({{60, 10}, {100, 20}, {120, 30}}, 50);
    cout << "KnapsackProblem01Recur: " << result << endl;

    cout << "==================dp======================" << endl;
    result = KnapsackProblem01Dp({{60, 10}, {100, 20}, {120, 30}}, 50);
    cout << "KnapsackProblem01Dp: " << result << endl;
  }

    //lintcode 92
  int backPack(int m, vector<int> &A) {
    vector<vector<bool>> dp(A.size(), vector<bool>(m+1, false));
    for (int i = 0; i < A.size(); ++i)
    {
      dp[i][0] = true;
    }

    if (A[0] <= m)
    {
      dp[0][A[0]] = true;
    }

    for (int i = 1; i < A.size(); ++i)
    {
      for (int j = 1; j <= m; ++j)
      {
        dp[i][j] = dp[i-1][j];
        if (j - A[i] >= 0 && dp[i-1][j-A[i]])
        {
          dp[i][j] = true;
        }
      }
    }

    for (int i = m; i >= 0; --i)
    {
      if (dp.back()[i])
      {
        return i;
      }
    }

    return 0;
  }

  //lintcode 125
  int backPackII(int m, vector<int> &A, vector<int> &V) {
    vector<vector<int>> dp(A.size(), vector<int>(m+1, -1));
    for (int i = 0; i < A.size(); ++i)
    {
      dp[i][0] = 0;
    }

    if (A[0] <= m)
    {
      dp[0][A[0]] = V[0];
    }

    for (int i = 1; i < A.size(); ++i)
    {
      for (int j = 1; j <= m; ++j)
      {
        dp[i][j] = dp[i-1][j];
        if ((j - A[i]) >= 0 && dp[i-1][j - A[i]] >= 0)
        {
          dp[i][j] = std::max(dp[i][j], dp[i-1][j - A[i]] + V[i]);
        }
      }
    }

    return *std::max_element(dp.back().begin(), dp.back().end());
  }

  int KnapsackProblem01RecurAux(vector<pair<int, int>> goods, int pos, int weight)
  {
    if (pos >= goods.size())
    {
      return 0;
    }

    int val1 = 0;
    int val2 = 0;

    if (goods[pos].second <= weight)
    {
      val1 = goods[pos].first + KnapsackProblem01RecurAux(goods, pos + 1, weight - goods[pos].second);
    }

    val2 = KnapsackProblem01RecurAux(goods, pos + 1, weight);

    return std::max(val1, val2);
  }

  int KnapsackProblem01Recur(vector<pair<int, int>> goods, int weight)
  {
    int goods_size = goods.size();
    if (goods_size <= 0)
    {
      return 0;
    }

    return KnapsackProblem01RecurAux(goods, 0, weight);
  }

  int KnapsackProblem01Dp(vector<pair<int, int>> goods, int weight)
  {
    int goods_size = goods.size();
    if (goods_size <= 0)
    {
      return 0;
    }

    vector<vector<int>> dp(goods_size, vector<int>(weight + 1, 0));
    for (int i = 0; i < goods_size; ++i)
    {
      if (goods[i].second <= weight)
      {
        dp[i][goods[i].second] = goods[i].first;
      }
    }

    for (int i = 1; i < goods_size; ++i)
    {
      for (int j = 0; j <= weight; ++j)
      {
        if (dp[i-1][j] != 0)
        {
          dp[i][j] = dp[i-1][j];
          if (j + goods[i].second <= weight)
          {
            dp[i][j+goods[i].second] = dp[i][j] + goods[i].first;
          }
        }
      }
    }

    return *std::max_element(dp[goods_size-1].begin(), dp[goods_size-1].end());
  }

  template<class T>
  void Show(const vector<T> &result)
  {
    for (size_t i = 0; i < result.size(); ++i)
    {
      cout << result[i] << ", ";
    }
    cout << endl;
  }

  template<class T>
  void Show(const vector<vector<T>> &result)
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
