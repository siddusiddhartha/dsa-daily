#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>

using namespace std;

class Solution {
public:
  // TODO: need to implement yet
  static int nextGreaterElement(int n) {
    vector<int> nums;
    int temp = n;
    while (temp) {
      nums.push_back(temp % 10);
      temp /= 10;
    }
    reverse(nums.begin(), nums.end());
    int size = nums.size();
    int pos = -1;
    for (int i = size - 1; i > 0; i--) {
      if (nums[i - 1] < nums[i]) {
        pos = i - 1;
        break;
      } 
    }
    cout << "original number" << endl;
    for (auto& i : nums) {
      cout << i << " ";
    }
    cout << endl;
    cout << "============" << endl;
    int nextMin = INT_MAX;
    int nextMinPos = 0;
    for (int i = pos + 1; i < size; i++) {
      if (nextMin > nums[i]) {
        nextMin = nums[i];
        nextMinPos = i;
      }
    }
    cout << pos << " " << nextMinPos << " " << endl;
    temp = nums[pos];
    nums[pos] = nums[nextMin];
    nums[nextMin] = temp;
    cout << "original number" << endl;
    for (auto& i : nums) {
      cout << i << " ";
    }
    cout << endl;
    cout << "============" << endl;
    // reverse(nums.begin() + pos, nums.end());
    int val = 0;
    for (auto& i: nums) {
      cout << i << endl;
      val = val * 10 + i;
    }
    if (val == n) return -1;
    return val;
  }
  static int nextGreaterElementII(int n) {
    auto str = to_string(n);
    next_permutation(begin(str), end(str));
    auto res = stoll(str);
    return (res > INT_MAX || res <= n) ? -1 : res;
  }
};

int main() {
  cout << Solution::nextGreaterElementII(21) << endl;
}