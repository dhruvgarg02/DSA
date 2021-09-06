#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

// Tabulation
int coinChange(vector<int>& coins, int n, int amount) {
    vector<vector<int>> dp(n+1, vector<int> (amount+1, 0));
    for (int i = 0; i < n+1; i++) {
        dp[i][0] = 1;
    }

    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < amount + 1; j++) {
            if (coins[i-1] <= j) {
                dp[i][j] = dp[i-1][j] + dp[i][j-coins[i-1]];
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp.back().back();
}

// Space Optimized
int coinChange_1d(vector<int>& coins, int n, int amount) {
    vector<int> dp(amount+1, 0);
    dp[0] = 1;

    for (auto i : coins) {
        for (int j = i; j < amount+1; j++) {
            dp[j] = dp[j] + dp[j-i];
        }
    }

    return dp.back();
}

// Memoization
int mem_util(vector<int>& coins, int n, int amount, vector<vector<int>>& dp) {
    if (amount == 0) {
        return dp[n][amount] = 1;
    }

    if (n == 0) {
        return dp[n][amount] = 0;
    }
    if (dp[n][amount] != -1) {
        return dp[n][amount];
    }

    int count = 0;
    if (amount >= coins[n-1]) {
        count += mem_util(coins, n, amount-coins[n-1], dp);
        count += mem_util(coins, n-1, amount, dp);
    } else {
        count += mem_util(coins, n-1, amount, dp);
    }
    return dp[n][amount] = count;
}

int coinChange_memoization(vector<int>& coins, int n, int amount) {
    vector<vector<int>> dp(n+1, vector<int> (amount+1, -1));
    return mem_util(coins, n, amount, dp);
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

    cout << coinChange_memoization(coins, n, amount);
    return 0;
}
