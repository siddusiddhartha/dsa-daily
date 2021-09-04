class Solution {
public:
  void rotate(vector<vector<int>>& a) {
    int size = a.size();
    for(int i = 0; i < size; i++) {
      for (int j = i + 1; j < size; j++) {
        swap(a[i][j], a[j][i]);
      }
    }
    for(int i = 0; i < size; i++) {
      for (int j = 0; j < size / 2; j++) {
        swap(a[i][j], a[i][size-j-1]);
      }
    }
  }
};
