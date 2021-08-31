class Solution {
public:
  bool rotateString(string s, string goal) {
    if (s.size() != goal.size()) {
      return false;
    }
    s += s;
    if (strstr(s.c_str(), goal.c_str())) {
      return true;
    } 
    return false;
  }
};
