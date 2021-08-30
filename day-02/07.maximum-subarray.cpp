class Solution {
public:
  int maxSubArray(const vector<int>& nums) {
    int sum = nums[0];
    int bestSum = nums[0];
    for (int i = 1; i < nums.size(); i++) {
      sum = max(nums[i], sum + nums[i]);
      bestSum = max(bestSum, sum);
    }
    return bestSum;
  }
};
