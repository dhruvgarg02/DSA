#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("../../Input.txt","r",stdin);
    freopen("../../Output.txt","w",stdout);
    #endif

    string X, Y;
    cin >> X >> Y;

    int m = X.size();
    int n = Y.size();
    vector<vector<int>> dp(m+1, vector<int> (n+1, 0));

        for (int i = 1; i < m+1; i++) {
            for (int j = 1; j < n+1; j++) {
                if (X[i-1] == Y[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        cout << m+n-dp.back().back();

    return 0;
}
