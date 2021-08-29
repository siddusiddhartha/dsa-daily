class Solution {
public:
  int maxChunksToSorted(vector<int>& arr) {
    int count = 0;
    int maxValue = INT_MIN;
    for (int i = 0; i < arr.size(); i++) {
      maxValue = max(maxValue, arr[i]);
      if (maxValue == i) {
        count++;
      }
    }
    return count;
  }
};
