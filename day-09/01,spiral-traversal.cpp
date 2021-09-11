class Solution {
public:
  void printVector(vector<int> v) {
    for (auto& i: v) {
      cout << i << " ";
    }
    cout << endl;
  }
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> result;
    int left = 0;
    int top = 0;
    int bottom = matrix.size() - 1;
    int right = matrix[0].size() - 1;
    int size = matrix.size() * matrix[0].size();
    while (result.size() < size) {
      for (int i = top; i <= right && result.size() < size; i++) {
        result.push_back(matrix[top][i]);
      }
      top++;
      // printVector(result);
      for (int i = top; i <= bottom && result.size() < size; i++) {
        result.push_back(matrix[i][right]);
      }
      right--;
      // printVector(result);
      for (int i = right; i >= left && result.size() < size; i--) {
        result.push_back(matrix[bottom][i]);
      }
      bottom--;
      // printVector(result);
      for (int i = bottom; i >= top && result.size() < size; i--) {
        result.push_back(matrix[i][left]);
      }
      left++;
      // printVector(result);
    }
    return result;
  }
};
