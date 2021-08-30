class Solution {
public:
  int modulo = 1e9 + 7;
  int kadenseSum(vector<int>& arr) {
    long long maxSum = arr[0];
    long long currSum = arr[0];
    for (int i = 1; i < arr.size(); i++) {
      if (currSum > 0) {
        currSum += arr[i];
      } else {
        currSum = arr[i];
      }

      if (maxSum < currSum) {
        maxSum = currSum;
      }
    }
    return maxSum % modulo;
  }
  int kadenseDouble(vector<int>& arr, int times) {
    vector<int> result;
    for (int i = 0; i < times; i++) {
      for (int j = 0; j < arr.size(); j++) {
        result.push_back(arr[j]);
      }
    }
    return kadenseSum(result);
  }
  int kConcatenationMaxSum(vector<int>& arr, int k) {
    long long sum = 0;
    for (auto& i: arr) {
      sum += i;
    }
    if (k == 1) {
      return kadenseSum(arr);
    }
    if (sum < 0) {
      return max(0, kadenseDouble(arr, 2));
    } else {
      return (kadenseDouble(arr, 2) + (k - 2) * sum) % modulo;
    }
  }
};
