// 面试题21：调整数组顺序使奇数位于偶数前面
// 题目：输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有奇数位于数组的前半部分，所
// 有偶数位于数组的后半部分。

#include <stddef.h>

void exchange(int* nums, size_t len) {
  if (nums == nullptr || len == 0) {
    return;
  }

  size_t left = 0;
  size_t right = len - 1;
  while (left < right) {
    if ((nums[left] & 1) == 1) {
      ++left;
      continue;
    }
    if ((nums[right] & 1) == 0) {
      --right;
      continue;
    }

    int tmp = nums[left];
    nums[left] = nums[right];
    nums[right] = tmp;

    ++left;
    --right;
  }
}

int main() {
  size_t x = 0;
  --x;
  return 0;
}
