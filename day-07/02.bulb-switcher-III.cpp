class Solution {
public:
  int numTimesAllBlue(vector<int>& light) {
    int count = 0;
    int right = -1;
    for (int i = 0; i < light.size(); i++) {
      right = max(right, light[i]);
      if (right == i + 1) count++;
    }
    return count;
  }
};
