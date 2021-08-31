class Solution {
public:
  int fibonacci(int n, vector<int>& dp) {
    if (n < 2) return n;
    if (dp[n] != -1) return dp[n];
    dp[n] = fibonacci(n - 1, dp) + fibonacci(n - 2, dp);
    return dp[n];
  }
  int fib(int N) {
    vector<int> result(N + 1, -1);
    return fibonacci(N, result);
  }
};
