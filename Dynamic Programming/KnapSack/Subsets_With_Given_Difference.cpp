#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

int subsets_with_given_difference(vector<int>& v, int n, int diff) {
    int sum = 0;
    for (auto i : v) {
        sum += i;
    }

    int target = (sum + diff) / 2; // Problem reduced to count of subset sum

    vector<vector<int>> dp(n+1, vector<int> (target+1, 0));
    for (int i = 0; i < n+1; i++) {
        dp[i][0] = 1;
    }

    for (int i = 1; i < n+1; i++) {
        for (int j = 1; j < target+1; j++) {
            if (j >= v[i-1]) {
                dp[i][j] = dp[i-1][j] + dp[i-1][j-v[i-1]];
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[n][target];
}

// Space Optimized
int subsets_with_given_difference_1d(vector<int>& v, int n, int diff) {
    int sum = 0;
    for (auto i : v) {
        sum += i;
    }

    int target = (sum + diff) / 2; // Problem reduced to count of subset sum

    vector<int> dp(target+1, 0);
    dp[0] = 1;

    for (auto i : v) {
        for (int j = target; j >= i; j--) {
            dp[j] = dp[j] + dp[j-i];
        }
    }

    return dp[target];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("Input.txt","r",stdin);
    freopen("Output.txt","w",stdout);
    #endif

    int n;
    cin>>n;

    vector<int> v;
    int temp;

    int diff;
    cin>>diff;

    for (int i = 0; i < n; i++) {
        cin>>temp;
        v.push_back(temp);
    }

    cout<<subsets_with_given_difference_1d(v, n, diff);

    return 0;
}
