// https://leetcode.com/problems/find-the-difference/
class Solution {
public:
  char findTheDifference(string s, string t) {
   char r = 0;
   int i = 0;
    while (i < s.size()) {
      r ^= s[i] ^ t[i];
      i++;
    }
    return r ^ t[i];
  }
};
