// 面试题38：字符串的排列
// 题目：输入一个字符串，打印出该字符串中字符的所有排列。例如，输入字符串abc，则打印出由字符a、b、
// c所能排列出来的所有字符串abc、acb、bac、bca、cab和cba。

#include <algorithm>

#include <assert.h>
#include <stdio.h>

void permutation(char* str, char* start) {
  assert(str != nullptr && start != nullptr);

  if (*start == '\0') {
    printf("%s\n", str);
    return;
  }

  for (char* c = start; *c != '\0'; ++c) {
    std::swap(*c, *start);
    permutation(str, start + 1);
    std::swap(*c, *start);
  }
}

void permutation(char* str) {
  if (str == nullptr) {
    return;
  }
  permutation(str, str);
}

#include <algorithm>
#include <vector>

using std::swap;
using std::vector;

class Solution {
 public:
  void backtrack(vector<vector<int>> &res, vector<int>& output, int first, int len) {
    if (first == len) {
      res.emplace_back(output);
      return;
    }

    for (int i = first; i < len; ++i) {
      swap(output[i], output[first]);
      backtrack(res, output, first + 1, len);
      swap(output[i], output[first]);
    }
  }

  vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int> > res;
    backtrack(res, nums, 0, (int) nums.size());
    return res;
  }
};

int main() {
  return 0;
}
