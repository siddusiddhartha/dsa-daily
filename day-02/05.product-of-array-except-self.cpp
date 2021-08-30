class Solution {
public:
  vector<int> productExceptSelf(vector<int>& nums) {
    int size = nums.size();
    vector<int> res(size, 1);
    int p = 1;
    for(int i = 0; i < size - 1; i++) {
      p *= nums[i];
      res[i + 1] *= p;
    }

    p = 1;
    for (int i = size - 1; i > 0; i--) {
      p *= nums[i];
      res[i - 1] *= p;
    }
    return res;
  }
};
