class Solution {
public:
  int shipWithinDays(vector<int>& weights, int days) {
    int maxW = *max_element(weights.begin(), weights.end());
    int sum = accumulate(weights.begin(), weights.end(), 0);
    int low = maxW;
    int high = sum;
    while (low < high) {
      int mid = (low + high) / 2;
      int tot = 0;
      int res = 1;
      for (auto& w: weights) {
        if (tot + w > mid) {
          res++;
          tot = w;
        } else {
          tot += w;
        }
      }
      if (res <= days) {
        high = mid;
      } else {
        low = mid + 1;
      }

    }
    return low;
  }
};
