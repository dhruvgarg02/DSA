#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

int tabulation(int n, int x, int y, int z) {
    vector<int> dp(n+1, -1);
    dp[0] = 0;
    for (int i = 0; i < n+1; i++) {
        if (dp[i] == -1) continue;
        if (i + x <= n) dp[i+x] = max(dp[i+x], dp[i]+1);
        if (i + y <= n) dp[i+y] = max(dp[i+y], dp[i]+1);
        if (i + z <= n) dp[i+z] = max(dp[i+z], dp[i]+1);
    }
    if (dp[n] == -1) dp[n] = 0;
    return dp[n];
}


int memoization_helper(int i, int x, int y, int z, vector<int>& dp) {
    if (i == 0) return 0;
    if (dp[i] != -1) return dp[i];

    int a = INT_MIN, b = INT_MIN, c = INT_MIN;
    if (x <= i) a = memoization_helper(i-x, x, y, z, dp);
    if (y <= i) b = memoization_helper(i-y, x, y, z, dp);
    if (z <= i) c = memoization_helper(i-z, x, y, z, dp);

    return dp[i] = 1 + max(a, max(b, c));
}

int memoization(int n, int x, int y, int z) {
    vector<int> dp(n+1, -1);
    int res = memoization_helper(n, x, y, z, dp);
    return res < 0 ? 0 : res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("Input.txt","r",stdin);
    freopen("Output.txt","w",stdout);
    #endif

    int n, x, y, z;
    cin >> n >> x >> y >> z;

    cout << memoization(n, x, y, z);
    return 0;
}
