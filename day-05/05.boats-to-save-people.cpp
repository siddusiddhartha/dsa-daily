class Solution {
public:
  int numRescueBoats(vector<int>& people, int limit) {
    sort(people.rbegin(), people.rend());
    int i = 0;
    int j = people.size() - 1;
    for (; i <= j; i++) {
      if (people[i] + people[j] <= limit) {
        j--;
      }
    }
    return i;
  }
};
