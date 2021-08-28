#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;
class Solution {
public:
  static vector<int> majorityElement(vector<int>& nums) {
    int count1 = 0;
    int count2 = 0;
    int candidate1 = INT_MAX;
    int candidate2 = INT_MAX;
    for (auto& i: nums) {
      if (i == candidate1) {
        count1++;
      } else if (i == candidate2) {
        count2++;
      } else if (count1 == 0) {
        candidate1 = i;
        count1 = 1;
      } else if (count2 == 0) {
        candidate2 = i;
        count2 = 1;
      } else {
        count1--;
        count2--;
      }
    }
    count1 = 0;
    count2 = 0;
    vector<int> result;
    for (auto& i: nums) {
      if (i == candidate1) count1++;
      else if (i == candidate2) count2++;
    }
    int size = nums.size() / 3;
    if (count1 > size) result.push_back(candidate1);
    if (count2 > size) result.push_back(candidate2);
    return result;
  }
};

int main() {
  vector<int> input = {1, 2};
  vector<int> result = Solution::majorityElement(input);
  for (auto& i: result) {
    cout << i << " ";
  }
  cout << endl;
}