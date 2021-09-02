#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
  vector<int> input = {5, 20, 3, 2, 50, 80};
  int expectedDiff;
  cin >> expectedDiff;
  int size = input.size();
  sort(input.begin(), input.end());
  int l = 0;
  int r = 1;
  bool found = false;
  while (l < r) {
    int diff = input[r] - input[l];
    if (diff == expectedDiff) {
      found = true;
      break;
    } else if (diff > expectedDiff) {
      l++;
    } else {
      r++;
    }
  }
  if (found) {
    cout << input[l] << " " << input[r] << endl;
  } else {
    cout << "NOT FOUND" << endl;
  }
  return 0;
}
