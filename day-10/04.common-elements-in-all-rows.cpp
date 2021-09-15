#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

void printCommonElements(vector<vector<int>> &arr) {
  int m = arr.size();
  int n = arr[0].size();
  unordered_map<int, int> mp;
  for (int i = 0; i < n; i++) {
    mp[arr[0][i]] = 1;
  }

  for (int i = 1; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (mp[arr[i][j]] == i) {
        mp[arr[i][j]] = i + 1;
        if (mp[arr[i][j]] == m) {
          cout << arr[i][j] << " ";
        }
      }
    }
  }
  cout << endl;
}

int main() {
  vector<vector<int>> v = {
      {1, 2, 1, 4, 8},
      {3, 7, 8, 5, 1},
      {8, 7, 7, 3, 1},
      {8, 1, 2, 7, 9},
  };
  printCommonElements(v);
  return 0;
}
