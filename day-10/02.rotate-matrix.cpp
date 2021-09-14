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
void rotate90ClockWise(vector<vector<int>> &arr) {
  int m = arr.size();
  int n = arr[0].size();
  // step 1 tranpose the matrix
  for (int i = 0; i < m; i++) {
    for (int j = i; j < n; j++) {
      swap(arr[i][j], arr[j][i]);
    }
  }
  // interchange the column j and n-j-1
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n / 2; j++) {
      swap(arr[i][j], arr[i][n - j - 1]);
    }
  }
  printVector(arr);
}

int main() {
  vector<vector<int>> arr = {
      {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
  printVector(arr);
  cout << "===========" << endl;
  rotate90ClockWise(arr);
}
