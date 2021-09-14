#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

// Using Longest Common Subsequence
int lcs_version(string &word1, string &word2) {
    int n = word1.size();
    int m = word2.size();
    vector<vector<int>> dp (n+1, vector<int> (m+1, 0));

    for (int i = 1; i < n+1; i++) {
        for (int j = 1; j < m+1; j++) {
            if (word1[i-1] == word2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
        }
    }

    return n+m-2*dp.back().back();
}

// Without LCS
int without_lcs(string &word1, string &word2) {
    int n = word1.size();
    int m = word2.size();
    vector<vector<int>> dp (n+1, vector<int> (m+1, 0));

    for (int i = 0; i < n+1; i++) {
        for (int j = 0; j < m+1; j++) {
            if (i == 0 || j == 0) dp[i][j] = i + j;    // Initialization
            else if (word1[i-1] == word2[j-1]) dp[i][j] = dp[i-1][j-1];
            else dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + 1;
        }
    }

    return dp.back().back();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("../../Input.txt","r",stdin);
    freopen("../../Output.txt","w",stdout);
    #endif

    string word1, word2;
    cin >> word1 >> word2;

    cout << without_lcs(word1, word2);

    return 0;
}
