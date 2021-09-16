#include "limits.h"
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  static double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    if (nums1.size() > nums2.size()) {
      return findMedianSortedArrays(nums2, nums1);
    }
    int x = nums1.size();
    int y = nums2.size();
    double result = 0;

    int low = 0;
    int high = x;
    while (low <= high) {
      cout << low << " " << high << endl;
      int partitionX = (low + high) / 2;
      int partitionY = (x + y + 1) / 2 - partitionX;

      int maxLeftX = partitionX == 0 ? INT_MIN : nums1[partitionX - 1];
      int minRightX = partitionX == x ? INT_MAX : nums1[partitionX];

      int maxLeftY = partitionY == 0 ? INT_MIN : nums2[partitionY - 1];
      int minRightY = partitionY == y ? INT_MAX : nums2[partitionY];

      cout << maxLeftX << " " << minRightY << " " << maxLeftY << " "
           << minRightX << endl;

      if (maxLeftX <= minRightY && maxLeftY <= minRightX) {
        if ((x + y) & 1) {
          result = max(maxLeftX, maxLeftY);
        } else {
          result =
              (double)(max(maxLeftX, maxLeftY) + min(minRightX, minRightY)) / 2;
        }
        return result;
      } else if (maxLeftX > minRightY) {
        high = partitionX - 1;
      } else {
        low = partitionX + 1;
      }
    }
    return result;
  }
};

int main() {
  vector<int> a = {1, 3};
  vector<int> b = {2};
  cout << Solution::findMedianSortedArrays(a, b) << endl;
}
