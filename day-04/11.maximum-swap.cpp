class Solution {
public:
  int maximumSwap(int num) {
    string digits = to_string(num);
    int maxIdx = -1;
    int maxDigit = -1;
    int leftIdx = -1;
    int rightIdx = -1;
    for (int i = digits.size() - 1; i >= 0; i--) {
      if (digits[i] > maxDigit) {
        maxDigit = digits[i];
        maxIdx = i;
        continue;
      }
      if (digits[i] < maxDigit) {
        leftIdx = i;
        rightIdx = maxIdx;
      }
    }
    if (leftIdx == -1) return num;
    swap(digits[leftIdx], digits[rightIdx]);
    return stoi(digits);
  }
};
