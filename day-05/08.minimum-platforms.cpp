#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minPlatform(vector<int>& arrivals, vector<int>& departures) {
  sort(arrivals.begin(), arrivals.end());
  sort(departures.begin(), departures.end());

  int platforms = 0;
  int count = 0;
  int i = 0;
  int j = 0;
  int size = arrivals.size();
  while (i < size && j < size) {
    if (arrivals[i] <= departures[j]) {
      count++;
      i++;
    } else {
      count--;
      j++;
    }
    platforms = max(platforms, count);
  }
  return platforms;
}

int main() {
  vector<int> arr = {900, 940, 950, 1100, 1500, 1800};
  vector<int> dep = {910, 1200, 1120, 1130, 1900, 2000};
  cout << minPlatform(arr, dep) << endl;
}
