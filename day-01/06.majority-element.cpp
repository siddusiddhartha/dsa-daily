#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
  static int majorityElement(vector<int>& nums) {
    int size = nums.size();
    map<int, int> count;
    for (auto& i: nums) {
      count[i]++;
    }
    for (auto& m: count) {
      if (m.second > (size / 2)) {
        return m.first;
      }
    }
    return -1;
  }
  static int majorityElementII(vector<int>& nums) {
    int size = nums.size();
    int candidate = nums[0];
    int count = 1;
    for (int i = 1; i < size - 1; i++) {
      if (count == 0) {
        candidate = nums[i];
      } else if (candidate == nums[i]) {
        count++;
      } else {
        count--;
      }
    }
    return candidate;
  }
};

int main() {
  vector<int> input = {3,2,3};
  cout << Solution::majorityElementII(input) << endl;
}