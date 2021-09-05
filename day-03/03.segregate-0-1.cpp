#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void segregate(vector<int>& list) {
  int count = 0;
  for (int& i: list) {
    if (i == 1) count++;
  }
  int size = list.size();
  for (int i = 0; i < size - count; i++) {
    list[i] = 0;
  }
  for (int i = count; i > 0; i--) {
    list[size - i] = 1;
  }
}

int main() {
  vector<int> input = {0, 1, 0, 1, 0, 0, 1, 1, 1, 0};
  segregate(input);
  for (auto& i: input) {
    cout << i << " ";
  }
  cout << endl;
}
