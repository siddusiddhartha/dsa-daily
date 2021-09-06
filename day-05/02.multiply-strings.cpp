class Solution {
public:
  string multiply(string num1, string num2) {
    int l1 = num1.size();
    int l2 = num2.size();
    vector<int> res(l1 + l2, 0);
    
    for (int i = l1 - 1; i >= 0; i--) {
      for (int j = l2 - 1; j >= 0; j--) {
        int mul = (num1[i] - '0') * (num2[j] - '0');
        int p1 = i + j;
        int p2 = i + j + 1;
        int sum = mul + res[p2];
        
        res[p1] += sum / 10;
        res[p2] = sum % 10;
      }
    }

    string result;
    for (int p : res) {
      if (!(result.size() == 0 && p == 0)) {
        result += to_string(p);
      } 
    }
    return result.size() == 0 ? "0" : result;
  }
};
