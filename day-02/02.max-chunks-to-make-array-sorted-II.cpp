class Solution {
public:
  void printVector(vector<int>& arr) {
    for (auto& i: arr) {
      cout << i << " ";
    }
    cout << endl;
  }
  int maxChunksToSorted(vector<int>& arr) {
    int size = arr.size();
    vector<int> leftMax(size + 1);
    vector<int> rightMin(size + 1);
    int maxValue = INT_MIN;
    for (int i = 0; i < size; i++) {
      maxValue = max(maxValue, arr[i]);
      leftMax[i] = maxValue;
    }
    rightMin[size] = INT_MAX;
    for (int i = size - 1; i >= 0; i--) {
      rightMin[i] = min(arr[i], rightMin[i + 1]);
    }
    //printVector(leftMax);
    //printVector(rightMin);
    int count = 0;
    for (int i = 0; i < size; i++) {
      //cout << i << " ";
      if (leftMax[i] <= rightMin[i + 1]) {
        count++;
      }
    }
    //cout << endl;
    return count;
  }
};
