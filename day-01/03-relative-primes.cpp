#include <iostream>

using ll = long long;
using namespace std;

int main() {
  ll l, r;
  cin >> l >> r;
  cout << "YES" << endl;
  for (int i = l; i <= r; i+= 2) {
    cout << i << " " << i + 1 << endl;
  }
  return 0;
}