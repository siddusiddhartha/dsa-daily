class Solution {
public:
  int minEatingSpeed(vector<int>& nums, int m) {
    int low = 1;
    int high = *max_element(nums.begin(), nums.end());
    while (low < high) {
      int mid = (low + high) / 2;
      int res = 0;
      for (auto& w: nums) {
        res += (w + mid - 1) / mid;
      }
      if (res <= m) {
        high = mid;
      } else {
        low = mid + 1;
      }

    }
    return low;
  }
