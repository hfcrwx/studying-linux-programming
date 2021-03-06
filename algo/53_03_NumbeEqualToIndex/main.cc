// 面试题53（三）：数组中数值和下标相等的元素
// 题目：假设一个单调递增的数组里的每个元素都是整数并且是唯一的。请编程实现一个函数，找出数组中任意
// 一个数值等于其下标的元素。例如，在数组{-3, -1, 1, 3, 5}中，数字3和它的下标相等。

#include <assert.h>

int numberEqualToIndex(const int* nums, int size) {
  assert(nums != nullptr && size > 0);

  int low = 0;
  int high = size - 1;
  while (low <= high) {
    int mid = low + (high - low)/2;
    if (nums[mid] < mid) {
      low = mid + 1;
    } else if (nums[mid] > mid) {
      high = mid - 1;
    } else {
      return mid;
    }
  }

  return -1;
}

int main() {
  return 0;
}
