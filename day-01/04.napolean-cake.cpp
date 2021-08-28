#include <iostream>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a[n], b[n] = {0};
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int j = n - 1;
    while (j > 0) {
      int temp = a[j];
      while (temp) {
        b[j--] = 1;
        temp--;
      }
      j--;
    }
    for (auto& num : b) {
      cout << num << " ";
    }
    cout << endl;
  }
}
