#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  static vector<int> sortedSquares(vector<int>& nums) {
    int size = nums.size();
    int l = 0;
    int r = size - 1;
    vector<int> result(size);
    for (int i = size - 1; i >= 0; i--) {
      if (abs(nums[l]) > abs(nums[r])) {
        result[i] = nums[l] * nums[l];
        l++;
      } else {
        result[i] = nums[r] * nums[r];
        r--;
      }
    }
    for (auto& i: result) {
      cout << i << " ";
    }
    cout << endl;
    return result;
  }
};

int main() {
  cout << "Squares of sorted array" << endl;
  vector<int> input = {-4,-1,0,3,10};
  Solution::sortedSquares(input);
  input = {-7,-3,2,3,11};
  Solution::sortedSquares(input);
}