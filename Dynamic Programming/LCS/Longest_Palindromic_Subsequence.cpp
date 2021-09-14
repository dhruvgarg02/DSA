#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

// Using LCS
int using_lcs(string &s) {
    vector<vector<int>> dp(s.size() + 1, vector<int> (s.size() + 1, 0));

    for (int i = 1; i < s.size()+1; i++) {
        for (int j = 1; j < s.size()+1; j++) {
            if (s[i-1] == s[s.size()-j]) {
                dp[i][j] = 1 + dp[i-1][j-1];
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    return dp.back().back();
}

// Without lcs_version (GAP Method)
int without_lcs(string &s) {
    vector<vector<int>> dp(s.size(), vector<int> (s.size(), 0));

    for (int gap = 0; gap < s.size(); gap++) {
        for (int i = 0, j = gap; j < s.size(); i++, j++) {
            if (gap == 0) {
                dp[i][j] = 1;     // Initialization
            } else if (gap == 1) {
                dp[i][j] = s[i] == s[j] ? 2 : 1;    // Initialization
            } else {
                if (s[i] == s[j]) dp[i][j] = 2 + dp[i+1][j-1];
                else dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
            }
        }
    }

    return dp[0].back();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("../../Input.txt","r",stdin);
    freopen("../../Output.txt","w",stdout);
    #endif

    string s;
    cin >> s;

    cout << without_lcs(s);

    return 0;
}
