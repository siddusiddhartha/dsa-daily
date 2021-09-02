#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int kthSmallestNumber(vector<int>& input, int k) {
  priority_queue<int, vector<int>, greater<int>> pq;
  for (auto& i: input) {
    pq.push(i);
  }
  for (int i = 1; i < k; i++) {
    pq.pop();
  }
  return pq.top();
}

int main() {
  vector<int> input = {7,10,4,3,20,15};
  cout << kthSmallestNumber(input, 3) << endl;
}
