#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
  static void rotate(vector<int>& nums, int k) {      
    int size = nums.size();
    int rem = k % size;
    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + rem);
    reverse(nums.begin() + rem, nums.end());
    for (auto& i: nums) 
    {
      cout << i << " " ;
    }
    cout << endl;
  }
};

int main() {
  vector<int> input = {1,2,3,4,5,6,7};
  Solution::rotate(input, 3);
}