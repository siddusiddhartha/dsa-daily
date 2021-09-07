class Solution {
public:
  int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
    int count1 = 0;
    int count2 = 0;
    int count3 = 0;
    int count4 = 0;
    int num1 = tops[0];
    int num2 = bottoms[0];
    for (int i = 0; i < tops.size(); i++) {
      if (count1 != INT_MAX) {
        if (tops[i] == num1) {
          // do nothing
        } else if (bottoms[i] == num1) {
          count1++;
        } else {
          count1 = INT_MAX;
        }
      }
      if (count2 != INT_MAX) {
        if (bottoms[i] == num1) {
          // do nothing
        } else if (tops[i] == num1) {
          count2++;
        } else {
          count2 = INT_MAX;
        }
      }
      if (count3 != INT_MAX) {
        if (tops[i] == num2) {
          // do nothing
        } else if (bottoms[i] == num2) {
          count3++;
        } else {
          count3 = INT_MAX;
        }
      }
      if (count4 != INT_MAX) {
        if (bottoms[i] == num2) {
          // do nothing
        } else if (tops[i] == num2) {
          count4++;
        } else {
          count4 = INT_MAX;
        }
      }
    }
    int val = min(min(count1, count2), min(count3, count4));
    return val == INT_MAX ? -1 : val;
  }
};
