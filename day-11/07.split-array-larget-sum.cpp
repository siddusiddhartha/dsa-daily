class Solution {
public:
  int splitArray(vector<int>& nums, int m) {
    int maxW = *max_element(nums.begin(), nums.end());
    int sum = accumulate(nums.begin(), nums.end(), 0);
    int low = maxW;
    int high = sum;
    while (low < high) {
      int mid = (low + high) / 2;
      int tot = 0;
      int res = 1;
      for (auto& w: nums) {
        if (tot + w > mid) {
          res++;
          tot = w;
        } else {
          tot += w;
        }
      }
      if (res <= m) {
        high = mid;
      } else {
        low = mid + 1;
      }

    }
    return low;
  }
};
