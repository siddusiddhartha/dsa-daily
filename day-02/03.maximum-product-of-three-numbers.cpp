class Solution {
public:
  int maximumProduct(vector<int>& nums) {
    int size = nums.size() - 1;
    sort(nums.begin(), nums.end());
    return max(nums[0] * nums[1]* nums[size], nums[size] * nums[size - 1] * nums[size - 2]);
  }
};
