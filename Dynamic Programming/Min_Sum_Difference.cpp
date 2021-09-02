#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

int min_sum_diff(vector<int>& arr, int n) {
    int arr_sum = 0;
    for (int i = 0; i < n; i++) {
        arr_sum += arr[i];
    }

    int range = arr_sum/2;
    vector<vector<bool>> dp(n+1, vector<bool> (range+1, false));

    for (int i = 0; i < n+1; i++) {
        dp[i][0] = true;
    }

    for (int i = 1; i < n+1; i++) {
        for (int j = 1; j < range+1; j++) {
            if (j >= arr[i-1]) {
                dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    int sum1 = INT_MIN;
    for (int i = 0; i < range+1; i++) {
        if (dp[n][i] == true) sum1 = i;
    }

    return arr_sum - 2*sum1;
}

// Space Optimized DP
int min_sum_diff_1d(vector<int>& arr, int n) {
    int arr_sum = 0;
    for (int i = 0; i < n; i++) {
        arr_sum += arr[i];
    }

    int range = arr_sum / 2;
    vector<bool> dp(range+1, false);

    dp[0] = true;

    for (int i = 0; i < n; i++) {
        for (int j = range; j >= arr[i]; j--) {
            dp[j] = dp[j] || dp[j-arr[i]];
        }
    }

    int sum1 = INT_MIN;

    for (int i = 0; i < range+1; i++) {
        if (dp[i] == true) sum1 = i;
    }

    return arr_sum - 2*sum1;
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

    vector<int> arr;
    int temp;

    for (int i = 0; i < n; i++) {
        cin >> temp;
        arr.push_back(temp);
    }

    cout << min_sum_diff(arr, n);

    return 0;
}
