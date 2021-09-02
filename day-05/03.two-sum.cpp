#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
  vector<int> input {1, 4, 45, 6, 10, -8};
  const int expectedSum = 16;
  int l = 0;
  int r = input.size() - 1;
  bool found = false;
  sort(input.begin(), input.end());
  while (l < r) {
    int sum = input[l] + input[r];
    if (sum == expectedSum) {
      found = true;
      break;
    } else if (sum < expectedSum) {
      l++;
    } else {
      r--;
    }
  }
  if (found) {
    cout << input[l] << " " << input[r] << endl;
  } else {
    cout << "NOT FOUND" << endl;
  }
  return 0;
}
