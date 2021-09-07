class Solution {
public:
  int maxDistToClosest(vector<int>& seats) {
    int res = 0;
    int size = seats.size();
    int last = -1;
    for (int i = 0; i < size; i++) {
      if (seats[i] == 1) {
        res = last < 0 ? i : max(res, (i - last) / 2);
        last = i;
      }
    }
    return max(res, size - last - 1);
  }
};
