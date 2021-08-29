class Solution {
public:
  // first implementation
  int dominantIndex(vector<int>& nums) {
    map<int, int> count;
    int maxCount = INT_MIN;
    for (int i = 0; i < nums.size(); i++) {
      count[nums[i]] = i;
      maxCount = max(maxCount, nums[i]);
    }
    cout << maxCount << endl;
    for (auto& m: count) {
      if (m.first == maxCount) {
        break;
      } else if ((m.first * 2) > maxCount) {
        return -1;
      }
    }
    return count[maxCount];
  }
  // second implementation
  int dominantIndex(vector<int>& nums) {
    int max = -1;
    int index = -1;
    int second = -1;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] > max) {
        second = max;
        max = nums[i];
        index = i;
      } else if (nums[i] > second) {
        second = nums[i];
      }
    }
    return (second * 2) <= max ? index : -1;
  }
};
