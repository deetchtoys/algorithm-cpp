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

  ListNode* sortList(ListNode* head) {
    if (!head || !head->next)
    {
      return head;
    }
    ListNode *fast = head;
    ListNode *slow = head;
    ListNode *prev = nullptr;
    while (fast && fast->next)
    {
      fast = fast->next->next;
      prev = slow;
      slow = slow->next;
    }

    if (prev)
    {
      prev->next = nullptr;
    }

    ListNode *list_1 = sortList(head);
    ListNode *list_2 = sortList(slow);

    return merge(list_1, list_2);
  }

  ListNode *merge(ListNode* list_1, ListNode *list_2)
  {
    ListNode dummy(0);
    ListNode *cur = &dummy;
    while (list_1 && list_2)
    {
      if (list_1->val >= list_2->val)
      {
        cur->next = list_2;
        list_2 = list_2->next;
      }
      else
      {
        cur->next = list_1;
        list_1 = list_1->next;
      }
      cur = cur->next;
    }

    while (list_1)
    {
      cur->next = list_1;
      list_1 = list_1->next;
      cur = cur->next;
    }

    while (list_2)
    {
      cur->next = list_2;
      list_2 = list_2->next;
      cur = cur->next;
    }

    return dummy.next;
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
