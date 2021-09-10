#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

// recursion
int lcs_recursion(string text1, string text2, int n, int m) {
    if (n == 0 || m == 0) return 0;
    if (text1[n-1] == text2[m-1]) {
        return (1 + lcs_recursion(text1, text2, n-1, m-1));
    } else {
        return (max(lcs_recursion(text1, text2, n, m-1), lcs_recursion(text1, text2, n-1, m)));
    }
}

// memoization
int lcs_memoization(string &text1, string &text2, int n, int m, vector<vector<int>>& dp) {
    if (n == 0 || m == 0) return 0;
    if (dp[n-1][m-1] >= 0) return dp[n-1][m-1];
    if (text1[n-1] == text2[m-1]) {
        dp[n-1][m-1] = 1 + lcs_memoization(text1, text2, n-1, m-1, dp);
    } else {
        dp[n-1][m-1] = max(lcs_memoization(text1, text2, n, m-1, dp), lcs_memoization(text1, text2, n-1, m, dp));

    }
    return dp[n-1][m-1];
}

int lcs_tabulation(string &text1, string &text2, int n, int m) {
    vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
    for (int i = 1; i < n+1; i++) {
        for (int j = 1; j < m+1; j++) {
            if (text1[i-1] == text2[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    return dp.back().back();
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("Input.txt","r",stdin);
    freopen("Output.txt","w",stdout);
    #endif

    string text1, text2;
    cin >> text1 >> text2;

    int n = text1.length();
    int m = text2.length();

    // cout << lcs_recursion(text1, text2, n, m);

    // Memoization
    // vector<vector<int>> dp(n, vector<int> (m, -1));
    // cout << lcs_memoization(text1, text2, n, m, dp);

    // Tabulation
    cout<<lcs_tabulation(text1, text2, n, m);


    return 0;
}
