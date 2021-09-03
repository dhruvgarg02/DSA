#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

int target_sum(vector<int>& v, int n, int target) {
    int sum = 0;
    for (auto i : v) {
        sum += i;
    }

    target = abs(target);  // Handle for negative target
    if (sum < target || (sum + target) & 1) return 0;  // checking if (sum+target) is odd
    int new_target = (target + sum) / 2;

    vector<vector<int>> dp(n+1, vector<int> (new_target+1, 0));
    dp[0][0] = 1;

    for (int i = 1; i < n+1; i++) {
        for (int j = 0; j < new_target+1; j++) {
            if (v[i-1] <= j) {
                dp[i][j] = dp[i-1][j] + dp[i-1][j-v[i-1]];
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[n][new_target];
}

// Space Optimized
int target_sum_1d(vector<int>& v, int n, int target) {
    int sum = 0;
    for (auto i : v) {
        sum += i;
    }
    
    target = abs(target);  // Handle for negative target
    if (sum < target || (sum + target) & 1) return 0;  // checking if (sum+target) is odd
    int new_target = (target + sum) / 2;

    vector<int> dp(new_target+1, 0);
    dp[0] = 1;

    for (auto i : v) {
        for (int j = new_target; j >= i; j--) {
            dp[j] = dp[j] + dp[j-i];
        }
    }

    return dp.back();
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

    vector<int> v;
    int temp;

    for (int i = 0; i < n; i++) {
        cin >> temp;
        v.push_back(temp);
    }

    int target;
    cin >> target;

    cout << target_sum(v, n, target);

    return 0;
}
