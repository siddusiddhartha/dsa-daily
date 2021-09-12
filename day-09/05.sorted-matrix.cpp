#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    vector < vector < int >> sortedMatrix(int N, vector < vector < int >> Mat) {
      vector < int > result;
      for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
          result.push_back(Mat[i][j]);
        }
      }
      sort(result.begin(), result.end());
      vector < vector < int >> temp(N);
      for (int i = 0; i < result.size(); i++) {
        temp[i / N].push_back(result[i]);
      }
      return temp;
    }
};

int main() {
  int t;
  cin >> t;
  while (t--) {
    int N;
    cin >> N;
    vector < vector < int >> v(N, vector < int > (N));
    for (int i = 0; i < N; i++)
      for (int j = 0; j < N; j++) cin >> v[i][j];
    Solution ob;
    v = ob.sortedMatrix(N, v);
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) cout << v[i][j] << " ";
      cout << "\n";
    }
  }
}
