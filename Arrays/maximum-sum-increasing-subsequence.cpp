#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

int maxSumIncreasingSubsequence(int n, vector<int>& v) {
    vector<int> dp;
    dp = v;
    for (int i = 1; i < dp.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (v[i] > v[j] and dp[i] < dp[j] + v[i])
                dp[i] = dp[j] + v[i];
        }
    }

    return *max_element(dp.begin(), dp.end());
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

    for (int i = 0; i < n; i++) {
        int temp;
        cin>>temp;
        v.push_back(temp);
    }
    cout<<maxSumIncreasingSubsequence(n, v);
    return 0;
}
