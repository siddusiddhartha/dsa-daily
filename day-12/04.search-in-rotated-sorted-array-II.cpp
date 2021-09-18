// https://leetcode.com/problems/search-in-rotated-sorted-array-ii/
class Solution {
public:
  bool search(vector<int>& nums, int target) {
    int low = 0;
    int high = nums.size() - 1;
    while (low <= high) {
      int mid = low + (high - low) / 2;
      if (nums[mid] == target) {
        return true;
      }
      if (nums[mid] < nums[high]) {
        if (nums[high] >= target && target >= nums[mid]) {
          low = mid + 1;
        } else {
          high = mid - 1;
        }
      } else if (nums[mid] > nums[high]) {
        if (nums[low] <= target && target <= nums[mid]) {
          high = mid - 1;
        } else {
          low = mid + 1;
        }
      } else {
        high--;
      }
    }
    return false;
  }
};
