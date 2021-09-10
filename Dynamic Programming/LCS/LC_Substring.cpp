#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("Input.txt","r",stdin);
    freopen("Output.txt","w",stdout);
    #endif

    string s1, s2;
    cin >> s1 >> s2;

    int n = s1.length();
    int m = s2.length();

    int res = 0;
    vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
    for (int i = 1; i < n+1; i++) {
        for (int j = 1; j < m+1; j++) {
            if (s1[i-1] == s2[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
                res  = max(res, dp[i][j]);
            }
        }
    }

   cout << res;
   return 0;
}
