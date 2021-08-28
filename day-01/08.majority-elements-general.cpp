#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
  static vector<int> majorityElement(vector<int>& nums, int k) {
    int size = nums.size();
    unordered_map<int, int> count;
    for (auto& i: nums) {
      count[i]++;
    }
    int x = size / k;
    vector<int> result;
    for (auto& i: count) {
      if (i.second > x) {
        result.push_back(i.first);
      }
    }
    return result;
  }
};

void printElements(const vector<int>& input) {
  for (const auto& i: input) {
    cout << i << " ";
  }
  cout << endl;
}

int main() {
  vector<int> input = {1, 1, 2, 2, 3, 5, 4, 2, 2, 3, 1, 1, 1 };
  vector<int> result = Solution::majorityElement(input, 4);
  printElements(result);
  return 0;
}
