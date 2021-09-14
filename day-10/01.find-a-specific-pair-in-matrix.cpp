#include "limits.h"
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
void printVector(vector<vector<int>> &arr) {
  int m = arr.size();
  int n = arr[0].size();
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cout << arr[i][j] << "\t";
    }
    cout << endl;
  }
}

// approach 1
int findMaxValue(vector<vector<int>> &arr) {
  int m = arr.size();
  int n = arr[0].size();
  int maxValue = INT_MIN;
  for (int a = 0; a < m - 1; a++) {
    for (int b = 0; b < n - 1; b++) {
      for (int d = a + 1; d < m; d++) {
        for (int e = b + 1; e < n; e++) {
          if (maxValue < (arr[d][e] - arr[a][b])) {
            maxValue = arr[d][e] - arr[a][b];
          }
        }
      }
    }
  }
  return maxValue;
}

// approach 2
int findMaxValue2(vector<vector<int>> &arr) {
  int maxValue = INT_MIN;
  int m = arr.size();
  int n = arr[0].size();
  int maxArr[m][n];
  fill((int *)maxArr, (int *)maxArr + (m * n), INT_MIN);
  maxArr[m - 1][n - 1] = arr[m - 1][n - 1];

  int maxv = arr[m - 1][n - 1];
  for (int j = n - 2; j >= 0; j--) {
    if (arr[m - 1][j] > maxv) {
      maxv = arr[m - 1][j];
    }
    maxArr[m - 1][j] = maxv;
  }

  maxv = arr[m - 1][n - 1];
  for (int i = m - 2; i >= 0; i--) {
    if (arr[i][n - 1] > maxv) {
      maxv = arr[i][n - 1];
    }
    maxArr[i][n - 1] = maxv;
  }

  for (int i = m - 2; i >= 0; i--) {
    for (int j = n - 2; j >= 0; j--) {
      if ((maxArr[i + 1][j + 1] - arr[i][j]) > maxValue) {
        maxValue = maxArr[i + 1][j + 1] - arr[i][j];
      }
      maxArr[i][j] = max(arr[i][j], max(maxArr[i + 1][j], maxArr[i][j + 1]));
    }
  }

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cout << maxArr[i][j] << "\t";
    }
    cout << endl;
  }

  return maxValue;
}
int main() {
  vector<vector<int>> v = {{1, 2, -1, -4, -20},
                           {-8, -3, 4, 2, 1},
                           {3, 8, 6, 1, 3},
                           {-4, -1, 1, 7, -6},
                           {0, -4, 10, -5, 1}};
  cout << findMaxValue(v) << endl;
  cout << findMaxValue2(v) << endl;
}
