#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    int binaryCount(vector < int > & A, int val) {
      int low = 0;
      int high = A.size() - 1;
      while (low <= high) {
        int mid = (low + high) / 2;
        if (A[mid] <= val) {
          low = mid + 1;
        } else {
          high = mid - 1;
        }
      }
      return low;
    }
  int median(vector < vector < int >> & matrix, int r, int c) {
    int low = 1;
    int high = 2000;
    int m = matrix.size();
    int n = matrix[0].size();
    while (low <= high) {
      int mid = (low + high) / 2;
      int count = 0;
      for (int i = 0; i < m; i++) {
        count += binaryCount(matrix[i], mid);
      }
      if (count <= (n * m) / 2) low = mid + 1;
      else high = mid - 1;
    }
    return low;

  }
};

int main() {
  int t;
  cin >> t;
  while (t--) {
    int r, c;
    cin >> r >> c;
    vector < vector < int >> matrix(r, vector < int > (c));
    for (int i = 0; i < r; ++i)
      for (int j = 0; j < c; ++j)
        cin >> matrix[i][j];
    Solution obj;
    cout << obj.median(matrix, r, c) << endl;
  }
  return 0;
}
