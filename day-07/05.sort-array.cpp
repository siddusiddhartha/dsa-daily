#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int L = -1;
  int R = -1;
  for (int i = 0; i < n; i++) {
    if (a[i] != i + 1) {
      L = i;
      break;
    }
  }
  for (int i = n - 1; i > 0; i--) {
    if (a[i] != i + 1) {
      R = i;
      break;
    }
  }
  reverse(a + L, a + R + 1);
  bool flag = true;
  for (int i = 0; i < n; i++) {
    if (a[i] != i + 1) {
      flag = false;
      break;
    }
  }
  if (flag) {
    cout << "yes" << endl;
    if (L == -1 || R == -1) {
      cout << 1 << " " << 1 << endl;
    } else {
      cout << L + 1<< " " << R + 1 << endl;
    }
  } else {
    cout << "no" << endl;
  }
}
