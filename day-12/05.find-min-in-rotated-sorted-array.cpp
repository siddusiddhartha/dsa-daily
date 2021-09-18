class Solution {
public:
  int findMin(vector<int>& nums) {
    if (nums.size() == 1) {
      return nums[0];
    }
    int low = 0;
    int high = nums.size() -  1;
    // if the array is already sorted and not rotated
    if (nums[high] > nums[low]) {
      return nums[low];
    }
    while (low <= high) {
      int mid = low + (high - low) / 2;
      if (nums[mid] > nums[mid + 1]) {
        return nums[mid + 1];
      }
      if (nums[mid] < nums[mid - 1]) {
        return nums[mid];
      }
      if (nums[mid] > nums[0]) {
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }
    return -1;
  }
};
