#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

int coin_change(vector<int>& coins, int n, int amount) {
    vector<vector<int>> dp(n+1, vector<int> (amount+1, 0));

    // Notice the unusual initialization
    for (int i = 0; i < amount+1; i++) {
        dp[0][i] = amount+1;
        if (i > 0) {
            if (i % coins[0] == 0) dp[1][i] = i / coins[0];
            else dp[1][i] = dp[0][i];
        }
    }

    for (int i = 2; i < n+1; i++) {
        for (int j = 1; j < amount+1; j++) {
            if (coins[i-1] <= j) {
                dp[i][j] = min(1 + dp[i][j-coins[i-1]], dp[i-1][j]);
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp.back().back() == amount + 1 ? -1 : dp.back().back();
}

int coin_change_1d(vector<int>& coins, int n, int amount) {
    vector<int> dp(amount+1, amount+1);
    dp[0] = 0;
    for (auto i : coins) {
        for (int j = i; j < amount + 1; j++) {
            dp[j] = min(dp[j-i] + 1, dp[j]);
        }
    }

    return dp.back() > amount ? -1 : dp.back();
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

    vector<int> coins;
    int temp;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        coins.push_back(temp);
    }

    int amount;
    cin >> amount;

    cout << coin_change_1d(coins, n, amount);

    return 0;
}
