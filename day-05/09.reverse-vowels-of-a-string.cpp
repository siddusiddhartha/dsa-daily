class Solution {
public:
  string reverseVowels(string s) {
    int l = 0; 
    int r = s.size() - 1;
    vector<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    while (l < r) {
      bool leftVowel = find(vowels.begin(), vowels.end(), s[l]) != vowels.end();
      bool rightVowel = find(vowels.begin(), vowels.end(), s[r]) != vowels.end();
      if (leftVowel && rightVowel) {
        swap(s[l], s[r]);
        l++;
        r--;
      } else if (leftVowel && !rightVowel) {
        r--;
      } else if (rightVowel && !leftVowel) {
        l++;
      } else {
        l++;
        r--;
      }
    }
    return s;
  }
};
