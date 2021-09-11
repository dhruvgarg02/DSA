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

    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> b(m);
    for (int i = 0; i < n; i++) cin>>a[i];
    for (int i = 0; i < m; i++) cin>>b[i];
    vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
    for (int i = 1; i < n+1; i++) {
        for (int j = 1; j < m+1; j++) {
            if (a[i-1] == b[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    vector<int> res;
    int i = n, j = m;
    while(i > 0 && j > 0) {
        if (a[i-1] == b[j-1]) {
            res.push_back(a[i-1]);
            i--; j--;
        } else {
            if (dp[i][j-1] > dp[i-1][j]) j--;
            else i--;
        }
    }
    reverse(res.begin(), res.end());

    for (int x : res) cout << x << " ";

    return 0;
}
