#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

int cutRod (vector<int>& prices, int n) {
    vector<vector<int>> dp(n+1, vector<int> (n+1, 0));

    for (int i = 1; i < n+1; i++) {
        for (int j = 1; j < n+1; j++) {
            if (i <= j) {
                dp[i][j] = max (prices[i-1] + dp[i][j-i], dp[i-1][j]);
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[n][n];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("Input.txt","r",stdin);
    freopen("Output.txt","w",stdout);
    #endif

    int n;
    cin >> n;

    vector<int> prices;
    int temp;

    for (int i = 0; i < n; i++) {
        cin >> temp;
        prices.push_back(temp);
    }

    cout << cutRod(prices, n);

    return 0;
}
