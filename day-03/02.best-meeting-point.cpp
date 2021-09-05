class Solution {
public:
  /**
    * @param grid: a 2D grid
    * @return: the minimize travel distance
    */
  int minTotalDistance(vector<vector<int>> &grid) {
    int ans = 0;
    int ysize = grid.size();
    int xsize = grid[0].size();
    // Get x-coordinate
    vector<int> x;
    for (int i = 0; i < ysize; i++) {
      for (int j = 0; j < xsize; j++) {
        if (grid[i][j] == 1) {
            x.push_back(i);
        }
      }
    }
    // Get y-coordinate
    vector<int> y;
    for (int i = 0; i < xsize; i++) {
      for (int j = 0; j < ysize; j++) {
        if (grid[j][i] == 1) {
            y.push_back(i);
        }
      }
    }
    // Get median
    int midx = x[x.size() / 2];
    int midy = y[y.size() / 2];
    // calculate distance
    for (auto& i: x) {
      ans += abs(midx - i);
    }
    for (auto& i: y) {
      ans += abs(midy - i);
    }
    // return result
    return ans;
  }
};
